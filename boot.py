"""
Boot file - runs on Pico startup before automatically running kb.py
Sets up USB HID descriptors and initial configuration
"""

import board
import digitalio
import busio
import usb_hid
import usb_cdc

# Configure USB settings
usb_hid.enable((usb_hid.Device.KEYBOARD,))

# Optional: Enable serial console for debugging
# Set to False if you want the serial port free for other use
usb_cdc.enable(console=True, data=True)

# Optional: Set up a status LED on the built-in LED
# led = digitalio.DigitalInOut(board.LED)
# led.direction = digitalio.Direction.OUTPUT
# led.value = True  # Turn on

print("CircuitPython boot complete. Loading keyboard firmware...")
