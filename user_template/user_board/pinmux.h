/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef HPM_PINMUX_H
#define HPM_PINMUX_H

#include "hpm_soc.h"

#ifdef __cplusplus
extern "C" {
#endif

void init_uart_pins(UART_Type *ptr);

#ifdef __cplusplus
}
#endif
#endif /* HPM_PINMUX_H */
