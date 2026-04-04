# Available Keycodes for KMK Firmware

This document lists the keycodes available in KMK for use in your keymap.

## Letter Keys
- `KC.A` through `KC.Z` - Letter keys

## Number Keys
- `KC.N0` through `KC.N9` - Number row keys (top of keyboard)

## Modifier Keys
- `KC.LCTL` - Left Control
- `KC.RCTL` - Right Control
- `KC.LSFT` - Left Shift
- `KC.RSFT` - Right Shift
- `KC.LALT` - Left Alt
- `KC.RALT` - Right Alt
- `KC.LGUI` - Left Windows/Command
- `KC.RGUI` - Right Windows/Command

## Function Keys
- `KC.F1` through `KC.F24` - Function keys

## Navigation Keys
- `KC.HOME` - Home
- `KC.END` - End
- `KC.PGUP` - Page Up
- `KC.PGDN` - Page Down
- `KC.UP` - Up Arrow
- `KC.DOWN` - Down Arrow
- `KC.LEFT` - Left Arrow
- `KC.RIGHT` - Right Arrow

## Special Keys
- `KC.ESC` - Escape
- `KC.ENT` / `KC.RETURN` - Enter
- `KC.BSPC` - Backspace
- `KC.DEL` - Delete
- `KC.TAB` - Tab
- `KC.CAPS` - Caps Lock
- `KC.SPC` - Space

## Symbol Keys
- `KC.GRAVE` / `KC.GRV` - ` ~
- `KC.MINUS` / `KC.MINS` - - _
- `KC.EQUAL` / `KC.EQL` - = +
- `KC.LBRC` - [ {
- `KC.RBRC` - ] }
- `KC.BSLS` - \ |
- `KC.SCLN` - ; :
- `KC.QUOT` - ' "
- `KC.COMM` - , <
- `KC.DOT` - . >
- `KC.SLSH` - / ?

## Media Keys
- `KC.MUTE` - Mute
- `KC.VOLU` - Volume Up
- `KC.VOLD` - Volume Down
- `KC.MPRV` - Media Previous
- `KC.MPLY` - Media Play/Pause
- `KC.MNXT` - Media Next

## Special Functions
- `KC.PSCR` - Print Screen
- `KC.SLCK` - Scroll Lock
- `KC.PAUS` - Pause
- `KC.INS` - Insert
- `KC.APP` - Application Menu
- `KC.NO` - No operation (empty key)

## Layer Control (in `keymap.py`)
```python
from kmk.keys import KC
from kmk.modules.layers import Layers

# Add to your keymap for layer control:
# MO(layer_num) - Momentary layer (hold to activate)
# TG(layer_num) - Toggle layer
# LT(layer_num, key) - Layer tap (hold for layer, tap for key)

# Example in keymap:
# KC.MO(1)  - Momentary Layer 1
# KC.TG(1)  - Toggle Layer 1
# KC.LT(1, KC.SPC) - Hold for Layer 1, Tap for Space
```

## Custom Macros and String Output

In your `keymap.py`, you can define macros:

```python
from kmk.handlers.sequences import send_string

MACROS = {
    'EMAIL': send_string('your.email@example.com'),
    'GREET': send_string('Hello, World!'),
}
```

Then use them in your keymap. See the KMK documentation for advanced macro features.

## Usage Example

```python
# In keymap.py, Layer 0:
from kmk.keys import KC

LAYER_0 = (
    # Row 0
    (KC.ESC, KC.N1, KC.N2, KC.N3, KC.N4, KC.N5, ...),
    # Add more rows...
)
```

## Complete Keycode Reference

For the complete and most up-to-date keycode reference, visit:
https://github.com/KMKfw/kmk_firmware/blob/master/docs/en/keycodes.md

## Adding a New Keycode

If you need a keycode that doesn't exist, check the KMK modules:
- Media keys: `kmk.keys.KC` (built-in)
- Consumer codes: Might require additional modules
- Custom keycodes: Can be defined using layers and macros
