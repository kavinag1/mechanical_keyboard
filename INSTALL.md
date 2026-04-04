# QMK Installation & Building Guide

This guide explains how to compile and flash your 60% mechanical keyboard firmware using QMK.

## Prerequisites

- Raspberry Pi Pico microcontroller
- USB cable (Micro-USB for Pico)
- A computer with Python 3.8 or newer
- Git installed
- Text editor (VS Code recommended)

## Step 1: Install QMK

### On Windows (via WSL or native)

**Using native Windows:**

1. Install Python 3.8+ from [python.org](https://www.python.org)
2. Install Git for Windows from [git-scm.com](https://git-scm.com)
3. Install the QMK CLI:

```bash
pip install qmk
```

4. Set up QMK:

```bash
qmk setup
```

This clones the main QMK repository.

### On macOS

1. Install Homebrew from [brew.sh](https://brew.sh)
2. Install Python and Git:

```bash
brew install python git
```

3. Install QMK:

```bash
pip install qmk
```

4. Set up QMK:

```bash
qmk setup
```

### On Linux (Ubuntu/Debian)

```bash
sudo apt install git python3 python3-pip
pip install qmk
qmk setup
```

## Step 2: Clone Your Keyboard Repository

After QMK is set up, clone this keyboard repository into QMK's keyboards directory:

```bash
cd ~/qmk_firmware/keyboards
git clone https://github.com/yourusername/mechanical-keyboard-pico.git mechanical_keyboard
cd mechanical_keyboard
```

Or if you already have the code elsewhere, copy it:

```bash
cp -r /path/to/mechanical_keyboard ~/qmk_firmware/keyboards/
```

## Step 3: Test the Build Environment

```bash
qmk compile -kb mechanical_keyboard -km default
```

If successful, this will create a `.uf2` file in the build directory:
```
.build/mechanical_keyboard_default.uf2
```

### Troubleshooting Build Issues

If you get errors, try:

1. Update QMK:
```bash
cd ~/qmk_firmware
git pull
qmk setup --update
```

2. Clear the build directory:
```bash
rm -rf .build
```

3. Recompile with verbose output:
```bash
qmk compile -kb mechanical_keyboard -km default -v
```

## Step 4: Wire Your Keyboard Hardware

### GPIO Connections

Wire your 60% keyboard matrix to the Pico according to [docs/PINOUT.md](docs/PINOUT.md):

**Rows:** Connect to GPIO13-GPIO17
**Columns:** Connect to GPIO0-GPIO12 and GPIO18

Each switch should have a 1N4148 diode soldered in series.

### Test Solder Joints

- Use a multimeter to verify continuity
- Check for shorts between adjacent rows/columns
- Verify all diodes are in the correct orientation

## Step 5: Flash the Firmware

### Prepare Your Pico

1. **Hold the BOOTSEL button** on your Raspberry Pi Pico
2. **While holding BOOTSEL**, plug the Pico into your computer via USB
3. A drive named `RPI-RP2` will appear

### Copy the Firmware

1. Locate the compiled `.uf2` file:
   ```
   .build/mechanical_keyboard_default.uf2
   ```

2. **Drag and drop** (or copy) the `.uf2` file to the `RPI-RP2` drive

3. The Pico will automatically reboot and run the firmware

### Verify Installation

1. Plug the Pico into your computer (any USB port, any computer)
2. Open a text editor
3. Press keys on your keyboard
4. Characters should appear as expected

## Compiling Different Keymaps

To compile with a different keymap:

```bash
qmk compile -kb mechanical_keyboard -km your_keymap_name
```

To create a new keymap:

1. Create a directory:
```bash
mkdir keyboards/mechanical_keyboard/keymaps/gaming
```

2. Copy the default keymap:
```bash
cp keyboards/mechanical_keyboard/keymaps/default/keymap.c keyboards/mechanical_keyboard/keymaps/gaming/
```

3. Edit `gaming/keymap.c` with your custom layout

4. Compile:
```bash
qmk compile -kb mechanical_keyboard -km gaming
```

## Development Workflow

### Quick Compile & Flash Loop

1. Edit your keymap in `keymaps/default/keymap.c`
2. Compile:
```bash
qmk compile -kb mechanical_keyboard -km default
```
3. Flash to Pico (hold BOOTSEL, drag .uf2 file)
4. Test
5. Repeat

### Version Control

Once you have a working setup, commit your changes:

```bash
git add -A
git commit -m "Add custom keymap"
git push
```

## Customization Guide

See [docs/CUSTOMIZATION.md](docs/CUSTOMIZATION.md) for detailed instructions on:
- Changing key assignments
- Adding new layers
- Creating macros
- Enabling hardware features

See [docs/PINOUT.md](docs/PINOUT.md) for:
- GPIO pin assignments
- Physical matrix layout
- Troubleshooting key press issues

## Enabling Features

### RGB Underglow

1. Update `config.h`:
```c
#define RGB_DI_PIN GP26
#define RGBLED_NUM 64
```

2. Enable in `rules.mk`:
```makefile
RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = ws2812
```

3. Recompile

### Per-Key RGB

1. Update `config.h`:
```c
#define RGB_MATRIX_ENABLE
#define RGB_MATRIX_DRIVER ws2812
```

2. Enable in `rules.mk`:
```makefile
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
```

### OLED Display

1. Update `config.h`:
```c
#define OLED_DRIVER_ENABLE
#define I2C_DRIVER I2C1
```

2. Enable in `rules.mk`:
```makefile
OLED_DRIVER_ENABLE = yes
I2C_ENABLE = yes
```

For full examples, see the [QMK Documentation](https://docs.qmk.fm/).

## Troubleshooting

### Firmware won't compile
- Ensure QMK is properly installed: `qmk doctor`
- Check file paths - they're case-sensitive on Linux/Mac
- Try `qmk setup --update`

### Keyboard not recognized after flashing
- Verify the `.uf2` file copied successfully
- Try a different USB cable
- Try a different USB port
- Hold BOOTSEL again and reflash

### Wrong keys responding
- Check [docs/PINOUT.md](docs/PINOUT.md) for matrix layout
- Verify GPIO pin assignments in `config.h`
- Test matrix with `DEBUG_MATRIX_SCAN_RATE` enabled
- Check for solder bridges between row/column traces

### Some keys don't work
- Check for bad diodes (reversed polarity?)
- Check for cracked traces on PCB
- Test continuity with multimeter
- Verify debounce settings in `config.h`

### Double-presses or ghosting
- Increase `DEBOUNCE` value in `config.h`
- Verify all diodes are installed
- Check diode orientation (stripe toward column)

## QMK Documentation

For more detailed information:

- [QMK Overview](https://docs.qmk.fm/)
- [Keyboard Guidelines](https://docs.qmk.fm/newbs)
- [Keycodes](https://docs.qmk.fm/keycodes)
- [Features](https://docs.qmk.fm/features)
- [RP2040 Documentation](https://docs.qmk.fm/platformdev_rp2040)

## Next Steps

1. ✅ Build and flash the default firmware
2. 📝 Customize your keymap in `keymaps/default/keymap.c`
3. 🎮 Create additional keymaps for gaming, coding, etc.
4. 🔧 Enable features like RGB LEDs or OLED displays
5. 📤 Push your changes to GitHub!

Enjoy your custom mechanical keyboard! 🎹
