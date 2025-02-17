/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef OLED_ENABLE
#    include "features/oled_config.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "features/rgb_matrix_config.h"
#endif

// #define USE_MATRIX_I2C

// Hand configuration.
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Delay to determine whether a key press is a tap or hold.
// https://docs.qmk.fm/#/tap_hold?id=tapping-term
#define TAPPING_TERM 200
// Ignore the tap/hold delay (defined by TAPPING_TERM) when you quickly press a
// tap/hold key plus a second key (ABBA style).
// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
#define PERMISSIVE_HOLD_PER_KEY
// Allows you to double/tap and hold to repeat a tap/hold key. Setting to 0
// disables it.
// https://docs.qmk.fm/#/tap_hold?id=quick-tap-term
#define QUICK_TAP_TERM 0

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#endif
