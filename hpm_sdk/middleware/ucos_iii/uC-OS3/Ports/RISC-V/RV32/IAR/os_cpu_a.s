;********************************************************************************************************
;                                              uC/OS-III
;                                        The Real-Time Kernel
;
;                    Copyright 2009-2022 Silicon Laboratories Inc. www.silabs.com
;
;                                 SPDX-License-Identifier: APACHE-2.0
;
;               This software is subject to an open source license and is distributed by
;                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
;                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
;
;********************************************************************************************************

;********************************************************************************************************
;
;                                        ASSEMBLY LANGUAGE PORT
;                                              RISC-V PORT
;
; File      : os_cpu_a.S
; Version   : V3.08.02
;********************************************************************************************************
; For       : RISC-V RV32
; Toolchain : GNU C Compiler
;********************************************************************************************************
; Note(s)   : Hardware FP is not supported.
;********************************************************************************************************
#include "ucos_risc_v_chip_specific_extensions.h"
#include "context.h"
;********************************************************************************************************
;                                          PUBLIC FUNCTIONS
;********************************************************************************************************

    EXTERN  OSRunning                               ; External references
    EXTERN  OSPrioCur
    EXTERN  OSPrioHighRdy
    EXTERN  OSTCBCurPtr
    EXTERN  OSTCBHighRdyPtr
    EXTERN  OSIntExit
    EXTERN  OSTaskSwHook
    PUBLIC  OSStartHighRdy                          ; Functions declared in this file
    PUBLIC  OSCtxSw
    PUBLIC  OSIntCtxSw
    PUBLIC  Software_IRQHandler


;********************************************************************************************************
;                                               EQUATES
;********************************************************************************************************

RISCV_MSTATUS_MIE      DEFINE       0x08

RISCV_MIE_MSIE         DEFINE       0x08            ; M Soft Interrupt bit

RISCV_MEIE_MTIE        DEFINE       0x880           ; M Extral MachineTimer Interrupt bit

RISCV_PRCI_BASE_ADDR   DEFINE       0xE6401000

HPM_PLICSW_CLAIM_ADDR  DEFINE       0xE6600004

RISCV_PRCI_EN_ADDR     DEFINE       0xE6402000

;********************************************************************************************************
;                                     CODE GENERATION DIRECTIVES
;********************************************************************************************************

;********************************************************************************************************
;                                         START MULTITASKING
;                                      void OSStartHighRdy(void)
;
; Note(s) : 1) OSStartHighRdy() MUST:
;              a) Call OSTaskSwHook() then,
;              b) Set OSRunning to TRUE,
;              c) Set OSTCBHighRdyPtr->StkPtr = SP
;              d) Restore x1-x31; There is no need to restore x0 since it is always zero.
;              e) Enable interrupts (tasks will run with interrupts enabled).
;              f) Switch to highest priority task.
;********************************************************************************************************

    SECTION `.text`:CODE:REORDER:NOROOT(2)
    CODE
OSStartHighRdy:
; Disable interrupts
    li     t0, RISCV_MSTATUS_MIE
    csrrc  zero, mstatus, t0

; Execute OS task switch hook.
    jal    OSTaskSwHook

; OSRunning = TRUE;
    li     t0, 0x01
    la     t1, OSRunning
    sb     t0, 0(t1)

; SWITCH TO HIGHEST PRIORITY TASK
    la     t0, OSTCBHighRdyPtr
    lw     t1, 0(t0)
    lw     sp, 0(t1)

; Restore Fpu registers when fpu is enabled. Added by Hpmicro
    portasmRESTORE_FPU_REGISTERS

; Restore Additional registers. Added by Hpmicro
    portasmRESTORE_ADDITIONAL_REGISTERS

; Retrieve the location where to jump
    lw     t0, 31 * 4(sp)
    csrw   mepc, t0

; Restore x1 to x31 registers
    lw     ra,   0 * 4(sp)
    lw     t0,   4 * 4(sp)
    lw     t1,   5 * 4(sp)
    lw     t2,   6 * 4(sp)
    lw     s0,   7 * 4(sp)
    lw     s1,   8 * 4(sp)
    lw     a0,   9 * 4(sp)
    lw     a1,  10 * 4(sp)
    lw     a2,  11 * 4(sp)
    lw     a3,  12 * 4(sp)
    lw     a4,  13 * 4(sp)
    lw     a5,  14 * 4(sp)
    lw     a6,  15 * 4(sp)
    lw     a7,  16 * 4(sp)
    lw     s2,  17 * 4(sp)
    lw     s3,  18 * 4(sp)
    lw     s4,  19 * 4(sp)
    lw     s5,  20 * 4(sp)
    lw     s6,  21 * 4(sp)
    lw     s7,  22 * 4(sp)
    lw     s8,  23 * 4(sp)
    lw     s9,  24 * 4(sp)
    lw     s10, 25 * 4(sp)
    lw     s11, 26 * 4(sp)
    lw     t3,  27 * 4(sp)
    lw     t4,  28 * 4(sp)
    lw     t5,  29 * 4(sp)
    lw     t6,  30 * 4(sp)

; Compensate for the stack pointer
    addi   sp, sp, 32 * 4

; Use register t6 to jump to HIGHEST priority
    csrr   t6, mepc

; Enable mchtmr interrupts
    li     t0, RISCV_MEIE_MTIE
    csrrs  zero, mie, t0

; Enable global interrupts
    li     t0, RISCV_MSTATUS_MIE
    csrrs  zero, mstatus, t0

; Jump to HIGHEST priority task.
    jalr   x0, t6, 0


;********************************************************************************************************
;                       PERFORM A CONTEXT SWITCH (From task level) - OSCtxSw()
;                   PERFORM A CONTEXT SWITCH (From interrupt level) - OSIntCtxSw()
;
; Note(s) : 1) OSCtxSw() is called when OS wants to perform a task context switch.  This function
;              triggers a synchronous software interrupt by writing into the MSIP register
;
;           2) OSIntCtxSw() is called by OSIntExit() when it determines a context switch is needed as
;              the result of an interrupt.  This function triggers a synchronous software interrupt by
;              writing into the MSIP register
;********************************************************************************************************

    SECTION `.isr_vector`:CODE(2)
OSCtxSw:
    SECTION `.isr_vector`:CODE(2)
OSIntCtxSw:
; MIE_MSIE -- enable software interrupt bit
    li     t0, RISCV_MIE_MSIE
    csrrs  zero, mie, t0
    
    li     t0, RISCV_PRCI_EN_ADDR
    li     t1, 0x2
    sw     t1, 0x0(t0)
    
; This will trigger a synchronous software interrupt; PRCI->MSIP[0] = 0x02;
    li     t0, RISCV_PRCI_BASE_ADDR
    li     t1, 0x2
    sw     t1, 0x0(t0)
    ret


;********************************************************************************************************
;                                   void Software_IRQHandler (void)
;
; Note(s) : 1) This function is defined with weak linking in 'riscv_hal_stubs.c' so that it can be
;              overridden by the kernel port with same prototype.
;
;           2) Pseudo-code is:
;              a) Disable global interrupts.
;              b) Clear soft interrupt for hart0.
;              c) Save the process SP in its TCB, OSTCBCurPtr->StkPtr = SP;
;              d) Call OSTaskSwHook();
;              e) Get current high priority, OSPrioCur = OSPrioHighRdy;
;              f) Get current ready thread TCB, OSTCBCurPtr = OSTCBHighRdyPtr;
;              g) Get new process SP from TCB, SP = OSTCBHighRdyPtr->StkPtr;
;              h) Retrieve the address at which exception happened
;              i) Restore x1-x31 from new process stack; x0 is always zero.
;              j) Perform exception return which will restore remaining context.
;
;           3) On entry into Software_IRQHandler:
;              a) The initial register context save is being done by 'entry.S'
;              b) Stack pointer was passed by 'entry.s' in register a2.
;                 #change log
;                 # 2023-03-02 not needed, already done in the entry
;              c) OSTCBCurPtr      points to the OS_TCB of the task to suspend
;                 OSTCBHighRdyPtr  points to the OS_TCB of the task to resume
;********************************************************************************************************

    SECTION `.text`:CODE:REORDER:NOROOT(2)
    CODE
Software_IRQHandler:
; Disable interrupts globally and prevent interruption during context switch
    li     t0, RISCV_MSTATUS_MIE
    csrrc  zero, mstatus, t0

; Clear soft interrupt for hart0, PRCI->MSIP[0] = 0x00;
    li     t0, HPM_PLICSW_CLAIM_ADDR
    lw     t0, 0(t0)

; Execute OS task switch hook.
    jal    OSTaskSwHook

; OSPrioCur = OSPrioHighRdy;
    la     t0, OSPrioHighRdy
    lb     t1, 0(t0)
    la     t0, OSPrioCur
    sb     t1, 0(t0)

; OSTCBCurPtr = OSTCBHighRdyPtr;
    la     t0, OSTCBHighRdyPtr
    lw     t1, 0(t0)
    la     t0, OSTCBCurPtr
    sw     t1, 0(t0)

; SP = OSTCBHighRdyPtr->StkPtr;
    lw     sp, 0(t1)

;   mscratch is indicating interrupt nest count
;   Before exiting the software interrupt routinue, reduce mscratch
    csrr t0, mscratch
    addi t0, t0, -1
    csrw mscratch, t0
; Restore Fpu registers when fpu is enabled. Added by Hpmicro
    portasmRESTORE_FPU_REGISTERS

; Restore Additional registers. Added by Hpmicro
    portasmRESTORE_ADDITIONAL_REGISTERS

; Retrieve the address at which exception happened
    lw     t0, 31 * 4(sp)
    csrw   mepc, t0

; Restore x1 to x31 registers
    lw     ra,   0 * 4(sp)
    lw     t0,   4 * 4(sp)
    lw     t1,   5 * 4(sp)
    lw     t2,   6 * 4(sp)
    lw     s0,   7 * 4(sp)
    lw     s1,   8 * 4(sp)
    lw     a0,   9 * 4(sp)
    lw     a1,  10 * 4(sp)
    lw     a2,  11 * 4(sp)
    lw     a3,  12 * 4(sp)
    lw     a4,  13 * 4(sp)
    lw     a5,  14 * 4(sp)
    lw     a6,  15 * 4(sp)
    lw     a7,  16 * 4(sp)
    lw     s2,  17 * 4(sp)
    lw     s3,  18 * 4(sp)
    lw     s4,  19 * 4(sp)
    lw     s5,  20 * 4(sp)
    lw     s6,  21 * 4(sp)
    lw     s7,  22 * 4(sp)
    lw     s8,  23 * 4(sp)
    lw     s9,  24 * 4(sp)
    lw     s10, 25 * 4(sp)
    lw     s11, 26 * 4(sp)
    lw     t3,  27 * 4(sp)
    lw     t4,  28 * 4(sp)
    lw     t5,  29 * 4(sp)
    lw     t6,  30 * 4(sp)

    addi   sp, sp, 4 * 32


; Exception return will restore remaining context
    mret


;********************************************************************************************************
;                                             MODULE END
;*********************************************************************************************************
