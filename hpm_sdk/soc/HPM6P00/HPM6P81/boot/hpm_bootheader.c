/*
 * Copyright (c) 2021,2025 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "hpm_bootheader.h"

/* symbol exported from startup.S */
extern uint32_t _start[];

/* following symbols exported from linker script */
extern uint32_t __app_load_addr__[];
extern uint32_t __app_offset__[];

#ifdef __ICCRISCV__
#pragma section = "RO_BLOCK"
#define __fw_size__ (__section_size("RO_BLOCK"))
#else /* Non-IAR toolchains */
#ifndef HPM_SES_USE_SEGGER_LD
extern uint32_t __fw_size__[];
#else
extern uint32_t __FLASH_segment_used_size__[];
const uint32_t __fw_size__ = (const uint32_t)__FLASH_segment_used_size__;
#endif
#endif

#define FW_SIZE (32768)
__attribute__ ((section(".fw_info_table"), used)) const fw_info_table_t fw_info = {
    (uint32_t)__app_offset__,   /* offset */
    (uint32_t)__fw_size__,      /* size */
    0,                          /* flags */
    0,                          /* reserved0 */
    (uint32_t) &__app_load_addr__, /* load_addr */
    0,                          /* reserved1 */
    (uint32_t) _start,          /* entry_point */
    0,                          /* reserved2 */
    {0},                          /* hash */
    {0},                          /* iv */
};

__attribute__ ((section(".boot_header"), used)) const boot_header_t header = {
    HPM_BOOTHEADER_TAG,                         /* tag */
    0x10,                                       /* version*/
    sizeof(header) + sizeof(fw_info),
    0,                                          /* flags */
    0,                                          /* sw_version */
    0,                                          /* fuse_version */
    1,                                          /* fw_count */
    0,
    0,                                          /* sig_block_offset */
};
