# Equivalent to `qmk {compile,flash} ... -e CONVERT_TO=elite_pi`
# https://docs.qmk.fm/#/feature_converters
CONVERT_TO = elite_pi

# OLED begin.
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
SRC += features/oled.c
# OLED end.
