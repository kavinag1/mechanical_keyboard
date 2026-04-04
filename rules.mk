# Build Options
#----------------------------------------------------------------------------
# change yes to no to disable
#
BOOTLOADER = rp2040
BOARD = GENERIC_RP_RP2040

# These files specify functionality
SRC += $(QUANTUM_DIR)/quantum.c

MCU = RP2040

# Microcontroller settings
ARMV = 7
USE_FPU = yes
FLOAT_IMPLEMENTATION = newlib

# Bootloader selection
BOOTLOADER = rp2040

# Build Options
#-- don't edit the lines below this point --

# Debugging / Flashing options
DFU_ARGS = -d 1209:bA42 -a 0 -R
DFU_SUFFIX_ARGS = -v 1209 -p bA42
PROGRAMMER = atmel_dfu

# Input/Output Options
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Feature options - uncomment to enable
MOUSEKEY_ENABLE = yes           # Mouse keys
EXTRAKEY_ENABLE = yes           # Audio control and System control
CONSOLE_ENABLE = yes            # Console for debug and messages
COMMAND_ENABLE = yes            # Commands for debug and configuration
NKRO_ENABLE = yes               # Enable N-Key Rollover for more responsive keystroke detection
BACKLIGHT_ENABLE = no           # Enable keyboard backlight functionality
MAGIC_ENABLE = yes              # Magic key functionality
UNICODE_ENABLE = no             # Unicode
BLUETOOTH_ENABLE = no           # Enable Bluetooth (not typically on RP2040)
SPLIT_KEYBOARD = no             # Not a split keyboard

# Tap dance (optional - uncomment to enable)
# TAP_DANCE_ENABLE = yes

# Combo keys (optional - uncomment to enable)
# COMBO_ENABLE = yes

# Macro recording (optional - uncomment to enable)
# DYNAMIC_MACRO_ENABLE = yes

# RGB Underglow (optional - uncomment to enable)
# RGBLIGHT_ENABLE = yes
# RGBLIGHT_DRIVER = ws2812

# Per-key RGB (optional - uncomment to enable)
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = ws2812

# OLED Display Support (optional - uncomment to enable)
# OLED_DRIVER_ENABLE = yes

# Encoder support (optional - uncomment to enable)
# ENCODER_ENABLE = yes

# LTO for size optimization
LTO_ENABLE = yes

# Size optimizations
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
