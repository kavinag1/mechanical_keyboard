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
