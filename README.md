# Mechanical Keyboard Firmware - Raspberry Pi Pico

A custom QMK firmware for a 60% mechanical keyboard using Raspberry Pi Pico (RP2040) microcontroller.

## Features

- 60% keyboard layout support (5 rows × 14 columns)
- QMK firmware - powerful and highly customizable
- Raspberry Pi Pico (RP2040) based
- USB HID keyboard support
- Multiple layers for extended functionality
- Easy customization and compilation with QMK
- Support for macros, tap dance, and more

## Hardware Specifications

**Microcontroller:** Raspberry Pi Pico (RP2040)

**Matrix Layout:**
- Rows: 5 (GPIO13-GPIO17)
- Columns: 14 (GPIO0-GPIO12, GPIO18)
- Total Keys: 60 keys (standard 60% layout)

**GPIO Pin Assignment:**

| Function | GPIO Pins |
|----------|-----------|
| Rows (Output) | GP13, GP14, GP15, GP16, GP17 |
| Columns (Input) | GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18 |

## Keyboard Layout

```
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
│Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bcksp │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┬──┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \   │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────┬──┤
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │    │ En│
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼──┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ /  Shift   │  │
├────┬───┴┬──┴───┴───┴───┴───┴───┴───┴──┬┴───┼───────┬───┬──┤
│Ctrl│Win │         Space               │ Alt│ Win/Fn│ Ctl│  │
└────┴────┴──────────────────────────────┴────┴───────┴────┘
```

## Installation

### Prerequisites

- Raspberry Pi Pico microcontroller
- USB cable (Micro-USB for Pico)
- QMK firmware build environment
- Python 3.8+

### Step 1: Set Up QMK

1. Clone the QMK firmware repository:
```bash
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
make git-submodule
```

2. Run the QMK setup:
```bash
qmk setup
```

### Step 2: Add Your Keyboard to QMK

1. Copy this project into the QMK keyboards directory:
```bash
cp -r /path/to/mechanical-keyboard-pico keyboards/mechanical_keyboard
```

Or clone directly:
```bash
cd keyboards
git clone https://github.com/yourusername/mechanical-keyboard-pico.git mechanical_keyboard
cd ..
```

### Step 3: Compile the Firmware

```bash
qmk compile -kb mechanical_keyboard -km default
```

This creates a `.uf2` file that can be flashed to your Pico.

### Step 4: Flash the Firmware

1. Hold the **BOOTSEL** button on your Pico
2. Plug the Pico into your computer via USB
3. A drive named `RPI-RP2` will appear
4. Copy the generated `.uf2` file to this drive
5. The Pico will automatically reboot with the new firmware

### Step 5: Wire Your Keyboard

Connect your keyboard matrix to the Pico according to the pin assignments:

**Rows (GPIO13-GPIO17):** Connect to row scan lines
**Columns (GPIO0-GPIO12, GPIO18):** Connect to column scan lines with pull-up resistors

Each switch should have a diode connected to prevent ghosting.

## Customization

### Changing Keymaps

Edit `keymaps/default/keymap.c` to customize your keys:

```c
[0] = {
    {KC_ESC, KC_1, KC_2, ... },
    // ... more rows
}
```

### Adding Layers

Add new layer definitions in `keymap.c`:

```c
[2] = {
    // Your layer definition
}
```

### Modifying Configuration

Edit `config.h` to adjust:
- Debounce time
- Report interval
- Feature enablement
- RGB LED settings (if applicable)

Edit `rules.mk` to enable/disable features:
- `MOUSEKEY_ENABLE` - Mouse key support
- `EXTRAKEY_ENABLE` - Media controls
- `NKRO_ENABLE` - N-Key Rollover

## Building for Different Keymaps

To compile with a different keymap:

```bash
qmk compile -kb mechanical_keyboard -km your_keymap_name
```

## Testing

After flashing, verify your keyboard:

1. Plug into your computer
2. Open a text editor
3. Press keys - they should produce the expected characters
4. Check that the FN layer works (press Right Alt to activate layer 1)

## Troubleshooting

### Firmware won't compile
- Ensure QMK is properly installed: `qmk setup`
- Check that all files are in the correct directories
- Verify Python 3.8+ is installed

### Keyboard not recognized
- Verify USB cable and port
- Check that the `.uf2` file was copied successfully
- Try replugging the Pico while holding BOOTSEL

### Wrong keys
- Check GPIO pin assignments in `config.h` match your PCB
- Verify matrix wiring
- Test individual rows/columns for shorts

### Some keys not responding
- Check for cold solder joints
- Verify diodes are installed correctly
- Test debounce settings in `config.h`

## Resources

- [QMK Firmware Documentation](https://docs.qmk.fm/)
- [QMK Keyboard Guidelines](https://docs.qmk.fm/newbs)
- [Raspberry Pi Pico Documentation](https://www.raspberrypi.com/documentation/)
- [RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)

## File Structure

```
mechanical_keyboard/
├── README.md                 # This file
├── config.h                  # Hardware configuration
├── rules.mk                  # Build rules and features
├── info.json                 # Keyboard metadata
├── keymaps/
│   └── default/
│       └── keymap.c         # Default keymap
└── docs/
    ├── PINOUT.md            # GPIO pinout reference
    └── CUSTOMIZATION.md     # Customization guide
```

## License

MIT License - See LICENSE file for details

## Support

For issues and questions, please open an issue on GitHub.

