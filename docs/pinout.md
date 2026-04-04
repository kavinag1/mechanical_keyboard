# GPIO Pinout Reference - 60% Keyboard

This document details the GPIO pin assignments for your specific PCB layout.

## Pico GPIO Assignments

### Row Pins (Output - GPIO13 to GPIO17)

These are the row scan pins. They drive the rows of the keyboard matrix.

| Row | GPIO Pin | Pico Pin |
|-----|----------|----------|
| 0   | GP13     | Pin 17   |
| 1   | GP14     | Pin 19   |
| 2   | GP15     | Pin 20   |
| 3   | GP16     | Pin 21   |
| 4   | GP17     | Pin 22   |

### Column Pins (Input - GPIO0-GPIO12, GPIO18)

These are the column sense pins with internal pull-ups. They detect key presses.

| Column | GPIO Pin | Pico Pin |
|--------|----------|----------|
| 0      | GP0      | Pin 1    |
| 1      | GP1      | Pin 2    |
| 2      | GP2      | Pin 4    |
| 3      | GP3      | Pin 5    |
| 4      | GP4      | Pin 6    |
| 5      | GP5      | Pin 7    |
| 6      | GP6      | Pin 9    |
| 7      | GP7      | Pin 10   |
| 8      | GP8      | Pin 11   |
| 9      | GP9      | Pin 12   |
| 10     | GP10     | Pin 13   |
| 11     | GP11     | Pin 14   |
| 12     | GP12     | Pin 15   |
| 13     | GP18     | Pin 24   |

## Physical Layout

```
          COLUMNS
    ┌─────────────────────────────────────────────────────┐
    │ 0  1  2  3  4  5  6  7  8  9 10 11 12 13            │
┌───┼─────────────────────────────────────────────────────┤
│ 0 │ Esc 1  2  3  4  5  6  7  8  9  0  -  =  BSPC        │
├───┼─────────────────────────────────────────────────────┤
│ 1 │ TAB Q  W  E  R  T  Y  U  I  O  P  [  ]  \            │
├───┼─────────────────────────────────────────────────────┤
│ 2 │ CAPS A  S  D  F  G  H  J  K  L  ;  '     ENTER       │
├───┼─────────────────────────────────────────────────────┤
│ 3 │ SHIFT Z  X  C  V  B  N  M  ,  .  /      SHIFT       │
├───┼─────────────────────────────────────────────────────┤
│ 4 │ CTRL WIN ALT      SPACE      ALT WIN MNU CTRL       │
└───┴─────────────────────────────────────────────────────┘
  ▲
  ROWS
```

## Wiring Guide

### Connection Order

1. **Rows**: Solder row lines to GPIO13-GPIO17 on Pico
2. **Columns**: Solder column lines to GPIO0-GPIO12 and GPIO18 on Pico
3. **Each switch**: Should have a 1N4148 diode in series (cathode to column)

### Diode Orientation

```
Switch Circuit:
    Row Pin
        │
    Anode ├─────┫├----- Cathode
         [1N4148 Diode]
        │
    Column Pin (with pull-up)
```

The diode prevents "ghosting" where multiple key presses trigger unintended keys.

## Standard 60% ANSI Matrix

Row by Row breakdown:

**Row 0 (GP13):**
- (0,0)=ESC, (0,1)=1, (0,2)=2, (0,3)=3, (0,4)=4, (0,5)=5
- (0,6)=6, (0,7)=7, (0,8)=8, (0,9)=9, (0,10)=0, (0,11)=-, (0,12)==, (0,13)=BSPC

**Row 1 (GP14):**
- (1,0)=TAB, (1,1)=Q, (1,2)=W, (1,3)=E, (1,4)=R, (1,5)=T
- (1,6)=Y, (1,7)=U, (1,8)=I, (1,9)=O, (1,10)=P, (1,11)=[, (1,12)=], (1,13)=\

**Row 2 (GP15):**
- (2,0)=CAPS, (2,1)=A, (2,2)=S, (2,3)=D, (2,4)=F, (2,5)=G
- (2,6)=H, (2,7)=J, (2,8)=K, (2,9)=L, (2,10)=;, (2,11)=', (2,12)=NONE, (2,13)=ENTER

**Row 3 (GP16):**
- (3,0)=LSHIFT, (3,1)=Z, (3,2)=X, (3,3)=C, (3,4)=V, (3,5)=B
- (3,6)=N, (3,7)=M, (3,8)=,, (3,9)=., (3,10)=/, (3,11)=NONE, (3,12)=NONE, (3,13)=RSHIFT

**Row 4 (GP17):**
- (4,0)=LCTRL, (4,1)=LGUI, (4,2)=LALT, (4,3)=NONE, (4,4)=NONE, (4,5)=SPACE
- (4,6)=NONE, (4,7)=NONE, (4,8)=RALT, (4,9)=RGUI, (4,10)=NONE, (4,11)=NONE, (4,12)=NONE, (4,13)=RCTRL

## Troubleshooting

### Detecting Wrong Keys

If a key is registering as the wrong character:
1. Note the physical key position (e.g., "2" key = row 0, column 2)
2. Check the wiring for that row and column
3. Verify the correct keycode is assigned in `keymap.c`

### No Response from a Key

1. **Check the diode**: Ensure the 1N4148 diode is soldered correctly
2. **Check GPIO connection**: Verify solder joints at the Pico and PCB
3. **Test continuity**: Use a multimeter to check for shorts
4. **Check debounce**: Increase `DEBOUNCE` value in `config.h` if inconsistent

### Multiple Keys Activating

This indicates **ghosting** - missing or reversed diodes:
1. Verify all diodes are installed
2. Check diode orientation (stripe = cathode, toward column)
3. Check for shorted switches or traces

## Pin Conflicts

These pins should NOT be used for custom features without modification:

- **GP13-GP17, GP0-GP12, GP18**: Reserved for matrix scanning
- **GP24-GPIO25**: Reserved for USB (if using native USB)
- **GPIO26-GPIO29**: ADC pins (can be used if not needed for ADC)

If you need to add features like RGB LEDs or OLED displays, use available pins:
- **GP19-23, GP25+**: Available for extensions (if not conflicting with matrix)

## Configuration File Reference

Your GPIO assignments are defined in `config.h`:

```c
#define MATRIX_ROW_PINS { GP13, GP14, GP15, GP16, GP17 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18 }
```

Do NOT modify these pins unless you have physical changes to your board.

## Testing Individual Keys via REPL

You can test your keyboard via the QMK REPL (if available on your Pico):

```python
# Test if a switch is working
# Press the key at Row 0, Column 0 (ESC key)
# The REPL should show the matrix position being read
```

For more detailed debugging, compile with `DEBUG_MATRIX_SCAN_RATE` enabled in `rules.mk`.
