/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

// OLED begin.
#ifdef OLED_ENABLE
#    include "features/oled.h"
#endif
// OLED end.

#ifdef RGB_MATRIX_ENABLE
#    include "features/rgb_matrix.h"
#endif

enum layers { BASE, SMBL, NUMS, ARWS, ADJS };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                    ,-------------------------------------------------------------.
       KC_TAB,    KC_Q,      KC_W,               KC_E,               KC_R,            KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,        KC_P,       KC_BSPC,
  //|--------+-------------+-------------------+------------------+----------------+--------|                    |--------+--------+--------+--------+----------------+--------|
      KC_LCTL, LCTL_T(KC_A), LT(SMBL, KC_S),     LT(ARWS, KC_D),     LT(NUMS, KC_F),  KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   RCTL_T(KC_SCLN), KC_QUOT,
  //|--------+-------------+-------------------+------------------+----------------+--------|                    |--------+--------+--------+--------+----------------+--------|
      KC_LSFT, LSFT_T(KC_Z), KC_X,               KC_C,               KC_V,            KC_B,                         KC_N,    KC_M,   KC_COMM,  KC_DOT, RSFT_T(KC_SLSH), KC_RSFT,
  //|--------+-------------+-------------------+------------------+----------------+--------+--------|  |--------+--------+--------+--------+--------+----------------+--------|
                                                                           SC_LAPO, LT(SMBL, KC_BSPC),  KC_ESC, KC_ENT, LT(SMBL, KC_SPC), RGUI_T(KC_TAB)
                                                 //'-------------------------------------------------'  '-------------------------------------------------'
                                                            // LALT_T(KC_LPRN) -> left paren on tap, alt on hold
  ),

    [SMBL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_LBRC, KC_RBRC, XXXXXXX, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_LCBR, KC_RCBR, KC_AMPR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LGUI,   MO(ADJS),  KC_SPC,     KC_ENT, MO(ADJS), KC_RALT
                                  //'------------------------------'  '---------------------------'
  ),

    [NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_EQL,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,    KC_4,    KC_5,    KC_6,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS,    KC_1,    KC_2,    KC_3, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         SC_LAPO, _______,  KC_ESC,     KC_ENT, _______, RGUI_T(KC_TAB)
                                  //'------------------------------'  '---------------------------------'
  ),

    [ARWS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGUP, KC_HOME, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_RCTL, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         SC_LAPO, _______,  KC_ESC,     KC_ENT, _______, RGUI_T(KC_TAB)
                                  //'------------------------------'  '---------------------------------'
  ),

    [ADJS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //'--------------------------'  '--------------------------'
  )
};
// clang-format on

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            // Respect TAPPING_TERM on next key down.
            return false;
        default:
            // Ignore TAPPING_TERM and select the hold action on next key down.
            return true;
    }
}
#endif
