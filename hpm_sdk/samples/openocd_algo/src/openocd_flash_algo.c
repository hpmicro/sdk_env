/*
 * Copyright (c) 2021 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "board.h"
#include "hpm_common.h"
#include "hpm_l1c_drv.h"
#include "hpm_romapi.h"

#define XPI0_MEM_START (0x80000000UL)
#define XPI1_MEM_START (0x90000000UL)
#define XPI_USE_PORT_B_MASK (0x100)
#define XPI_USE_PORT_A_MASK (0)
#define XPI_USE_PORT_SHIFT (0x8)

#define ROMAPI_SUPPORTS_HYBRIDXPI() (ROM_API_TABLE_ROOT->xpi_nor_driver_if->version >= 0x56010300)

typedef struct {
    uint32_t total_sz_in_bytes;
    uint32_t sector_sz_in_bytes;
} hpm_flash_info_t;

__attribute__ ((section(".flash_algo.data"))) xpi_nor_config_t nor_config;
__attribute__ ((section(".flash_algo.data"))) bool xpi_inited = false;
__attribute__ ((section(".flash_algo.data"))) uint32_t channel = xpi_channel_a1;
__attribute__ ((section(".flash_algo.data"))) XPI_Type *xpi_base;

__attribute__ ((section(".flash_algo.text"))) void refresh_device_size(XPI_Type *base, xpi_nor_config_option_t *option)
{
    volatile uint32_t *dev_size = (volatile uint32_t *)((uint32_t)base + 0x60);
    bool enable_channelb = false;
    if (option->header.words > 1) {
        enable_channelb = option->option1.connection_sel == xpi_nor_connection_sel_chnb_cs0;
    }
    if (enable_channelb) {
        dev_size[0] = 0;
        dev_size[1] = 0;
    }
}

__attribute__ ((section(".flash_algo.text"))) uint32_t flash_init(uint32_t flash_base, uint32_t header, uint32_t opt0, uint32_t opt1, uint32_t xpi_base_addr)
{
    uint32_t i = 0;
    xpi_nor_config_option_t cfg_option;
    hpm_stat_t stat = status_success;

    xpi_base = (XPI_Type *)xpi_base_addr;
    if (xpi_inited) {
        return stat;
    }

    for (i = 0; i < sizeof(cfg_option); i++) {
        *((uint8_t *)&cfg_option + i) = 0;
    }
    for (i = 0; i < sizeof(nor_config); i++) {
        *((uint8_t *)&nor_config + i) = 0;
    }

    cfg_option.header.U = header;
    cfg_option.option0.U = opt0;
    cfg_option.option1.U = opt1;

    if (opt1 & XPI_USE_PORT_B_MASK) {
        channel = xpi_channel_b1;
    } else {
        channel = xpi_channel_a1;
    }

    stat = ROM_API_TABLE_ROOT->xpi_nor_driver_if->auto_config(xpi_base, &nor_config, &cfg_option);
    if (stat) {
        return stat;
    }

    if (ROMAPI_SUPPORTS_HYBRIDXPI()) {
        ROM_API_TABLE_ROOT->xpi_nor_driver_if->enable_hybrid_xpi(xpi_base);
    }

    refresh_device_size(xpi_base, &cfg_option);

    nor_config.device_info.clk_freq_for_non_read_cmd = 0;
    if (!xpi_inited) {
        xpi_inited = true;
    }
    return stat;
}

__attribute__ ((section(".flash_algo.text"))) uint32_t flash_erase(uint32_t flash_base, uint32_t address, uint32_t size)
{
    hpm_stat_t stat = status_success;
    uint32_t left, start, block_size, align;

    left = size;
    start = address;
    if (ROMAPI_SUPPORTS_HYBRIDXPI()) {
        start += flash_base;
    }
    block_size = nor_config.device_info.block_size_kbytes * 1024;
    if (left >= block_size) {
        align = block_size - (start % block_size);
        if (align != block_size) {
            stat = ROM_API_TABLE_ROOT->xpi_nor_driver_if->erase(xpi_base, channel, &nor_config, start, align);
            if (stat != status_success) {
                return stat;
            }
            left -= align;
            start += align;
        }
        while (left > block_size) {
            stat = ROM_API_TABLE_ROOT->xpi_nor_driver_if->erase_block(xpi_base, channel, &nor_config, start);
            if (stat != status_success) {
                break;
            }
            left -= block_size;
            start += block_size;
        }
    }
    if ((stat == status_success) && left) {
        stat = ROM_API_TABLE_ROOT->xpi_nor_driver_if->erase(xpi_base, channel, &nor_config, start, left);
    }
    return stat;
}

__attribute__ ((section(".flash_algo.text"))) uint32_t flash_program(uint32_t flash_base, uint32_t address, uint32_t *buf, uint32_t size)
{
    hpm_stat_t stat;

    if (ROMAPI_SUPPORTS_HYBRIDXPI()) {
        address += flash_base;
    }
    stat = ROM_API_TABLE_ROOT->xpi_nor_driver_if->program(xpi_base, channel, &nor_config, buf, address, size);
    return stat;
}

__attribute__ ((section(".flash_algo.text"))) uint32_t flash_read(uint32_t flash_base, uint32_t *buf, uint32_t address, uint32_t size)
{
    hpm_stat_t stat;

    if (ROMAPI_SUPPORTS_HYBRIDXPI()) {
        address += flash_base;
    }
    stat = rom_xpi_nor_read(xpi_base, channel, &nor_config, buf, address, size);
    return stat;
}

__attribute__ ((section(".flash_algo.text"))) uint32_t flash_get_info(uint32_t flash_base, hpm_flash_info_t *flash_info)
{
    if (!flash_info) {
        return status_invalid_argument;
    }

    flash_info->total_sz_in_bytes = nor_config.device_info.size_in_kbytes << 10;
    flash_info->sector_sz_in_bytes = nor_config.device_info.sector_size_kbytes << 10;
    return status_success;
}

__attribute__ ((section(".flash_algo.text"))) uint32_t flash_erase_chip(uint32_t flash_base)
{
    return rom_xpi_nor_erase_chip(xpi_base, channel, &nor_config);
}

__attribute__ ((section(".flash_algo.text"))) void flash_deinit(void)
{
    return;
}
