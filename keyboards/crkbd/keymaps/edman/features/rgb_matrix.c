
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

#define LED_K0A g_led_config.matrix_co[0][0]
#define LED_K0B g_led_config.matrix_co[0][1]
#define LED_K0C g_led_config.matrix_co[0][2]
#define LED_K0D g_led_config.matrix_co[0][3]
#define LED_K0E g_led_config.matrix_co[0][4]
#define LED_K0F g_led_config.matrix_co[0][5]
#define LED_K1A g_led_config.matrix_co[1][0]
#define LED_K1B g_led_config.matrix_co[1][1]
#define LED_K1C g_led_config.matrix_co[1][2]
#define LED_K1D g_led_config.matrix_co[1][3]
#define LED_K1E g_led_config.matrix_co[1][4]
#define LED_K1F g_led_config.matrix_co[1][5]
#define LED_K2A g_led_config.matrix_co[2][0]
#define LED_K2B g_led_config.matrix_co[2][1]
#define LED_K2C g_led_config.matrix_co[2][2]
#define LED_K2D g_led_config.matrix_co[2][3]
#define LED_K2E g_led_config.matrix_co[2][4]
#define LED_K2F g_led_config.matrix_co[2][5]
#define LED_K3D g_led_config.matrix_co[3][3]
#define LED_K3E g_led_config.matrix_co[3][4]
#define LED_K3F g_led_config.matrix_co[3][5]
#define LED_K4A g_led_config.matrix_co[4][0]
#define LED_K4B g_led_config.matrix_co[4][1]
#define LED_K4C g_led_config.matrix_co[4][2]
#define LED_K4D g_led_config.matrix_co[4][3]
#define LED_K4E g_led_config.matrix_co[4][4]
#define LED_K4F g_led_config.matrix_co[4][5]
#define LED_K5A g_led_config.matrix_co[5][0]
#define LED_K5B g_led_config.matrix_co[5][1]
#define LED_K5C g_led_config.matrix_co[5][2]
#define LED_K5D g_led_config.matrix_co[5][3]
#define LED_K5E g_led_config.matrix_co[5][4]
#define LED_K5F g_led_config.matrix_co[5][5]
#define LED_K6A g_led_config.matrix_co[6][0]
#define LED_K6B g_led_config.matrix_co[6][1]
#define LED_K6C g_led_config.matrix_co[6][2]
#define LED_K6D g_led_config.matrix_co[6][3]
#define LED_K6E g_led_config.matrix_co[6][4]
#define LED_K6F g_led_config.matrix_co[6][5]
#define LED_K7D g_led_config.matrix_co[7][3]
#define LED_K7E g_led_config.matrix_co[7][4]
#define LED_K7F g_led_config.matrix_co[7][5]

// clang-format off
//,----------------------------.                    ,----------------------------.
// k0A, k0B, k0C, k0D, k0E, k0F,                     k4F, k4E, k4D, k4C, k4B, k4A,
//|----+---+----+----+----+----|                    |---+----+----+----+----+----|
// k1A, k1B, k1C, k1D, k1E, k1F,                     k5F, k5E, k5D, k5C, k5B, k5A,
//|----+---+----+----+----+----|                    |---+----+----+----+----+----|
// k2A, k2B, k2C, k2D, k2E, k2F,                     k6F, k6E, k6D, k6C, k6B, k6A,
//|----+---+----+----+----+----+--------|  |--------+---+----+----+----+----+----|
//                        k3D, k3E, k3F,    k7F, k7E, k7D
//                       '--------------'  '-------------'
//      0    1    2    3    4    5
// 0: {k0A, k0B, k0C, k0D, k0E, k0F},
// 1: {k1A, k1B, k1C, k1D, k1E, k1F},
// 2: {k2A, k2B, k2C, k2D, k2E, k2F},
// 3: {Non, Non, Non, k3D, k3E, k3F},
// 4: {k4A, k4B, k4C, k4D, k4E, k4F},
// 5: {k5A, k5B, k5C, k5D, k5E, k5F},
// 6: {k6A, k6B, k6C, k6D, k6E, k6F},
// 7: {Non, Non, Non, k7D, k7E, k7F}
// clang-format on

// Must be kept in sync with your keymap.
enum layers { BASE, SYMBOLS, ADJUST, NUMS, ARROWS };

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(ADJUST)) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index < led_min || index >= led_max || index == NO_LED) continue;

                uint16_t keycode = keymap_key_to_keycode(ADJUST, (keypos_t){col, row});
                if (keycode == QK_BOOT)
                    rgb_matrix_set_color(index, RGB_ORANGE);
                else if (keycode == RGB_TOG)
                    rgb_matrix_set_color(index, RGB_RED);
                else if (keycode == RGB_MOD)
                    rgb_matrix_set_color(index, RGB_TEAL);
                else if (keycode >= RGB_HUI && keycode <= RGB_SPD)
                    keycode % 2 == 0 ? rgb_matrix_set_color(index, RGB_MAGENTA) : rgb_matrix_set_color(index, RGB_TURQUOISE);
            }
        }
        return false;
    }

    if (layer_state_is(SYMBOLS)) {
        const uint8_t pair_key[] = {LED_K4E, LED_K4D, LED_K5E, LED_K5D, LED_K6E, LED_K6D};
        for (uint8_t i = 0; i < ARRAY_LEN(pair_key); ++i)
            i % 2 == 0 ? rgb_matrix_set_color(pair_key[i], RGB_TURQUOISE) : rgb_matrix_set_color(pair_key[i], RGB_MAGENTA);
        rgb_matrix_set_color(/*S*/ LED_K1C, RGB_CORAL);
        rgb_matrix_set_color(/*Right thumb 2*/ LED_K7E, RGB_CORAL);
        return false;
    }

    if (layer_state_is(NUMS)) {
        const uint8_t num_key[] = {
            LED_K4E, LED_K4D, LED_K4C, LED_K5E, LED_K5D, LED_K5C, LED_K6E, LED_K6D, LED_K6C,
        };
        for (uint8_t i = 0; i < ARRAY_LEN(num_key); i++)
            rgb_matrix_set_color(num_key[i], RGB_CORAL);
        rgb_matrix_set_color(/*F*/ LED_K1E, RGB_CORAL);
        rgb_matrix_set_color(/*Plus*/ LED_K6F, RGB_BLUE);
        rgb_matrix_set_color(/*Asterisk*/ LED_K6B, RGB_BLUE);
        rgb_matrix_set_color(/*Minus*/ LED_K5F, RGB_RED);
        rgb_matrix_set_color(/*Equals*/ LED_K4F, RGB_TEAL);
        return false;
    }

    if (layer_state_is(ARROWS)) {
        const uint8_t arrow_key[] = {LED_K5F, LED_K5E, LED_K5D, LED_K5C};
        for (uint8_t i = 0; i < ARRAY_LEN(arrow_key); ++i)
            rgb_matrix_set_color(arrow_key[i], RGB_CORAL);
        rgb_matrix_set_color(/*D*/ LED_K1D, RGB_CORAL);
        return false;
    }

    return true;
}
