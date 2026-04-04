# Installation & Flashing Guide

## Prerequisites

- Raspberry Pi Pico microcontroller
- USB cable (USB-A to Micro-USB)
- Computer with USB port
- Text editor (VS Code recommended)

## Step 1: Flash CircuitPython onto Pico

### Download CircuitPython

1. Go to [circuitpython.org](https://circuitpython.org)
2. Find and download CircuitPython 8.x or newer for **Raspberry Pi Pico**
3. Save the `.uf2` file

### Install on Pico

1. **Hold the BOOTSEL button** on your Pico
2. **While holding BOOTSEL**, plug the Pico into your computer via USB
3. A drive called `RPI-RP2` will appear
4. Drag and drop the CircuitPython `.uf2` file onto the `RPI-RP2` drive
5. Wait for the file to copy and the Pico to reboot
6. A new drive called `CIRCUITPY` will appear - this is your Pico's filesystem

## Step 2: Install Required Libraries

The firmware uses KMK, which needs to be installed on your Pico.

### Option A: Automated Installation (Recommended)

1. Download KMK from: https://github.com/KMKfw/kmk_firmware/releases
2. Download the `.zip` file
3. Extract and copy the `kmk` folder to the `CIRCUITPY` drive

### Option B: Manual Installation

1. Go to [KMK GitHub](https://github.com/KMKfw/kmk_firmware)
2. Click "Code" → "Download ZIP"
3. Extract the zip file
4. Copy the `kmk` folder to your `CIRCUITPY` drive

## Step 3: Copy Firmware Files

1. Take the firmware files from this project:
   - `kb.py`
   - `boot.py`
   - `config.py`
   - `keymap.py`

2. Copy these files to the root of your `CIRCUITPY` drive

### Your CIRCUITPY drive should look like:

```
CIRCUITPY/
├── boot.py
├── kb.py
├── config.py
├── keymap.py
├── kmk/  (from KMK installation)
└── docs/
    ├── pinout.md
    ├── keycodes.md
    └── customization.md
```

## Step 4: Wire Your Keyboard Matrix

Follow the pinout guide in `docs/pinout.md` to wire your keyboard:

- Connect rows to output pins (GP0-GP4)
- Connect columns to input pins (GP5-GP14)
- Use diodes at each switch to prevent ghosting

## Step 5: Test the Firmware

1. Connect your Pico to your computer
2. Open a serial monitor (e.g., using Thonny IDE or Python serial tools)
3. You should see:
   ```
   CircuitPython boot complete. Loading keyboard firmware...
   Keyboard firmware loaded!
   ```

4. Press keys on your keyboard matrix - they should appear in the serial output

## Step 6: Test in OS

1. Plug your Pico into a computer (different from the one you're developing on, or just any computer)
2. Open a text editor (Notepad, Word, etc.)
3. Press keys on your keyboard
4. They should type the characters defined in your keymap

## Troubleshooting

### Firmware not loading
- Check that all files are copied to CIRCUITPY drive
- Verify CircuitPython 8.x or newer is installed
- Check the serial output for error messages

### No CIRCUITPY drive appearing
- Hold BOOTSEL and replug the Pico
- Try a different USB cable
- Try a different USB port

### Wrong key codes
- Review your `config.py` row/column pin assignments
- Check that diodes are installed correctly
- Test individual matrix positions

### Keys not responding
- Verify wiring matches `config.py`
- Check row pins can source current properly
- Verify column pins have pull-ups (built into KMK)

## Next Steps

Once your keyboard is working:

1. **Customize keymaps** - Edit `keymap.py` to change keys
2. **Add layers** - Create additional layers for gaming/coding
3. **Configure settings** - Adjust debounce, brightness, etc. in `config.py`
4. **Add features** - Enable RGB LEDs, OLED display, etc.

See `docs/customization.md` for more detailed customization instructions.

## Additional Resources

- [CircuitPython Documentation](https://docs.circuitpython.org/)
- [KMK Firmware GitHub](https://github.com/KMKfw/kmk_firmware)
- [Raspberry Pi Pico Documentation](https://www.raspberrypi.com/documentation/)
- [KMK Features](https://github.com/KMKfw/kmk_firmware/tree/master/docs)
