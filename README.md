# Mechanical Keyboard Firmware - Raspberry Pi Pico

A custom firmware for a 60% mechanical keyboard using Raspberry Pi Pico microcontroller.

## Features

- 60% keyboard layout support
- CircuitPython-based firmware using KMK
- Customizable key mappings
- Layer support for extended functionality
- Easy to modify and extend
- USB HID keyboard support

## Hardware Requirements

- Raspberry Pi Pico (RP2040)
- 60% mechanical keyboard PCB compatible with Pico
- USB cable (for Pico)
- Firmware files and key switches

## Installation

### 1. Flash CircuitPython onto Pico

1. Download CircuitPython for Pico from [circuitpython.org](https://circuitpython.org)
2. Hold BOOTSEL button on Pico and plug into USB
3. Copy the `.uf2` file to the RPI-RP2 drive that appears
4. Wait for automatic reboot

### 2. Install KMK and Dependencies

1. Clone this repository to your Pico's CIRCUITPY drive:
```bash
cd /Volumes/CIRCUITPY  # macOS
# or cd /d/         # Windows

git clone https://github.com/yourusername/mechanical-keyboard-pico.git firmware
```

2. Or manually copy the files from `/firmware` directory to CIRCUITPY drive

### 3. Wire Your Keyboard Matrix

Connect your keyboard matrix to the Pico GPIO pins as defined in `config.py`:
- Row pins: GP0-GP4 (5 rows for 60% keyboard)
- Column pins: GP5-GP14 (10 columns for 60% keyboard)

### 4. Start Using Your Keyboard

Once the files are copied, the Pico will load the firmware automatically. Your keyboard should be recognized as a standard USB HID keyboard by your computer.

## File Structure

```
.
├── README.md                 # This file
├── config.py                 # Keyboard configuration
├── kb.py                     # Main firmware entry point
├── keymap.py                 # Key mappings and layers
├── firmware/
│   ├── kmk/                  # KMK library
│   ├── circuitpython/        # CircuitPython modules
│   └── boot.py               # Boot sequence
└── docs/
    ├── pinout.md             # GPIO pinout reference
    ├── keycodes.md           # Available keycodes
    └── customization.md      # Customization guide
```

## Configuration

Edit `config.py` to customize:
- GPIO pin assignments
- Keyboard matrix layout
- Debounce settings
- LED configuration

Edit `keymap.py` to customize:
- Key assignments
- Layer configurations
- Macros and shortcuts

## Development

### Requirements
- Python 3.8+
- CircuitPython 8.0+ installed on Pico

### USB Serial Connection (Debugging)

Connect via Serial to view debug output:
```bash
python -m serial.tools.miniterm /dev/ttyACM0 115200
```

## Troubleshooting

### Keyboard not recognized
- Check USB connection
- Verify CircuitPython is properly installed
- Check GPIO pin connections

### Keys not responding
- Verify matrix wiring matches config.py
- Check for shorted connections
- View REPL output for debug information

### Wrong keys being detected
- Review keymap assignments in keymap.py
- Test individual rows and columns
- Check for debounce issues

## Contributing

Feel free to open issues and pull requests!

## License

MIT License - See LICENSE file for details

## Resources

- [KMK Firmware](https://github.com/KMKfw/kmk_firmware)
- [CircuitPython Documentation](https://docs.circuitpython.org/)
- [Raspberry Pi Pico Pinout](https://datasheets.raspberrypi.com/pico/Pico-R3_A2_1_6.23620527.pdf)

## Support

For questions and support, please open an issue on GitHub.
