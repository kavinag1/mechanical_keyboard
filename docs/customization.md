# Customization Guide for KMK Mechanical Keyboard Firmware

## Quick Start

This guide will help you customize your keyboard firmware quickly and easily.

## Table of Contents
1. [Changing Key Mappings](#changing-key-mappings)
2. [Adding New Layers](#adding-new-layers)
3. [Layer Switching](#layer-switching)
4. [Macros](#macros)
5. [Debounce Adjustment](#debounce-adjustment)
6. [Adding RGB LED Support](#adding-rgb-led-support)
7. [Troubleshooting](#troubleshooting)

## Changing Key Mappings

The easiest customization is to remap keys. This is done in `keymap.py`.

### Basic Key Remapping

1. Open `keymap.py`
2. Find the key you want to change in `LAYER_0`
3. Replace it with the keycode you want
4. Save the file

Example: Change ESC to Grave key (`)
```python
# Change this:
(KC.ESC, KC.N1, KC.N2, ...)

# To this:
(KC.GRV, KC.N1, KC.N2, ...)
```

### Available Keycodes
See `docs/keycodes.md` for a complete list of available keycodes.

## Adding New Layers

Create additional layers for gaming, coding, or other purposes.

### Example: Adding a Layer 2

1. Open `keymap.py`
2. Add a new layer definition after `LAYER_1`:

```python
# Layer 2 - Gaming Layer
LAYER_2 = (
    # Row 0: Same as default
    (KC.ESC, KC.N1, KC.N2, KC.N3, KC.N4, KC.N5, KC.N6, KC.N7, KC.N8, KC.N9, KC.N0, KC.MINUS, KC.EQUAL, KC.BSPC),
    
    # Row 1: WASD for movement, other keys for gaming
    (KC.TAB, KC.W, KC.Q, KC.E, KC.R, KC.T, KC.Y, KC.U, KC.I, KC.O, KC.P, KC.LBRC, KC.RBRC, KC.BSLS),
    
    # ... add remaining rows
)
```

3. Update the `KEYMAP` tuple to include the new layer:

```python
KEYMAP = (
    LAYER_0,
    LAYER_1,
    LAYER_2,  # Add this
)
```

4. Update `NUM_LAYERS` in `config.py`:

```python
NUM_LAYERS = 3  # Changed from 2
```

## Layer Switching

Control how you switch between layers using layer switching keys.

### Layer Switching Keys

In your keymap, use these special layer control keys:

```python
from kmk.keys import KC

# Momentary - Hold to activate, release to deactivate
KC.MO(1)  # Hold for Layer 1

# Toggle - Press to activate, press again to deactivate
KC.TG(1)  # Toggle Layer 1

# Layer Tap - Hold for layer, tap for key
KC.LT(1, KC.SPC)  # Hold for Layer 1, Tap for Space
```

### Example: Add FN Key (Layer 1 Momentary)

In `keymap.py`, replace an unused key with layer switching:

```python
# In LAYER_0, replace right Alt with Layer 1 momentary:
(KC.LCTL, KC.LGUI, KC.LALT, KC.NO, KC.NO, KC.SPC, KC.NO, KC.NO, KC.MO(1), KC.RGUI, KC.NO, KC.NO, KC.NO, KC.RCTL),
```

Now holding the right Alt key will activate Layer 1 temporarily.

## Macros

Create macros for frequently typed text or key combinations.

### Simple Text Macro

In `keymap.py`:

```python
from kmk.handlers.sequences import send_string

MACROS = {
    'EMAIL': send_string('user@example.com'),
    'ADDRESS': send_string('123 Main St, Anytown, USA'),
}
```

### Using Macros in Keymap

To use macros in your keymap, you need to map them to physical keys. This typically requires a macro module (see KMK documentation for advanced macro setup).

For now, text strings work well in special keys.

## Debounce Adjustment

If keys are registering multiple times, increase debounce. If response is sluggish, decrease it.

In `config.py`:

```python
# Default: 20ms
DEBOUNCE_TIME = 20

# Increase if you get double-presses:
DEBOUNCE_TIME = 25  # or 30

# Decrease for more responsive feel (may need to increase if double-press occurs):
DEBOUNCE_TIME = 15
```

The debounce time is in milliseconds. Test values of 15-25ms typically work best.

## Adding RGB LED Support

If your keyboard has underglow or per-key RGB LEDs:

### 1. Install NeoPixel Library

Copy the NeoPixel CircuitPython library to your Pico.

### 2. Enable in `config.py`

```python
# Change from:
LED_PIN = None
LED_NUM = 0

# To your actual pin and number of LEDs:
LED_PIN = board.GP26  # or whatever pin you're using
LED_NUM = 64  # Number of LEDs
LED_BRIGHTNESS = 100  # 0-255
```

### 3. Enable in `kb.py`

Uncomment the LED support section:

```python
from kmk.extensions.NeoPixel import NeoPixelExt

neopixel = NeoPixelExt(
    pixel_pin=keyboard.config.led_pin,
    num_pixels=keyboard.config.led_num,
    val_default=keyboard.config.led_brightness,
)
keyboard.extensions.append(neopixel)
```

## Troubleshooting

### Issue: Keys are double-registering

**Solution:** Increase `DEBOUNCE_TIME` in `config.py`

```python
DEBOUNCE_TIME = 25  # Try 25ms instead of 20ms
```

### Issue: Some keys not responding

**Solution:** Check your matrix configuration
1. Verify GPIO pins in `config.py` match your wiring
2. Test individual rows/columns (see pinout.md)
3. Ensure diodes are properly installed

### Issue: Wrong keys in certain positions

**Solution:** Verify your matrix layout
1. Check that `LAYER_0` matches your physical keyboard layout
2. Count the columns carefully (should be 14 for 60%)
3. Test pressing each physical key and note which keycode it produces

### Issue: Firmware won't load

**Solution:**
1. Ensure CircuitPython 8.x is installed on Pico
2. Check that `kb.py` is in the root of CIRCUITPY drive
3. View REPL output for error messages

For more advanced customization, see the KMK documentation:
https://github.com/KMKfw/kmk_firmware/tree/master/docs
