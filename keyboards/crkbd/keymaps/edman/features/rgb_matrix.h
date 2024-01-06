
#pragma once

#ifndef RGB_MATRIX_ENABLE
#    error this feature requires 'RGB_MATRIX_ENABLE=yes', update your rules.mk
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max);
