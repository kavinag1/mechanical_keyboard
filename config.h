#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCAFE
#define PRODUCT_ID      0xDEAD
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Your Name"
#define PRODUCT         "60% Keyboard"

/* Key matrix size (rows x columns) */
#define MATRIX_ROWS     5
#define MATRIX_COLS     14

/* GPIO pins for rows (RP2040) - Based on your PCB layout */
#define MATRIX_ROW_PINS { GP13, GP14, GP15, GP16, GP17 }

/* GPIO pins for columns (RP2040) - Based on your PCB layout */
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended key presses) - set 0 if debouncing disabled */
#define DEBOUNCE 20

/* Define if matrix has ghost (lacks diodes) */
/* #define MATRIX_HAS_GHOST */

/* Set 0 if debouncing disabled for faster response, 1 if enabled */
#define DEBOUNCE 20

/* Mechanical locking support. Use KC.LCAP, KC.LNUM or KC.LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Prevent modifiers from being stuck on after layer changes */
#define PREVENT_STUCK_MODIFIERS

/* Enable this if you want the keyboard to wake up from suspend. */
/* #define WAKEUP_FQBN "raspberry-pi-pico" */

/* 
 * Feature disable options
 * These options allow you to save program space by removing support
 * for features you know you won't be using.
 */

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* USB polling interval in ms */
#define USB_POLLING_INTERVAL_MS 1

/* Allow 6-key rollover by default (QMK uses NKRO by default on most boards) */
#define FORCE_NKRO

/* RGB LED Support (if using underglow or per-key RGB) */
/* Uncomment and configure if you have RGB LEDs */
/*
#define RGB_DI_PIN GP26
#define RGBLED_NUM 64
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_ANIMATIONS
*/

/* OLED Display Support */
/* Uncomment if you have an OLED display */
/*
#define OLED_DRIVER_ENABLE
#define OLED_DISPLAY_128x64
#define I2C_DRIVER I2C1
#define I2C_DRIVER_REQUIRED
*/

/* Encoder Support */
/* Uncomment if you have rotary encoders */
/*
#define ENCODERS_PAD_A { GP25 }
#define ENCODERS_PAD_B { GP24 }
#define ENCODER_RESOLUTION 4
*/

/* Tap Dance support */
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

/* Split Keyboard Support (for communication between left/right halves) */
/* Uncomment if using a split keyboard */
/*
#define SPLIT_KEYBOARD
#define SPLIT_UART_PINS
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP16
#define SERIAL_USART_RX_PIN GP17
*/
