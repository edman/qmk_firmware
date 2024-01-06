
#pragma once

#ifndef OLED_ENABLE
#    error this feature requires 'OLED_ENABLE=yes', update your rules.mk
#endif

#undef USE_I2C
#undef SSD1306OLED
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
// This is the font copied from soundmonster/glcdfont.c
// #    define OLED_FONT_H "keyboards/crkbd/keymaps/edman/features/oled_glcdfont.c"
// Mostly same as above, but I changed the logo to android's instead of corne's.
#undef OLED_FONT_H
#define OLED_FONT_H "keyboards/crkbd/keymaps/edman/features/oled_glcdfont_android.c"
#define OLED_TIMEOUT 30000
