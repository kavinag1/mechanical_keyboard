# 60% Mechanical Keyboard - Complete Build & Firmware Guide

A comprehensive guide to designing, building, and programming a custom 60% mechanical keyboard with Raspberry Pi Pico (RP2040) microcontroller running QMK firmware.

---

## ✨ Overview

This project documents the complete process of creating a professional-grade 60% mechanical keyboard from scratch, including:
- **Case Design** - CAD model for 3D printing or CNC
- **PCB Design** - KiCad schematic and layout with Pico integration
- **Assembly Guide** - Step-by-step instructions for building
- **Firmware** - QMK-based customizable firmware
- **Documentation** - Comprehensive guides for others to replicate

---

## 📐 Design Process

### 1. Case Design
The keyboard case is designed with a clean, minimalist aesthetic featuring:
- **Top portion**: Keycap layout area with mounting points
- **Bottom portion**: PCB and electronics housing
- **Frame**: Solid frame for structural integrity
- **Mounting positions**: Precise alignment for 60-key standard layout

You can design your own case using:
- **Fusion 360** (free for personal use) - Professional CAD
- **FreeCAD** - Free and open-source
- **Tinkercad** - Browser-based and beginner-friendly

Export as **STL** for 3D printing or **DWG** for CNC machining.

### 2. PCB Design & Schematic
The PCB is the heart of the keyboard. Our design uses KiCad and includes:

**Layout:**
- **60 switch footprints** in standard ANSI layout
- **Diode pads** on every switch position (for ghost prevention)
- **GPIO header** for connecting Pico microcontroller
- **Row/Column trace routing** to separate pins
- **Industrial-grade design** from professional KiCad

**Key Features:**
- 5 row lines (GPIO13-17)
- 14 column lines (GPIO0-12, GPIO18)
- 1N4148 diode on every switch
- Pull-up resistor support on column lines
- Proper layer stackup and trace width for reliable scanning

**Design Steps:**
1. Create schematic in **KiCad** showing switch matrix
2. Add Pico microcontroller connections
3. Route PCB with proper trace isolation
4. Generate Gerber files for manufacturing
5. Order PCB from JLCPCB, PCBWay, or similar ($20-50 for 5 boards)

### 3. Switch Matrix Circuit
Each key in the matrix consists of:

```
     Row Output (GP13-17)
              ↓
          ┌────────┐
    ┌─────┤ Switch ├─────┬─── Column Sense (GP0-12, GP18)
    │     └────────┘     │
    │                    │
   Anode              Cathode
    │                    │
    └──[1N4148 Diode]────┘
```

**Why diodes?**
- Prevent "ghosting" - multiple unintended key presses
- Allow multiple simultaneous key presses (NKRO)
- Protect from electrical noise

---

## 🎹 Keyboard Layout

**Standard 60% ANSI Layout:**
```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
│Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bcksp │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┬──┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┬──┤
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │    │ En│
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼──┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ /  Shift   │  │
├────┬───┴┬──┴───┴───┴───┴───┴───┴───┴──┬┴───┼────────┬───┬──┤
│Ctrl│Win │         Space               │ Alt│ Win/Fn │Ctl│  │
└────┴────┴──────────────────────────────┴────┴────────┴────┘
```

**Matrix Coordinates:**
- 5 rows × 14 columns = 60 keys total
- Standard ANSI-compliant layout
- Compatible with any 60% keycap set

---

## 🛠️ Step-by-Step Build Guide

### Phase 1: Firmware & Pico Setup

#### Step 1.1: Install QMK
Choose your OS:

**Windows:**
```bash
pip install qmk
qmk setup
```

**macOS:**
```bash
brew install python
pip install qmk
qmk setup
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt install python3 python3-pip
pip install qmk
qmk setup
```

#### Step 1.2: Add This Keyboard
```bash
cd ~/qmk_firmware/keyboards
git clone https://github.com/yourusername/mechanical-keyboard-pico.git mechanical_keyboard
cd ~/qmk_firmware
```

#### Step 1.3: Verify GPIO Configuration
Open `keyboards/mechanical_keyboard/config.h` and confirm:
```c
#define MATRIX_ROW_PINS { GP13, GP14, GP15, GP16, GP17 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18 }
```

This MUST match your actual wiring!

### Phase 2: Hardware Assembly

#### Step 2.1: Gather Components

**Microcontroller & Essentials:**
- 1× Raspberry Pi Pico (RP2040) - $4-5
- 1× Micro-USB cable
- Solder & soldering iron (30-40W)
- Wire (22 AWG) for matrix connections

**Switches & Stabilizers:**
- 60× Cherry MX compatible mechanical switches - $30-60
- 1× 7u spacebar stabilizer
- 2× 2.25u shift stabilizers (if using split shift)
- Other stabilizers as needed for layout

**Diodes & Circuit:**
- 60× 1N4148 signal diodes - $3-5
- 14× 10kΩ resistors (optional for pull-ups)
- Breadboard or PCB (custom designed or handwired)

**Tools:**
- Soldering iron & solder
- Solder sucker or solder braid
- Wire strippers
- Multimeter for testing
- Small screwdriver set
- Hot glue gun

**Total Cost Estimate:**
- Pico-based custom PCB: $150-250
- Handwired on breadboard: $80-150
- Full professional PCB + case: $200-400

#### Step 2.2: Design & Manufacture PCB (Option A: Professional)

**Using KiCad:**

1. **Create Schematic:**
   - Draw 60 switch positions with diodes
   - Connect diodes to column lines (14 columns)
   - Connect switches to row lines (5 rows)
   - Wire Pico GPIO connections

2. **Route PCB:**
   - Route rows as one layer/traces
   - Route columns as perpendicular layer
   - Maintain clearance between traces
   - Add mounting holes

3. **Export & Order:**
   - Export as Gerber files
   - Order from JLCPCB.com, PCBWay.com, or similar
   - Typical cost: $20-50 for 5 PCBs + shipping

4. **Receive & Inspect:**
   - Check for manufacturing defects
   - Test continuity with multimeter
   - Store in dry place

#### Step 2.3: Alternative - Handwire on Breadboard (Option B: DIY)

If custom PCB is not available:

1. Use a solderless breadboard
2. Connect Pico pins to breadboard
3. Wire each row/column using jumper wires
4. Mount switches on custom laser-cut mounting plate
5. Solder diodes directly to switch terminals

**Advantages:**
- No waiting for PCB manufacturing
- Easy to prototype and test
- Can modify design on the fly

**Disadvantages:**
- Less reliable than PCB
- More prone to connection issues
- Bulkier wiring setup

#### Step 2.4: Solder Diodes

**Critical: Diode Orientation**
```
         Column Input
              ↑
         Cathode (stripe)
              │
    Anode ─────[1N4148]─────
              │
         Row Input
```

**Procedure:**
1. Bend diode legs into "L" shape
2. Insert into PCB pads (or breadboard)
3. **Stripe MUST face toward column** - this is critical!
4. Solder both legs securely
5. Trim excess leads with wire cutter

**Testing:**
- Use multimeter to verify continuity
- Check no shorts between adjacent columns/rows
- Fix cold solder joints immediately

#### Step 2.5: Solder Column Pull-up Resistors (Optional)

Most Pico pins have internal pull-ups, but for reliability:

1. Take 14× 10kΩ resistors
2. Connect from each column line to 3.3V
3. Solder to PCB or breadboard
4. Test with multimeter

#### Step 2.6: Wire Pico Connections

**Row Pins (Output from Pico):**
```
Row 0 ← GP13 (Pin 17)
Row 1 ← GP14 (Pin 19)  
Row 2 ← GP15 (Pin 20)
Row 3 ← GP16 (Pin 21)
Row 4 ← GP17 (Pin 22)
```

**Column Pins (Input to Pico):**
```
Column 0 ← GP0  (Pin 1)
Column 1 ← GP1  (Pin 2)
Column 2 ← GP2  (Pin 4)
Column 3 ← GP3  (Pin 5)
Column 4 ← GP4  (Pin 6)
Column 5 ← GP5  (Pin 7)
Column 6 ← GP6  (Pin 9)
Column 7 ← GP7  (Pin 10)
Column 8 ← GP8  (Pin 11)
Column 9 ← GP9  (Pin 12)
Column 10 ← GP10 (Pin 13)
Column 11 ← GP11 (Pin 14)
Column 12 ← GP12 (Pin 15)
Column 13 ← GP18 (Pin 24)
```

**Power Connections:**
```
Pico GND ← PCB GND (CRITICAL!)
Pico 3V3 ← PCB 3.3V (if needed for resistors)
```

**Wire Selection:**
- Use 22 AWG solid core wire
- Solder all connections securely
- Use hot glue to secure Pico to PCB
- Double-check connections before power-on

#### Step 2.7: Test Electrical Connections

**BEFORE installing switches:**

1. **Continuity Test:**
   - Use multimeter in continuity mode
   - Test each row line for continuity
   - Test each column line for continuity
   - Verify no shorts between adjacent lines

2. **Pico Connection Test:**
   - Connect Pico to USB
   - Check Pico is recognized by computer
   - Verify no magical smoke appears

3. **Matrix Test:**
   - In QMK REPL or debugging environment
   - Press along a row - should see response
   - Press along a column - should see response

#### Step 2.8: Install Switches

1. Insert stabilizers into mounting holes
2. Clip and secure stabilizer
3. Line up switch with PCB holes
4. Gently press down - should click into place
5. Test by pulling up - requires firm resistance
6. Repeat for all 60 switches

**Pro Tips:**
- Install spacebar stabilizer first (easiest)
- Work systematically - row by row
- Check alignment before pressing fully down
- Don't force switches - they should slide in smooth

#### Step 2.9: Install Keycaps

1. Keycaps should just slide onto switch stems
2. They should be flush with no tilting
3. If loose, the switch may not be fully seated
4. Test by gently pressing down

### Phase 3: Firmware Compilation & Flashing

#### Step 3.1: Compile the Firmware

```bash
qmk compile -kb mechanical_keyboard -km default
```

**Output:** `.build/mechanical_keyboard_default.uf2`

**If errors occur:**
```bash
# Update QMK
cd ~/qmk_firmware
git pull
qmk setup --update

# Clear build cache
rm -rf .build

# Try again with verbose output
qmk compile -kb mechanical_keyboard -km default -v
```

#### Step 3.2: Flash to Pico

1. **Enter bootloader mode:**
   - Hold **BOOTSEL** button on Pico
   - Keep holding, plug into USB
   - Release BOOTSEL
   - Drive `RPI-RP2` should appear

2. **Copy firmware:**
   - Copy `.build/mechanical_keyboard_default.uf2` file
   - Paste into `RPI-RP2` drive
   - Wait for copy to complete
   - Pico reboots automatically

3. **Verify:**
   - Drive `RPI-RP2` should disappear
   - Pico is now running your firmware!

#### Step 3.3: Test the Keyboard

1. Plug Pico into any computer
2. Open text editor or terminal
3. Press keys - they should type!
4. Test each row systematically
5. Test the function layer:
   - Press **Right Alt** or **Right Ctrl** (varies by custom mapping)
   - Try **F-keys** - should control volume/media

---

## 🎮 Customization

### Changing Key Assignments

Edit `keymaps/default/keymap.c`:

```c
[0] = {
    {KC_ESC, KC_1, KC_2, KC_3, /* ... 14 keys per row */},
    {KC_TAB, KC_Q, KC_W, KC_E, /* ... */},
    // ... 5 rows total
}
```

### Creating Alternate Keymaps

1. Create new directory:
```bash
mkdir keyboards/mechanical_keyboard/keymaps/gaming
```

2. Copy default keymap:
```bash
cp keyboards/mechanical_keyboard/keymaps/default/keymap.c keyboards/mechanical_keyboard/keymaps/gaming/
```

3. Edit `gaming/keymap.c` with your custom layout

4. Compile:
```bash
qmk compile -kb mechanical_keyboard -km gaming
```

### Adding Layers

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {  // QWERTY
        {KC_ESC, KC_1, /* ... */},
        // ...
    },
    [1] = {  // Function layer
        {KC_GRV, KC_F1, /* ... */},
        // ...
    },
    [2] = {  // Gaming layer
        {KC_ESC, KC_1, /* ... */},
        // ...
    },
};
```

### Enabling Features

Edit `rules.mk`:
```makefile
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Media controls (volume, play, etc.)
TAP_DANCE_ENABLE = yes      # Double-tap actions
COMBO_ENABLE = yes          # Combo shortcuts
NKRO_ENABLE = yes           # N-Key Rollover (already enabled)
```

See [docs/CUSTOMIZATION.md](docs/CUSTOMIZATION.md) for detailed examples.

---

## 🐛 Troubleshooting

### Compilation Issues
```bash
# Update and retry
qmk setup --update
qmk compile -kb mechanical_keyboard -km default -v

# Clear everything and start fresh
rm -rf .build
cd ~/qmk_firmware
git pull
```

### Keyboard Not Recognized
- **Check USB cable** - try different port
- **Enter bootloader** - hold BOOTSEL and replug
- **Verify Pico** - green LED should blink
- **Check Pico pinout** - firmware may have wrong pin config

### Wrong Keys Responding
1. Note which physical key is wrong
2. Check GPIO mapping in `config.h`
3. Verify matrix wiring matches documentation
4. Test with multimeter for continuity issues

### Some Keys Not Responding
- **Check diode polarity** - stripe must face column
- **Check solder joints** - reflow with iron if needed
- **Test continuity** - use multimeter on row/column lines
- **Check for shorts** - verify adjacent lines aren't touching

### Ghosting or Multiple Keys Pressing
- **Install all diodes** - check none are missing
- **Verify diode orientation** - all stripes facing column
- **Increase debounce** - change in `config.h`: `#define DEBOUNCE 25`
- **Check for shorts** - solder bridges or damaged traces

### Double-Presses on Single Key Press
- **Increase debounce time:**
  ```c
  #define DEBOUNCE 25  // Try 25-30ms
  ```
- **Check switch** - may be defective
- **Check solder** - cold joint on diode leg

---

## 📚 Additional Resources

- [INSTALL.md](INSTALL.md) - Detailed QMK installation guide
- [docs/PINOUT.md](docs/PINOUT.md) - Complete GPIO pinout reference
- [docs/CUSTOMIZATION.md](docs/CUSTOMIZATION.md) - Firmware customization examples

**External Resources:**
- [QMK Firmware Docs](https://docs.qmk.fm/) - Official documentation
- [Raspberry Pi Pico](https://www.raspberrypi.com/documentation/) - Hardware documentation
- [RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf) - Technical details
- [KiCad](https://kicad.org/) - Open-source PCB design software

---

## 📋 Project Structure

```
mechanical_keyboard/
├── README.md                   # This file - Build & customization guide
├── INSTALL.md                  # QMK compilation & flashing guide
├── LICENSE                     # MIT License
├── config.h                    # Hardware pin configuration
├── rules.mk                    # QMK build rules & features
├── info.json                   # Keyboard metadata
├── keymaps/
│   └── default/
│       └── keymap.c           # Default QWERTY + Function layers
└── docs/
    ├── PINOUT.md              # GPIO pinout reference
    └── CUSTOMIZATION.md       # Advanced firmware customization
```

---

## 🚀 Quick Start Checklist

- [ ] Install QMK (`pip install qmk && qmk setup`)
- [ ] Clone keyboard repository into QMK keyboards directory
- [ ] Verify GPIO pins in `config.h` match your wiring
- [ ] Gather components (Pico, switches, diodes, etc.)
- [ ] Solder diodes on PCB/breadboard
- [ ] Wire up Pico GPIO connections
- [ ] Test electrical continuity with multimeter
- [ ] Install switches and keycaps
- [ ] Compile firmware (`qmk compile -kb mechanical_keyboard -km default`)
- [ ] Flash to Pico (hold BOOTSEL, drag .uf2 file)
- [ ] Test keyboard in text editor
- [ ] Customize keymap for your needs
- [ ] Enjoy your custom mechanical keyboard! ⌨️

---

## 📄 License

MIT License - Feel free to modify and share this design

---

## 🙋 Getting Help

**Issues?** Check in this order:
1. [docs/PINOUT.md](docs/PINOUT.md) - Hardware wiring issues
2. [docs/CUSTOMIZATION.md](docs/CUSTOMIZATION.md) - Firmware issues  
3. [QMK Discord](https://discord.gg/Uq7gcHh) - Community support
4. Open an issue on GitHub

---

**Made with ⌨️ and ❤️**  
Enjoy your custom mechanical keyboard!
