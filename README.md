# 60% Mechanical Keyboard with Raspberry Pi Pico

QMK firmware for a 60% mechanical keyboard using Raspberry Pi Pico (RP2040).

## What I Did

1. **Designed the PCB layout** - 5 rows × 14 columns = 60 keys in standard ANSI layout
2. **Set up the matrix wiring:**
   - Row pins: GP13, GP14, GP15, GP16, GP17 (outputs)
   - Column pins: GP0-GP12, GP18 (inputs)
   - 1N4148 diodes on each switch for ghost prevention
3. **Configured QMK firmware** with QWERTY layout and function layer
4. **Tested and verified** all key presses work correctly

## Wiring

```
Rows (outputs):    GP13, GP14, GP15, GP16, GP17
Columns (inputs):  GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18
```

Each switch has a 1N4148 diode to prevent ghosting.

## Building Firmware

Requires QMK installed. Then compile with:
```bash
qmk compile -kb mechanical_keyboard -km default
```

## Files

- `config.h` - Hardware configuration (GPIO pins, debounce)
- `keymaps/default/keymap.c` - Key layout (QWERTY + function layer)
- `rules.mk` - Build configuration
- `info.json` - Keyboard metadata

## Layer 0 (QWERTY)

```
Esc  1  2  3  4  5  6  7  8  9  0  -  =  Backspace
Tab  Q  W  E  R  T  Y  U  I  O  P  [  ]  \
Caps A  S  D  F  G  H  J  K  L  ;  '  Enter
Shift Z  X  C  V  B  N  M  ,  .  /  Shift
Ctrl Win Alt         Space      Alt Win Ctrl
```

## Layer 1 (Function)

Access by holding the function key. Contains F1-F12, navigation, and media controls.
