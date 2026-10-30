#include "input.h"
#include "settings.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const struct { const char *name, *label; uint16_t bits; } k_act[ACT_COUNT] = {
    { "up", "Up", PS2_UP },
    { "down", "Down", PS2_DOWN },
    { "left", "Left", PS2_LEFT },
    { "right", "Right", PS2_RIGHT },
    { "lp", "Light punch (SQUARE)", PS2_SQUARE },
    { "hp", "Heavy punch (TRIANGLE)", PS2_TRIANGLE },
    { "lk", "Light kick (CROSS)", PS2_CROSS },
    { "hk", "Heavy kick (CIRCLE)", PS2_CIRCLE },
    { "a1", "Assist 1 (L1)", PS2_L1 },
    { "a2", "Assist 2 (R1)", PS2_R1 },
    { "l2", "L2 (game config)", PS2_L2 },
    { "r2", "R2 (game config)", PS2_R2 },
    { "start", "Start", PS2_START },
    { "select", "Select", PS2_SELECT },
    { "macro1", "Macro 1", 0 },
    { "macro2", "Macro 2", 0 },
};

static const char *const k_pi_name[PI_COUNT] = {
    "south", "east", "west", "north", "lb", "rb", "lt", "rt",
    "back", "start", "ls", "rs", "up", "down", "left", "right", "guide",
    "lx-", "lx+", "ly-", "ly+", "rx-", "rx+", "ry-", "ry+",
};
/* face/shoulder labels per style: south east west north lb rb lt rt back start ls rs */
static const char *const k_pi_label[3][12] = {
    { "A", "B", "X", "Y", "LB", "RB", "LT", "RT", "View", "Menu", "LS", "RS" },
    { "Cross", "Circle", "Square", "Triangle", "L1", "R1", "L2", "R2", "Share", "Options", "L3", "R3" },
    { "B", "A", "Y", "X", "L", "R", "ZL", "ZR", "Minus", "Plus", "LS", "RS" },
};
static const char *const k_pi_common[] = {
    "D-pad up", "D-pad down", "D-pad left", "D-pad right", "Guide",
    "L-stick left", "L-stick right", "L-stick up", "L-stick down",
    "R-stick left", "R-stick right", "R-stick up", "R-stick down",
};

/* macro combos: PS2 bits */
static const char *const k_combo_label[] = {
    "LP+HP", "LK+HK", "LP+LK", "HP+HK", "A1+A2", "LP+HP+LK+HK", "LP+HP+HK", NULL };
static const char *const k_combo_value[] = {
    "lp+hp", "lk+hk", "lp+lk", "hp+hk", "a1+a2", "lp+hp+lk+hk", "lp+hp+hk", NULL };
static const uint16_t k_combo_bits[] = {
    PS2_SQUARE | PS2_TRIANGLE, PS2_CROSS | PS2_CIRCLE, PS2_SQUARE | PS2_CROSS,
    PS2_TRIANGLE | PS2_CIRCLE, PS2_L1 | PS2_R1, PS2_SQUARE | PS2_TRIANGLE | PS2_CROSS | PS2_CIRCLE,
    PS2_SQUARE | PS2_TRIANGLE | PS2_CIRCLE };

typedef struct { int n; int code[BIND_MAX]; } Bind;
static struct {
    Bind b[INPUT_PLAYERS][2][ACT_COUNT];
    int stale;
    int cap_on, cap_player, cap_kind, cap_act;
    char text[128];
} I;

static void def_kb(int player, int act, Bind *b)
{
    static const int p1[ACT_COUNT][2] = {
        { SDL_SCANCODE_UP }, { SDL_SCANCODE_DOWN }, { SDL_SCANCODE_LEFT }, { SDL_SCANCODE_RIGHT },
        { SDL_SCANCODE_A }, { SDL_SCANCODE_S }, { SDL_SCANCODE_Z }, { SDL_SCANCODE_X },
        { SDL_SCANCODE_D }, { SDL_SCANCODE_C }, { SDL_SCANCODE_Q }, { SDL_SCANCODE_W },
        { SDL_SCANCODE_RETURN }, { SDL_SCANCODE_RSHIFT }, { 0 }, { 0 },
    };
    static const int p2[ACT_COUNT][2] = {
        { SDL_SCANCODE_KP_8 }, { SDL_SCANCODE_KP_5, SDL_SCANCODE_KP_2 }, { SDL_SCANCODE_KP_4 }, { SDL_SCANCODE_KP_6 },
        { SDL_SCANCODE_I }, { SDL_SCANCODE_O }, { SDL_SCANCODE_K }, { SDL_SCANCODE_L },
        { SDL_SCANCODE_P }, { SDL_SCANCODE_SEMICOLON }, { SDL_SCANCODE_9 }, { SDL_SCANCODE_0 },
        { SDL_SCANCODE_KP_ENTER }, { SDL_SCANCODE_KP_PLUS }, { 0 }, { 0 },
    };
    const int *d = player ? p2[act] : p1[act];
    b->n = 0;
    for (int i = 0; i < 2; i++)
        if (d[i]) b->code[b->n++] = d[i];
}

static void def_pad(int act, Bind *b)
{
    static const int d[ACT_COUNT] = {
        PI_UP, PI_DOWN, PI_LEFT, PI_RIGHT, PI_WEST, PI_NORTH, PI_SOUTH, PI_EAST,
        PI_LB, PI_RB, PI_LT, PI_RT, PI_START, PI_BACK, -1, -1,
    };
    b->n = 0;
    if (d[act] >= 0) b->code[b->n++] = d[act];
}

const char *input_action_name(int act) { return act >= 0 && act < ACT_COUNT ? k_act[act].name : ""; }
const char *input_action_label(int act) { return act >= 0 && act < ACT_COUNT ? k_act[act].label : ""; }
const char *input_padin_name(int pi) { return pi >= 0 && pi < PI_COUNT ? k_pi_name[pi] : ""; }

uint16_t input_action_bits(int act)
{
    if (act == ACT_MACRO1 || act == ACT_MACRO2) {
        int c = settings_get_int(act == ACT_MACRO1 ? "input.macro1" : "input.macro2");
        return k_combo_bits[c < 0 || c > 6 ? 0 : c];
    }
    return act >= 0 && act < ACT_COUNT ? k_act[act].bits : 0;
}

const char *input_padin_label(int pi, int style)
{
    if (style < 0 || style > 2) style = 0;
    if (pi >= 0 && pi < 12) return k_pi_label[style][pi];
    if (pi >= PI_UP && pi < PI_COUNT) return k_pi_common[pi - PI_UP];
    return "?";
}

int input_padin_from_name(const char *s)
{
    for (int i = 0; i < PI_COUNT; i++)
        if (!SDL_strcasecmp(s, k_pi_name[i])) return i;
    return -1;
}

int input_pad_style_from_name(const char *n)
{
    if (!n) return PAD_STYLE_XBOX;
    if (SDL_strcasestr(n, "054c") || SDL_strcasestr(n, "playstation") || SDL_strcasestr(n, "dualshock") ||
        SDL_strcasestr(n, "dualsense") || SDL_strcasestr(n, "ps3") || SDL_strcasestr(n, "ps4") ||
        SDL_strcasestr(n, "ps5") || SDL_strcasestr(n, "sony"))
        return PAD_STYLE_PLAYSTATION;
    if (SDL_strcasestr(n, "057e") || SDL_strcasestr(n, "nintendo") || SDL_strcasestr(n, "switch") ||
        SDL_strcasestr(n, "joy-con") || SDL_strcasestr(n, "pro controller"))
        return PAD_STYLE_NINTENDO;
    return PAD_STYLE_XBOX;
}

static void key_of(int player, int kind, int act, char *out, size_t cap)
{
    snprintf(out, cap, "input.p%d.%s.%s", player + 1, kind == BIND_KB ? "kb" : "pad", k_act[act].name);
}

static void parse_one(int player, int kind, int act)
{
    char key[64];
    Bind *b = &I.b[player][kind][act];
    key_of(player, kind, act, key, sizeof key);
    const char *s = settings_get(key);
    if (!s) {
        if (kind == BIND_KB) def_kb(player, act, b);
        else def_pad(act, b);
        return;
    }
    b->n = 0;
    while (*s && b->n < BIND_MAX) {
        char tok[48];
        size_t n = 0;
        while (*s == ' ' || *s == ',') s++;
        while (*s && *s != ',' && n + 1 < sizeof tok) tok[n++] = *s++;
        while (n && tok[n - 1] == ' ') n--;
        tok[n] = 0;
        if (!n) continue;
        int code = kind == BIND_KB ? (int)SDL_GetScancodeFromName(tok) : input_padin_from_name(tok);
        if (kind == BIND_KB && code == 0 && tok[0] == '#') code = atoi(tok + 1);
        if ((kind == BIND_KB && code > 0) || (kind == BIND_PAD && code >= 0)) b->code[b->n++] = code;
    }
}

static void reparse(void)
{
    for (int p = 0; p < INPUT_PLAYERS; p++)
        for (int k = 0; k < 2; k++)
            for (int a = 0; a < ACT_COUNT; a++) parse_one(p, k, a);
    I.stale = 0;
}

static void on_setting(const char *key)
{
    if (!strncmp(key, "input.", 6)) I.stale = 1;
}

static const char *const k_players[] = { "Player 1", "Player 2", NULL };
static const char *const k_players_v[] = { "1", "2", NULL };
static const SetDesc k_desc[] = {
    { "input.pad1_player", "First gamepad plays", SET_SECTION_INPUT, SET_ENUM, 0, 0, 1, k_players, k_players_v,
      NULL, 0, "The first connected gamepad controls this player; the second gamepad the other. "
      "Keyboard set 1 is always player 1, keyboard set 2 player 2.", 0 },
    { "input.stick_dpad", "Left stick moves", SET_SECTION_INPUT, SET_BOOL, 1, 0, 1, NULL, NULL, NULL, 0,
      "The left analog stick works as a d-pad as well as the bound directions.", 0 },
    { "input.deadzone", "Stick dead zone", SET_SECTION_INPUT, SET_INT, 50, 20, 90, NULL, NULL, NULL, 0,
      "How far the stick must be pushed to register a direction (percent).", 5 },
    { "input.macro1", "Macro 1 presses", SET_SECTION_INPUT, SET_ENUM, 0, 0, 6, k_combo_label, k_combo_value,
      NULL, 0, "Buttons pressed together by the Macro 1 binding (unbound by default).", 0 },
    { "input.macro2", "Macro 2 presses", SET_SECTION_INPUT, SET_ENUM, 1, 0, 6, k_combo_label, k_combo_value,
      NULL, 0, "Buttons pressed together by the Macro 2 binding (unbound by default).", 0 },
};

void input_init(void)
{
    for (size_t i = 0; i < sizeof k_desc / sizeof k_desc[0]; i++) settings_register(&k_desc[i]);
    settings_add_listener(on_setting);
    reparse();
}

int input_bindings(int player, int kind, int act, int out[BIND_MAX])
{
    if (I.stale) reparse();
    if (player < 0 || player >= INPUT_PLAYERS || act < 0 || act >= ACT_COUNT) return 0;
    const Bind *b = &I.b[player][kind][act];
    for (int i = 0; i < b->n; i++) out[i] = b->code[i];
    return b->n;
}

static void write_bind(int player, int kind, int act)
{
    char key[64], val[256] = "";
    const Bind *b = &I.b[player][kind][act];
    key_of(player, kind, act, key, sizeof key);
    for (int i = 0; i < b->n; i++) {
        if (i) strncat(val, ",", sizeof val - strlen(val) - 1);
        strncat(val, kind == BIND_KB ? SDL_GetScancodeName((SDL_Scancode)b->code[i]) : k_pi_name[b->code[i]],
                sizeof val - strlen(val) - 1);
    }
    settings_set(key, val);
}

void input_bind_set(int player, int kind, int act, int code)
{
    if (I.stale) reparse();
    if (player < 0 || player >= INPUT_PLAYERS || act < 0 || act >= ACT_COUNT) return;
    if (code >= 0) {
        /* one input drives one action per player: an action that had it gets
         * this action's old input instead (a swap), so nothing ends up unbound */
        const Bind *mine = &I.b[player][kind][act];
        int old = mine->n ? mine->code[0] : -1;
        for (int a = 0; a < ACT_COUNT; a++) {
            if (a == act) continue;
            Bind *o = &I.b[player][kind][a];
            int hit = 0;
            for (int i = 0; i < o->n; i++)
                if (o->code[i] == code) { hit = 1; o->code[i] = old; }
            if (!hit) continue;
            int n = 0;
            for (int i = 0; i < o->n; i++)
                if (o->code[i] >= 0) o->code[n++] = o->code[i];
            o->n = n;
            write_bind(player, kind, a);
        }
    }
    Bind *b = &I.b[player][kind][act];
    b->n = 0;
    if (code >= 0) b->code[b->n++] = code;
    write_bind(player, kind, act);
    I.stale = 1;
}

void input_bind_reset(int player)
{
    char pre[16];
    snprintf(pre, sizeof pre, "input.p%d.", player + 1);
    settings_reset_prefix(pre);
    I.stale = 1;
}

const char *input_binding_text(int player, int kind, int act, int style)
{
    int c[BIND_MAX], n = input_bindings(player, kind, act, c);
    I.text[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i) strncat(I.text, ", ", sizeof I.text - strlen(I.text) - 1);
        strncat(I.text, kind == BIND_KB ? SDL_GetScancodeName((SDL_Scancode)c[i]) : input_padin_label(c[i], style),
                sizeof I.text - strlen(I.text) - 1);
    }
    if (!n) snprintf(I.text, sizeof I.text, "-");
    return I.text;
}

uint16_t input_map_keys(int player, const uint8_t *keys, int nkeys)
{
    if (I.stale) reparse();
    uint16_t out = 0;
    for (int a = 0; a < ACT_COUNT; a++) {
        const Bind *b = &I.b[player][BIND_KB][a];
        for (int i = 0; i < b->n; i++)
            if (b->code[i] < nkeys && keys[b->code[i]]) { out |= input_action_bits(a); break; }
    }
    return out;
}

uint16_t input_map_pad(int player, uint32_t padin)
{
    if (I.stale) reparse();
    uint16_t out = 0;
    for (int a = 0; a < ACT_COUNT; a++) {
        const Bind *b = &I.b[player][BIND_PAD][a];
        for (int i = 0; i < b->n; i++)
            if (padin & (1u << b->code[i])) { out |= input_action_bits(a); break; }
    }
    if (settings_get_int("input.stick_dpad")) {
        if (padin & (1u << PI_LX_NEG)) out |= PS2_LEFT;
        if (padin & (1u << PI_LX_POS)) out |= PS2_RIGHT;
        if (padin & (1u << PI_LY_NEG)) out |= PS2_UP;
        if (padin & (1u << PI_LY_POS)) out |= PS2_DOWN;
    }
    return out;
}

int input_pad_player(int slot)
{
    int first = settings_get_int("input.pad1_player");
    return slot == 0 ? first : !first;
}

int input_stick_deadzone(void) { return settings_get_int("input.deadzone") * 127 / 100; }

void input_capture_begin(int player, int kind, int act)
{
    I.cap_on = 1;
    I.cap_player = player;
    I.cap_kind = kind;
    I.cap_act = act;
}
void input_capture_cancel(void) { I.cap_on = 0; }
int input_capture_active(int *player, int *kind, int *act)
{
    if (I.cap_on) {
        if (player) *player = I.cap_player;
        if (kind) *kind = I.cap_kind;
        if (act) *act = I.cap_act;
    }
    return I.cap_on;
}

int input_capture_key(int sc)
{
    if (!I.cap_on) return 0;
    if (sc == SDL_SCANCODE_ESCAPE) { I.cap_on = 0; return 1; }
    if (sc == SDL_SCANCODE_BACKSPACE || sc == SDL_SCANCODE_DELETE) {
        I.cap_on = 0;
        input_bind_set(I.cap_player, I.cap_kind, I.cap_act, -1);
        return 1;
    }
    if (I.cap_kind != BIND_KB) return 1; /* waiting for a pad button: swallow keys */
    I.cap_on = 0;
    input_bind_set(I.cap_player, BIND_KB, I.cap_act, sc);
    return 1;
}

int input_capture_pad(int pi)
{
    if (!I.cap_on || I.cap_kind != BIND_PAD) return 0;
    if (pi == PI_GUIDE) return 1;
    I.cap_on = 0;
    input_bind_set(I.cap_player, BIND_PAD, I.cap_act, pi);
    return 1;
}
