/* SDL2 platform layer: window + GL context, fixed 60 Hz loop, input, lifecycle.
 *
 * Loop contract (callback-friendly so Emscripten's emscripten_set_main_loop
 * can drive it; no threads):
 *   plat_run(app) calls plat_frame() once per host frame. plat_frame():
 *     accumulate real time (clamped), then for each 1/60 s step:
 *        plat_poll_input()   <- input sampled immediately before the update
 *        app->update(user)
 *     then app->render(user) and swap.
 *   While paused (window hidden / app backgrounded / tab invisible) no steps
 *   run and time does not accumulate; app->on_pause(user, 1/0) is called on
 *   transitions so audio can be suspended without losing its state.
 *   Fixed-step mode (headless capture) runs exactly one step per frame.
 */
#ifndef PORT_PLATFORM_H
#define PORT_PLATFORM_H
#include "pad.h"
#include "touch.h"

typedef struct PlatConfig {
    const char *title;
    int width, height;   /* initial window size (ignored on the web: canvas size) */
    int hidden;          /* headless: hidden window, use with SDL_VIDEODRIVER=offscreen */
    int vsync;
    int force_desktop_gl;/* skip the GL ES 3 attempt */
} PlatConfig;

typedef struct PlatApp {
    void *user;
    void (*update)(void *user);           /* one 60 Hz tick */
    void (*render)(void *user);           /* draw current state */
    void (*on_pause)(void *user, int paused);
} PlatApp;

#define PLAT_HZ 60
#define PLAT_MAX_PADS 2

int plat_init(const PlatConfig *cfg);    /* 0 = ok; GL is loaded on return */
void plat_shutdown(void);
void plat_drawable_size(int *w, int *h);
void plat_swap(void);
const char *plat_gl_description(void);

void plat_run(PlatApp *app);             /* returns when quit (native) */
void plat_frame(PlatApp *app);           /* one host frame */
void plat_request_quit(void);
int plat_quit_requested(void);
void plat_set_fixed_step(int on);        /* 1 step per frame, ignores real time */
int plat_paused(void);

/* Input, valid after plat_poll_input(). */
void plat_poll_input(void);
const PadRaw *plat_pad(int port);        /* merged keyboard/controller/touch */
int plat_key_held(int sdl_scancode);
int plat_key_hit(int sdl_scancode);      /* went down since the previous poll */
TouchPad *plat_touch(void);
void plat_set_touch_visible(int on);

#endif
