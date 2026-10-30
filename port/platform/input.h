/* Input mapping: keyboard keys and gamepad inputs -> the PS2 pad the game reads.
 *
 * The game has its own BUTTON CONFIG (OPTION menu, func_003DB020, run as
 * decompiled C) that maps PS2 pad buttons to LP/HP/LK/HK/A1/A2.  This layer
 * sits in front of it and maps *physical* inputs to PS2 buttons, so both work:
 *   physical key / button --(input.pN.kb.* / input.pN.pad.*)--> PS2 button
 *   PS2 button --(the game's own button config)--> attack
 * With the game's default config: SQUARE LP, TRIANGLE HP, CROSS LK, CIRCLE HK,
 * L1 A1, R1 A2, L2 / R2 = whatever the game's config puts there.
 *
 * Gamepads are read through one positional layout (W3C "standard" mapping on
 * the web, SDL GameController natively): south/east/west/north face buttons,
 * so an Xbox, PlayStation and Switch pad all get the same physical layout;
 * only the labels shown in the menus follow the pad type.
 *
 * Bindings are settings (port/platform/settings.h): "input.p1.kb.lp = A",
 * "input.p2.pad.hk = east,rt" (comma list; empty = unbound; unset = default).
 */
#ifndef PORT_INPUT_H
#define PORT_INPUT_H
#include <stdint.h>
#include "pad.h"

enum {
    ACT_UP, ACT_DOWN, ACT_LEFT, ACT_RIGHT,
    ACT_LP, ACT_HP, ACT_LK, ACT_HK, ACT_A1, ACT_A2,
    ACT_L2, ACT_R2, ACT_START, ACT_SELECT, ACT_MACRO1, ACT_MACRO2,
    ACT_COUNT
};

/* Gamepad inputs (bit index in a PadIn state word). */
enum {
    PI_SOUTH, PI_EAST, PI_WEST, PI_NORTH, PI_LB, PI_RB, PI_LT, PI_RT,
    PI_BACK, PI_START, PI_LS, PI_RS, PI_UP, PI_DOWN, PI_LEFT, PI_RIGHT, PI_GUIDE,
    PI_LX_NEG, PI_LX_POS, PI_LY_NEG, PI_LY_POS, PI_RX_NEG, PI_RX_POS, PI_RY_NEG, PI_RY_POS,
    PI_COUNT
};

enum { PAD_STYLE_XBOX, PAD_STYLE_PLAYSTATION, PAD_STYLE_NINTENDO };
enum { BIND_KB, BIND_PAD };
#define INPUT_PLAYERS 2
#define BIND_MAX 4

const char *input_action_name(int act);   /* "lp" (setting key part) */
const char *input_action_label(int act);  /* "Light punch (SQUARE)" */
uint16_t input_action_bits(int act);      /* PS2 bits (macros: the chosen combo) */
const char *input_padin_name(int pi);     /* "west" */
const char *input_padin_label(int pi, int style); /* "X" / "Square" / "Y" */
int input_padin_from_name(const char *s);
int input_pad_style_from_name(const char *controller_name);

void input_init(void);                    /* registers input.* options, loads bindings */
/* Binding lists (scancodes or PadIn indices); returns the count. */
int input_bindings(int player, int kind, int act, int out[BIND_MAX]);
void input_bind_set(int player, int kind, int act, int code); /* replace (code < 0: clear) */
void input_bind_reset(int player);       /* both kinds back to defaults */
/* Text for a binding cell ("A, Space"), in the given pad style. */
const char *input_binding_text(int player, int kind, int act, int style);

/* Mapping. keys: SDL scancode state (1 = down); padin: PadIn bits. */
uint16_t input_map_keys(int player, const uint8_t *keys, int nkeys);
uint16_t input_map_pad(int player, uint32_t padin);
int input_pad_player(int slot);           /* gamepad slot 0/1 -> player 0/1 */
int input_stick_deadzone(void);           /* 0..127 */

/* Capture ("press a key / button"): the platform feeds new presses while active. */
void input_capture_begin(int player, int kind, int act);
void input_capture_cancel(void);
int input_capture_active(int *player, int *kind, int *act);
/* returns 1 when the press was consumed by a capture */
int input_capture_key(int scancode);
int input_capture_pad(int pi);

#endif
