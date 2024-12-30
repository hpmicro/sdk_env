/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*---------------------------------------------------------------------*
 * Includes
 *---------------------------------------------------------------------*/
#include "frame_preemption_ingress.h"

static volatile tsw_phy_status_t last_status = {.tsw_phy_link = tsw_phy_link_unknown};
uint8_t mac[] = {0x98, 0x2c, 0xbc, 0xb1, 0x9f, 0x17};
ATTR_PLACE_AT_NONCACHEABLE_INIT_WITH_ALIGNMENT(4) tsw_tsf_t entry[10];
ATTR_PLACE_AT_NONCACHEABLE_BSS_WITH_ALIGNMENT(TSW_SOC_DATA_BUS_WIDTH) uint8_t send_buff[TSW_SEND_DESC_COUNT][TSW_SEND_BUFF_LEN];
ATTR_PLACE_AT_NONCACHEABLE_BSS_WITH_ALIGNMENT(TSW_SOC_DATA_BUS_WIDTH) uint8_t recv_buff[TSW_RECV_DESC_COUNT][TSW_RECV_BUFF_LEN];
ATTR_PLACE_AT_NONCACHEABLE_INIT_WITH_ALIGNMENT(4)  uint8_t data_buff[] = {
0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x98, 0x2c, 0xbc, 0xb1, 0x9f, 0x17,
0x08, 0x06,
0x00, 0x01,
0x08, 0x00,
0x06,
0x04,
0x00, 0x01,
0x98, 0x2c, 0xbc, 0xb1, 0x9f, 0x17,
0xc0, 0xa8, 0x64, 0x0a,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xc0, 0xa8, 0x64, 0x05,
};


ATTR_PLACE_AT_NONCACHEABLE_INIT_WITH_ALIGNMENT(4)  uint8_t data_buff1[16+512] = {
0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x98, 0x2c, 0xbc, 0xb1, 0x9f, 0x17,
0x08, 0x06,
0x00, 0x01,
0x08, 0x00,
0x06,
0x04,
0x00, 0x01,
0x98, 0x2c, 0xbc, 0xb1, 0x9f, 0x17,
0xc0, 0xa8, 0x64, 0x0a,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xc0, 0xa8, 0x64, 0x05,
};
/*---------------------------------------------------------------------*
 * Initialization
 *---------------------------------------------------------------------*/
hpm_stat_t tsw_init(TSW_Type *ptr)
{
    rtl8211_config_t phy_config;
    tsw_dma_config_t config;

    /* Disable all MACs(TX/RX) */
    tsw_ep_disable_all_mac_ctrl(ptr, TSW_RXFIFO_E1);

    /* Set Mac Address */
    tsw_ep_set_mac_addr(ptr, BOARD_TSW_PORT, mac, true);

    /* Set MAC Mode: GMII, CLKSEL: refclk */
    tsw_ep_set_mac_mode(ptr, BOARD_TSW_PORT, BOARD_TSW_PORT_ITF ==  tsw_port_phy_itf_rgmii ? tsw_mac_mode_gmii : tsw_mac_mode_mii);

    /* Set port PHY interface */
    tsw_set_port_interface(ptr, BOARD_TSW_PORT, BOARD_TSW_PORT_ITF);

    /* Enable all MACs(TX/RX) */
    tsw_ep_enable_all_mac_ctrl(ptr, TSW_RXFIFO_E1);

    tsw_ep_enable_all_mac_ctrl(ptr, TSW_RXFIFO_P1);

    /* Clear CAM */
    tsw_clear_cam(ptr);

    /* Wait for cam clearing completion */
    board_delay_ms(10);

    /* Enable VLAN-ID 1 at all ports */
    tsw_set_cam_vlan_port(ptr);

    /* Get the default DMA config */
    tsw_get_default_dma_config(&config);

    /* Initilaize DMA for sending */
    tsw_init_send(ptr, &config);

    for (uint8_t i = 0; i < TSW_RECV_DESC_COUNT; i++) {
        *send_buff[i] = BOARD_TSW_PORT + 1;
    }

    /* Initialize DMA for receiving */
    tsw_init_recv(ptr, &config);

    for (uint8_t i = 0; i < TSW_RECV_DESC_COUNT; i++) {
        tsw_commit_recv_desc(ptr, recv_buff[i], TSW_RECV_BUFF_LEN, i);
    }

    /* Set MDC clock frequency to 2.5MHz */
    tsw_ep_set_mdio_config(BOARD_TSW, BOARD_TSW_PORT, 19);

    /* Initialize PHY */
    rtl8211_reset(ptr, BOARD_TSW_PORT);
    rtl8211_basic_mode_default_config(ptr, &phy_config);
    if (rtl8211_basic_mode_init(ptr, BOARD_TSW_PORT, &phy_config) == true) {
        printf("TSW phy init passed !\n");
        return status_success;
    } else {
        printf("TSW phy init failed !\n");
        return status_fail;
    }

    return status_success;
}

bool tsw_get_link_status(void)
{
    return (last_status.tsw_phy_link == tsw_phy_link_up) ? true : false;
}

void tsw_self_adaptive_port_speed(void)
{
    tsw_phy_status_t status = {0};
    tsw_port_speed_t port_speed[] = {tsw_port_speed_10mbps, tsw_port_speed_100mbps, tsw_port_speed_1000mbps};
    char *speed_str[] = {"10Mbps", "100Mbps", "1000Mbps"};
    char *duplex_str[] = {"Half duplex", "Full duplex"};

    rtl8211_get_phy_status(BOARD_TSW, BOARD_TSW_PORT, &status);

    if (status.tsw_phy_link || (status.tsw_phy_link != last_status.tsw_phy_link)) {
        if (memcmp((uint8_t *)&last_status, &status, sizeof(tsw_phy_status_t)) != 0) {
            memcpy((uint8_t *)&last_status, &status, sizeof(tsw_phy_status_t));
            if (status.tsw_phy_link) {
                printf("Link Status: Up\n");
                printf("Link Speed:  %s\n", speed_str[status.tsw_phy_speed]);
                printf("Link Duplex: %s\n", duplex_str[status.tsw_phy_duplex]);

                tsw_set_port_speed(BOARD_TSW, BOARD_TSW_PORT, port_speed[status.tsw_phy_speed]);

                if (!status.tsw_phy_duplex) {
                    printf("Error: PHY is in half duplex now, but TSW MAC supports only full duplex mode!\n");
                    return;
                }
            } else {
                printf("Link Status: Down\n");
            }
        }
    }
}

/*---------------------------------------------------------------------*
 * Main
 *---------------------------------------------------------------------*/
int main(void)
{
    tsw_fpe_config_t config;
    uint32_t count = 0;
    uint64_t current;
    uint64_t last;
    uint32_t value = 0;

    /* Initialize BSP */
    board_init();

    /* Initialize GPIOs */
    board_init_tsw_pins(BOARD_TSW);

    /* Reset an TSW PHY */
    board_reset_tsw_phy(BOARD_TSW, BOARD_TSW_PORT);

    printf("This is a TSW demo: Frame Preemption Ingress\n");

    #if defined(RGMII) && RGMII
    board_init_tsw_rgmii_clock_delay(BOARD_TSW, BOARD_TSW_PORT);
    #endif

    board_timer_create(TSW_APP_TIMER_INTERVAL, tsw_self_adaptive_port_speed);

    /* Set RTC increment */
    tsw_set_rtc_time_increment(BOARD_TSW, (10 << 24));

    /* Initialize MAC and DMA */
    if (tsw_init(BOARD_TSW) == 0) {
        /* Set dest port */
        data_buff[0] = BOARD_TSW_PORT + 1;
        data_buff1[0] = BOARD_TSW_PORT + 1;

        /* Prepare streams */
        memcpy(send_buff[0], data_buff, sizeof(data_buff));
        memcpy(send_buff[1], data_buff1, sizeof(data_buff1));

        /* Set FPE config */
        tsw_fpe_get_default_mms_ctrl_config(BOARD_TSW, BOARD_TSW_PORT, &config);
        tsw_fpe_set_mms_ctrl(BOARD_TSW, BOARD_TSW_PORT, &config);
        tsw_fpe_enable_mms(BOARD_TSW, BOARD_TSW_PORT);

        while (1) {
            if (tsw_get_link_status()) {
                send_buff[1][2] = tsw_traffic_queue_1;
                send_buff[1][2] |= 2 << 3;
                tsw_send_frame(BOARD_TSW, send_buff[1], sizeof(data_buff1), 2);

                send_buff[0][2] = tsw_traffic_queue_0;
                send_buff[0][2] |= 1 << 3;
                tsw_send_frame(BOARD_TSW, send_buff[0], sizeof(data_buff), 0);
                board_delay_ms(500);

                while (1) {
                  tsw_get_txtimestampfifo_used(BOARD_TSW, BOARD_TSW_PORT, &count);
                  if (count == 2) {
                      break;
                  }
                }

                for (int i = 0; i < 2; i++) {
                    tsw_get_txtimestampfifo_entry(BOARD_TSW, BOARD_TSW_PORT, &entry[i]);

                    current = (uint64_t)entry[i].tstamphi << 32UL | entry[i].tstamplo;
                    last = (uint64_t)entry[i - 1].tstamphi << 32UL | entry[i - 1].tstamplo;
                    if (i > 0) {
                        printf("tc: %d - utag: %d - tts(s): %d.%09d - frame interval(ns): %u\n", entry[i].tqueue,  entry[i].tuser, entry[i].tstamphi, entry[i].tstamplo, (uint32_t)(current - last));
                    } else {
                        printf("tc: %d - utag: %d - tts(s): %d.%09d - frame interval(ns): 0\n", entry[i].tqueue,  entry[i].tuser, entry[i].tstamphi, entry[i].tstamplo, 0);
                    }

                }

                tsw_fpe_get_mms_statistics_counter(BOARD_TSW, BOARD_TSW_PORT, tsw_fpe_mms_fragment_tx_counter, &value);
                printf("FPE MMS Fragment Tx Counter: %d\n", value);

              printf("==================================================================\n");
            }

        }
    } else {
        printf("TSW initialization fails !!!\n");

        while (1) {

        }
    }

    return 0;
}
