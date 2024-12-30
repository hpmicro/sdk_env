/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "hpm_spi.h"
#include "board.h"

#define TEST_SPI                    BOARD_APP_SPI_BASE
#define TEST_SPI_SCLK_FREQ          (2000000UL)
#define TEST_SPI_DATA_LEN_BITS      (8U)
#define TEST_SPI_DATA_LEN_BYTES     ((TEST_SPI_DATA_LEN_BITS + 7) / 8)
#if (SPI_SOC_TRANSFER_COUNT_MAX == 512)
#if (TEST_SPI_DATA_LEN_BYTES > 2)
#define TRANSFER_COUNT_MAX          (SPI_SOC_TRANSFER_COUNT_MAX * 4)
#else
#define TRANSFER_COUNT_MAX          (SPI_SOC_TRANSFER_COUNT_MAX * TEST_SPI_DATA_LEN_BYTES)
#endif
#else
#define TRANSFER_COUNT_MAX          SPI_SOC_TRANSFER_COUNT_MAX
#endif

#if ((TEST_SPI_DATA_LEN_BYTES * 8) == 8)
#define TEST_SPI_DATA_TYPE_SIZE     8
#elif ((TEST_SPI_DATA_LEN_BYTES * 8) == 16)
#define TEST_SPI_DATA_TYPE_SIZE     16
#else
#define TEST_SPI_DATA_TYPE_SIZE     32
#endif

#define _BUFFER_CONCAT3(x, y, z)     x ## y ## z
#define BUFFER_CONCAT3(x, y, z)     _BUFFER_CONCAT3(x, y, z)

#define TEST_TRANSFER_DATA_COUNT  (512U)

typedef BUFFER_CONCAT3(uint, TEST_SPI_DATA_TYPE_SIZE, _t)  buffer_type;
buffer_type sent_buff[TEST_TRANSFER_DATA_COUNT];
buffer_type receive_buff[TEST_TRANSFER_DATA_COUNT];

static void prepare_transfer_data(void);
static void spi_check_transfer_data(void);

int main(void)
{
    spi_initialize_config_t init_config;
    uint32_t remain_size = sizeof(sent_buff);
    uint32_t transfer_size = 0;
    uint32_t index = 0;
    board_init();
    printf("half_duplex spi master use polling\n");
    board_init_spi_clock(TEST_SPI);
    /* pins init*/
    board_init_spi_pins_with_gpio_as_cs(TEST_SPI);
    hpm_spi_get_default_init_config(&init_config);
    init_config.mode = spi_master_mode;
    init_config.clk_phase = spi_sclk_sampling_odd_clk_edges;
    init_config.clk_polarity = spi_sclk_low_idle;
    init_config.data_len = TEST_SPI_DATA_LEN_BITS;
    /* step.1  initialize spi */
    if (hpm_spi_initialize(TEST_SPI, &init_config) != status_success) {
        printf("hpm_spi_initialize fail\n");
        while (1) {
        }
    }
    /* step.2  set spi sclk frequency for master */
    if (hpm_spi_set_sclk_frequency(TEST_SPI, TEST_SPI_SCLK_FREQ) != status_success) {
        printf("hpm_spi_set_sclk_frequency fail\n");
        while (1) {
        }
    }

    /* step.3 half duplex */
    prepare_transfer_data();
    /* half duplex transmit */
    printf("half_duplex transmit.....\n");
    board_write_spi_cs(BOARD_SPI_CS_PIN, BOARD_SPI_CS_ACTIVE_LEVEL);
    while (remain_size > 0) {
        transfer_size = (remain_size > TRANSFER_COUNT_MAX) ? TRANSFER_COUNT_MAX : remain_size;
        if (hpm_spi_transmit_blocking(TEST_SPI, (uint8_t *)&sent_buff[index], transfer_size, 0xFFFFFFFF) != status_success) {
            printf("hpm_spi_transmit_blocking fail\n");
            break;
        }
        remain_size -= transfer_size;
        index += transfer_size;
    }
    board_write_spi_cs(BOARD_SPI_CS_PIN, !BOARD_SPI_CS_ACTIVE_LEVEL);
    board_delay_ms(10);

    remain_size = sizeof(receive_buff);
    index = 0;
    /* half duplex receive */
    printf("half_duplex receive.....\n");
    board_write_spi_cs(BOARD_SPI_CS_PIN, BOARD_SPI_CS_ACTIVE_LEVEL);
    while (remain_size > 0) {
        transfer_size = (remain_size > TRANSFER_COUNT_MAX) ? TRANSFER_COUNT_MAX : remain_size;
        if (hpm_spi_receive_blocking(TEST_SPI, (uint8_t *)&receive_buff[index], transfer_size, 0xFFFFFFFF) != status_success) {
            printf("hpm_spi_receive_blocking fail\n");
            break;
        }
        remain_size -= transfer_size;
        index += transfer_size;
    }
    board_write_spi_cs(BOARD_SPI_CS_PIN, !BOARD_SPI_CS_ACTIVE_LEVEL);
    spi_check_transfer_data();
}

static void prepare_transfer_data(void)
{
    for (uint32_t i = 0; i < sizeof(sent_buff); i++) {
        sent_buff[i] = i % 0xFFFFFFFF;
    }
    memset(receive_buff, 0, sizeof(receive_buff));
}

static void spi_check_transfer_data(void)
{
    uint32_t i = 0U, error_count = 0U;
    printf("The sent data are:");
    for (i = 0; i < sizeof(sent_buff) / sizeof(buffer_type); i++) {
        if ((i & 0x0FU) == 0U) {
            printf("\r\n");
        }
        printf("0x%x ", sent_buff[i]);
    }
    printf("\n");
    printf("The received data are:");
    for (i = 0; i < sizeof(receive_buff) / sizeof(buffer_type); i++) {
        if ((i & 0x0FU) == 0U) {
            printf("\n");
        }
        printf("0x%x ", receive_buff[i]);
        if (sent_buff[i] != receive_buff[i]) {
            error_count++;
        }
    }
    printf("\n");
    if (error_count == 0) {
        printf("SPI transfer all data matched!\n");
    } else {
        printf("Error occurred in SPI transfer!\n");
    }
}
