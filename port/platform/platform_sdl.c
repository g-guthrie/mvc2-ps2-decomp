#include "platform.h"
#include "gl.h"
#include <SDL.h>
#include <stdio.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

static struct {
    SDL_Window *win;
    SDL_GLContext ctx;
    char gl_desc[160];
    int quit;
    int paused, paused_reported;
    int fixed_step;
    Uint64 last;
    double acc;
    PadRaw pads[PLAT_MAX_PADS];
    SDL_GameController *gc[PLAT_MAX_PADS];
    SDL_Joystick *js[PLAT_MAX_PADS]; /* fallback: browser "standard" gamepads without a mapping */
    Uint8 keys_prev[SDL_NUM_SCANCODES];
    Uint8 keys_now[SDL_NUM_SCANCODES];
    TouchPad touch;
    int mouse_touch; /* desktop: mouse drives the touch overlay while it is visible */
} P;

static void open_controllers(void);

#ifdef __EMSCRIPTEN__
static EM_BOOL on_visibility(int type, const EmscriptenVisibilityChangeEvent *e, void *u)
{
    (void)type; (void)u;
    P.paused = e->hidden ? 1 : 0;
    return 0;
}
#endif

int plat_init(const PlatConfig *cfg)
{
    memset(&P, 0, sizeof P);
    SDL_SetHint(SDL_HINT_TOUCH_MOUSE_EVENTS, "0");
    SDL_SetHint(SDL_HINT_MOUSE_TOUCH_EVENTS, "0");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0) {
        /* controllers are optional (headless containers have no joystick subsystem) */
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
            fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
            return -1;
        }
    }
    Uint32 wflags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    if (cfg->hidden) wflags |= SDL_WINDOW_HIDDEN;
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
    SDL_GL_SetSwapInterval(cfg->vsync ? 1 : 0);
    snprintf(P.gl_desc, sizeof P.gl_desc, "%s | %s | %s", is_es ? "GLES3 ctx" : "GL3.3 core ctx",
             (const char *)glGetString(GL_VERSION), (const char *)glGetString(GL_RENDERER));
#ifdef __EMSCRIPTEN__
    emscripten_set_visibilitychange_callback(NULL, 0, on_visibility);
#endif
    int w, h;
    plat_drawable_size(&w, &h);
    touch_layout(&P.touch, w, h);
    open_controllers();
    P.last = SDL_GetPerformanceCounter();
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
TouchPad *plat_touch(void) { return &P.touch; }
void plat_set_touch_visible(int on) { P.touch.visible = on; }
const PadRaw *plat_pad(int port) { return &P.pads[port < 0 || port >= PLAT_MAX_PADS ? 0 : port]; }
int plat_key_held(int sc) { return sc > 0 && sc < SDL_NUM_SCANCODES && P.keys_now[sc]; }
int plat_key_hit(int sc) { return sc > 0 && sc < SDL_NUM_SCANCODES && P.keys_now[sc] && !P.keys_prev[sc]; }

static int pad_slot_has(SDL_JoystickID id)
{
    for (int i = 0; i < PLAT_MAX_PADS; i++) {
        if (P.gc[i] && SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(P.gc[i])) == id) return 1;
        if (P.js[i] && SDL_JoystickInstanceID(P.js[i]) == id) return 1;
    }
    return 0;
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
    }
}

/* W3C "standard" gamepad layout, used when SDL has no controller mapping. */
static void joystick_fill(SDL_Joystick *j, PadRaw *p)
{
    static const uint16_t map[16] = {
        PS2_CROSS, PS2_CIRCLE, PS2_SQUARE, PS2_TRIANGLE, PS2_L1, PS2_R1, PS2_L2, PS2_R2,
        PS2_SELECT, PS2_START, PS2_L3, PS2_R3, PS2_UP, PS2_DOWN, PS2_LEFT, PS2_RIGHT };
    int nb = SDL_JoystickNumButtons(j), na = SDL_JoystickNumAxes(j);
    for (int b = 0; b < nb && b < 16; b++)
        if (SDL_JoystickGetButton(j, b)) p->buttons |= map[b];
    if (na >= 2) {
        int x = 0x80 + SDL_JoystickGetAxis(j, 0) / 256, y = 0x80 + SDL_JoystickGetAxis(j, 1) / 256;
        p->lx = (uint8_t)(x < 0 ? 0 : x > 255 ? 255 : x);
        p->ly = (uint8_t)(y < 0 ? 0 : y > 255 ? 255 : y);
        p->analog = 1;
    }
    if (na >= 4) {
        int x = 0x80 + SDL_JoystickGetAxis(j, 2) / 256, y = 0x80 + SDL_JoystickGetAxis(j, 3) / 256;
        p->rx = (uint8_t)(x < 0 ? 0 : x > 255 ? 255 : x);
        p->ry = (uint8_t)(y < 0 ? 0 : y > 255 ? 255 : y);
    }
}

static void set_paused(int p) { P.paused = p; }

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
        case SDL_WINDOWEVENT_FOCUS_LOST: touch_release_all(&P.touch); break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            plat_drawable_size(&w, &h);
            touch_layout(&P.touch, w, h);
            break;
        }
        break;
    case SDL_CONTROLLERDEVICEADDED:
    case SDL_CONTROLLERDEVICEREMOVED:
    case SDL_JOYDEVICEADDED:
    case SDL_JOYDEVICEREMOVED: open_controllers(); break;
    case SDL_FINGERDOWN:
    case SDL_FINGERMOTION:
    case SDL_FINGERUP:
        plat_drawable_size(&w, &h);
        if (w != P.touch.w || h != P.touch.h) touch_layout(&P.touch, w, h);
        touch_finger(&P.touch, (long long)e->tfinger.fingerId, e->type != SDL_FINGERUP,
                     e->tfinger.x * w, e->tfinger.y * h);
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

static int axis_byte(Sint16 v) { int b = 0x80 + v / 256; return b < 0 ? 0 : b > 255 ? 255 : b; }

/* Keyboard (player 1):
 *   arrows = d-pad, A S D = LP HP A1 (SQUARE TRIANGLE L1), Z X C = LK HK A2
 *   (CROSS CIRCLE R1), Q W = L2 R2, Enter = START, Right Shift = SELECT. */
static uint16_t keyboard_bits(void)
{
    static const struct { int sc; uint16_t bit; } map[] = {
        { SDL_SCANCODE_UP, PS2_UP }, { SDL_SCANCODE_DOWN, PS2_DOWN },
        { SDL_SCANCODE_LEFT, PS2_LEFT }, { SDL_SCANCODE_RIGHT, PS2_RIGHT },
        { SDL_SCANCODE_A, PS2_SQUARE }, { SDL_SCANCODE_S, PS2_TRIANGLE }, { SDL_SCANCODE_D, PS2_L1 },
        { SDL_SCANCODE_Z, PS2_CROSS }, { SDL_SCANCODE_X, PS2_CIRCLE }, { SDL_SCANCODE_C, PS2_R1 },
        { SDL_SCANCODE_Q, PS2_L2 }, { SDL_SCANCODE_W, PS2_R2 },
        { SDL_SCANCODE_RETURN, PS2_START }, { SDL_SCANCODE_RSHIFT, PS2_SELECT },
    };
    uint16_t b = 0;
    for (size_t i = 0; i < sizeof map / sizeof map[0]; i++)
        if (P.keys_now[map[i].sc]) b |= map[i].bit;
    return b;
}

static void controller_fill(SDL_GameController *c, PadRaw *p)
{
    static const struct { SDL_GameControllerButton b; uint16_t bit; } map[] = {
        { SDL_CONTROLLER_BUTTON_A, PS2_CROSS }, { SDL_CONTROLLER_BUTTON_B, PS2_CIRCLE },
        { SDL_CONTROLLER_BUTTON_X, PS2_SQUARE }, { SDL_CONTROLLER_BUTTON_Y, PS2_TRIANGLE },
        { SDL_CONTROLLER_BUTTON_LEFTSHOULDER, PS2_L1 }, { SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, PS2_R1 },
        { SDL_CONTROLLER_BUTTON_LEFTSTICK, PS2_L3 }, { SDL_CONTROLLER_BUTTON_RIGHTSTICK, PS2_R3 },
        { SDL_CONTROLLER_BUTTON_BACK, PS2_SELECT }, { SDL_CONTROLLER_BUTTON_START, PS2_START },
        { SDL_CONTROLLER_BUTTON_DPAD_UP, PS2_UP }, { SDL_CONTROLLER_BUTTON_DPAD_DOWN, PS2_DOWN },
        { SDL_CONTROLLER_BUTTON_DPAD_LEFT, PS2_LEFT }, { SDL_CONTROLLER_BUTTON_DPAD_RIGHT, PS2_RIGHT },
    };
    for (size_t i = 0; i < sizeof map / sizeof map[0]; i++)
        if (SDL_GameControllerGetButton(c, map[i].b)) p->buttons |= map[i].bit;
    if (SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 16000) p->buttons |= PS2_L2;
    if (SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 16000) p->buttons |= PS2_R2;
    p->lx = (uint8_t)axis_byte(SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX));
    p->ly = (uint8_t)axis_byte(SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY));
    p->rx = (uint8_t)axis_byte(SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_RIGHTX));
    p->ry = (uint8_t)axis_byte(SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_RIGHTY));
    p->analog = 1;
}

void plat_poll_input(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) handle_event(&e);
    memcpy(P.keys_prev, P.keys_now, sizeof P.keys_now);
    int n = 0;
    const Uint8 *ks = SDL_GetKeyboardState(&n);
    memset(P.keys_now, 0, sizeof P.keys_now);
    memcpy(P.keys_now, ks, (size_t)(n < SDL_NUM_SCANCODES ? n : SDL_NUM_SCANCODES));
    for (int i = 0; i < PLAT_MAX_PADS; i++) {
        PadRaw *p = &P.pads[i];
        memset(p, 0, sizeof *p);
        p->lx = p->ly = p->rx = p->ry = 0x80;
        p->connected = 1; /* the game always sees two pads, like DualShocks in both ports */
        if (P.gc[i]) controller_fill(P.gc[i], p);
        else if (P.js[i]) joystick_fill(P.js[i], p);
    }
    P.pads[0].buttons |= keyboard_bits();
    P.pads[0].buttons |= touch_buttons(&P.touch);
}

void plat_frame(PlatApp *app)
{
    const double step = 1.0 / PLAT_HZ;
    Uint64 now = SDL_GetPerformanceCounter();
    double dt = (double)(now - P.last) / (double)SDL_GetPerformanceFrequency();
    P.last = now;
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
    if (P.fixed_step) {
        plat_poll_input();
        app->update(app->user);
    } else {
        if (dt > 0.25) dt = 0.25;  /* after a stall, do not spiral */
        P.acc += dt;
        int steps = 0;
        while (P.acc >= step && steps < 8) {
            plat_poll_input();     /* sampled immediately before each update */
            app->update(app->user);
            P.acc -= step;
            steps++;
        }
        if (steps == 0 && P.acc < step) {
            /* still pump events so the window stays responsive */
            SDL_PumpEvents();
        }
    }
    app->render(app->user);
    plat_swap();
}

#ifdef __EMSCRIPTEN__
static void em_frame(void *arg) { plat_frame((PlatApp *)arg); }
#endif

void plat_run(PlatApp *app)
{
    P.last = SDL_GetPerformanceCounter();
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(em_frame, app, 0, 0); /* rAF-driven, returns immediately */
#else
    while (!P.quit) {
        plat_frame(app);
        if (P.fixed_step) continue;
        /* without vsync, sleep until roughly the next step */
        SDL_Delay(1);
    }
#endif
}
