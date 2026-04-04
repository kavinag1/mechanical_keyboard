# My 60% Mechanical Keyboard with Raspberry Pi Pico

This is how I built my own mechanical keyboard from scratch using a Raspberry Pi Pico.

## The Build Story

### Step 1: I Made the PCB Layout

I started by designing a 60% keyboard matrix - 5 rows and 14 columns giving me 60 keys total in a standard ANSI layout. This meant figuring out exactly where each switch would go and how the electrical connections would work.

**The Layout I Designed:**
- 5 row lines
- 14 column lines  
- 60 key positions in standard ANSI format

![PCB Layout](images/pcb-layout.png)

### Step 2: I Routed the Electrical Design

Once I had the layout, I had to design the actual circuit. I added 1N4148 diodes on each switch to prevent ghosting (when multiple keys activate unintentionally). Then I routed the traces to connect everything properly.

**The Wiring:**
- Row pins (outputs): GP13, GP14, GP15, GP16, GP17
- Column pins (inputs): GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18
- Each switch connects through a 1N4148 diode cathode to column, anode to row

![PCB Routing](images/pcb-routing.png)
![Diode Connections](images/diode-diagram.png)

### Step 3: I Designed the Case

I designed a case to hold everything together - the PCB, the Pico microcontroller, and all the switches. The case protects the electronics while keeping the keyboard solid and stable.

![Case Design](images/case-design.png)
![Case Assembly](images/case-assembled.png)

### Step 4: I Assembled the Keyboard

Soldered the diodes to each switch. Wired the rows and columns. Connected the Pico microcontroller. Put it all in the case and tested that everything worked.

![Assembly Process](images/assembly-process.png)
![Finished Keyboard](images/finished-keyboard.png)

### Step 5: I Configured the Firmware

I used QMK - an open-source keyboard firmware framework - to program the Pico. I set up:
- Layer 0: Standard QWERTY layout for typing
- Layer 1: Function keys, navigation, and media controls (F1-F12, arrow keys, volume control)

### Step 6: I Tested Everything

Plugged it in via USB and tested every single key to make sure the wiring was correct and nothing was ghosting.

## The Files I Created

Here's what makes this keyboard work:

- **config.h** - Tells QMK which GPIO pins are the rows and columns
- **keymaps/default/keymap.c** - Defines what keys do what (the QWERTY layout and function layer)
- **rules.mk** - Build configuration for the Pico
- **info.json** - Keyboard metadata for QMK tools

## How to Compile It

If you want to build the firmware yourself:

```bash
qmk compile -kb mechanical_keyboard -km default
```

This creates a .uf2 file that you can drag onto the Pico to program it.

## Key Mappings

**Layer 0 (QWERTY):**
```
Esc  1  2  3  4  5  6  7  8  9  0  -  =  Backspace
Tab  Q  W  E  R  T  Y  U  I  O  P  [  ]  \
Caps A  S  D  F  G  H  J  K  L  ;  '  Enter
Shift Z  X  C  V  B  N  M  ,  .  /  Shift
Ctrl Win Alt         Space      Alt Win Ctrl
```

**Layer 1 (Function):**
F-keys, navigation arrows, media controls (accessed by holding Fn)

