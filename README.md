# 60% Mechanical Keyboard with Raspberry Pi Pico

## What I Did

1. Designed PCB layout - 5 rows × 14 columns = 60 keys ANSI layout
2. Set up matrix wiring with row pins GP13-17 and column pins GP0-12, GP18
3. Added 1N4148 diodes on each switch for ghost prevention
4. Configured QMK firmware with QWERTY layout and function layer
5. Tested and verified all key presses work correctly

## Wiring

Row pins (outputs): GP13, GP14, GP15, GP16, GP17
Column pins (inputs): GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18

Each switch has a 1N4148 diode to prevent ghosting.

## To Compile

```bash
qmk compile -kb mechanical_keyboard -km default
```
