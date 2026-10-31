/* SDL2 platform layer: window + GL context, fixed 60 Hz loop, input, lifecycle.
 *
 * Loop contract (callback-friendly: the web build runs it from
 * requestAnimationFrame; no threads):
 *   plat_run(app) calls plat_frame() once per display frame. plat_frame():
 *     measure real time (snapped to the display's refresh interval when it is
 *     within a fraction of a millisecond of one, so 60 Hz displays run exactly
 *     one step per frame and 120/144 Hz displays alternate evenly), then for
 *     each 1/60 s step that is due:
 *        plat_poll_input()   <- input sampled immediately before the update
 *        app->update(user)   (plat_step_is_last() tells whether this step's
 *                             picture will be shown; earlier ones may skip drawing)
 *     then, if at least one step ran (or the UI is up), app->render(user) and swap.
 *   Slow devices: up to plat_set_max_steps() steps per display frame (default
 *   8, i.e. down to 7.5 fps display with 60 Hz logic); beyond that the game
 *   slows down rather than spiral.  Render frames are dropped, logic frames are not.
 *   While paused (window hidden / app backgrounded / tab invisible) no steps
 *   run and time does not accumulate; app->on_pause(user, 1/0) is called on
 *   the transition itself (also from the browser's visibilitychange event, as
 *   a hidden tab gets no animation frames).
 *   While held (plat_set_hold: the settings UI is open) no steps run, input is
 *   polled once per display frame and render runs every frame.
 *   Fixed-step mode (headless capture) runs exactly one step per frame.
 */
#ifndef PORT_PLATFORM_H
#define PORT_PLATFORM_H
#include <stdint.h>
#include "pad.h"
#include "touch.h"

typedef struct PlatConfig {
    const char *title;
    int width, height;   /* initial window size (ignored on the web: canvas size) */
    int hidden;          /* headless: hidden window, use with SDL_VIDEODRIVER=offscreen */
    int vsync;
    int force_desktop_gl;/* skip the GL ES 3 attempt */
    int fullscreen;      /* native: start in desktop fullscreen */
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
void plat_set_speed(int n);             /* testing: run the game n times faster than real time */
void plat_set_fixed_step(int on);        /* 1 step per frame, ignores real time */
int plat_paused(void);
void plat_set_hold(int on);              /* settings UI open: logic stops, input + render go on */
int plat_hold(void);
int plat_step_is_last(void);             /* inside update: this step's picture is presented */
void plat_set_max_steps(int n);          /* 1..8 */
void plat_set_frame_skip(int on);        /* 0: draw every step (no render-frame dropping) */
void plat_set_vsync(int on);             /* native swap interval; the web always paces to rAF */
void plat_set_fullscreen(int on);
int plat_fullscreen(void);
void plat_request_render(void);          /* draw on the next frame even without a step */

typedef struct PlatStats {
    float render_fps, logic_fps;          /* last second */
    float lat_avg_ms, lat_max_ms;         /* input event -> logic step that read it (last 32 presses) */
    float lat_last_ms;
    int lat_samples;
    int dropped_render;                   /* steps drawn but not presented (last second) */
    int slowed;                           /* steps the logic lost to the step cap (total) */
    float refresh_hz;                     /* measured display frame rate */
    float update_ms, render_ms;           /* average cost of one logic step / one present (CPU side) */
} PlatStats;
void plat_stats(PlatStats *s);

/* Input, valid after plat_poll_input(). */
void plat_poll_input(void);
const PadRaw *plat_pad(int player);      /* merged keyboard/controller/touch, after mapping */
int plat_key_held(int sdl_scancode);
int plat_key_hit(int sdl_scancode);      /* went down since the previous poll */
int plat_key_repeat(int sdl_scancode);   /* hit, or an auto-repeat since the previous poll */
TouchPad *plat_touch(void);
void plat_set_touch_visible(int on);
/* Gamepads: slot 0/1 (connection order). */
int plat_pad_connected(int slot);
const char *plat_pad_name(int slot);
int plat_pad_style(int slot);            /* PAD_STYLE_* (input.h) */
uint32_t plat_padin(int slot);           /* PadIn bits (input.h), raw (not remapped) */
uint32_t plat_padin_hit(int slot);       /* went down since the previous poll */
/* Everything held now is ignored until released (no menu key leaks into the game). */
void plat_input_swallow_held(void);

#endif
