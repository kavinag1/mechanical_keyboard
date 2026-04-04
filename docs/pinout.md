# Raspberry Pi Pico Mechanical Keyboard Firmware

## GPIO Pinout Reference for 60% Keyboard

### Row Pins (Outputs)
```
GP0  - Row 0
GP1  - Row 1
GP2  - Row 2
GP3  - Row 3
GP4  - Row 4
```

### Column Pins (Inputs with Pull-ups)
```
GP5  - Col 0
GP6  - Col 1
GP7  - Col 2
GP8  - Col 3
GP9  - Col 4
GP10 - Col 5
GP11 - Col 6
GP12 - Col 7
GP13 - Col 8
GP14 - Col 9
GP15 - (Available)
GP16 - (Available)
GP17 - (Available)
GP18 - (Available)
GP19 - (Available)
GP20 - (Available)
GP21 - (Available)
GP22 - (Available)
```

### Optional Features
```
GP26 - UNDERGLOW_PIN (RGB data line)
GP27 - LED_PIN (Status LED)
GP28 - Reserved (ADC use)
```

## USB Connections
```
- D0 (GPIO29) - USB D+ (built-in, via USB port)
- D1 (GPIO30) - USB D- (built-in, via USB port)
- Power - 5V from USB
- Ground - GND from USB
```

## Standard 60% Keyboard Matrix Layout

### Visual Layout
```
ESC  1    2    3    4    5    6    7    8    9    0    -    =    BSPC
TAB  Q    W    E    R    T    Y    U    I    O    P    [    ]    \
CAPS A    S    D    F    G    H    J    K    L    ;    '         RET
SHFT Z    X    C    V    B    N    M    ,    .    /         SHFT
CTRL WIN  ALT  [SPC]                              ALT  WIN  MNU  CTRL
```

### Matrix Position Reference (Row x Col)
The matrix is typically 5 rows × 14 columns for a 60% keyboard:

```
Row 0: [ESC(0,0)  1(0,1)  2(0,2)  3(0,3) ... BSPC(0,13)]
Row 1: [TAB(1,0)  Q(1,1)  W(1,2)  E(1,3) ...   \(1,13)]
Row 2: [CAP(2,0)  A(2,1)  S(2,2)  D(2,3) ...  RET(2,13)]
Row 3: [SFT(3,0)  Z(3,1)  X(3,2)  C(3,3) ...  SFT(3,13)]
Row 4: [CTL(4,0) WIN(4,1) ALT(4,2) SPC(4,5) ...]
```

## Tips for Wiring

1. **Rows should be connected to OUTPUT pins** - These actively drive row signals
2. **Columns should be connected to INPUT pins with pull-up resistors** - These detect key presses
3. **Use diodes** - Place a schottky diode (1N4148) at each switch to prevent ghosting
4. **Debouncing** - Electronic debouncing is handled in software (DEBOUNCE_TIME = 20ms)
5. **Test each key** - Use the REPL to test individual row/column combinations

## Testing Individual Keys

Connect to the keyboard via REPL and test:
```python
# In REPL
import board
import digitalio

# Test Row 0
row = digitalio.DigitalInOut(board.GP0)
row.direction = digitalio.Direction.OUTPUT
row.value = False  # Pull low

# Test Column 0
col = digitalio.DigitalInOut(board.GP5)
col.direction = digitalio.Direction.INPUT
col.pull = digitalio.Pull.UP

print(f"Column 0 state: {col.value}")  # Should read False when key is pressed
```

## Wiring Example with Diodes

```
Switch Matrix:
┌─────────────┐
│ Switch      │
├─────────────┤
│ Anode   > [1N4148 Diode] ──── COL pin
│            
│ Cathode > ─── ROW pin
└─────────────┘
```

The diode prevents current from flowing backwards through multiple switches (ghosting).
