# Building My Own 60% Mechanical Keyboard with a Raspberry Pi Pico

I've always wanted a keyboard that was truly *mine* — not just a different keycap set, but something I designed and built from the ground up. So I did it. This is the story of how I went from a blank screen to a fully working 60% mechanical keyboard powered by a Raspberry Pi Pico.

---

## The Journey

### Step 1: Designing the PCB Layout

Everything started with the layout. I decided on a 60% form factor — 5 rows and 14 columns, totalling 60 keys in a standard ANSI arrangement. I had to figure out the exact position of every switch and how the electrical matrix would connect them all.

I spent an evening mapping out the grid, making sure the rows and columns lined up cleanly before touching any routing tools.

**The Matrix I Landed On:**
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

Here's what the layout looked like when I first got it working in the design tool:

![](<images/Screenshot 2026-04-02 175157.png>)

*The full 5×14 key matrix taking shape.*

![](<images/Screenshot 2026-04-02 175205.png>)

*Zooming in to check the key positions matched the ANSI standard.*

---

### Step 2: Routing the Electrical Design

With the layout sorted, I moved on to the actual circuit. The biggest challenge here was getting the diodes right — every single switch needs a 1N4148 diode to prevent *ghosting*, where pressing multiple keys at once causes phantom keypresses you didn't intend.

I wired the rows to the Pico's output pins and the columns to the input pins with pull-up resistors, routing traces between them carefully so nothing shorted.

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

![](<images/Screenshot 2026-04-03 162517.png>)

*The PCB routing in progress — getting all those traces to play nicely together.*

![](<images/Screenshot 2026-04-03 162530.png>)

*Checking the diode footprints before committing to the final layout.*

![](<images/Screenshot 2026-04-03 162539.png>)

*A small but important detail — confirming the diode orientation was consistent.*

---

### Step 3: Designing the Case

The PCB needed a home. I designed a case that would hold the PCB, the Raspberry Pi Pico, and all 60 switches — keeping everything rigid, protected, and not ugly.

This part took more iteration than I expected. Getting the mounting holes and switch cutouts to line up precisely with the PCB took a few rounds of tweaking.

![](<images/Screenshot 2026-04-03 173027.png>)

*The case design coming together — cutouts aligned with the switch matrix.*

![](<images/Screenshot 2026-04-03 173038.png>)

*A closer look at how the Pico sits inside the case.*

---

### Step 4: Putting It All Together

This was the most satisfying part. I soldered the diodes onto each switch one by one, then ran the row and column wires, and finally connected the Raspberry Pi Pico. Once everything was wired up I slotted the PCB into the case and gave it a first test.

![](<images/Screenshot 2026-04-03 193041.png>)

*The assembled board — soldering complete, everything seated in the case.*

![](<images/Screenshot 2026-04-03 193055.png>)

*A wider view of the finished build before the keycaps went on.*

![](<images/Screenshot 2026-04-03 193108.png>)

*The completed keyboard, keycaps on, ready to type.*

---

### Step 5: Flashing the Firmware

I used QMK — an open-source keyboard firmware framework — to program the Pico. I set up two layers:

- **Layer 0:** Standard QWERTY layout for everyday typing
- **Layer 1:** Function keys (F1–F12), navigation arrows, and media controls — all accessible by holding `Fn`

---

### Step 6: Testing Every Key

Plugged it in via USB and went through every single key to make sure the matrix was reading correctly, no ghosting, no stuck keys. It worked first try (well, after fixing one dodgy solder joint on the `B` key).

---

## The Files

Here's what makes this keyboard tick:

| File | What it does |
|------|-------------|
| `config.h` | Tells QMK which GPIO pins are rows and columns |
| `keymaps/default/keymap.c` | Defines the QWERTY layout and function layer |
| `rules.mk` | Build configuration for the Pico |
| `info.json` | Keyboard metadata for QMK tools |

---

## Building the Firmware Yourself

If you want to compile and flash the firmware:

```bash
qmk compile -kb mechanical_keyboard -km default
```

This produces a `.uf2` file. Hold `BOOTSEL` on the Pico while plugging it in, and it mounts as a drive — just drag the `.uf2` onto it.

---

## Key Mappings

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

---

## Troubleshooting

### A key isn't responding
- Check the solder joint at the switch — a cold joint is the most common culprit
- Verify the diode is in the right orientation (stripe = cathode, pointing toward the column)
- Use a multimeter to test continuity from row through diode to column

### A key types the wrong character
- Check the row/column position in `keymap.c` against the physical layout
- Recompile and reflash the firmware

### Multiple keys activate at once (ghosting)
- A diode is likely missing or reversed — check every switch
- Inspect for solder bridges between traces

### The computer doesn't detect the keyboard
- Put the Pico into bootloader mode (hold `BOOTSEL` while plugging in)
- Make sure you're using a data USB cable, not a charge-only one
- Try a different USB port
- Check that QMK compiled without errors

