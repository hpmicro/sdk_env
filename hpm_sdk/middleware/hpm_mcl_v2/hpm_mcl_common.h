/*
 * Copyright (c) 2023 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef HPM_MCL_COMMON_H
#define HPM_MCL_COMMON_H
#include "hpm_common.h"
#include "hpm_mcl_cfg.h"
#include "hpm_mcl_physical.h"
#include "hpm_mcl_math.h"
#include "stdio.h"

typedef uint32_t hpm_mcl_stat_t;

enum {
    mcl_group_common = 0,
    mcl_group_motor = 1,
    mcl_group_encoder = 2,
    mcl_group_analog = 3,
    mcl_group_drivers = 4,
};

/**
 * @brief User-defined data with data and enable bits
 *
 */
typedef struct {
    float value;
    bool enable;
} mcl_user_value_t;

enum {
    mcl_success = MAKE_STATUS(mcl_group_common, 0),
    mcl_fail = MAKE_STATUS(mcl_group_common, 1),
    mcl_invalid_argument = MAKE_STATUS(mcl_group_common, 2),
    mcl_invalid_pointer = MAKE_STATUS(mcl_group_common, 3),
    mcl_timeout = MAKE_STATUS(mcl_group_common, 4),
    mcl_in_development = MAKE_STATUS(mcl_group_common, 5),   /**< Functions under development */
    mcl_running = MAKE_STATUS(mcl_group_common, 6),
};


/**
 * @brief user define code
 *
 */
void mcl_user_delay_us(uint64_t tick);

#define MCL_DEBUG printf
#define MCL_PI HPM_PI
#define MCL_2PI HPM_2_PI
#define MCL_PI_DIV3 (MCL_PI / 3.0f)

#define MCL_DELAY_US(x) mcl_user_delay_us(x)
#define MCL_DELAY_MS(x) MCL_DELAY_US(1000*x)
#define MCL_EMPTY

#define MCL_ASSERT_BOOL(b, code_extend, errcode)    \
    do {    \
        if (!b) {   \
            code_extend; \
            MCL_DEBUG("errcode:%d, file:%s, line:%d.\r\n", errcode, __FILE__, __LINE__);  \
            return errcode;    \
        }   \
    } while (0)

#define MCL_ASSERT_EXEC_CODE_BOOL(b, code_extend)    \
    do {    \
        if (!b) {   \
            code_extend; \
        }   \
    } while (0)

#define MCL_ASSERT(x, return_errcode) MCL_ASSERT_BOOL(((uint32_t)(x) != 0), MCL_EMPTY, return_errcode)

#define MCL_ASSERT_EXEC_CODE(x, code) MCL_ASSERT_EXEC_CODE_BOOL((x), code)

#define MCL_ASSERT_EXEC_CODE_AND_RETURN(x, code, return_errcode)    MCL_ASSERT_BOOL((x), code, return_errcode)

#ifdef NDEBUG
    #define MCL_ASSERT_EXEC_CODE_OPT(x, code) ((void)0)
    #define MCL_ASSERT_OPT(x, return_errcode) ((void)0)
    #define MCL_ASSERT_EXEC_CODE_AND_RETURN_OPT(x, code, return_errcode) ((void)0)
#else
    #define MCL_ASSERT_EXEC_CODE_OPT MCL_ASSERT_EXEC_CODE
    #define MCL_ASSERT_OPT MCL_ASSERT
    #define MCL_ASSERT_EXEC_CODE_AND_RETURN_OPT MCL_ASSERT_EXEC_CODE_AND_RETURN
#endif

#define MCL_FUNCTION_EXC_IF_ENABLE(b, str_f, f) \
    do {    \
        if (b) {    \
            str_f = f;  \
        }   \
    } while (0)

#define MCL_FUNCTION_EXC_IF_ELSE_ENABLE(b, str_f, _if, _else) \
    do {    \
        if (b) {    \
            str_f = _if;  \
        } else {    \
            str_f = _else;  \
        }   \
    } while (0)

#define MCL_FUNCTION_INIT_IF_EMPTY(str_function, function)  MCL_FUNCTION_EXC_IF_ENABLE((str_function == NULL), str_function, function)

#define MCL_FUNCTION_INIT_IF_NO_EMPTY(function, str_function)  MCL_FUNCTION_EXC_IF_ENABLE((str_function != NULL), function, str_function)

#define MCL_STATUS_SET_IF_TRUE(real, str, status) MCL_FUNCTION_EXC_IF_ENABLE((real), str, status)

#define MCL_VALUE_SET_IF_TRUE(real, str, value) MCL_FUNCTION_EXC_IF_ENABLE((real), str, value)

#define MCL_FUNCTION_SET_IF_ELSE_TRUE(real, str, _if, _else) MCL_FUNCTION_EXC_IF_ELSE_ENABLE((real), str, _if, _else)

/**
 * @brief If used, this means that the callback function is optional
 *
 */
#define _FUNC_OPTIONAL_

/**
 * @brief Remainder of angle
 *
 */
#define MCL_ANGLE_MOD_X(down, up, val)  \
({    \
    float val_; \
    if ((val) > up) { \
        val_ = (val); \
        do {  \
            val_ = (val_) - (up - down);    \
        } while ((val_) > up); \
    } else if ((val) < down) {    \
        val_ = (val); \
        do {  \
            val_ = (val_) + (up - down);   \
        } while ((val_) < down); \
    } else {    \
        val_ = (val); \
    }   \
    (val_);  \
})

/**
 * @brief Calculate the difference in angle,
 * because the angle is then changed between 0-360 degrees,
 * there are 350 degrees to 0 degrees of the process of change,
 * as well as 10 degrees to 360 degrees of the process of change,
 * in this process, the actual angle change is 10 degrees,
 * but it may be calculated as 350 degrees,
 * so the role of the calculation is to strive for an angle value of 10 degrees,
 * the offset value of the maximum angle value, the default is 2pi
 *
 */
#define MCL_GET_ANGLE_DELTA(val, offset)  \
({    \
    float val_; \
    float temp; \
    val_ = 0;   \
    temp = 0;   \
    if ((val) > 0) { \
        temp = (val) - offset;    \
    } else if ((val) < 0) {    \
        temp = (val) + offset;   \
    } else {    \
        val_ = 0; \
    }   \
    if (fabs(val) < fabs(temp)) { \
        val_ = val; \
    } else {\
        val_ = temp; \
    } \
    (val_);  \
})

/**
 * @brief Data Range Limits
 *
 */
#define MCL_VALUE_LIMIT(val, min, max)   \
    do {    \
        if ((val) > (max)) {  \
            val = max;  \
        } else if ((val) < (min)) { \
            val = min;  \
        }   \
    } while (0)

/**
 * @brief Get ADC data with 12bit valid bits
 *
 */
#define MCL_GET_ADC_12BIT_VALID_DATA(x)             ((x & 0xffff) >> 4)

typedef struct {
    mcl_physical_para_t physical;
    mcl_physical_para_q_t physical_q;
} mcl_cfg_t;


#endif
