/*
 * Copyright (c) 2022-2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef LV_DEMO_MUSIC_LIST_H
#define LV_DEMO_MUSIC_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_music.h"
#if LV_USE_DEMO_MUSIC

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
lv_obj_t * _lv_demo_music_list_create(lv_obj_t * parent);
void _lv_demo_music_list_button_check(uint32_t track_id, bool state);
void _lv_demo_music_list_button_img(uint32_t track_id, bool state);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_DEMO_MUSIC*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_DEMO_MUSIC_LIST_H*/