"""
Keyboard Configuration for 60% Mechanical Keyboard with Raspberry Pi Pico

This file contains the hardware configuration for your keyboard.
Modify the pins and layout settings to match your physical setup.
"""

# GPIO Pin Assignments for Keyboard Matrix
# Rows - Output pins (5 rows typical for 60% keyboard)
ROW_PINS = (0, 1, 2, 3, 4)

# Columns - Input pins with pull-ups (10-14 columns for 60%)
COL_PINS = (5, 6, 7, 8, 9, 10, 11, 12, 13, 14)

# Keyboard Matrix Layout (60% keyboard - 5 rows x 14 columns)
# This represents the physical layout of your keyboard
# Leave as 'KC.NO' for unused positions
# Format: [
#    [key1, key2, key3, ..., key14],  # Row 0 (topmost)
#    [key1, key2, key3, ..., key14],  # Row 1
#    [key1, key2, key3, ..., key14],  # Row 2
#    [key1, key2, key3, ..., key14],  # Row 3
#    [key1, key2, key3, ..., key14],  # Row 4 (bottommost)
# ]

# For a standard 60% layout:
# Row 0: Esc 1 2 3 4 5 6 7 8 9 0 - = [BackSpace]
# Row 1: Tab Q W E R T Y U I O P [ ] \
# Row 2: Caps A S D F G H J K L ; '   [Return]
# Row 3: Shift Z X C V B N M , . / [Shift]
# Row 4: Ctrl Win Alt [Space] Alt Win Menu Ctrl

KEYBOARD_MATRIX = None  # Will be initialized in kb.py

# Debounce timing in milliseconds
DEBOUNCE_TIME = 20

# Report Interval - How often to send keyboard reports (ms)
REPORT_INTERVAL = 10

# LED Configuration (optional)
# Set to None if your keyboard doesn't have RGB
LED_PIN = None
LED_NUM = 0
LED_BRIGHTNESS = 100

# Underglow LED (optional)
UNDERGLOW_PIN = None
UNDERGLOW_NUM = 0

# OLED Display (optional)
# Set OLED_ENABLED = True to enable
OLED_ENABLED = False
OLED_SCL_PIN = None  # I2C SCL pin
OLED_SDA_PIN = None  # I2C SDA pin

# Encoder Support (optional) - for rotary encoders
ENCODER_ENABLED = False
ENCODER_PINS = []  # List of (clk_pin, dt_pin) tuples

# Split Keyboard Support (optional)
SPLIT_ENABLED = False
SPLIT_SIDE = 'LEFT'  # 'LEFT' or 'RIGHT'
SPLIT_UART_PIN = None

# USB Vendor and Product IDs
USB_VID = 0xCAFE
USB_PID = 0xDEAD
MANUFACTURER = "Your Name"
PRODUCT = "60% Keyboard"

# Tap dance and macro support
ENABLE_TAP_DANCE = True
ENABLE_MACROS = True

# Layer support
NUM_LAYERS = 2

# Debug mode - set to True to see debug output in REPL
DEBUG = False
