/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "board.h"
#include "FreeRTOS.h"
#include "hpm_sysctl_drv.h"
#include "hpm_pcfg_drv.h"
#include "hpm_bcfg_drv.h"
#include "low_power_inf.h"
#include "hpm_port.h"

__attribute__( ( weak ) ) void soc_lowpower_init(void)
{
    bcfg_vbg_enable_lp_mode(HPM_BCFG);
    bcfg_ldo_set_voltage(HPM_BCFG, 800);
    pcfg_dcdc_set_lp_current_limit(HPM_PCFG, pcfg_dcdc_lp_current_limit_250ma, false);
}

/* This function do necessary things before entering lowpower mode, and call the user custom code to allow user
 * implementing custom behavior.
 */
ATTR_RAMFUNC __attribute__( ( weak ) ) void vPreSleepProcessing(unsigned long uxExpectedIdleTime)
{
    (void)(uxExpectedIdleTime);

#if defined(CONFIG_FREERTOS_TICKLESS_USE_STOP_MODE) && CONFIG_FREERTOS_TICKLESS_USE_STOP_MODE
#if( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 )
#error "Machine Timer not supported cpu stop mode yet! Please set CONFIG_FREERTOS_TIMER_RESOURCE_NOT_MTIMER in CMakeLists to select gptmr to generate system tick."
#else
    uint32_t retention = 0x40FUL;
    sysctl_set_cpu0_lp_retention(HPM_SYSCTL, retention);
    sysctl_clear_cpu0_flags(HPM_SYSCTL, cpu_event_flag_mask_all);
    sysctl_set_cpu0_lp_mode(HPM_SYSCTL, cpu_lp_mode_trigger_system_lp);
    sysctl_enable_cpu0_wakeup_source_with_irq(HPM_SYSCTL, FREERTOS_TIMER_IRQ);
#endif /* #if( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 ) */
#else
#if( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 )
    /* Shutdown cpu clock will cause machine timer stop as well, we use the machine timer to generate interrupt, so we keep the clock on */
    sysctl_set_cpu0_lp_mode(HPM_SYSCTL, cpu_lp_mode_ungate_cpu_clock);
#else
    /* Only shut down CPU clock, enter cpu WAIT mode */
    sysctl_set_cpu0_lp_mode(HPM_SYSCTL, cpu_lp_mode_gate_cpu_clock);
#endif /* #if( configMTIME_BASE_ADDRESS != 0 ) && ( configMTIMECMP_BASE_ADDRESS != 0 ) */
#endif /* #if defined(CONFIG_FREERTOS_TICKLESS_USE_STOP_MODE) && CONFIG_FREERTOS_TICKLESS_USE_STOP_MODE */
    pcfg_disable_power_trap(HPM_PCFG);

    /* Call User Custom Processing Code */
    vPreSleepUserCustomProcessing(uxExpectedIdleTime);
}

/* This function do necessary things after exiting lowpower mode, and call the user custom code to allow user
 * implementing custom behavior.
 */
ATTR_RAMFUNC __attribute__( ( weak ) ) void vPostSleepProcessing(unsigned long uxExpectedIdleTime)
{
    (void)(uxExpectedIdleTime);
    /* Call User Custom Processing Code */
    vPostSleepUserCustomProcessing(uxExpectedIdleTime);
}

/* Redefine this function to customize the processing before entering low power consumption */
ATTR_RAMFUNC __attribute__( ( weak ) ) void vPreSleepUserCustomProcessing(unsigned long uxExpectedIdleTime)
{
    (void)(uxExpectedIdleTime);
}

/* Redefine this function to customize the processing after exit low power consumption */
ATTR_RAMFUNC __attribute__( ( weak ) ) void vPostSleepUserCustomProcessing(unsigned long uxExpectedIdleTime)
{
    (void)(uxExpectedIdleTime);
}
