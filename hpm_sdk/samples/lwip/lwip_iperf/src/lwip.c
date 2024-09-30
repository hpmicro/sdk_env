/*
 * Copyright (c) 2021-2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*---------------------------------------------------------------------*
 * Includes
 *---------------------------------------------------------------------*/
#include "common.h"
#include "netconf.h"
#include "sys_arch.h"
#include "ethernetif.h"
#include "lwip.h"
#include "lwip/init.h"
#include "lwip/timeouts.h"
#include "lwip/apps/lwiperf.h"
#include "lwip/dhcp.h"
#include "lwip/prot/dhcp.h"

#ifndef IPERF_UDP_CLIENT_RATE
#if defined(RGMII) && RGMII
    #define IPERF_UDP_CLIENT_RATE (1000 * 1024 * 1024)
#else
    #define IPERF_UDP_CLIENT_RATE (100 * 1024 * 1024)
#endif
#endif

#ifndef IPERF_CLIENT_AMOUNT
#define IPERF_CLIENT_AMOUNT (-1000) /* 10 seconds */
#endif

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_DESC_ADDR_ALIGNMENT)
__RW enet_rx_desc_t dma_rx_desc_tab[ENET_RX_BUFF_COUNT] ; /* Ethernet Rx DMA Descriptor */

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_DESC_ADDR_ALIGNMENT)
__RW enet_tx_desc_t dma_tx_desc_tab[ENET_TX_BUFF_COUNT] ; /* Ethernet Tx DMA Descriptor */

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_BUFF_ADDR_ALIGNMENT)
__RW uint8_t rx_buff[ENET_RX_BUFF_COUNT][ENET_RX_BUFF_SIZE]; /* Ethernet Receive Buffer */

ATTR_PLACE_AT_NONCACHEABLE_WITH_ALIGNMENT(ENET_SOC_BUFF_ADDR_ALIGNMENT)
__RW uint8_t tx_buff[ENET_TX_BUFF_COUNT][ENET_TX_BUFF_SIZE]; /* Ethernet Transmit Buffer */

enet_desc_t desc;
uint8_t mac[ENET_MAC];
struct netif gnetif;

/*---------------------------------------------------------------------*
 * Initialization
 *---------------------------------------------------------------------*/
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

    /* Initialize enet controller */
    if (enet_controller_init(ptr, ENET_INF_TYPE, &desc, &enet_config, &int_config) != status_success) {
        return status_fail;
    }

    /* Initialize phy */
    #if defined(RGMII) && RGMII
        #if defined(__USE_DP83867) && __USE_DP83867
        dp83867_reset(ptr);
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

static void
lwiperf_report(void *arg, enum lwiperf_report_type report_type,
  const ip_addr_t* local_addr, u16_t local_port, const ip_addr_t* remote_addr, u16_t remote_port,
  u32_t bytes_transferred, u32_t ms_duration, u32_t bandwidth_kbitpsec)
{
  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(local_addr);
  LWIP_UNUSED_ARG(local_port);

  LWIP_PLATFORM_DIAG(("iperf report: type=%d, remote: %s:%d, total bytes: %"U32_F", duration in ms: %"U32_F", kbits/s: %"U32_F"\n",
    (int)report_type, ipaddr_ntoa(remote_addr), (int)remote_port, bytes_transferred, ms_duration, bandwidth_kbitpsec));
}

static bool select_mode(struct netif *netif, bool *server_mode, bool *tcp, enum lwiperf_client_type *client_type)
{
    char code;

    if (!netif_is_link_up(netif)) {
        return false;
    }

    printf("\n");
    printf("1: TCP Server Mode\n");
    printf("2: TCP Client Mode\n");
    printf("3: UDP Server Mode\n");
    printf("4: UDP Client Mode\n");
    printf("Please enter one of modes above (e.g. 1 or 2 ...): ");
    code = getchar();
    printf("%c\n", code);

    switch (code)
    {
        case '1':
            *server_mode = true;
            *tcp         = true;
            *client_type = LWIPERF_CLIENT;
            break;

        case '2':
            *server_mode = false;
            *tcp         = true;
            *client_type = LWIPERF_CLIENT;
            break;

        case '3':
            *server_mode = true;
            *tcp         = false;
            *client_type = LWIPERF_CLIENT;
            break;

        case '4':
            *server_mode = false;
            *tcp         = false;
            *client_type = LWIPERF_CLIENT;
            break;

        default:
            return false;
    }

    return true;
}

void *start_iperf(void)
{
    bool server = false;
    bool tcp = false;
    enum lwiperf_client_type client_type;
    void *session;
    ip_addr_t remote_addr;

    if (!select_mode(&gnetif, &server, &tcp, &client_type)) {
        return NULL;
    }

    if (server) {
        if (tcp) {
            session = lwiperf_start_tcp_server_default(lwiperf_report, NULL);
        } else {
            session = lwiperf_start_udp_server(netif_ip_addr4(netif_default), LWIPERF_UDP_PORT_DEFAULT,
                                               lwiperf_report, NULL);
        }
    } else {
        IP_ADDR4(&remote_addr, REMOTE_IP_ADDR0, REMOTE_IP_ADDR1, REMOTE_IP_ADDR2, REMOTE_IP_ADDR3);
        if (tcp) {
            session = lwiperf_start_tcp_client_default(&remote_addr, lwiperf_report, NULL);
        } else {
            session = lwiperf_start_udp_client(netif_ip_addr4(netif_default), LWIPERF_UDP_PORT_DEFAULT,
                                               &remote_addr, LWIPERF_UDP_PORT_DEFAULT, client_type,
                                               IPERF_CLIENT_AMOUNT, IPERF_UDP_CLIENT_RATE, 0,
                                               lwiperf_report, NULL);
        }
    }

    return session;
}

void iperf(void)
{
    static void *session = NULL;

#if defined(LWIP_DHCP) && LWIP_DHCP
    if (netif_dhcp_data(&gnetif)->state == DHCP_STATE_BOUND) {
#endif
        if (session == NULL) {
            session = start_iperf();
        } else {
            if (console_try_receive_byte() == ' ') {
                lwiperf_abort(session);
                session = NULL;
            }
        }

        lwiperf_poll_udp_client();
#if defined(LWIP_DHCP) && LWIP_DHCP
    }
#endif
}

/*---------------------------------------------------------------------*
 * Main
/ *---------------------------------------------------------------------*/
int main(void)
{
    /* Initialize Clocks */
    board_init();

    /* Initialize GPIOs */
    board_init_enet_pins(ENET);

    /* Reset an enet PHY */
    board_reset_enet_phy(ENET);

    printf("This is an ethernet demo: Iperf\n");
    printf("LwIP Version: %s\n", LWIP_VERSION_STRING);

    #if defined(RGMII) && RGMII
    /* Set RGMII clock delay */
    board_init_enet_rgmii_clock_delay(ENET);
    #elif defined(RMII) && RMII
    /* Set RMII reference clock */
    board_init_enet_rmii_reference_clock(ENET, BOARD_ENET_RMII_INT_REF_CLK);
    printf("Reference Clock: %s\n", BOARD_ENET_RMII_INT_REF_CLK ? "Internal Clock" : "External Clock");
    #endif

    /* Initialize MAC and DMA */
    if (enet_init(ENET) == 0) {
        /* Initialize the Lwip stack */
        lwip_init();
        board_timer_create(LWIP_APP_TIMER_INTERVAL, sys_timer_callback);
        netif_config(&gnetif);

        /* Start services */
        enet_services(&gnetif);

        while (1) {
            enet_common_handler(&gnetif);
            iperf();
        }
    } else {
        printf("Enet initialization fails !!!\n");
        while (1);
    }

    return 0;
}
