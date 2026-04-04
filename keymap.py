"""
Keymap Configuration for 60% Mechanical Keyboard

Define your key mappings here. This is where you customize
which physical key produces which output.
"""

from kmk.keys import KC
from kmk.handlers.sequences import send_string

# Layer 0 - Default QWERTY Layout for 60% keyboard
LAYER_0 = (
    # Row 0: Esc 1 2 3 4 5 6 7 8 9 0 - = Backspace
    (KC.ESC, KC.N1, KC.N2, KC.N3, KC.N4, KC.N5, KC.N6, KC.N7, KC.N8, KC.N9, KC.N0, KC.MINUS, KC.EQUAL, KC.BSPC),
    
    # Row 1: Tab Q W E R T Y U I O P [ ] \
    (KC.TAB, KC.Q, KC.W, KC.E, KC.R, KC.T, KC.Y, KC.U, KC.I, KC.O, KC.P, KC.LBRC, KC.RBRC, KC.BSLS),
    
    # Row 2: Caps A S D F G H J K L ; '   Enter
    (KC.CAPS, KC.A, KC.S, KC.D, KC.F, KC.G, KC.H, KC.J, KC.K, KC.L, KC.SCLN, KC.QUOT, KC.NO, KC.ENT),
    
    # Row 3: Shift Z X C V B N M , . / Shift
    (KC.LSFT, KC.Z, KC.X, KC.C, KC.V, KC.B, KC.N, KC.M, KC.COMM, KC.DOT, KC.SLSH, KC.NO, KC.NO, KC.RSFT),
    
    # Row 4: Ctrl Win Alt Space Alt Win Menu Ctrl
    (KC.LCTL, KC.LGUI, KC.LALT, KC.NO, KC.NO, KC.SPC, KC.NO, KC.NO, KC.RALT, KC.RGUI, KC.NO, KC.NO, KC.NO, KC.RCTL),
)

# Layer 1 - Function/Media Layer
# Access via Fn key (usually a layer toggle or momentary)
LAYER_1 = (
    # Row 0: ` F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12 Del
    (KC.GRV, KC.F1, KC.F2, KC.F3, KC.F4, KC.F5, KC.F6, KC.F7, KC.F8, KC.F9, KC.F10, KC.F11, KC.F12, KC.DEL),
    
    # Row 1: --- Home Up End PgUp --- --- --- --- PrintScreen ScrLck Pause --- ---
    (KC.NO, KC.HOME, KC.UP, KC.END, KC.PGUP, KC.NO, KC.NO, KC.NO, KC.NO, KC.PSCR, KC.SLCK, KC.PAUS, KC.NO, KC.NO),
    
    # Row 2: --- Left Down Right PgDn --- Left Down Up Right --- --- ---
    (KC.NO, KC.LEFT, KC.DOWN, KC.RIGHT, KC.PGDN, KC.NO, KC.LEFT, KC.DOWN, KC.UP, KC.RIGHT, KC.NO, KC.NO, KC.NO, KC.NO),
    
    # Row 3: --- VolDn VolUp Mute --- --- --- --- --- --- --- --- ---
    (KC.NO, KC.VOLD, KC.VOLU, KC.MUTE, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO),
    
    # Row 4: --- --- --- --- --- --- --- --- --- --- --- --- --- ---
    (KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO, KC.NO),
)

# Keymap: Combine all layers
KEYMAP = (
    LAYER_0,
    LAYER_1,
)

# Define special key combinations and macros
MACROS = {
    'EMAIL': send_string('your.email@example.com'),
    'USERNAME': send_string('your_username'),
    # Add more macros as needed
}

# Layer switching keys
# These keys can be used to switch between layers
# Example: MO(1) = Momentary Layer 1 (press to activate)
#         LT(1, KC.SPC) = Layer Tap: Hold for Layer 1, Tap for Space
#
# from kmk.keys import KC
# You can use: MO(), LT(), TG() for layer switching
# See KMK documentation for more options

# Tap Dance definitions (optional)
# Example: Tap once = Esc, Tap twice = Caps Lock
# from kmk.modules.layers import Layers
# from kmk.modules.tapdance import TapDance
# 
# TAPDANCE_CONFIG = {
#     'tap_time': 200,
#     'actions': {
#         0: (KC.ESC, KC.CAPS),  # Tap ESC, Double tap CAPS
#     }
# }
