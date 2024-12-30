/*
 * Copyright (c) 2023 hpmicro
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* RT-Thread Configuration */

#include "finsh_config.h"
/* RT-Thread Kernel */

#define RT_NAME_MAX 16
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_MAX 56
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 512

/* kservice optimization */

#define RT_DEBUG
#define RT_DEBUG_COLOR
#define RT_DEBUG_INIT_CONFIG
#define RT_DEBUG_INIT 1

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_HEAP
#define RT_HEAP_SIZE (32 * 1024)

/* Kernel Device Object */

/* #define RT_USING_DEVICE */
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "uart0"
#define RT_PRINTF_LONGLONG
#define RT_VER_NUM 0x40004
#define RT_CONSOLE_BAUDRATE 115200
/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE (4096)
#define RT_MAIN_THREAD_PRIORITY 10

/* C++ features */


/* Command shell */
#define RT_USING_FINSH
#define FINSH_USING_MSH
#define FINSH_USING_MSH_ONLY
#define FINSH_THREAD_PRIORITY       21
#define FINSH_THREAD_STACK_SIZE     1024
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_NAME "tshell"
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_CMD_SIZE 80
#define FINSH_ARG_MAX 10
#define FINSH_RX_BUF_SIZE 64

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ 512
#define RT_USING_SERIAL
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_PIN
#define RT_USING_RTC
/* #define RT_USING_SDIO */
#define RT_SDIO_STACK_SIZE 512
#define RT_SDIO_THREAD_PRIORITY 15
#define RT_MMCSD_STACK_SIZE 2048
#define RT_MMCSD_THREAD_PREORITY 22
#define RT_MMCSD_MAX_PARTITION 16
#define RT_SDIO_DEBUG
#define RT_USING_WDT

/* Using USB */


/* POSIX layer and C standard library */

#define RT_USING_LIBC
#define RT_USING_POSIX
#define RT_LIBC_DEFAULT_TIMEZONE 8

/* Network */

/* Socket abstraction layer */


/* Network interface device */


/* light weight TCP/IP stack */


/* AT commands */


/* VBUS(Virtual Software BUS) */


/* Utilities */


/* RT-Thread Utestcases */


/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */


/* multimedia packages */


/* tools packages */


/* system packages */

/* acceleration: Assembly language or algorithmic acceleration packages */


/* Micrium: Micrium software products porting for RT-Thread */


/* peripheral libraries and drivers */


/* AI packages */


/* miscellaneous packages */

/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */


/* Onboard Peripheral Drivers */

/* On-chip Peripheral Drivers */

#define BSP_USING_UART
#define BSP_USING_UART0
/* #define BSP_USING_UART2 */
#define BSP_USING_RTC
/* #define BSP_USING_SDIO */
#define BSP_USING_SDIO1

#endif
