#pragma once

#include "config_common.h"

#define VENDOR_ID       0xCAFE
#define PRODUCT_ID      0xDEAD
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Kavin"
#define PRODUCT         "60% Keyboard"

#define MATRIX_ROWS     5
#define MATRIX_COLS     14

#define MATRIX_ROW_PINS { GP13, GP14, GP15, GP16, GP17 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP18 }

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 20

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
#define PREVENT_STUCK_MODIFIERS

#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO

// OLED display (SSD1306 128x32 via I2C)
// SCL = GP26, SDA = GP25
#define I2C_DRIVER I2CD2
#define I2C1_SCL_PIN GP26
#define I2C1_SDA_PIN GP25
#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 30000

// Rotary encoder
// A = GP27, B = GP29
#define ENCODERS_PAD_A { GP27 }
#define ENCODERS_PAD_B { GP29 }
#define ENCODER_RESOLUTION 4
