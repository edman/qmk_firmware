
#pragma once

#ifndef OLED_ENABLE
#    error this feature requires 'OLED_ENABLE=yes', update your rules.mk
#endif

#include QMK_KEYBOARD_H

oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool            oled_task_user(void);
