#include "platform.h"
#include "input.h"
#include "gl.h"
#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

#define LAT_N 32

static struct {
    SDL_Window *win;
    SDL_GLContext ctx;
    char gl_desc[160];
    int quit;
    int paused, paused_reported;
    int hold;
    int fixed_step, step_last, max_steps, frame_skip, force_render;
    double last;            /* seconds */
    double acc;
    PlatApp *app;
    /* players (after mapping) */
    PadRaw pads[PLAT_MAX_PADS];
    /* gamepad slots */
    SDL_GameController *gc[PLAT_MAX_PADS];
    SDL_Joystick *js[PLAT_MAX_PADS]; /* fallback: browser "standard" gamepads without a mapping */
    uint32_t padin[PLAT_MAX_PADS], padin_prev[PLAT_MAX_PADS], pad_swallow[PLAT_MAX_PADS], padraw[PLAT_MAX_PADS];
    int pad_style[PLAT_MAX_PADS];
    /* keyboard, from events: taps shorter than a frame still register */
    Uint8 kdown[SDL_NUM_SCANCODES], klatch[SDL_NUM_SCANCODES], krep[SDL_NUM_SCANCODES];
    Uint8 kswallow[SDL_NUM_SCANCODES];
    Uint8 keys_prev[SDL_NUM_SCANCODES], keys_now[SDL_NUM_SCANCODES], keys_rep[SDL_NUM_SCANCODES];
    TouchPad touch;
    int mouse_touch; /* desktop: mouse drives the touch overlay while it is visible */
    /* latency: press events waiting for the next logic step */
    Uint32 pend_ts[16];
    int npend;
    float lat[LAT_N];
    int lat_n, lat_i;
    float lat_last;
    /* rates */
    double rate_t0;
    int rate_frames, rate_steps, rate_dropped;
    PlatStats st;
    double frame_dt_avg;
} P;

static void open_controllers(void);
static double now_s(void) { return (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency(); }

static void set_paused(int p)
{
    if (P.paused == p) return;
    P.paused = p;
    /* report now: a hidden browser tab gets no more animation frames */
    if (P.app && P.paused_reported != p) {
        P.paused_reported = p;
        if (P.app->on_pause) P.app->on_pause(P.app->user, p);
    }
    P.acc = 0;
    if (!p) P.last = now_s();
    if (p) {
        memset(P.kdown, 0, sizeof P.kdown);
        touch_release_all(&P.touch);
    }
}

#ifdef __EMSCRIPTEN__
/* Input latency on the web: SDL's event timestamps are not on the page's clock,
 * so the page records performance.now() for every key / pointer / touch press
 * (capture phase, before SDL sees it), and for gamepads the Gamepad.timestamp
 * of a sample with a newly pressed button; the poll before each logic step
 * turns them into "event -> logic step" times. */
EM_JS(void, web_input_times_install, (void), {
    if (Module.__inT) return;
    var q = Module.__inT = [];
    var push = function(e) { if (e.repeat) return; q.push(performance.now()); if (q.length > 32) q.shift(); };
    ['keydown', 'pointerdown', 'touchstart'].forEach(function(t) {
        window.addEventListener(t, push, { capture: true, passive: true });
    });
});
EM_JS(int, web_input_latencies, (float *out, int max), {
    var now = performance.now(), n = 0, q = Module.__inT || [];
    while (q.length && n < max) HEAPF32[(out >> 2) + n++] = now - q.shift();
    try {
        var pads = navigator.getGamepads ? navigator.getGamepads() : [];
        var last = Module.__padPrev || (Module.__padPrev = {});
        for (var i = 0; i < pads.length; i++) {
            var p = pads[i];
            if (!p) continue;
            var mask = 0;
            for (var b = 0; b < p.buttons.length && b < 31; b++) if (p.buttons[b].pressed) mask |= 1 << b;
            var prev = last[i] || 0;
            last[i] = mask;
            if ((mask & ~prev) && n < max && p.timestamp > 0 && p.timestamp <= now) HEAPF32[(out >> 2) + n++] = now - p.timestamp;
        }
    } catch (e) {}
    return n;
});

static EM_BOOL on_visibility(int type, const EmscriptenVisibilityChangeEvent *e, void *u)
{
    (void)type; (void)u;
    set_paused(e->hidden ? 1 : 0);
    return 0;
}
#endif

int plat_init(const PlatConfig *cfg)
{
    memset(&P, 0, sizeof P);
    P.max_steps = 8;
    P.frame_skip = 1;
    SDL_SetHint(SDL_HINT_TOUCH_MOUSE_EVENTS, "0");
    SDL_SetHint(SDL_HINT_MOUSE_TOUCH_EVENTS, "0");
    /* positional face buttons on Nintendo pads too (south = B on a Switch pad) */
    SDL_SetHint(SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS, "0");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "0");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0) {
        /* controllers are optional (headless containers have no joystick subsystem) */
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
            fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
            return -1;
        }
    }
    Uint32 wflags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    if (cfg->hidden) wflags |= SDL_WINDOW_HIDDEN;
#ifndef __EMSCRIPTEN__
    if (cfg->fullscreen && !cfg->hidden) wflags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
#endif
    int is_es = 0;
    for (int attempt = cfg->force_desktop_gl ? 1 : 0; attempt < 2 && !P.ctx; attempt++) {
        SDL_GL_ResetAttributes();
        if (attempt == 0) {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        } else {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        }
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);   /* game renders into its own FBO */
        if (P.win) SDL_DestroyWindow(P.win);
        P.win = SDL_CreateWindow(cfg->title ? cfg->title : "mvc2", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, cfg->width, cfg->height, wflags);
        if (!P.win) continue;
        P.ctx = SDL_GL_CreateContext(P.win);
        is_es = attempt == 0;
    }
    if (!P.ctx) {
        fprintf(stderr, "no GL ES 3.0 / GL 3.3 context: %s\n", SDL_GetError());
        return -1;
    }
    SDL_GL_MakeCurrent(P.win, P.ctx);
    if (gl_load(is_es)) return -1;
    plat_set_vsync(cfg->vsync);
    snprintf(P.gl_desc, sizeof P.gl_desc, "%s | %s | %s", is_es ? "GLES3 ctx" : "GL3.3 core ctx",
             (const char *)glGetString(GL_VERSION), (const char *)glGetString(GL_RENDERER));
#ifdef __EMSCRIPTEN__
    emscripten_set_visibilitychange_callback(NULL, 0, on_visibility);
    web_input_times_install();
#endif
    int w, h;
    plat_drawable_size(&w, &h);
    touch_layout(&P.touch, w, h);
    open_controllers();
    P.last = now_s();
    P.rate_t0 = P.last;
    return 0;
}

void plat_shutdown(void)
{
    for (int i = 0; i < PLAT_MAX_PADS; i++) {
        if (P.gc[i]) SDL_GameControllerClose(P.gc[i]);
        if (P.js[i]) SDL_JoystickClose(P.js[i]);
    }
    if (P.ctx) SDL_GL_DeleteContext(P.ctx);
    if (P.win) SDL_DestroyWindow(P.win);
    SDL_Quit();
}

void plat_drawable_size(int *w, int *h) { SDL_GL_GetDrawableSize(P.win, w, h); }
void plat_swap(void) { SDL_GL_SwapWindow(P.win); }
const char *plat_gl_description(void) { return P.gl_desc; }
void plat_request_quit(void) { P.quit = 1; }
int plat_quit_requested(void) { return P.quit; }
void plat_set_fixed_step(int on) { P.fixed_step = on; }
int plat_paused(void) { return P.paused; }
void plat_set_hold(int on) { P.hold = on != 0; P.acc = 0; P.force_render = 1; }
int plat_hold(void) { return P.hold; }
int plat_step_is_last(void) { return P.step_last; }
void plat_set_max_steps(int n) { P.max_steps = n < 1 ? 1 : n > 8 ? 8 : n; }
void plat_set_frame_skip(int on) { P.frame_skip = on != 0; }
void plat_request_render(void) { P.force_render = 1; }
TouchPad *plat_touch(void) { return &P.touch; }
void plat_set_touch_visible(int on) { if (P.touch.visible != on) P.force_render = 1; P.touch.visible = on; }
const PadRaw *plat_pad(int port) { return &P.pads[port < 0 || port >= PLAT_MAX_PADS ? 0 : port]; }
int plat_key_held(int sc) { return sc > 0 && sc < SDL_NUM_SCANCODES && P.keys_now[sc]; }
int plat_key_hit(int sc) { return sc > 0 && sc < SDL_NUM_SCANCODES && P.keys_now[sc] && !P.keys_prev[sc]; }
int plat_key_repeat(int sc) { return plat_key_hit(sc) || (sc > 0 && sc < SDL_NUM_SCANCODES && P.keys_rep[sc]); }
int plat_pad_connected(int s) { return s >= 0 && s < PLAT_MAX_PADS && (P.gc[s] || P.js[s]); }
int plat_pad_style(int s) { return s >= 0 && s < PLAT_MAX_PADS ? P.pad_style[s] : 0; }
uint32_t plat_padin(int s) { return s >= 0 && s < PLAT_MAX_PADS ? P.padin[s] : 0; }
uint32_t plat_padin_hit(int s) { return s >= 0 && s < PLAT_MAX_PADS ? P.padin[s] & ~P.padin_prev[s] : 0; }

void plat_input_swallow_held(void)
{
    for (int i = 0; i < SDL_NUM_SCANCODES; i++)
        if (P.kdown[i] || P.klatch[i]) P.kswallow[i] = 1;
    memset(P.klatch, 0, sizeof P.klatch);
    for (int s = 0; s < PLAT_MAX_PADS; s++) P.pad_swallow[s] |= P.padraw[s];
    touch_release_all(&P.touch);
}

const char *plat_pad_name(int s)
{
    if (s < 0 || s >= PLAT_MAX_PADS) return NULL;
    /* the device's own name (on the web: the Gamepad API id, with the vendor id) */
    if (P.gc[s]) return SDL_JoystickName(SDL_GameControllerGetJoystick(P.gc[s]));
    if (P.js[s]) return SDL_JoystickName(P.js[s]);
    return NULL;
}

void plat_set_vsync(int on)
{
#ifndef __EMSCRIPTEN__
    if (P.win) SDL_GL_SetSwapInterval(on ? 1 : 0);
#else
    (void)on;
#endif
}

void plat_set_fullscreen(int on)
{
    if (!P.win) return;
    SDL_SetWindowFullscreen(P.win, on ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    P.force_render = 1;
}

int plat_fullscreen(void)
{
    return P.win && (SDL_GetWindowFlags(P.win) & (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP)) != 0;
}

static int pad_slot_has(SDL_JoystickID id)
{
    for (int i = 0; i < PLAT_MAX_PADS; i++) {
        if (P.gc[i] && SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(P.gc[i])) == id) return 1;
        if (P.js[i] && SDL_JoystickInstanceID(P.js[i]) == id) return 1;
    }
    return 0;
}

static int style_of(int k)
{
    if (P.gc[k]) {
#if SDL_VERSION_ATLEAST(2, 0, 12)
        switch (SDL_GameControllerGetType(P.gc[k])) {
        case SDL_CONTROLLER_TYPE_PS3:
        case SDL_CONTROLLER_TYPE_PS4:
        case SDL_CONTROLLER_TYPE_PS5: return PAD_STYLE_PLAYSTATION;
        case SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO: return PAD_STYLE_NINTENDO;
        default: break;
        }
#endif
    }
    return input_pad_style_from_name(plat_pad_name(k));
}

static void open_controllers(void)
{
    for (int i = 0; i < PLAT_MAX_PADS; i++) {
        if (P.gc[i] && !SDL_GameControllerGetAttached(P.gc[i])) { SDL_GameControllerClose(P.gc[i]); P.gc[i] = NULL; }
        if (P.js[i] && !SDL_JoystickGetAttached(P.js[i])) { SDL_JoystickClose(P.js[i]); P.js[i] = NULL; }
    }
    int n = SDL_NumJoysticks();
    for (int j = 0; j < n; j++) {
        if (pad_slot_has(SDL_JoystickGetDeviceInstanceID(j))) continue;
        int k = 0;
        while (k < PLAT_MAX_PADS && (P.gc[k] || P.js[k])) k++;
        if (k == PLAT_MAX_PADS) break;
        if (SDL_IsGameController(j)) P.gc[k] = SDL_GameControllerOpen(j);
        else P.js[k] = SDL_JoystickOpen(j);
        P.pad_style[k] = style_of(k);
        SDL_Log("pad slot %d: %s (%s)", k, plat_pad_name(k) ? plat_pad_name(k) : "?",
                P.gc[k] ? "game controller" : "joystick, standard layout");
    }
    P.force_render = 1;
}

static uint32_t axis_bits(int x, int y, int dz, int nx)
{
    uint32_t b = 0;
    if (x < -dz) b |= 1u << nx;
    if (x > dz) b |= 1u << (nx + 1);
    if (y < -dz) b |= 1u << (nx + 2);
    if (y > dz) b |= 1u << (nx + 3);
    return b;
}

/* W3C "standard" gamepad layout (index = PadIn for 0..16), used when SDL has no mapping. */
static uint32_t joystick_padin(SDL_Joystick *j, int dz)
{
    uint32_t s = 0;
    int nb = SDL_JoystickNumButtons(j), na = SDL_JoystickNumAxes(j);
    for (int b = 0; b < nb && b <= PI_GUIDE; b++)
        if (SDL_JoystickGetButton(j, b)) s |= 1u << b;
    if (na >= 2) s |= axis_bits(SDL_JoystickGetAxis(j, 0), SDL_JoystickGetAxis(j, 1), dz, PI_LX_NEG);
    if (na >= 4) s |= axis_bits(SDL_JoystickGetAxis(j, 2), SDL_JoystickGetAxis(j, 3), dz, PI_RX_NEG);
    if (SDL_JoystickNumHats(j) > 0) {
        Uint8 h = SDL_JoystickGetHat(j, 0);
        if (h & SDL_HAT_UP) s |= 1u << PI_UP;
        if (h & SDL_HAT_DOWN) s |= 1u << PI_DOWN;
        if (h & SDL_HAT_LEFT) s |= 1u << PI_LEFT;
        if (h & SDL_HAT_RIGHT) s |= 1u << PI_RIGHT;
    }
    return s;
}

static uint32_t controller_padin(SDL_GameController *c, int dz)
{
    static const struct { SDL_GameControllerButton b; int pi; } map[] = {
        { SDL_CONTROLLER_BUTTON_A, PI_SOUTH }, { SDL_CONTROLLER_BUTTON_B, PI_EAST },
        { SDL_CONTROLLER_BUTTON_X, PI_WEST }, { SDL_CONTROLLER_BUTTON_Y, PI_NORTH },
        { SDL_CONTROLLER_BUTTON_LEFTSHOULDER, PI_LB }, { SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, PI_RB },
        { SDL_CONTROLLER_BUTTON_BACK, PI_BACK }, { SDL_CONTROLLER_BUTTON_START, PI_START },
        { SDL_CONTROLLER_BUTTON_LEFTSTICK, PI_LS }, { SDL_CONTROLLER_BUTTON_RIGHTSTICK, PI_RS },
        { SDL_CONTROLLER_BUTTON_DPAD_UP, PI_UP }, { SDL_CONTROLLER_BUTTON_DPAD_DOWN, PI_DOWN },
        { SDL_CONTROLLER_BUTTON_DPAD_LEFT, PI_LEFT }, { SDL_CONTROLLER_BUTTON_DPAD_RIGHT, PI_RIGHT },
        { SDL_CONTROLLER_BUTTON_GUIDE, PI_GUIDE },
    };
    uint32_t s = 0;
    for (size_t i = 0; i < sizeof map / sizeof map[0]; i++)
        if (SDL_GameControllerGetButton(c, map[i].b)) s |= 1u << map[i].pi;
    if (SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 16000) s |= 1u << PI_LT;
    if (SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 16000) s |= 1u << PI_RT;
    s |= axis_bits(SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX),
                   SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY), dz, PI_LX_NEG);
    s |= axis_bits(SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_RIGHTX),
                   SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_RIGHTY), dz, PI_RX_NEG);
    return s;
}

static void note_press(Uint32 ts)
{
    if (P.npend < (int)(sizeof P.pend_ts / sizeof P.pend_ts[0])) P.pend_ts[P.npend++] = ts;
}

static void handle_event(const SDL_Event *e)
{
    int w, h;
    switch (e->type) {
    case SDL_QUIT: P.quit = 1; break;
    case SDL_APP_WILLENTERBACKGROUND:
    case SDL_APP_DIDENTERBACKGROUND: set_paused(1); break;
    case SDL_APP_WILLENTERFOREGROUND:
    case SDL_APP_DIDENTERFOREGROUND: set_paused(0); break;
    case SDL_WINDOWEVENT:
        switch (e->window.event) {
        case SDL_WINDOWEVENT_MINIMIZED:
        case SDL_WINDOWEVENT_HIDDEN: set_paused(1); break;
        case SDL_WINDOWEVENT_RESTORED:
        case SDL_WINDOWEVENT_SHOWN: set_paused(0); break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            touch_release_all(&P.touch);
            memset(P.kdown, 0, sizeof P.kdown); /* no stuck keys after alt-tab */
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
        case SDL_WINDOWEVENT_EXPOSED:
            plat_drawable_size(&w, &h);
            if (w != P.touch.w || h != P.touch.h) touch_layout(&P.touch, w, h);
            P.force_render = 1;
            break;
        }
        break;
    case SDL_KEYDOWN:
    case SDL_KEYUP: {
        int sc = e->key.keysym.scancode;
        if (sc <= 0 || sc >= SDL_NUM_SCANCODES) break;
        if (e->type == SDL_KEYUP) { P.kdown[sc] = 0; P.kswallow[sc] = 0; break; }
        if (e->key.repeat) { P.krep[sc] = 1; break; }
        if (input_capture_key(sc)) { P.kswallow[sc] = 1; P.force_render = 1; break; }
        P.kdown[sc] = 1;
        P.klatch[sc] = 1;
        note_press(e->key.timestamp);
        break;
    }
    case SDL_CONTROLLERBUTTONDOWN: note_press(e->cbutton.timestamp); break;
    case SDL_JOYBUTTONDOWN: note_press(e->jbutton.timestamp); break;
    case SDL_CONTROLLERDEVICEADDED:
    case SDL_CONTROLLERDEVICEREMOVED:
    case SDL_JOYDEVICEADDED:
    case SDL_JOYDEVICEREMOVED: open_controllers(); break;
    case SDL_FINGERDOWN:
    case SDL_FINGERMOTION:
    case SDL_FINGERUP:
        plat_drawable_size(&w, &h);
        if (w != P.touch.w || h != P.touch.h) touch_layout(&P.touch, w, h);
        if (e->type == SDL_FINGERDOWN) note_press(e->tfinger.timestamp);
        touch_finger(&P.touch, (long long)e->tfinger.fingerId, e->type != SDL_FINGERUP,
                     e->tfinger.x * w, e->tfinger.y * h);
        P.force_render = 1;
        break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEMOTION:
        if (!P.touch.visible) break;
        {
            int ww, wh;
            SDL_GetWindowSize(P.win, &ww, &wh);
            plat_drawable_size(&w, &h);
            int down = e->type == SDL_MOUSEBUTTONDOWN ? 1 : e->type == SDL_MOUSEBUTTONUP ? 0 : P.mouse_touch;
            if (e->type == SDL_MOUSEMOTION && !P.mouse_touch) break;
            P.mouse_touch = down;
            float mx = (float)(e->type == SDL_MOUSEMOTION ? e->motion.x : e->button.x);
            float my = (float)(e->type == SDL_MOUSEMOTION ? e->motion.y : e->button.y);
            touch_finger(&P.touch, -1000, down, mx * w / (ww ? ww : 1), my * h / (wh ? wh : 1));
        }
        break;
    }
}

void plat_poll_input(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) handle_event(&e);
    memcpy(P.keys_prev, P.keys_now, sizeof P.keys_now);
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        P.keys_now[i] = (Uint8)((P.kdown[i] | P.klatch[i]) & !P.kswallow[i]);
        P.keys_rep[i] = P.krep[i];
    }
    memset(P.klatch, 0, sizeof P.klatch);
    memset(P.krep, 0, sizeof P.krep);

    /* gamepads (polled: the web Gamepad API has no events) */
    int dz = input_stick_deadzone() * 256;
    for (int s = 0; s < PLAT_MAX_PADS; s++) {
        P.padin_prev[s] = P.padin[s];
        uint32_t v = P.gc[s] ? controller_padin(P.gc[s], dz) : P.js[s] ? joystick_padin(P.js[s], dz) : 0;
        uint32_t fresh = v & ~P.padin_prev[s];
        if (fresh && input_capture_active(NULL, NULL, NULL)) {
            for (int b = 0; b < PI_COUNT; b++)
                if (fresh & (1u << b)) {
                    if (input_capture_pad(b)) { P.pad_swallow[s] |= 1u << b; P.force_render = 1; }
                    break;
                }
        }
        P.padraw[s] = v;
        P.pad_swallow[s] &= v;            /* released: no longer swallowed */
        P.padin[s] = v & ~P.pad_swallow[s];
        if (P.padin[s] & ~P.padin_prev[s]) P.force_render = 1;
    }

    /* players */
    for (int i = 0; i < PLAT_MAX_PADS; i++) {
        PadRaw *p = &P.pads[i];
        memset(p, 0, sizeof *p);
        p->lx = p->ly = p->rx = p->ry = 0x80;
        p->connected = 1; /* the game always sees two pads, like DualShocks in both ports */
        p->analog = 0;    /* sticks arrive as directions (input.stick_dpad) */
        p->buttons = input_map_keys(i, P.keys_now, SDL_NUM_SCANCODES);
    }
    for (int s = 0; s < PLAT_MAX_PADS; s++)
        if (P.gc[s] || P.js[s]) P.pads[input_pad_player(s)].buttons |= input_map_pad(input_pad_player(s), P.padin[s]);
    P.pads[0].buttons |= touch_buttons(&P.touch);

    /* latency: every press seen in this poll reaches the logic step that follows */
    {
        float ms[16];
        int n = 0;
#ifdef __EMSCRIPTEN__
        n = web_input_latencies(ms, 16);
#else
        Uint32 t = SDL_GetTicks();
        for (int k = 0; k < P.npend && n < 16; k++) ms[n++] = (float)(Uint32)(t - P.pend_ts[k]);
#endif
        P.npend = 0;
        for (int k = 0; k < n && !P.hold; k++) {
            if (ms[k] < 0 || ms[k] > 1000) continue;  /* not a game press (or a stall) */
            P.lat[P.lat_i] = ms[k];
            P.lat_i = (P.lat_i + 1) % LAT_N;
            if (P.lat_n < LAT_N) P.lat_n++;
            P.lat_last = ms[k];
        }
    }
}

void plat_stats(PlatStats *s)
{
    *s = P.st;
    float sum = 0, mx = 0;
    for (int i = 0; i < P.lat_n; i++) { sum += P.lat[i]; if (P.lat[i] > mx) mx = P.lat[i]; }
    s->lat_avg_ms = P.lat_n ? sum / P.lat_n : 0;
    s->lat_max_ms = mx;
    s->lat_last_ms = P.lat_last;
    s->lat_samples = P.lat_n;
}

/* Snap a measured frame time to a common display interval (vsync jitter). */
static double snap_dt(double dt)
{
    static const double hz[] = { 60, 120, 144, 165, 240, 75, 90, 100, 50, 30 };
    for (size_t i = 0; i < sizeof hz / sizeof hz[0]; i++) {
        double p = 1.0 / hz[i];
        if (fabs(dt - p) < 0.0005 + p * 0.02) return p;
    }
    return dt;
}

static void count_rates(double now, int steps, int presented)
{
    P.rate_frames += presented;
    P.rate_steps += steps;
    if (now - P.rate_t0 >= 1.0) {
        double span = now - P.rate_t0;
        P.st.render_fps = (float)(P.rate_frames / span);
        P.st.logic_fps = (float)(P.rate_steps / span);
        P.st.dropped_render = P.rate_dropped;
        P.st.refresh_hz = P.frame_dt_avg > 0 ? (float)(1.0 / P.frame_dt_avg) : 0;
        P.rate_frames = P.rate_steps = P.rate_dropped = 0;
        P.rate_t0 = now;
    }
}

static void frame_at(PlatApp *app, double now)
{
    const double step = 1.0 / PLAT_HZ;
    double dt = now - P.last;
    P.last = now;
    P.app = app;
    if (P.paused != P.paused_reported) {
        P.paused_reported = P.paused;
        if (app->on_pause) app->on_pause(app->user, P.paused);
        P.acc = 0;
    }
    if (P.paused) {
        SDL_Event e;               /* keep pumping so we notice the resume */
        while (SDL_PollEvent(&e)) handle_event(&e);
#ifndef __EMSCRIPTEN__
        SDL_Delay(50);
#endif
        return;
    }
    if (dt > 0 && dt < 0.25) P.frame_dt_avg = P.frame_dt_avg ? P.frame_dt_avg * 0.95 + dt * 0.05 : dt;
    if (P.hold) {
        plat_poll_input();
        P.acc = 0;
        app->render(app->user);
        plat_swap();
        P.force_render = 0;
        count_rates(now, 0, 1);
#ifndef __EMSCRIPTEN__
        SDL_Delay(1);
#endif
        return;
    }
    int steps = 0;
    if (P.fixed_step) {
        plat_poll_input();
        P.step_last = 1;
        app->update(app->user);
        steps = 1;
    } else {
        dt = snap_dt(dt);
        if (dt > 0.25) dt = 0.25;  /* after a stall, do not spiral */
        if (dt < 0) dt = 0;
        P.acc += dt;
        int n = (int)((P.acc + 1e-6) / step);
        if (n > P.max_steps) {
            P.st.slowed += n - P.max_steps;
            n = P.max_steps;
            P.acc = 0;
        } else {
            P.acc -= n * step;
            if (P.acc < 0) P.acc = 0;
        }
        for (int i = 0; i < n; i++) {
            plat_poll_input();     /* sampled immediately before each update */
            P.step_last = !P.frame_skip || i == n - 1;
            double t0 = now_s();
            app->update(app->user);
            P.st.update_ms = P.st.update_ms * 0.9f + (float)((now_s() - t0) * 1000.0) * 0.1f;
            steps++;
        }
        if (n > 1 && P.frame_skip) P.rate_dropped += n - 1;
        if (n == 0) {
            /* still pump events so the window stays responsive */
            SDL_PumpEvents();
        }
    }
    int present = steps > 0 || P.force_render;
    if (present) {
        double t0 = now_s();
        app->render(app->user);
        plat_swap();
        P.st.render_ms = P.st.render_ms * 0.9f + (float)((now_s() - t0) * 1000.0) * 0.1f;
        P.force_render = 0;
    }
    count_rates(now, steps, present);
#ifndef __EMSCRIPTEN__
    if (!present && !P.fixed_step) SDL_Delay(1);
#endif
}

void plat_frame(PlatApp *app) { frame_at(app, now_s()); }

#ifdef __EMSCRIPTEN__
/* requestAnimationFrame passes the frame's vsync timestamp: steadier than
 * reading the clock inside the callback. */
static EM_BOOL em_frame(double t_ms, void *arg)
{
    PlatApp *app = (PlatApp *)arg;
    frame_at(app, t_ms / 1000.0);
    return P.quit ? EM_FALSE : EM_TRUE;
}
#endif

void plat_run(PlatApp *app)
{
    P.app = app;
#ifdef __EMSCRIPTEN__
    P.last = emscripten_performance_now() / 1000.0;
    P.rate_t0 = P.last;
    emscripten_request_animation_frame_loop(em_frame, app);
    emscripten_exit_with_live_runtime();
#else
    P.last = now_s();
    while (!P.quit) plat_frame(app);
#endif
}
