/*
 * FreeRTOS Kernel V10.5.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */


#ifndef PORTMACRO_H
#define PORTMACRO_H

#ifdef __cplusplus
extern "C" {
#endif
#include "hpm_csr_drv.h"

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#if __riscv_xlen == 64
    #define portSTACK_TYPE          uint64_t
    #define portBASE_TYPE           int64_t
    #define portUBASE_TYPE          uint64_t
    #define portMAX_DELAY           ( TickType_t ) 0xffffffffffffffffUL
    #define portPOINTER_SIZE_TYPE   uint64_t
#elif __riscv_xlen == 32
    #define portSTACK_TYPE          uint32_t
    #define portBASE_TYPE           int32_t
    #define portUBASE_TYPE          uint32_t
    #define portMAX_DELAY           ( TickType_t ) 0xffffffffUL
#else
    #error Assembler did not define __riscv_xlen
#endif

typedef portSTACK_TYPE StackType_t;
typedef portBASE_TYPE BaseType_t;
typedef portUBASE_TYPE UBaseType_t;
typedef portUBASE_TYPE TickType_t;

/* Legacy type definitions. */
#define portCHAR            char
#define portFLOAT           float
#define portDOUBLE          double
#define portLONG            long
#define portSHORT           short

/* 32-bit tick type on a 32-bit architecture, so reads of the tick count do
 * not need to be guarded with a critical section. */
#define portTICK_TYPE_IS_ATOMIC 1
/*-----------------------------------------------------------*/

/* Architecture specifics. */
#define portSTACK_GROWTH            ( -1 )
#define portTICK_PERIOD_MS          ( ( TickType_t ) 1000 / configTICK_RATE_HZ )
#ifdef __riscv_32e
    #define portBYTE_ALIGNMENT      8   /* RV32E uses RISC-V EABI with reduced stack alignment requirements */
#else
    #define portBYTE_ALIGNMENT      16
#endif
/*-----------------------------------------------------------*/

/* Scheduler utilities. */
extern void vTaskSwitchContext( void );
#define portYIELD() __asm volatile( "ecall" );
#if !defined(DISABLE_IRQ_PREEMPTIVE) || (DISABLE_IRQ_PREEMPTIVE == 0)
#define portEND_SWITCHING_ISR( xSwitchRequired )    do {\
                                                        if( xSwitchRequired ) {\
                                                            UBaseType_t uxSavedInterruptStatus = portSET_INTERRUPT_MASK_FROM_ISR();\
                                                            vTaskSwitchContext();\
                                                            portCLEAR_INTERRUPT_MASK_FROM_ISR(uxSavedInterruptStatus);\
                                                        }\
                                                    } while( 0 )
#else
/* Preemptive is disabled, no need to mask interrupts */
#define portEND_SWITCHING_ISR( xSwitchRequired ) do { if( xSwitchRequired ) vTaskSwitchContext(); } while( 0 )
#endif
#define portYIELD_FROM_ISR( x ) portEND_SWITCHING_ISR( x )
/*-----------------------------------------------------------*/

/* Critical section management. */
#define portCRITICAL_NESTING_IN_TCB                             0

extern uint32_t ulPortEnterCriticalFromIsr( void );
extern void portExitCriticalFromIsr( uint32_t uxSavedStatusValue );
#define portSET_INTERRUPT_MASK_FROM_ISR()       ulPortEnterCriticalFromIsr()
#define portCLEAR_INTERRUPT_MASK_FROM_ISR( uxSavedStatusValue )    portExitCriticalFromIsr( uxSavedStatusValue )

/* Interrupts which priority higher than configMAX_SYSCALL_INTERRUPT_PRIORITY will never be delayed by anything the kernel is doing,
   can nest, but cannot use any FreeRTOS API functions.
   Refs FreeRTOS book: Mastering-the-FreeRTOS-Real-Time-Kernel.v1.1.0 7.8 Interrupt Nesting */
#if defined(USE_SYSCALL_INTERRUPT_PRIORITY) && USE_SYSCALL_INTERRUPT_PRIORITY
extern volatile uint32_t interruptMaskNestCnt;
extern void portDisableInterrupt( void );
extern void portEnableInterrupt(void);
#define portDISABLE_INTERRUPTS()    portDisableInterrupt()
#define portENABLE_INTERRUPTS()     portEnableInterrupt()
#define portMASK_LOWPRI_INTERRUPTS()    portDISABLE_INTERRUPTS()
#define portUNMASK_LOWPRI_INTERRUPTS()  portENABLE_INTERRUPTS()
#define portENABLE_GLOBAL_INTERRUPTS()  portEnableGlobalISR()
#define portDISABLE_GLOBAL_INTERRUPTS() portDisableGlobalISR()
#else
#define portDISABLE_INTERRUPTS()    clear_csr(CSR_MSTATUS, CSR_MSTATUS_MIE_MASK)
#define portENABLE_INTERRUPTS()     set_csr(CSR_MSTATUS, CSR_MSTATUS_MIE_MASK)
#endif

extern size_t xCriticalNesting;
#define portENTER_CRITICAL()            \
{                                       \
    portDISABLE_INTERRUPTS();           \
    xCriticalNesting++;                 \
}

#define portEXIT_CRITICAL()             \
{                                       \
    xCriticalNesting--;                 \
    if( xCriticalNesting == 0 )         \
    {                                   \
        portENABLE_INTERRUPTS();        \
    }                                   \
}

/*-----------------------------------------------------------*/

/* Tickless idle/low power functionality. */
#ifndef portSUPPRESS_TICKS_AND_SLEEP
	extern void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime );
	#define portSUPPRESS_TICKS_AND_SLEEP( xExpectedIdleTime )    vPortSuppressTicksAndSleep( xExpectedIdleTime )
#endif

/* Architecture specific optimisations. */
#ifndef configUSE_PORT_OPTIMISED_TASK_SELECTION
    #define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#endif

#if( configUSE_PORT_OPTIMISED_TASK_SELECTION == 1 )

    /* Check the configuration. */
    #if( configMAX_PRIORITIES > 32 )
        #error configUSE_PORT_OPTIMISED_TASK_SELECTION can only be set to 1 when configMAX_PRIORITIES is less than or equal to 32.  It is very rare that a system requires more than 10 to 15 difference priorities as tasks that share a priority will time slice.
    #endif

    /* Store/clear the ready priorities in a bit map. */
    #define portRECORD_READY_PRIORITY( uxPriority, uxReadyPriorities ) ( uxReadyPriorities ) |= ( 1UL << ( uxPriority ) )
    #define portRESET_READY_PRIORITY( uxPriority, uxReadyPriorities ) ( uxReadyPriorities ) &= ~( 1UL << ( uxPriority ) )

    /*-----------------------------------------------------------*/

    #define portGET_HIGHEST_PRIORITY( uxTopPriority, uxReadyPriorities ) uxTopPriority = ( 31UL - __builtin_clz( uxReadyPriorities ) )

#endif /* configUSE_PORT_OPTIMISED_TASK_SELECTION */


/*-----------------------------------------------------------*/

/* Task function macros as described on the FreeRTOS.org WEB site. These are
 * not necessary for to use this port.  They are defined so the common demo
 * files (which build with all the ports) will build. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

/*-----------------------------------------------------------*/

#define portNOP()    __asm volatile( " nop " )
#define portINLINE   __inline

#ifndef portFORCE_INLINE
    #define portFORCE_INLINE inline __attribute__(( always_inline))
#endif

#define portMEMORY_BARRIER() __asm volatile( "" ::: "memory" )

portFORCE_INLINE static BaseType_t xPortIsInsideInterrupt( void )
{
    return (read_csr(CSR_MSCRATCH) > 0) ? 1 : 0;
}
/*-----------------------------------------------------------*/

/* configCLINT_BASE_ADDRESS is a legacy definition that was replaced by the
 * configMTIME_BASE_ADDRESS and configMTIMECMP_BASE_ADDRESS definitions.  For
 * backward compatibility derive the newer definitions from the old if the old
 * definition is found. */
#if defined( configCLINT_BASE_ADDRESS ) && !defined( configMTIME_BASE_ADDRESS ) && ( configCLINT_BASE_ADDRESS == 0 )
    /* Legacy case where configCLINT_BASE_ADDRESS was defined as 0 to indicate
     * there was no CLINT.  Equivalent now is to set the MTIME and MTIMECMP
     * addresses to 0. */
    #define configMTIME_BASE_ADDRESS     ( 0 )
    #define configMTIMECMP_BASE_ADDRESS ( 0 )
#elif defined( configCLINT_BASE_ADDRESS ) && !defined( configMTIME_BASE_ADDRESS )
    /* Legacy case where configCLINT_BASE_ADDRESS was set to the base address of
     * the CLINT.  Equivalent now is to derive the MTIME and MTIMECMP addresses
     * from the CLINT address. */
    #define configMTIME_BASE_ADDRESS     ( ( configCLINT_BASE_ADDRESS ) + 0xBFF8UL )
    #define configMTIMECMP_BASE_ADDRESS ( ( configCLINT_BASE_ADDRESS ) + 0x4000UL )
#elif !defined( configMTIME_BASE_ADDRESS ) || !defined( configMTIMECMP_BASE_ADDRESS )
    #error configMTIME_BASE_ADDRESS and configMTIMECMP_BASE_ADDRESS must be defined in FreeRTOSConfig.h.  Set them to zero if there is no MTIME (machine time) clock.  See https://www.FreeRTOS.org/Using-FreeRTOS-on-RISC-V.html
#endif

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */
