/**
 * @file esp_lv_example_freetype.c
 * @note forum: https://forums.100ask.net
 */

/*********************
 *      INCLUDES
 *********************/

//#ifdef CONFIG_ESP_FREETYPE_EXAMPLE_LVGL
#if 1
#include "esp_lv_example_freetype.h"
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/
/* FreeType uses C standard file system, so no driver letter is required.
 * But on ESP, a mount point needs to be specified
*/
#define MOUNT_POINT        CONFIG_FS_100ASK_MOUNT_POINT

/* Store font files in the file system of the SD card
 *[Important] No need to specify a drive letter, but a mount point needs to be specified
*/
#define FREETYPE_FONT_FILE (MOUNT_POINT "/Lato-Regular.ttf")

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Load a font with FreeType
 */
void esp_lv_example_freetype(void)
{
    /*Create a font*/
    static lv_ft_info_t info;
    /*FreeType uses C standard file system, so no driver letter is required.*/
    info.name = FREETYPE_FONT_FILE;
    info.weight = 24;
    info.style = FT_FONT_STYLE_NORMAL;
    info.mem = NULL;
    if(!lv_ft_font_init(&info)) {
        LV_LOG_ERROR("create failed.");
    }

    /*Create style with the new font*/
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, info.font);
    lv_style_set_text_align(&style, LV_TEXT_ALIGN_CENTER);

    /*Create a label with the new style*/
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_obj_add_style(label, &style, 0);
    lv_label_set_text(label, "Hello Retro-Yao-Mio\nI'm a font created with FreeType");
    lv_obj_center(label);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif/*CONFIG_ESP_FREETYPE_EXAMPLE_LVGL*/
