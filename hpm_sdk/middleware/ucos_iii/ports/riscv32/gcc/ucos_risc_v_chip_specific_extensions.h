/*
 * Copyright (c) 2023 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef __UCOS_RISC_V_EXTENSIONS_H__
#define __UCOS_RISC_V_EXTENSIONS_H__

#include "hpm_csr_regs.h"

#ifndef CONFIG_UCOS_III_TIMER_RESOURCE_NOT_MCHTMR
#define portasmHAS_MTIME                1
#else
#define portasmHAS_MTIME                0
#endif

#define portasmADDITIONAL_CONTEXT_MCCTL_SIZE 4

#define portasmADDITIONAL_CONTEXT_SIZE  (portasmADDITIONAL_CONTEXT_MCCTL_SIZE)

#define portasmHANDLE_INTERRUPT         irq_handler_trap

.macro portasmSAVE_ADDITIONAL_REGISTERS
    addi sp, sp, -(4 * portasmADDITIONAL_CONTEXT_MCCTL_SIZE)
    csrr t0, CSR_MCCTLBEGINADDR
    sw   t0, 1 * 4( sp )
    csrr t0, CSR_MCCTLDATA
    sw   t0, 0 * 4( sp )
    .endm

.macro portasmRESTORE_ADDITIONAL_REGISTERS
    lw   t0, 0 * 4( sp )
    csrw CSR_MCCTLDATA, t0
    lw   t0, 1 * 4( sp )
    csrw CSR_MCCTLBEGINADDR, t0
    addi sp, sp, (4 * portasmADDITIONAL_CONTEXT_MCCTL_SIZE)
    .endm
#endif /* __UCOS_RISC_V_EXTENSIONS_H__ */
