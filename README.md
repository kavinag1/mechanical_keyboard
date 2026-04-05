# Building My Own 60% Mechanical Keyboard with a Raspberry Pi Pico

I've always wanted a keyboard that was truly *mine* — not just a different keycap set, but something I designed and built from the ground up. So I did it. This is the story of how I went from a blank screen to a 60% mechanical keyboard powered by a Raspberry Pi Pico.

---

## The Journey

### Step 1: Learning What a Keyboard Matrix Is

Before touching any design tools, I had to understand how keyboards actually work electrically. The answer is a *key matrix* — instead of wiring every single key directly to a microcontroller pin, you arrange the switches in a grid of rows and columns. The controller scans each row one at a time and reads which columns register a connection, letting you detect any key with just `rows + columns` pins instead of one pin per key.

To wrap my head around it, I started with a simple 3×3 example:

```
       Col0  Col1  Col2
Row0    K1    K2    K3
Row1    K4    K5    K6
Row2    K7    K8    K9
```

With 3 row pins and 3 column pins you can read 9 keys — that's the core idea. Scale it up and you get a full keyboard.

Once I understood the concept, I mapped out the full 60-key layout I wanted to build — a standard 60% ANSI arrangement: 5 rows and 14 columns.

**The Matrix:**
- 5 row lines
- 14 column lines
- 60 key positions in standard ANSI format

```
       Col0 Col1 Col2 Col3 Col4 Col5 Col6 Col7 Col8 Col9 Col10 Col11 Col12 Col13
Row0    Esc  1    2    3    4    5    6    7    8    9    0     -     =     Bksp
Row1    Tab  Q    W    E    R    T    Y    U    I    O    P     [     ]     \
Row2    Caps A    S    D    F    G    H    J    K    L    ;     '     None  Entr
Row3    Shft Z    X    C    V    B    N    M    ,    .    /     None  None  Shft
Row4    Ctrl Win  Alt  None None Space None None RAlt RGui None None None  Ctrl
```

![](<images/Screenshot 2026-04-02 175157.png>)

*The full 5×14 key matrix taking shape in the layout tool.*

![](<images/Screenshot 2026-04-02 175205.png>)

*Zooming in to check the key positions matched the ANSI standard.*

---

### Step 2: Designing the Schematic

With the matrix planned, I moved on to the electrical schematic. The biggest challenge was getting the diodes right — every single switch needs a 1N4148 diode to prevent *ghosting*, where pressing multiple keys at once causes phantom keypresses you didn't intend.

I wired the rows to the Pico's output pins and the columns to the input pins with pull-up resistors.

**Pin Assignments:**
- Row pins (outputs): GP13, GP14, GP15, GP16, GP17
- Column pins (inputs): GP0–GP12, GP18
- Each switch: 1N4148 diode with anode at the switch, cathode toward the column

**How each switch connects:**
```
         Row Output (GP13-17)
              |
         ┌────┴────┐
         │  Switch │
         └────┬────┘
              |
         ┌────▼────┐
         │ 1N4148  │  (Anode at switch, Cathode toward column)
         │ Diode   │
         └────┬────┘
              |
    Column Input (GP0-12, GP18) with 10kΩ pull-up to 3.3V
```

This diode arrangement:
- Prevents ghosting (phantom keypresses)
- Enables N-key rollover (press as many keys as you want simultaneously)
- Protects against electrical noise

![](<images/Screenshot 2026-04-02 194001.png>)

*The pin mapping — rows on one side, columns on the other.*

![](<images/Screenshot 2026-04-03 162539.png>)

*Confirming the diode orientation was consistent across the schematic.*

---

### Step 3: Routing the PCB

With the schematic done, I moved on to laying out and routing the actual PCB. Getting all the traces to fit cleanly without shorts — especially around the diode footprints — took a fair bit of iteration.

![](<images/Screenshot 2026-04-03 162517.png>)

*The PCB routing in progress — getting all those traces to play nicely together.*

![](<images/Screenshot 2026-04-03 162530.png>)

*Checking the diode footprints before committing to the final layout.*

---

### Step 4: Designing the Case

The PCB needed a home. I designed a case that would hold the PCB, the Raspberry Pi Pico, and all 60 switches — keeping everything rigid, protected, and not ugly.

Getting the mounting holes and switch cutouts to line up precisely with the PCB took a few rounds of tweaking.

![](<images/Screenshot 2026-04-03 173027.png>)

*The case design coming together — cutouts aligned with the switch matrix.*

![](<images/Screenshot 2026-04-03 173038.png>)

*A closer look at how the Pico sits inside the case.*

---

### Step 5: Firmware (In Progress)

The plan is to use QMK — an open-source keyboard firmware framework — to program the Pico with two layers:

- **Layer 0:** Standard QWERTY layout for everyday typing
- **Layer 1:** Function keys (F1–F12), navigation arrows, and media controls — all accessible by holding `Fn`

The firmware hasn't been written yet — this is the next step.

---

## Bill of Materials (BOM)

| Component | Purpose | Qty | Cost (USD) | Distributor | Link |
|-----------|---------|-----|-----------|-------------|------|
| Micro USB Cable | To connect the Pico | 1 | $1.62 | Amazon | [Buy](https://www.amazon.in/Ambrane-Unbreakable-Charging-Braided-Android/dp/B082LZGK39/) |
| 6mm Tactile Reset Button (SW1) | Reset button | 1 | $1.62 | Amazon | [Buy](https://www.amazon.in/ElectroBot-Momentary-Tactile-Push-Button/dp/B07PRRRBRY/) |
| 0.1uF Capacitor SMD 0805 (C1) | For the reset switch | 1 | $1.13 | Amazon | [Buy](https://www.amazon.in/0-1uF-100nF-Capacitor-0805-pack/dp/B0CMXNHQKP) |
| M2 Heat Set Inserts | For case assembly | 1 pack | $3.31 | Amazon | [Buy](https://www.amazon.in/BRASS-WAREHOUSE-Knurled-Threaded-Printing/dp/B0FMPZ3QHL/) |
| M2 Screws (20 pack) | Screwing the case | 1 pack | $1.93 | Amazon | [Buy](https://www.amazon.in/Tia-Golden-Screws-Length-Approx-480pcs/dp/B07VWKBHYZ/) |
| Keycaps | Keycaps for the keyboard | 1 set | $10.76 | Meckeys | [Buy](https://meckeys.com/shop/accessories/keyboard-accessories/keycaps/grey-black-keycaps/) |
| Gateron Switches | Switches for the keys | 7 packs | $15.12 | Meckeys | [Buy](https://meckeys.com/shop/accessories/keyboard-accessories/key-switches/gateron-optical-switch-pack/) |
| Raspberry Pi Pico | Microcontroller (the brain) | 1 | $4.00 | Robu.in | [Buy](https://robu.in/product/raspberry-pi-pico/) |
| 3D Printed Case | The keyboard case | 1 | $16.18 | Robu.in | — |
| 1N4148 Diode | Anti-ghosting diodes for the circuit | 1 pack | $3.08 | Amazon | [Buy](https://www.amazon.in/Circuit-Ranger-Switching-Electronic-Projects/dp/B0FJLP12GX) |
| PCB | The keyboard PCB | 5 | $36.01 | JLCPCB | — |
| **Total** | | | **$94.86** | | |

---

## Planned Key Mappings

**Layer 0 — QWERTY:**
```
Esc  1  2  3  4  5  6  7  8  9  0  -  =  Backspace
Tab  Q  W  E  R  T  Y  U  I  O  P  [  ]  \
Caps A  S  D  F  G  H  J  K  L  ;  '  Enter
Shift Z  X  C  V  B  N  M  ,  .  /  Shift
Ctrl Win Alt         Space      Alt Win Ctrl
```

**Layer 1 — Function (hold Fn):**
F1–F12, arrow keys, and media controls.

