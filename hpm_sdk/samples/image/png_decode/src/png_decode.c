/*
 * Copyright (c) 2024 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/*---------------------------------------------------------------------*
 * Includes
 *---------------------------------------------------------------------
 */
#include "board.h"
#include "hpm_lcdc_drv.h"
#include "file_op.h"
#include "hpm_pdma_drv.h"

#if defined PNG_USE_SDCARD
#include "sd_fatfs.h"
#elif defined PNG_USE_UDISK
#include "msc_app.h"
#else
#error "no target storage is specified, please set PNG_USE_SDCARD or PNG_USE_UDISK"
#endif

#include "lodepng.h"
#include "format_convert.h"

/*Pixel format of LCD display*/
#define PIXEL_FORMAT display_pixel_format_argb8888
/*PDMA Definitions*/
#define PDMA BOARD_PDMA_BASE
/*LCD Definitions*/
#define LCD                 BOARD_LCD_BASE
#define LCD_LAYER_INDEX     0
#define LCD_LAYER_DONE_MASK (LCD_LAYER_INDEX + 1)

#define PNG_SURFIX             ".png"
#define SHOW_IMAGE_DELAY_IN_MS 1500
/*---------------------------------------------------------------------*
 * Define variables
 *---------------------------------------------------------------------
 */
ATTR_PLACE_AT_NONCACHEABLE uint32_t scale_buffer[BOARD_LCD_HEIGHT * BOARD_LCD_WIDTH];
ATTR_PLACE_AT_NONCACHEABLE uint8_t file_buffer[FILE_BUFFER_LEN];
ATTR_PLACE_AT_NONCACHEABLE_BSS FIL file;

static bool lcd_is_on;
static volatile bool vsync;

/*---------------------------------------------------------------------*
 * Storage device initialization
 *---------------------------------------------------------------------
 */
void store_device_init(void)
{
#if defined PNG_USE_SDCARD
    /*Read picture data by SD card*/
    while (!check_disk()) {
    }
    printf("Read picture data by SD card\n");
#elif defined PNG_USE_UDISK
    /*Reading picture data in tinyusb mode*/
    printf("Read picture data by usb-mode\n");
    init_disk();
    while (!check_disk()) {
    }
#endif
}

/*
 * LCD configuration
 */
SDK_DECLARE_EXT_ISR_M(BOARD_LCD_IRQ, isr_lcd_d0)
void isr_lcd_d0(void)
{
    volatile uint32_t s = lcdc_get_dma_status(LCD);
    lcdc_clear_dma_status(LCD, s);
    if ((s & (LCD_LAYER_DONE_MASK << LCDC_DMA_ST_DMA0_DONE_SHIFT))) {
        vsync = true;
    }
}

void init_lcd(void)
{
    lcdc_config_t config = { 0 };

    lcdc_get_default_config(LCD, &config);
    board_panel_para_to_lcdc(&config);
    lcdc_init(LCD, &config);

    lcd_is_on = false;
}

static void update_lcd_layer(uint32_t buffer, uint32_t width, uint32_t height, uint8_t format)
{
    lcdc_layer_config_t layer = { 0 };

    lcdc_get_default_layer_config(LCD, &layer, format, LCD_LAYER_INDEX);

    layer.position_x = (BOARD_LCD_WIDTH - width) / 2;
    layer.position_y = (BOARD_LCD_HEIGHT - height) / 2;
    layer.width = width;
    layer.height = height;

    layer.buffer = core_local_mem_to_sys_address(BOARD_RUNNING_CORE, buffer);
    layer.alphablend.src_alpha = 0xFF; /* src */
    layer.alphablend.dst_alpha = 0xF0; /* dst */
    layer.alphablend.src_alpha_op = display_alpha_op_override;
    layer.alphablend.dst_alpha_op = display_alpha_op_override;
    layer.background.u = 0xFFFF0000;
    layer.alphablend.mode = display_alphablend_mode_src_over;

    if (lcd_is_on) {
        while (!vsync) {
        }
    }

    if (status_success != lcdc_config_layer(LCD, LCD_LAYER_INDEX, &layer, true)) {
        printf("failed to configure layer\n");
        while (1) {
        }
    }
    vsync = false;
    if (!lcd_is_on) {
        lcdc_enable_interrupt(LCD, LCD_LAYER_DONE_MASK << 16);
        intc_m_enable_irq_with_priority(BOARD_LCD_IRQ, 1);
        lcdc_turn_on_display(LCD);
        lcd_is_on = true;
    }
}

bool file_is_png(uint8_t *f_name)
{
    if (strlen((char *)f_name) < strlen(PNG_SURFIX)) {
        return false;
    }
    if (strncmp((char *)(f_name + strlen((char *)f_name) - strlen(PNG_SURFIX)), PNG_SURFIX, strlen(PNG_SURFIX))) {
        return false;
    }
    return true;
}

uint8_t get_display_scale_factor(uint32_t width, uint32_t height)
{
    uint8_t scale;
    for (scale = 0; ; scale++) {
        if (((width >> scale) <= BOARD_LCD_WIDTH) && ((height >> scale) <= BOARD_LCD_HEIGHT)) {
            break;
        }
    }
    return scale;
}

void decode_show(uint8_t *f_buf, uint32_t size)
{
    uint8_t *image;
    uint32_t image_width, image_height;
    uint32_t display_width, display_height;
    uint32_t error;
    uint32_t *u32_ptr;

    board_lcd_backlight(false);

    error = lodepng_decode32(&image, (unsigned *)&image_width, (unsigned *)&image_height, f_buf, size);
    if (error != 0) {
        printf("sw decode failed, error = %d: %s\n", error, lodepng_error_text(error));
        free(image);
        return;
    }
    convert_abgr8888_to_argb8888((uint32_t *)image, image_width, image_height);
    printf("sw decode completed\n");

    if ((image_width > BOARD_LCD_WIDTH) || (image_height > BOARD_LCD_HEIGHT)) {
        uint8_t scale = get_display_scale_factor(image_width, image_height);
        uint32_t status;
        hpm_stat_t stat;

        display_width = image_width >> scale;
        display_height = image_height >> scale;

        stat = pdma_scale(PDMA,
                (uint32_t)core_local_mem_to_sys_address(BOARD_RUNNING_CORE, (uint32_t)scale_buffer),
                display_width,
                (uint32_t)core_local_mem_to_sys_address(BOARD_RUNNING_CORE, (uint32_t)image),
                image_width,
                0, 0, image_width, image_height,
                display_width, display_height,
                0xFF, PIXEL_FORMAT, true, &status);

        if (stat != status_success) {
            printf("pdma scale failed: 0x%x\n", status);
            while (1) {
            }
        }

    } else {
        u32_ptr = (uint32_t *)image;
        for (uint32_t i = 0; i < (image_width * image_height); i++) {
            scale_buffer[i] = u32_ptr[i];
        }
        display_width = image_width;
        display_height = image_height;
    }

    free(image);
    update_lcd_layer((uint32_t)scale_buffer, display_width, display_height, PIXEL_FORMAT);
    board_delay_ms(120);
    board_lcd_backlight(true);
}

/*---------------------------------------------------------------------*
 * MAIN.C
 *---------------------------------------------------------------------
 */
int main(void)
{
    uint32_t size;
    DIR d_info;
    FILINFO f_info;
    FRESULT stat;

    board_init();
    clock_add_to_group(clock_pdma, 0);
    store_device_init();

    board_init_lcd();
    board_lcd_backlight(false);
    init_lcd();

    stat = f_opendir(&d_info, "/");
    if (stat != FR_OK) {
        printf("failed to open root directory, status = %d\n", stat);
        while (1) {
        }
    }

    while (f_readdir(&d_info, &f_info) == FR_OK) {
        /* If a file name is null, it means that the read operation is complete. */
        if (!f_info.fname[0]) {
            break;
        }
        if ((f_info.fattrib & AM_HID) != 0 || (f_info.fattrib & AM_SYS) != 0) {
            continue;
        }

        if ((f_info.fattrib & AM_DIR) == AM_DIR) {
            printf("folder: %s\r\n", f_info.fname);
            continue;
        } else if (!file_is_png((uint8_t *)f_info.fname)) {
            continue;
        }

        if (f_info.fsize > FILE_BUFFER_LEN) {
            printf("%s size is too large (%d bytes > %d bytes), skip\n", f_info.fname, f_info.fsize, FILE_BUFFER_LEN);
            continue;
        }

        stat = f_open(&file, f_info.fname, FA_OPEN_ALWAYS | FA_READ);
        if (stat != FR_OK) {
            printf("fail to open file %s, status=%d\n", f_info.fname, stat);
            while (1) {
            }
        }

        f_read(&file, file_buffer, FILE_BUFFER_LEN, (UINT *)&size);
        f_close(&file);

        printf("%s:\n", f_info.fname);
        decode_show(file_buffer, size);
        board_delay_ms(SHOW_IMAGE_DELAY_IN_MS);
    }
    f_closedir(&d_info);
    printf("decoding all done\n");
    while (1) {
    }

    return 0;
}
