/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "board.h"
#include "rtt_port.h"
#include <rtthread.h>

#include "common.h"
#include "lwip.h"
#include "lwip/init.h"
#include "lwip/tcpip.h"
#include "netconf.h"
#include "udp_echo.h"


#define TIMER_TIMEOUT_CNT    1000

/*--------------- Tasks Priority -------------*/
#define IDLE_TASK_PRIO      (RT_THREAD_PRIORITY_MAX - 1)
#define MAIN_TASK_PRIO      (IDLE_TASK_PRIO - 1)
#define DHCP_TASK_PRIO      (IDLE_TASK_PRIO - 4)
#define NETIF_STA_TASK_PRIO (IDLE_TASK_PRIO - 4)

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_DESC_ADDR_ALIGNMENT)
__RW enet_rx_desc_t dma_rx_desc_tab[ENET_RX_BUFF_COUNT]; /* Ethernet Rx DMA Descriptor */

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_DESC_ADDR_ALIGNMENT)
__RW enet_tx_desc_t dma_tx_desc_tab[ENET_TX_BUFF_COUNT]; /* Ethernet Tx DMA Descriptor */

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_BUFF_ADDR_ALIGNMENT)
__RW uint8_t rx_buff[ENET_RX_BUFF_COUNT][ENET_RX_BUFF_SIZE]; /* Ethernet Receive Buffer */

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_BUFF_ADDR_ALIGNMENT)
__RW uint8_t tx_buff[ENET_TX_BUFF_COUNT][ENET_TX_BUFF_SIZE]; /* Ethernet Transmit Buffer */

enet_desc_t desc;
uint8_t mac[ENET_MAC];
struct netif gnetif;

void Main_task(void *pvParameters);
void thread_entry(void *arg);

void bsp_init(void)
{
    /* Initialize BSP */
    board_init();

    /* Initialize GPIOs */
    board_init_enet_pins(ENET);

    /* Reset an enet PHY */
    board_reset_enet_phy(ENET);

    printf("This is an ethernet demo: UDP Echo On RTThread-Nano\n");
    printf("LwIP Version: %s\n", LWIP_VERSION_STRING);

    #if defined(RGMII) && RGMII
    /* Set RGMII clock delay */
    board_init_enet_rgmii_clock_delay(ENET);
    #elif defined(RMII) && RMII
    /* Set RMII reference clock */
    board_init_enet_rmii_reference_clock(ENET, BOARD_ENET_RMII_INT_REF_CLK);
    printf("Reference Clock: %s\n", BOARD_ENET_RMII_INT_REF_CLK ? "Internal Clock" : "External Clock");
    #endif
}

hpm_stat_t enet_init(ENET_Type *ptr)
{
    enet_int_config_t int_config = {.int_enable = 0, .int_mask = 0};
    enet_mac_config_t enet_config;
    enet_tx_control_config_t enet_tx_control_config;

    #if defined(RGMII) && RGMII
        #if defined(__USE_DP83867) && __USE_DP83867
        dp83867_config_t phy_config;
        #else
        rtl8211_config_t phy_config;
        #endif
    #else
        #if defined(__USE_DP83848) && __USE_DP83848
        dp83848_config_t phy_config;
        #else
        rtl8201_config_t phy_config;
        #endif
    #endif

    /* Initialize td, rd and the corresponding buffers */
    memset((uint8_t *)dma_tx_desc_tab, 0x00, sizeof(dma_tx_desc_tab));
    memset((uint8_t *)dma_rx_desc_tab, 0x00, sizeof(dma_rx_desc_tab));
    memset((uint8_t *)rx_buff, 0x00, sizeof(rx_buff));
    memset((uint8_t *)tx_buff, 0x00, sizeof(tx_buff));

    desc.tx_desc_list_head = (enet_tx_desc_t *)core_local_mem_to_sys_address(BOARD_RUNNING_CORE, (uint32_t)dma_tx_desc_tab);
    desc.rx_desc_list_head = (enet_rx_desc_t *)core_local_mem_to_sys_address(BOARD_RUNNING_CORE, (uint32_t)dma_rx_desc_tab);

    desc.tx_buff_cfg.buffer = core_local_mem_to_sys_address(BOARD_RUNNING_CORE, (uint32_t)tx_buff);
    desc.tx_buff_cfg.count = ENET_TX_BUFF_COUNT;
    desc.tx_buff_cfg.size = ENET_TX_BUFF_SIZE;

    desc.rx_buff_cfg.buffer = core_local_mem_to_sys_address(BOARD_RUNNING_CORE, (uint32_t)rx_buff);
    desc.rx_buff_cfg.count = ENET_RX_BUFF_COUNT;
    desc.rx_buff_cfg.size = ENET_RX_BUFF_SIZE;

    /*Get a default control config for tx descriptor */
    enet_get_default_tx_control_config(ENET, &enet_tx_control_config);

    /* Set the control config for tx descriptor */
    memcpy(&desc.tx_control_config, &enet_tx_control_config, sizeof(enet_tx_control_config_t));

    /* Get MAC address */
    enet_get_mac_address(mac);

    /* Set MAC0 address */
    enet_config.mac_addr_high[0] = mac[5] << 8 | mac[4];
    enet_config.mac_addr_low[0]  = mac[3] << 24 | mac[2] << 16 | mac[1] << 8 | mac[0];
    enet_config.valid_max_count  = 1;

    /* Set DMA PBL */
    enet_config.dma_pbl = board_get_enet_dma_pbl(ENET);

    /* Set SARC */
    enet_config.sarc = enet_sarc_replace_mac0;

    /* Enable Enet IRQ */
    board_enable_enet_irq(ENET);

    /* Get the default interrupt config */
    enet_get_default_interrupt_config(ENET, &int_config);

    /* Initialize enet controller */
    if (enet_controller_init(ptr, ENET_INF_TYPE, &desc, &enet_config, &int_config) != status_success) {
        return status_fail;
    }

    /* Disable LPI interrupt */
    enet_disable_lpi_interrupt(ENET);

    /* Initialize phy */
    #if defined(RGMII) && RGMII
        #if defined(__USE_DP83867) && __USE_DP83867
        dp83867_reset(ptr);
        #if defined(__DISABLE_AUTO_NEGO) && __DISABLE_AUTO_NEGO
        dp83867_set_mdi_crossover_mode(ENET, enet_phy_mdi_crossover_manual_mdix);
        #endif
        dp83867_basic_mode_default_config(ptr, &phy_config);
        if (dp83867_basic_mode_init(ptr, &phy_config) == true) {
        #else
        rtl8211_reset(ptr);
        rtl8211_basic_mode_default_config(ptr, &phy_config);
        if (rtl8211_basic_mode_init(ptr, &phy_config) == true) {
        #endif
    #else
        #if defined(__USE_DP83848) && __USE_DP83848
        dp83848_reset(ptr);
        dp83848_basic_mode_default_config(ptr, &phy_config);
        if (dp83848_basic_mode_init(ptr, &phy_config) == true) {
        #else
        rtl8201_reset(ptr);
        rtl8201_basic_mode_default_config(ptr, &phy_config);
        if (rtl8201_basic_mode_init(ptr, &phy_config) == true) {
        #endif
    #endif
            printf("Enet phy init passed !\n");
            return status_success;
        } else {
            printf("Enet phy init failed !\n");
            return status_fail;
        }
}

void rt_hw_board_init(void)
{
    /* Initialize bsp */
    bsp_init();

    rtt_base_init();
}

int rtthread_init(void)
{
    rt_thread_t main_thread = rt_thread_create("main", thread_entry, NULL, 1024, MAIN_TASK_PRIO, 10);
    rt_thread_startup(main_thread);

    return 0;
}

int main(void)
{
    rtthread_init();

    return 0;
}

void thread_entry(void *arg)
{
    (void)arg;

    static rt_timer_t timer = RT_NULL;

    /* Initialize MAC and DMA */
    enet_init(ENET);

    /* Initialize LwIP stack */
    tcpip_init(NULL, NULL);
    netif_config(&gnetif);

    udp_echo_init();

#if defined(LWIP_DHCP) && LWIP_DHCP
    rt_thread_t dhcp_thread = rt_thread_create("DHCP", LwIP_DHCP_task, &gnetif, 1024, DHCP_TASK_PRIO, 10);
    rt_thread_startup(dhcp_thread);
#endif

    rt_thread_t netif_update_link_status_thread = rt_thread_create("netif update status", netif_update_link_status, &gnetif, 1024, NETIF_STA_TASK_PRIO, 10);
    rt_thread_startup(netif_update_link_status_thread);

    timer = rt_timer_create("timer", timer_callback, RT_NULL, TIMER_TIMEOUT_CNT, RT_TIMER_FLAG_PERIODIC);
    rt_timer_start(timer);
}

