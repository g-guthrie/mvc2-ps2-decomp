/*
 * Frontend UI (port side, never game code): the player's options, the
 * in-game settings menu, the FPS / latency overlay and the touch pad.
 *
 * Options live in the settings store (port/platform/settings.h).  The menu
 * here (F1 / Esc natively, F1 on the web, or Back+Start / Guide on a pad) and
 * the web page's settings panel (port/web/shell.html) are both generated from
 * the registered option table, so an option registered anywhere (for example
 * the arcade-accuracy toggles, section SET_SECTION_ARCADE) appears in both.
 *
 * While the menu or the web panel is open the game is held (no logic steps,
 * audio paused).  Every option is described in port/docs/USER_GUIDE.md.
 */
#include <SDL.h>
#include <stdio.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include "../host.h"
#include "../host_loop.h"
#include "../../platform/platform.h"
#include "../../platform/input.h"
#include "../../platform/settings.h"
#include "../../render/render.h"
#include "../../audio/audio.h"

void fe_audio_pause(int paused);
void fe_audio_pump(double ahead_s);

/* ------------------------------------------------------------------ options */
static struct {
    RPresent pres;
    int show_fps;
    int touch_show;        /* 0 auto, 1 always, 2 never */
    float touch_size;
    int touch_alpha;       /* 0..255 */
    int audio_latency;     /* 0 auto, 1 low, 2 normal, 3 high */
    float vol, music, sfx;
    int web_panel;         /* the web page's settings panel is open */
} O;

static void ap_scale(int v) { O.pres.scale = v; plat_request_render(); }
static void ap_filter(int v) { O.pres.filter = v; plat_request_render(); }
static void ap_sprite(int v) { r_set_sprite_filter(v - 1); }
static void ap_crt(int v) { O.pres.crt = v; plat_request_render(); }
static void ap_crt_strength(int v) { O.pres.crt_strength = v / 100.f; O.pres.crt_mask = v / 100.f; plat_request_render(); }
static void ap_fullscreen(int v)
{
#ifndef __EMSCRIPTEN__
    if (plat_fullscreen() != (v != 0)) plat_set_fullscreen(v);
#else
    (void)v; /* the page's button / the menu's toggle: browsers need a gesture */
#endif
}
static void ap_vsync(int v) { plat_set_vsync(v); }
static void ap_frameskip(int v) { plat_set_frame_skip(v); }
static void ap_fps(int v) { O.show_fps = v; plat_request_render(); }
static void ap_vol(int v) { O.vol = v / 100.f; audio_set_master(O.vol * O.vol); }
static void ap_music(int v) { O.music = v / 100.f; audio_set_music_volume(O.music * O.music); }
static void ap_sfx(int v) { O.sfx = v / 100.f; audio_set_sfx_volume(O.sfx * O.sfx); }
static void ap_latency(int v) { O.audio_latency = v; }
static void ap_touch_show(int v) { O.touch_show = v; plat_request_render(); }
static void ap_touch_size(int v)
{
    TouchPad *t = plat_touch();
    O.touch_size = v / 100.f;
    t->scale = O.touch_size;
    t->w = 0; /* relayout on the next frame */
    plat_request_render();
}
static void ap_touch_alpha(int v) { O.touch_alpha = v * 255 / 100; plat_request_render(); }
static void ap_unlock(int v) { mvc2_unlock_all = v; }

#ifdef __EMSCRIPTEN__
EM_JS(void, web_toggle_fullscreen, (void), {
    var d = document, el = d.documentElement;
    try {
        if (d.fullscreenElement || d.webkitFullscreenElement) (d.exitFullscreen || d.webkitExitFullscreen).call(d);
        else (el.requestFullscreen || el.webkitRequestFullscreen).call(el);
    } catch (e) {}
});
static void ap_fs_toggle(int v) { (void)v; web_toggle_fullscreen(); }
#endif

static const char *const k_scale[] = { "Fit", "Integer", "Stretch", NULL };
static const char *const k_filter[] = { "Nearest", "Sharp", "Smooth", NULL };
static const char *const k_sprite[] = { "As the game", "Nearest", "Smooth", NULL };
static const char *const k_sprite_v[] = { "game", "nearest", "smooth", NULL };
static const char *const k_crt[] = { "Off", "Scanlines", "CRT", NULL };
static const char *const k_lat[] = { "Auto", "Low", "Normal", "High", NULL };
static const char *const k_touch[] = { "Auto", "Always", "Never", NULL };

static const SetDesc k_opts[] = {
    { "video.scale", "Scaling", SET_SECTION_VIDEO, SET_ENUM, 0, 0, 2, k_scale, NULL, ap_scale, 0,
      "Fit: largest 4:3 picture. Integer: whole multiples of 640x480 only. Stretch: fill the window.", 0 },
    { "video.filter", "Upscaling filter", SET_SECTION_VIDEO, SET_ENUM, 1, 0, 2, k_filter, NULL, ap_filter, 0,
      "Nearest: hard pixels. Sharp: crisp pixels without uneven widths. Smooth: bilinear.", 0 },
    { "video.sprite_filter", "Sprite filtering", SET_SECTION_VIDEO, SET_ENUM, 0, 0, 2, k_sprite, k_sprite_v,
      ap_sprite, 0, "Texture sampling for 2D sprites: as the game asks, always nearest, or always smooth.", 0 },
    { "video.crt", "CRT effect", SET_SECTION_VIDEO, SET_ENUM, 0, 0, 2, k_crt, NULL, ap_crt, 0,
      "Scanlines, or scanlines with a shadow mask and slight curvature.", 0 },
    { "video.crt_strength", "CRT strength", SET_SECTION_VIDEO, SET_INT, 60, 0, 100, NULL, NULL, ap_crt_strength,
      0, "How strong the scanlines and mask are.", 10 },
    { "video.fullscreen", "Fullscreen", SET_SECTION_VIDEO, SET_BOOL, 0, 0, 1, NULL, NULL, ap_fullscreen,
      SET_NATIVE_ONLY, "Desktop fullscreen (also Alt+Enter / F11).", 0 },
#ifdef __EMSCRIPTEN__
    { "video.fullscreen_toggle", "Toggle fullscreen", SET_SECTION_VIDEO, SET_ACTION, 0, 0, 1, NULL, NULL,
      ap_fs_toggle, SET_WEB_ONLY | SET_HIDDEN, "Enter or leave fullscreen.", 0 },
#endif
    { "video.vsync", "V-sync", SET_SECTION_VIDEO, SET_BOOL, 1, 0, 1, NULL, NULL, ap_vsync, SET_NATIVE_ONLY,
      "Wait for the display refresh. The game logic always runs at 60 Hz either way.", 0 },
    { "video.frame_skip", "Drop frames when slow", SET_SECTION_VIDEO, SET_BOOL, 1, 0, 1, NULL, NULL, ap_frameskip,
      0, "On a slow device skip drawing, never game logic, so the game keeps full speed.", 0 },
    { "video.fps", "Show FPS and latency", SET_SECTION_VIDEO, SET_BOOL, 0, 0, 1, NULL, NULL, ap_fps, 0,
      "Display rate, logic rate and input-to-logic latency in the corner.", 0 },
    { "audio.volume", "Master volume", SET_SECTION_AUDIO, SET_INT, 100, 0, 100, NULL, NULL, ap_vol, 0, NULL, 5 },
    { "audio.music", "Music volume", SET_SECTION_AUDIO, SET_INT, 100, 0, 100, NULL, NULL, ap_music, 0, NULL, 5 },
    { "audio.sfx", "Effects and voices", SET_SECTION_AUDIO, SET_INT, 100, 0, 100, NULL, NULL, ap_sfx, 0, NULL, 5 },
    { "audio.latency", "Audio buffer", SET_SECTION_AUDIO, SET_ENUM, 0, 0, 3, k_lat, NULL, ap_latency, SET_WEB_ONLY,
      "How far ahead sound is mixed. Raise it if you hear crackles.", 0 },
    { "touch.show", "Touch controls", SET_SECTION_INPUT, SET_ENUM, 0, 0, 2, k_touch, NULL, ap_touch_show, 0,
      "Auto: shown after the first touch.", 0 },
    { "touch.size", "Touch control size", SET_SECTION_INPUT, SET_INT, 100, 50, 160, NULL, NULL, ap_touch_size, 0,
      NULL, 10 },
    { "touch.opacity", "Touch control opacity", SET_SECTION_INPUT, SET_INT, 60, 10, 100, NULL, NULL, ap_touch_alpha,
      0, NULL, 10 },
    { "game.unlock_all", "Unlock everything", SET_SECTION_GAME, SET_BOOL, 1, 0, 1, NULL, NULL, ap_unlock, SET_RESTART,
      "Every character, stage and extra from the start. Turning it off takes effect on the next start.", 0 },
};

/* Register the options (before plat_init: the platform reads some at init). */
void fe_ui_register(void)
{
    O.vol = O.music = O.sfx = 1.f;
    O.touch_alpha = 153;
    O.touch_size = 1.f;
    O.pres.filter = R_FILTER_SHARP;
    O.pres.crt_strength = O.pres.crt_mask = 0.6f;
    for (size_t i = 0; i < sizeof k_opts / sizeof k_opts[0]; i++) settings_register(&k_opts[i]);
    input_init();
}

static int visible_here(const SetDesc *d)
{
    if (d->flags & SET_HIDDEN) return 0;
#ifdef __EMSCRIPTEN__
    if (d->flags & SET_NATIVE_ONLY) return 0;
#else
    if (d->flags & SET_WEB_ONLY) return 0;
#endif
    return 1;
}

/* --------------------------------------------------------------------- menu */
enum { PG_ROOT, PG_SECTION, PG_CONTROLS };
static const char *const k_sections[] = {
    SET_SECTION_VIDEO, SET_SECTION_AUDIO, SET_SECTION_INPUT, SET_SECTION_GAME, SET_SECTION_ARCADE };
#define NSECT 5
enum { R_SECTION, R_PLAYER, R_RESUME, R_QUIT, R_OPT, R_BIND, R_RESET, R_BACK, R_FULLSCREEN };
typedef struct { int kind, arg; const char *label; } Row;

static struct {
    int open, page, section, player, sel, col, scroll;
    int rep_dir, rep_t;
    int fresh;          /* opened during this frame: its key is not a menu key */
    uint32_t prev_chord;
    char msg[96];
    int msg_t;
} M;

static int build_rows(Row *r, int max)
{
    int n = 0;
    if (M.page == PG_ROOT) {
        for (int s = 0; s < NSECT && n < max; s++) r[n++] = (Row){ R_SECTION, s, k_sections[s] };
        r[n++] = (Row){ R_PLAYER, 0, "Controls: player 1" };
        r[n++] = (Row){ R_PLAYER, 1, "Controls: player 2" };
#ifdef __EMSCRIPTEN__
        r[n++] = (Row){ R_FULLSCREEN, 0, "Toggle fullscreen" };
#endif
        r[n++] = (Row){ R_RESUME, 0, "Resume" };
#ifndef __EMSCRIPTEN__
        r[n++] = (Row){ R_QUIT, 0, "Quit" };
#endif
    } else if (M.page == PG_SECTION) {
        for (int i = 0; i < settings_count() && n < max - 1; i++) {
            const SetDesc *d = settings_desc(i);
            if (strcmp(d->section, k_sections[M.section]) || !visible_here(d)) continue;
            r[n++] = (Row){ R_OPT, i, d->label };
        }
        r[n++] = (Row){ R_BACK, 0, "Back" };
    } else {
        for (int a = 0; a < ACT_COUNT && n < max - 2; a++) r[n++] = (Row){ R_BIND, a, input_action_label(a) };
        r[n++] = (Row){ R_RESET, 0, "Reset to defaults" };
        r[n++] = (Row){ R_BACK, 0, "Back" };
    }
    return n;
}

static int player_style(int player)
{
    for (int s = 0; s < PLAT_MAX_PADS; s++)
        if (plat_pad_connected(s) && input_pad_player(s) == player) return plat_pad_style(s);
    return PAD_STYLE_XBOX;
}

static void hold_changed(void)
{
    int h = M.open || O.web_panel;
    if (h != plat_hold()) {
        plat_set_hold(h);
        fe_audio_pause(h);
        if (!h) input_capture_cancel();
        plat_input_swallow_held(); /* the keys that opened / closed it stay out of the game */
    }
}

void fe_ui_menu_open(int on)
{
    M.open = on;
    M.fresh = on;
    M.page = PG_ROOT;
    M.sel = M.scroll = M.col = 0;
    hold_changed();
}

static void flash(const char *s) { snprintf(M.msg, sizeof M.msg, "%s", s); M.msg_t = 150; }

static void change(const Row *r, int dir, int activate)
{
    if (r->kind == R_OPT) {
        const SetDesc *d = settings_desc(r->arg);
        int v = settings_get_int(d->key);
        if (d->type == SET_ACTION) { if (activate && d->apply) d->apply(1); return; }
        if (d->type == SET_BOOL) v = !v;
        else if (d->type == SET_ENUM) {
            int n = d->max + 1, k = 0;
            while (d->choices[k]) k++;
            n = k;
            v = (v + (dir ? dir : 1) + n) % n;
        } else {
            int st = d->step ? d->step : 1;
            v += (dir ? dir : 1) * st;
            if (!dir && v > d->max) v = d->min;
        }
        settings_set_int(d->key, v);
        if (d->flags & SET_RESTART) flash("Takes effect on the next start");
    }
}

/* menu navigation: keyboard and any gamepad, independent of the bindings */
static int nav_dir(void)
{
    uint32_t pin = 0;
    for (int s = 0; s < PLAT_MAX_PADS; s++) pin |= plat_padin(s);
    int d = 0;
    if (pin & ((1u << PI_UP) | (1u << PI_LY_NEG))) d = 1;
    else if (pin & ((1u << PI_DOWN) | (1u << PI_LY_POS))) d = 2;
    else if (pin & ((1u << PI_LEFT) | (1u << PI_LX_NEG))) d = 3;
    else if (pin & ((1u << PI_RIGHT) | (1u << PI_LX_POS))) d = 4;
    if (d != M.rep_dir) { M.rep_dir = d; M.rep_t = 0; return d; }
    if (!d) return 0;
    M.rep_t++;
    return (M.rep_t > 18 && (M.rep_t - 18) % 5 == 0) ? d : 0;
}

static uint32_t pad_hits(void)
{
    uint32_t h = 0;
    for (int s = 0; s < PLAT_MAX_PADS; s++) h |= plat_padin_hit(s);
    return h;
}

static void menu_input(void)
{
    Row rows[48];
    int n = build_rows(rows, 48);
    if (input_capture_active(NULL, NULL, NULL)) return; /* the platform feeds the capture */
    if (M.fresh) { M.fresh = 0; nav_dir(); return; }
    int pd = nav_dir();
    uint32_t ph = pad_hits();
    int up = plat_key_repeat(SDL_SCANCODE_UP) || pd == 1;
    int down = plat_key_repeat(SDL_SCANCODE_DOWN) || pd == 2;
    int left = plat_key_repeat(SDL_SCANCODE_LEFT) || pd == 3;
    int right = plat_key_repeat(SDL_SCANCODE_RIGHT) || pd == 4;
    int ok = plat_key_hit(SDL_SCANCODE_RETURN) || plat_key_hit(SDL_SCANCODE_KP_ENTER) ||
             plat_key_hit(SDL_SCANCODE_SPACE) || (ph & ((1u << PI_SOUTH) | (1u << PI_START)));
    int back = plat_key_hit(SDL_SCANCODE_ESCAPE) || plat_key_hit(SDL_SCANCODE_F1) || (ph & (1u << PI_EAST));
    int clear = plat_key_hit(SDL_SCANCODE_DELETE) || plat_key_hit(SDL_SCANCODE_BACKSPACE) || (ph & (1u << PI_NORTH));
    if (up) M.sel = (M.sel + n - 1) % n;
    if (down) M.sel = (M.sel + 1) % n;
    if (M.sel >= n) M.sel = n - 1;
    const Row *r = &rows[M.sel];
    if (r->kind == R_BIND) {
        if (left || right) M.col = !M.col;
        if (ok) input_capture_begin(M.player, M.col ? BIND_PAD : BIND_KB, r->arg);
        if (clear) input_bind_set(M.player, M.col ? BIND_PAD : BIND_KB, r->arg, -1);
    } else if (r->kind == R_OPT) {
        if (left) change(r, -1, 0);
        if (right) change(r, 1, 0);
        if (ok) change(r, 0, 1);
    } else if (ok) {
        switch (r->kind) {
        case R_SECTION: M.page = PG_SECTION; M.section = r->arg; M.sel = M.scroll = 0; break;
        case R_PLAYER: M.page = PG_CONTROLS; M.player = r->arg; M.sel = M.scroll = 0; break;
        case R_RESUME: fe_ui_menu_open(0); return;
        case R_QUIT: plat_request_quit(); return;
        case R_RESET: input_bind_reset(M.player); flash("Controls reset"); break;
        case R_BACK: M.page = PG_ROOT; M.sel = M.scroll = 0; break;
#ifdef __EMSCRIPTEN__
        case R_FULLSCREEN: web_toggle_fullscreen(); break;
#endif
        }
    }
    if (back) {
        if (M.page == PG_ROOT) { fe_ui_menu_open(0); return; }
        M.page = PG_ROOT;
        M.sel = M.scroll = 0;
    }
}

/* Called every logic step before the game reads the pads: menu open triggers
 * (F1 / Esc natively, Back+Start, Guide).  Returns 1 when the menu opened (skip
 * this step: its buttons belong to the menu). */
int fe_ui_step(void)
{
    uint32_t chord = 0, hits = pad_hits();
    for (int s = 0; s < PLAT_MAX_PADS; s++)
        if ((plat_padin(s) & ((1u << PI_BACK) | (1u << PI_START))) == ((1u << PI_BACK) | (1u << PI_START))) chord = 1;
    int open = plat_key_hit(SDL_SCANCODE_F1) || (chord && !M.prev_chord) || (hits & (1u << PI_GUIDE));
#ifndef __EMSCRIPTEN__
    open |= plat_key_hit(SDL_SCANCODE_ESCAPE);
    if ((plat_key_hit(SDL_SCANCODE_RETURN) && (plat_key_held(SDL_SCANCODE_LALT) || plat_key_held(SDL_SCANCODE_RALT))) ||
        plat_key_hit(SDL_SCANCODE_F11))
        settings_set_int("video.fullscreen", !plat_fullscreen());
#endif
    M.prev_chord = chord;
    if (open && !M.open) { fe_ui_menu_open(1); return 1; }
    return 0;
}

/* ------------------------------------------------------------------ drawing */
static float g_px;

static void text(float x, float y, uint32_t c, const char *s) { r_overlay_text(x, y, g_px, c, s); }

static void draw_menu(int W, int H)
{
    Row rows[48];
    int n = build_rows(rows, 48);
    float px = g_px, lh = 11 * px;
    float pw = 84 * 6 * px, ph;
    if (pw > W - 16) { px = g_px = (float)((int)((W - 16) / (84 * 6.f)) > 1 ? (int)((W - 16) / (84 * 6.f)) : 1); pw = 84 * 6 * px; lh = 11 * px; }
    int vis = (int)((H * 0.86f - lh * 5) / lh);
    if (vis > n) vis = n;
    if (vis < 3) vis = 3;
    if (M.sel < M.scroll) M.scroll = M.sel;
    if (M.sel >= M.scroll + vis) M.scroll = M.sel - vis + 1;
    ph = lh * (vis + 5);
    float x0 = (W - pw) / 2, y0 = (H - ph) / 2;
    r_overlay_rect(0, 0, (float)W, (float)H, 0x80000000);
    r_overlay_rect(x0, y0, pw, ph, 0xF0141420);
    r_overlay_rect(x0, y0, pw, 2 * px, 0xFF3A6DF0);
    char title[96];
    if (M.page == PG_ROOT) snprintf(title, sizeof title, "SETTINGS");
    else if (M.page == PG_SECTION) snprintf(title, sizeof title, "%s", k_sections[M.section]);
    else snprintf(title, sizeof title, "Controls: player %d   (keyboard | gamepad)", M.player + 1);
    text(x0 + 4 * px, y0 + 4 * px, 0xFFFFFFFF, title);
    float y = y0 + lh * 1.6f;
    int style = player_style(M.player);
    int cap = 0, cap_kind = 0, cap_act = 0, cap_player = 0;
    cap = input_capture_active(&cap_player, &cap_kind, &cap_act);
    for (int i = M.scroll; i < M.scroll + vis && i < n; i++, y += lh) {
        const Row *r = &rows[i];
        int sel = i == M.sel;
        if (sel) r_overlay_rect(x0 + 2 * px, y - 2 * px, pw - 4 * px, lh, 0xFF2A4FB8);
        uint32_t tc = sel ? 0xFFFFFFFF : 0xFFD8D8E0;
        text(x0 + 6 * px, y, tc, r->label);
        char val[96] = "";
        if (r->kind == R_OPT) {
            const SetDesc *d = settings_desc(r->arg);
            if (d->type != SET_ACTION)
                snprintf(val, sizeof val, "< %s >%s", settings_value_label(d, settings_get_int(d->key)),
                         (d->flags & SET_RESTART) ? " *" : "");
            text(x0 + pw - r_overlay_text_width(px, val) - 6 * px, y, 0xFFFFD060, val);
        } else if (r->kind == R_BIND) {
            float cx = x0 + pw * 0.52f, cw = pw * 0.23f;
            for (int k = 0; k < 2; k++) {
                char b[40];
                int capping = cap && cap_player == M.player && cap_act == r->arg && cap_kind == (k ? BIND_PAD : BIND_KB);
                snprintf(b, sizeof b, "%s", capping ? "press..." : input_binding_text(M.player, k ? BIND_PAD : BIND_KB, r->arg, style));
                if (strlen(b) > 13) b[13] = 0;
                if (sel && M.col == k) r_overlay_rect(cx + k * cw - px, y - 2 * px, cw - px, lh, capping ? 0xFFB04020 : 0xFF4A6FD8);
                text(cx + k * cw + px, y, capping ? 0xFFFFFFFF : 0xFFFFD060, b);
            }
        } else if (r->kind == R_SECTION && r->arg == NSECT - 1) {
            int cnt = 0;
            for (int k = 0; k < settings_count(); k++)
                if (!strcmp(settings_desc(k)->section, SET_SECTION_ARCADE) && visible_here(settings_desc(k))) cnt++;
            if (!cnt) text(x0 + pw - r_overlay_text_width(px, "(none yet)") - 6 * px, y, 0xFF8888A0, "(none yet)");
        }
    }
    /* help line */
    const char *help = NULL;
    char hb[160];
    if (cap) {
        snprintf(hb, sizeof hb, "Press a %s for %s. Esc cancels, Backspace clears.",
                 cap_kind == BIND_KB ? "key" : "gamepad button", input_action_label(cap_act));
        help = hb;
    } else if (M.msg_t > 0) {
        help = M.msg;
        M.msg_t--;
    } else if (M.sel < n && rows[M.sel].kind == R_OPT) {
        help = settings_desc(rows[M.sel].arg)->help;
    } else if (M.page == PG_CONTROLS) {
        help = "Enter: rebind. Left/Right: keyboard or gamepad. Del / Y: clear.";
    } else {
        help = "Arrows / d-pad move, Enter / A select, Esc / B back.";
    }
    if (help) {
        /* wrap to the panel width */
        int cols = (int)((pw - 12 * px) / (6 * px));
        float hy = y0 + ph - lh * 2.6f;
        char line[128];
        const char *s = help;
        for (int l = 0; l < 2 && *s; l++, hy += lh) {
            int len = (int)strlen(s), cut = len;
            if (len > cols) { cut = cols; while (cut > 0 && s[cut] != ' ') cut--; if (!cut) cut = cols; }
            if (cut > (int)sizeof line - 1) cut = sizeof line - 1;
            memcpy(line, s, (size_t)cut);
            line[cut] = 0;
            text(x0 + 6 * px, hy, 0xFFA8A8B8, line);
            s += cut;
            while (*s == ' ') s++;
        }
    }
}

static void draw_touch(int W, int H)
{
    TouchPad *t = plat_touch();
    if (!t->visible) return;
    uint32_t a = (uint32_t)O.touch_alpha;
    uint32_t a_fill = (a * 0x50 / 0xFF) << 24, a_ring = (a * 0xB0 / 0xFF) << 24, a_held = (a * 0xD0 / 0xFF + 0x20) << 24;
    float ring = t->dr * 0.06f;
    r_overlay_disc(t->dcx, t->dcy, t->dr, ((a * 0x40 / 0xFF) << 24) | 0xFFFFFF);
    r_overlay_ring(t->dcx, t->dcy, t->dr, ring, a_ring | 0xFFFFFF);
    if (t->dpad_bits) {
        float dx = (t->dpad_bits & PS2_RIGHT) ? 1.f : (t->dpad_bits & PS2_LEFT) ? -1.f : 0.f;
        float dy = (t->dpad_bits & PS2_DOWN) ? 1.f : (t->dpad_bits & PS2_UP) ? -1.f : 0.f;
        r_overlay_disc(t->dcx + dx * t->dr * 0.55f, t->dcy + dy * t->dr * 0.55f, t->dr * 0.3f, a_held | 0xFFFFFF);
    } else {
        r_overlay_disc(t->dcx, t->dcy, t->dr * 0.3f, a_ring | 0xFFFFFF);
    }
    static const uint32_t col[TB_COUNT] = { 0x4FA3FF, 0x2F6FE0, 0x50D070, 0xFF6A6A, 0xD03A3A, 0xE0C040, 0xFFFFFF };
    for (int k = 0; k < TB_COUNT; k++) {
        const TouchButton *b = &t->b[k];
        uint32_t c = col[k];
        r_overlay_disc(b->cx, b->cy, b->r, (b->held ? a_held : a_fill) | c);
        r_overlay_ring(b->cx, b->cy, b->r, b->r * 0.1f, a_ring | c);
        float tp = b->r / 9.f;
        if (tp < 1) tp = 1;
        float tw = r_overlay_text_width(tp, b->label);
        r_overlay_text(b->cx - tw / 2, b->cy - 3.5f * tp, tp, (a_ring + 0x30000000u) | 0xFFFFFF, b->label);
    }
    (void)W; (void)H;
}

static void draw_fps(int W, int H)
{
    PlatStats s;
    char b[160];
    plat_stats(&s);
    float px = g_px > 2 ? g_px - 1 : g_px;
    snprintf(b, sizeof b, "%3.0f FPS  logic %3.0f (%.1f ms)  %3.0f Hz  input %4.1f ms = %.2f f, max %.2f f%s",
             s.render_fps, s.logic_fps, s.update_ms, s.refresh_hz, s.lat_avg_ms, s.lat_avg_ms / (1000.f / 60.f),
             s.lat_max_ms / (1000.f / 60.f), s.dropped_render ? "  skip" : "");
    float w = r_overlay_text_width(px, b);
    r_overlay_rect(4, 4, w + 6 * px, 10 * px, 0xA0000000);
    r_overlay_text(4 + 3 * px, 4 + 1.5f * px, px, 0xFF80FF80, b);
    (void)W; (void)H;
}

void fe_ui_render(int W, int H)
{
    TouchPad *t = plat_touch();
    if (O.touch_show == 1) plat_set_touch_visible(1);
    else if (O.touch_show == 2) { plat_set_touch_visible(0); touch_release_all(t); }
    O.pres.valign_top = t->visible && H > W;
    int x, y, w, h;
    r_present_rect(W, H, &O.pres, &x, &y, &w, &h);
    if (t->w != W || t->h != H || (t->portrait && t->picture_bottom != (float)(y + h))) {
        t->scale = O.touch_size;
        touch_layout_ex(t, W, H, H > W ? (float)(y + h) : 0.f);
    }
    if (M.open) menu_input();
    r_present_ex(W, H, &O.pres);
    g_px = (float)(H / 220 > 1 ? H / 220 : 1);
    if (g_px > 6) g_px = 6;
    r_overlay_begin(W, H);
    if (!M.open) draw_touch(W, H);
    if (O.show_fps) draw_fps(W, H);
    if (M.open) draw_menu(W, H);
    r_overlay_end();
    /* web: keep the audio queue topped up (~2.5 display frames ahead, at least 50 ms) */
    {
        static const double fixed[] = { 0, 0.04, 0.08, 0.15 };
        PlatStats s;
        plat_stats(&s);
        double fr = s.render_fps > 1 ? 1.0 / s.render_fps : 1.0 / 30;
        double ahead = O.audio_latency ? fixed[O.audio_latency] : 2.5 * fr;
        if (ahead < 0.05 && !O.audio_latency) ahead = 0.05;
        if (ahead > 0.3) ahead = 0.3;
        if (ahead < fr * 1.5) ahead = fr * 1.5;
        fe_audio_pump(ahead);
    }
}

/* ------------------------------------------------------------- web exports */
#ifdef __EMSCRIPTEN__
#define WEBAPI EMSCRIPTEN_KEEPALIVE
#else
#define WEBAPI
#endif

WEBAPI const char *mvc2_settings_json(void) { return settings_json(); }
WEBAPI void mvc2_setting_set(const char *key, const char *value)
{
    const SetDesc *d = settings_find(key);
    if (d && d->type == SET_ACTION) { if (d->apply) d->apply(1); return; }
    settings_set(key, value);
}
WEBAPI void mvc2_ui_hold(int on) { O.web_panel = on != 0; hold_changed(); }
WEBAPI void mvc2_menu_open(int on) { fe_ui_menu_open(on); }
WEBAPI void mvc2_bind_capture(int player, int kind, int act) { input_capture_begin(player, kind, act); }
WEBAPI void mvc2_bind_cancel(void) { input_capture_cancel(); }
WEBAPI void mvc2_bind_clear(int player, int kind, int act) { input_bind_set(player, kind, act, -1); }
WEBAPI void mvc2_bind_reset(int player) { input_bind_reset(player); }

static char g_json[8192];
static size_t jcat(size_t n, const char *s)
{
    for (; *s && n + 2 < sizeof g_json; s++) {
        if (*s == '"' || *s == '\\') g_json[n++] = '\\';
        g_json[n++] = *s;
    }
    g_json[n] = 0;
    return n;
}
static size_t jraw(size_t n, const char *s)
{
    size_t l = strlen(s);
    if (n + l + 1 >= sizeof g_json) return n;
    memcpy(g_json + n, s, l + 1);
    return n + l;
}

/* {"actions":[[name,label],..],"players":[{"style":s,"kb":[..],"pad":[..]},..],
 *  "pads":[{"name":..,"style":..,"player":..}],"capture":[p,kind,act]|null} */
WEBAPI const char *mvc2_bind_json(void)
{
    char b[64];
    size_t n = 0;
    n = jraw(n, "{\"actions\":[");
    for (int a = 0; a < ACT_COUNT; a++) {
        n = jraw(n, a ? ",[\"" : "[\"");
        n = jcat(n, input_action_name(a));
        n = jraw(n, "\",\"");
        n = jcat(n, input_action_label(a));
        n = jraw(n, "\"]");
    }
    n = jraw(n, "],\"players\":[");
    for (int p = 0; p < INPUT_PLAYERS; p++) {
        int st = player_style(p);
        snprintf(b, sizeof b, "%s{\"style\":%d", p ? "," : "", st);
        n = jraw(n, b);
        for (int k = 0; k < 2; k++) {
            n = jraw(n, k ? ",\"pad\":[" : ",\"kb\":[");
            for (int a = 0; a < ACT_COUNT; a++) {
                n = jraw(n, a ? ",\"" : "\"");
                n = jcat(n, input_binding_text(p, k ? BIND_PAD : BIND_KB, a, st));
                n = jraw(n, "\"");
            }
            n = jraw(n, "]");
        }
        n = jraw(n, "}");
    }
    n = jraw(n, "],\"pads\":[");
    for (int s = 0, first = 1; s < PLAT_MAX_PADS; s++) {
        if (!plat_pad_connected(s)) continue;
        snprintf(b, sizeof b, "%s{\"player\":%d,\"style\":%d,\"name\":\"", first ? "" : ",", input_pad_player(s), plat_pad_style(s));
        n = jraw(n, b);
        n = jcat(n, plat_pad_name(s) ? plat_pad_name(s) : "?");
        n = jraw(n, "\"}");
        first = 0;
    }
    int cp, ck, ca;
    if (input_capture_active(&cp, &ck, &ca)) snprintf(b, sizeof b, "],\"capture\":[%d,%d,%d]}", cp, ck, ca);
    else snprintf(b, sizeof b, "],\"capture\":null}");
    n = jraw(n, b);
    return g_json;
}

WEBAPI const char *mvc2_stats_json(void)
{
    static char b[512];
    PlatStats s;
    plat_stats(&s);
    snprintf(b, sizeof b,
             "{\"render_fps\":%.1f,\"logic_fps\":%.1f,\"refresh_hz\":%.1f,\"lat_avg_ms\":%.2f,\"lat_max_ms\":%.2f,"
             "\"lat_last_ms\":%.2f,\"lat_samples\":%d,\"lat_avg_frames\":%.3f,\"lat_max_frames\":%.3f,"
             "\"dropped_render\":%d,\"slowed\":%d,\"hold\":%d,\"frame\":%ld,\"p1\":%u,\"p2\":%u,"
             "\"update_ms\":%.2f,\"render_ms\":%.2f}",
             s.render_fps, s.logic_fps, s.refresh_hz, s.lat_avg_ms, s.lat_max_ms, s.lat_last_ms, s.lat_samples,
             s.lat_avg_ms / (1000.0 / 60), s.lat_max_ms / (1000.0 / 60), s.dropped_render, s.slowed, plat_hold(),
             (long)mvc2_host_frame, plat_pad(0)->buttons, plat_pad(1)->buttons, s.update_ms, s.render_ms);
    return b;
}
