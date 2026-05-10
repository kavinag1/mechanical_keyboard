# Building My Own 60% Mechanical Keyboard with a Raspberry Pi Pico

I have been wanting a mechanical keyboard. So instead of buying one why not make one. This was not really a easy journey but I am proud of what all I have learnt

---

## The Journey

### Step 1: Learning What a Keyboard Matrix Is

so before I could build this keyboard I needed to pratice what keyboard matrix is and understand how it works. So I followed a tutorial to make a simple and easy 3 by 3 keybaord matrix like the one you can see in the image. Keyboard matrix allows you to add more keys and use less number of pins like here I used 9 keys but only used 6 pins. This would be useful in the future when making the actual keyboard cause raspberry pico has only so many number of pins.

![](<images/Screenshot 2026-04-02 175157.png>)
![](<images/Screenshot 2026-04-02 175205.png>)
Once I understood the concept, I mapped out the full 60-key layout I wanted to build — a standard 60% ANSI arrangement: 5 rows and 14 columns.
this is the layout of the keyboard I went with

![](<images/Screenshot 2026-04-02 194001.png>)



![](<images/Screenshot 2026-04-03 162539.png>)

---

### Step 2: Designing the Schematic

With the matrix planned, I moved on to the electrical schematic. The biggest challenge was getting the diodes right — every single switch needs a 1N4148 diode to prevent *ghosting*, where pressing multiple keys at once causes phantom keypresses you didn't intend.

I wired the rows to the Pico's output pins and the columns to the input pins with pull-up resistors.

**Pin Assignments:**
- Row pins (outputs): GP13, GP14, GP15, GP16, GP17
- Column pins (inputs): GP0–GP12, GP18
- OLED SCL: GP26 | OLED SDA: GP25 (I2C1)
- Encoder A: GP27 | Encoder B: GP29
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

![](<images/Screenshot 2026-04-12 173455.png>)

*Updated schematic showing the Pico pin mapping, OLED, encoder, and matrix wiring.*

---

### Step 3: Routing the PCB

With the schematic done, I moved on to laying out and routing the actual PCB. Getting all the traces to fit cleanly without shorts — especially around the diode footprints — took a fair bit of iteration.

![](<images/Screenshot 2026-04-12 173311.png>)

*PCB routing in progress, with the switch matrix and controller area cleaned up for manufacture.*

![](<images/Screenshot 2026-04-12 173603.png>)

*A 3D PCB render used to check component placement and the overall board shape.*

---

### Step 4: Designing the Case

The PCB needed a home. I designed a case that would hold the PCB, the Raspberry Pi Pico, and all 60 switches — keeping everything rigid, protected, and not ugly.

Getting the mounting holes and switch cutouts to line up precisely with the PCB took a few rounds of tweaking.

![](<images/Screenshot 2026-04-12 175226.png>)

*Top case layout showing the switch cutouts and mounting points.*

![](<images/Screenshot 2026-04-12 175235.png>)

*Exploded case view used to verify the PCB fit and controller clearance.*

![](<images/Screenshot 2026-04-12 175245.png>)

*Top-down case fit check with the cutouts aligned to the keyboard layout.*



## Bill of Materials

| Component | Purpose | Qty | Cost (USD) | Distributor | Link |
|-----------|---------|-----|-----------|-------------|------|
| Screen | The screen for the keyboard | 1 | $1.56 | Tech Delivers | [Buy](https://techdelivers.com/0-91-inch-oled-lcd-display-module-blue-128x32-i2c-iic-serial?tag=i2c%20lcd) |
| Micro USB Cable | To connect the Pico | 1 | $1.62 | Amazon | [Buy](https://www.amazon.in/Ambrane-Unbreakable-Charging-Braided-Android/dp/B082LZGK39/) |
| M2 Heat Set Inserts | For case assembly | 1 pack | $3.31 | Amazon | [Buy](https://www.amazon.in/BRASS-WAREHOUSE-Knurled-Threaded-Printing/dp/B0FMPZ3QHL/) |
| M2 Screws (20 pack) | Screwing the case | 1 pack | $1.93 | Amazon | [Buy](https://www.amazon.in/Tia-Golden-Screws-Length-Approx-480pcs/dp/B07VWKBHYZ/) |
| Keycaps | Keycaps for the keyboard | 1 set | $10.76 | Meckeys | [Buy](https://meckeys.com/shop/accessories/keyboard-accessories/keycaps/grey-black-keycaps/) |
| Gateron Switches | Switches for the keys | 7 packs | $15.12 | Meckeys | [Buy](https://meckeys.com/shop/accessories/keyboard-accessories/key-switches/gateron-optical-switch-pack/) |
| Raspberry Pi Pico | The brain | 1 | $4.00 | Robu.in | [Buy](https://robu.in/product/raspberry-pi-pico/) |
| 3D Printed Case | The case | 1 | $16.18 | Robo In | — |
| DIODE | Its the diode for the circuit | 1 | $3.08 | Amazon | [Buy](https://www.amazon.in/Circuit-Ranger-Switching-Electronic-Projects/dp/B0FJLP12GX) |
| PCB | It is the pcb of the keyboard | 5 | $36.01 | JLCPCB | — |
| **Total** | | | **$93.57** | | |

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

