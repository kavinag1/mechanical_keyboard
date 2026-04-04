"""
Main Keyboard Firmware for 60% Mechanical Keyboard - Raspberry Pi Pico

This is the entry point for the keyboard firmware.
CircuitPython will automatically run this on startup.
"""

import gc
import board
from kmk.kmk_firmware import KMKFirmware
from kmk.keys import KC
from kmk.scanners.keypad import KeysScanner
from kmk.modules.layers import Layers

# Import configuration
from config import (
    ROW_PINS, COL_PINS, DEBOUNCE_TIME, REPORT_INTERVAL,
    DEBUG, KEYBOARD_MATRIX, NUM_LAYERS
)
from keymap import KEYMAP

# Initialize keyboard
keyboard = KMKFirmware()

# Configure layers module
keyboard.modules.append(Layers())

# Initialize the keyboard matrix scanner
# This will scan the physical keyboard for key presses
try:
    # Convert pin constants to actual GPIO objects
    row_pi = [getattr(board, f"GP{pin}") if isinstance(ROW_PINS[0], int) else ROW_PINS[i] 
              for i, pin in enumerate(ROW_PINS)]
    col_pins = [getattr(board, f"GP{pin}") if isinstance(COL_PINS[0], int) else COL_PINS[i] 
                for i, pin in enumerate(COL_PINS)]
    
    # Create the keypad scanner
    keyboard.matrix = KeysScanner(
        pins=tuple(row_pins) + tuple(col_pins),
        value_if_pressed=False,
        pull=True,
    )
    
except Exception as e:
    if DEBUG:
        print(f"Matrix initialization error: {e}")

# Configure keyboard settings
keyboard.debounce_time = DEBOUNCE_TIME
keyboard.report_interval = REPORT_INTERVAL
keyboard.debug_enabled = DEBUG

# Set the keymap
keyboard.keymap = KEYMAP

# USB Configuration
keyboard.max_layers = NUM_LAYERS

# Optional: Configure LED support (if you have RGB LEDs)
# from kmk.extensions.LED import LED
# led = LED()
# keyboard.extensions.append(led)

# Optional: Configure OLED display (if you have one)
# from kmk.extensions.OLED import OLED
# oled = OLED()
# keyboard.extensions.append(oled)

def on_startup():
    """Called on keyboard startup"""
    if DEBUG:
        print("Keyboard firmware loaded!")
        print(f"Matrix size: {len(ROW_PINS)} rows x {len(COL_PINS)} columns")
        print(f"Debounce time: {DEBOUNCE_TIME}ms")
        print(f"Report interval: {REPORT_INTERVAL}ms")

def on_shutdown():
    """Called on keyboard shutdown"""
    if DEBUG:
        print("Keyboard firmware shutting down")

# Run startup tasks
on_startup()

# Keep some memory free
gc.collect()

# Main loop - this runs forever
if __name__ == '__main__':
    try:
        keyboard.go()
    except KeyboardInterrupt:
        on_shutdown()
        raise
