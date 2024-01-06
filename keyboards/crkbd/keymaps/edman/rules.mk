# Equivalent to `qmk {compile,flash} ... -e CONVERT_TO=elite_pi`
# https://docs.qmk.fm/#/feature_converters
CONVERT_TO = elite_pi

# OLED begin.
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
SRC += features/oled.c
# OLED end.

# RGB_MATRIX begin.
RGBLIGHT_ENABLE    = no
RGB_MATRIX_ENABLE  = yes
RGB_MATRIX_DRIVER  = ws2812
# RGB_MATRIX end.
