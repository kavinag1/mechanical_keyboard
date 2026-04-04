# GPIO Pinout Reference

## Row Pins (GPIO13-17)

| Row | GPIO | Pico Pin |
|-----|------|----------|
| 0   | GP13 | 17       |
| 1   | GP14 | 19       |
| 2   | GP15 | 20       |
| 3   | GP16 | 21       |
| 4   | GP17 | 22       |

## Column Pins (GPIO0-12, 18)

| Col | GPIO | Pico Pin |
|-----|------|----------|
| 0   | GP0  | 1        |
| 1   | GP1  | 2        |
| 2   | GP2  | 4        |
| 3   | GP3  | 5        |
| 4   | GP4  | 6        |
| 5   | GP5  | 7        |
| 6   | GP6  | 9        |
| 7   | GP7  | 10       |
| 8   | GP8  | 11       |
| 9   | GP9  | 12       |
| 10  | GP10 | 13       |
| 11  | GP11 | 14       |
| 12  | GP12 | 15       |
| 13  | GP18 | 24       |

## Wiring

Each switch connects: Row → [1N4148 Diode Anode] → Cathode Stripe → Column

The diode prevents ghosting when multiple keys are pressed.

## Layout

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
```

## Configuration

```c
#define MATRIX_ROW_PINS { GP13, GP14, GP15, GP16, GP17 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18 }
```


## Testing Individual Keys via REPL

You can test your keyboard via the QMK REPL (if available on your Pico):

```python
# Test if a switch is working
# Press the key at Row 0, Column 0 (ESC key)
# The REPL should show the matrix position being read
```

For more detailed debugging, compile with `DEBUG_MATRIX_SCAN_RATE` enabled in `rules.mk`.
