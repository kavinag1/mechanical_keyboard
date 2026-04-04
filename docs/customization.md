# QMK Customization Guide

This guide will help you customize your 60% mechanical keyboard firmware using QMK.

## Quick Start

The easiest way to customize your keyboard is to modify files in this order:
1. **Keymaps** - Change which keys do what
2. **Config** - Adjust debounce, features, etc.
3. **Build Settings** - Enable/disable features

## Changing Keymaps

### Basic Key Reassignment

Edit `keymaps/default/keymap.c`:

```c
// Change the default layer
[0] = {
    {KC_ESC, KC_1, KC_2, KC_3, /* ... more keys ... */},
    // More rows...
}
```

### Available Keycodes

Common keycodes you can use:

**Letters & Numbers:**
- `KC_A` through `KC_Z` - Letters
- `KC_1` through `KC_0` - Numbers (top row)

**Modifiers:**
- `KC_LCTL`, `KC_RCTL` - Control keys
- `KC_LSFT`, `KC_RSFT` - Shift keys
- `KC_LALT`, `KC_RALT` - Alt keys
- `KC_LGUI`, `KC_RGUI` - Windows/Command keys

**Function Keys:**
- `KC_F1` through `KC_F24` - Function keys

**Navigation:**
- `KC_HOME`, `KC_END`, `KC_PGUP`, `KC_PGDN`
- `KC_UP`, `KC_DOWN`, `KC_LEFT`, `KC_RIGHT`
- `KC_INS`, `KC_DEL`

**Special Keys:**
- `KC_ESC`, `KC_TAB`, `KC_CAPS`, `KC_ENT`
- `KC_BSPC` - Backspace
- `KC_SPC` - Space
- `KC_LBRC`, `KC_RBRC` - [ and ]
- `KC_BSLS` - Backslash \
- `KC_SCLN` - Semicolon ;
- `KC_QUOT` - Quote '
- `KC_COMM`, `KC_DOT`, `KC_SLSH` - , . /
- `KC_MINS`, `KC_EQL` - - and =
- `KC_GRV` - Grave `

**Media Keys:**
- `KC_MUTE`, `KC_VOLU`, `KC_VOLD` - Volume control
- `KC_MPLY`, `KC_MNXT`, `KC_MPRV` - Media playback
- `KC_PSCR`, `KC_SLCK`, `KC_PAUS` - Print, Scroll Lock, Pause

**Special:**
- `KC_NO` - No operation (empty key)
- `_______` - Transparent (use key from lower layer)

### Example: Swap Caps Lock and Escape

```c
[0] = {
    {KC_CAPS,  KC_1,    KC_2,    /* ... */},  // Caps in ESC position
    {KC_TAB,   KC_Q,    KC_W,    /* ... */},
    {KC_ESC,   KC_A,    KC_S,    /* ... */},  // ESC in CAPS position
    // ... rest of keymap
}
```

## Layer Switching

### Add a New Layer

Create a new layer for gaming, coding, or other purposes:

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        // Default QWERTY layer
        {KC_ESC, KC_1, /* ... */}
    },

    [1] = {
        // Function layer (existing)
        {KC_GRV, KC_F1, /* ... */}
    },

    [2] = {
        // New gaming layer
        {KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC},
        {KC_TAB, KC_W, KC_Q, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS},
        // ... rest of gaming layout
    }
};
```

### Layer Switching Keys

Use these in your keymap to switch layers:

- `MO(layer)` - **Momentary**: Hold to activate, release to deactivate
  ```c
  MO(1)  // Hold down for layer 1, tap for nothing
  ```

- `LT(layer, key)` - **Layer Tap**: Hold for layer, tap for key
  ```c
  LT(1, KC_SPC)  // Hold for layer 1, tap for space
  ```

- `TG(layer)` - **Toggle**: Press to activate, press again to deactivate
  ```c
  TG(2)  // Press to toggle layer 2
  ```

### Example: Function Layer on Right Alt

Replace the right Alt key with layer switching:

```c
[0] = {
    // ... other keys ...
    {KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, MO(1), KC_RGUI, KC_NO, KC_NO, KC_NO, KC_RCTL},
};
```

Now holding right Alt activates layer 1.

## Configuring Features

### Debounce Settings

Edit `config.h` to adjust how the keyboard detects key presses:

```c
/* Debounce in milliseconds - default is 20 */
#define DEBOUNCE 20

// Lower value = faster response, but may cause double-presses
// Higher value = more stable, but slower response
```

Typical range: 10-30ms. Test what feels right for your switches.

### Enable Media Keys

Add to `rules.mk`:

```makefile
EXTRAKEY_ENABLE = yes
```

Now you can use: `KC_MUTE`, `KC_VOLU`, `KC_VOLD`, `KC_MPLY`, etc.

### Enable Mouse Keys

Add to `rules.mk`:

```makefile
MOUSEKEY_ENABLE = yes
```

Then use in your keymap:
- `KC_MS_UP`, `KC_MS_DN`, `KC_MS_LT`, `KC_MS_RT` - Mouse movement
- `KC_BTN1`, `KC_BTN2`, `KC_BTN3` - Left, Right, Middle click

### N-Key Rollover (NKRO)

Already enabled by default in `rules.mk`. This allows pressing multiple keys at once without interference.

Disable with:
```makefile
NKRO_ENABLE = no
```

## Adding Macros

### Simple Text Macro

In `keymap.c`:

```c
// Add this code before the keymaps
enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    GREET
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("user@example.com");
            }
            return false;
        case GREET:
            if (record->event.pressed) {
                SEND_STRING("Hello, World!");
            }
            return false;
    }
    return true;
}
```

Then use in your keymap:
```c
[1] = {
    {EMAIL, GREET, /* ... */}
}
```

## Building Custom Layouts

### Add a New Keymap

Create a new keymap file:

```bash
mkdir -p keymaps/gaming
```

Copy `keymaps/default/keymap.c` to `keymaps/gaming/keymap.c` and edit it.

### Compile Your New Keymap

```bash
qmk compile -kb mechanical_keyboard -km gaming
```

This creates a new `.uf2` file with your custom keymap.

## Advanced Customization

### Custom Behavior on Key Press/Release

```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A:
            if (record->event.pressed) {
                // Do something when A is pressed
                SEND_STRING("A pressed!");
            } else {
                // Do something when A is released
            }
            return true;  // Continue normal processing
    }
    return true;
}
```

### Tap Dance (Double-tap Actions)

Enable in `rules.mk`:
```makefile
TAP_DANCE_ENABLE = yes
```

Then in `keymap.c`:

```c
enum {
    TD_ESC_CAPS = 0,
    TD_SPC_SHIFT = 1
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once = ESC, Tap twice = CAPS LOCK
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    
    // Tap once = SPACE, Hold = SHIFT
    [TD_SPC_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LSFT)
};
```

Use in keymap:
```c
[0] = {
    {TD(TD_ESC_CAPS), /* ... */}
}
```

## Testing Your Changes

### Compile
```bash
qmk compile -kb mechanical_keyboard -km default
```

### Check for Errors
```bash
qmk compile -kb mechanical_keyboard -km default -v
```

The `-v` flag gives verbose output for debugging.

### Flash to Pico
1. Hold BOOTSEL on your Pico
2. Copy the `.uf2` file to the RPI-RP2 drive

## Troubleshooting

### Compilation Error: "LAYOUT not defined"
- Make sure you're using array syntax `{ { ... }, { ... }, ... }` instead of `LAYOUT_60_ansi()`

### Keys not working after compile
- Check Matrix in [docs/PINOUT.md](PINOUT.md)
- Verify GPIO pins in `config.h` match your board

### Some keys produce wrong characters
- Check your keycode assignment
- Verify the layer is correct
- Test in a simple text editor

### Weird compilation errors
- Run `qmk setup` again
- Delete the Build folder: `rm -rf .build`
- Recompile from scratch

## More Resources

- [QMK Docs - Keycodes](https://docs.qmk.fm/keycodes)
- [QMK Docs - Macros](https://docs.qmk.fm/feature_macros)
- [QMK Docs - Layers](https://docs.qmk.fm/feature_layers)
- [QMK GitHub - Example Keymaps](https://github.com/qmk/qmk_firmware/tree/master/keyboards/dz60/keymaps)
