# Building My Own 60% Mechanical Keyboard with a Raspberry Pi Pico

I have been wanting a mechanical keyboard. So instead of buying one why not make one. This was not really a easy journey but I am proud of what all I have learnt

---

## The Journey

### Step 0: Deciding the keyboard (1hr)
Over the past few days, I researched different types of keyboards to decide what I want to build. I compared layouts like 40%, 60%, 65%, and TKL, and chose a 60% layout because it offers a good balance between size and functionality while still being manageable to design. I also looked at existing open-source designs like the CO60 to understand how keyboard PCBs are structured and to confirm standard design practices.

I also researched switches, connectivity, and firmware. I selected EPOMAKER Creamy Jade switches because they are MX-style and compatible with standard footprints. I decided to make the keyboard wired instead of wireless to reduce complexity and allow me to use QMK firmware more easily.

The final specifications of my keyboard include a 60% layout, MX-style 5-pin switches, a row-column matrix with 1N4148 diodes, USB-C connectivity, and an STM32-based microcontroller. I will also include a rotary encoder for extra functionality and simple per-key backlighting. This research helped me clearly define my design before moving on to the PCB stage.

### Step 1: Learning What a Keyboard Matrix Is (1.5hr)

so before I could build this keyboard I needed to pratice what keyboard matrix is and understand how it works. So I followed a tutorial to make a simple and easy 3 by 3 keybaord matrix like the one you can see in the image. Keyboard matrix allows you to add more keys and use less number of pins like here I used 9 keys but only used 6 pins. This would be useful in the future when making the actual keyboard cause raspberry pico has only so many number of pins.

![](<images/Screenshot 2026-04-02 175157.png>)
![](<images/Screenshot 2026-04-02 175205.png>)
Once I understood the concept, I mapped out the full 60-key layout I wanted to build — a standard 60% ANSI arrangement: 5 rows and 14 columns.
this is the layout of the keyboard I went with

![](<images/Screenshot 2026-04-02 194001.png>)



![](<images/Screenshot 2026-04-03 162539.png>)

---

### Step 2: Designing the Schematic (2hr)

now after finalising the layout of my keyboard I needed to make the schematic of the keyboard. each key would need a switch and then a diode connected to it to prevnt phantom keypresses as if the diode are not present, when you are pressing multiple keys some keys you didnt press will also register and we dont want that. So I arranged the keys in a form of a matrix then conected the rows and collom pins to my GPIO pin in the pico. and then I also added a oled screen and a knob for the keyabord cause why not.

![](<images/Screenshot 2026-04-12 173455.png>)


---

### Step 3: Routing the PCB (1hr)

With the schematic done, I moved on to laying out and routing the actual PCB. 
![](<images/Screenshot 2026-04-12 173311.png>)



![](<images/Screenshot 2026-04-12 173603.png>)

the peices I used are given in the BOM if you want to use the same parts

---

### Step 4:Writing the firmware (1.3hr)

The firmware was developed to act as the core software controlling the mechanical keyboard. I configured the keyboard's key matrix so that every physical switch was correctly mapped to its corresponding keycode and created a custom keymap defining the functionality of each key. 

### Step 5: adding the screen and the knob (3hr)

later on I wanted to add the knob and scren as well. for which I had to change the entire PCB again as I need to create more space for both of them. It took me some time to get the pcb right again. So I had to reroute all the wires makwe the scehmatic again and finally I was able to make it. I also had to make changes to the firmware code.

### Step 6: Designing the Case (2hr + 2hr)

I designed the case two times first was without the screen and the knob and was very basic because I spent time figuuring out how to add the spaces for the keyboard in the first design and then later I changed it to a more ergonomic design.

Then the final step was designing the case itself. For this I would reccomened exporting the PCB as a stl file and adding it in your cad to see if it fits your case or not. It saved me multiple times as I messed up the dimensions but this is the final case I eneded up with which perectly fits the PCB inside. for the case as you can see I went with a open desgin wherethe top part is open so that i can somewhat see the PCB just to remind me this is something I have created on my own.

![](<images/Screenshot from 2026-05-10 15-09-00.png>)



![](<images/Screenshot from 2026-05-10 15-09-43.png>)



![](<images/Screenshot 2026-04-12 175245.png>)


### Step 7: making the case cooler (2hr)

after desiging the case I though of adding something on the back. For that I decided an engraving of the character brook from one peice./ So for that first i found and took inpiration from an arrt to create one fro the aspoect ratio of my keyboard. After which I uploaded the art on inkscape where i made the bitmap of the art. then i saved it as a dxf file which then I imported on onshape. AFter importing I resized itg and placed it on my case. I tried to extrude the whole sketch as it is but that didnt work because some part of the sketch broke. So I slowly divided it into difffernt parts and did it one by one. Overall I am pretty happy with the design.

![](<images/Screenshot from 2026-07-24 20-30-13.png>)
![](<images/Screenshot from 2026-07-24 20-30-27.png>)


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
| PCB | It is the pcb of the keyboard | 5 | $64 | JLCPCB | — |
| **Total** | | | **$121.57** | | |

---

rols.

