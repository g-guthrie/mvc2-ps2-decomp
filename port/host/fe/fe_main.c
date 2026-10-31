/*
 * mvc2: the game, natively compiled, as an app (Port J).
 *
 * SDL2 window + GL ES 3 / WebGL2 (port/platform), the game's main split into
 * boot + one 60 Hz iteration per host frame (port/host/game_loop.c), the
 * render library bound to port/render (fe_render.c), input from the
 * keyboard / controller / touch overlay into the game's libpad (iop.c).
 *
 *   mvc2 [--iso DISC.iso] [--frames N] [--shot F:FILE.png ...] [--shot-every N --shot-dir D]
 *        [--press F:BUTTON[:LEN] ...] [--script FILE] [--hidden] [--size WxH] [--desktop-gl] [-v]
 *        [--config FILE] [--set KEY=VALUE ...] [--fullscreen] [--no-unlock]
 *        [--wshot F:FILE.png ...] [--key F:KEYNAME[:LEN] ...]
 *        [--arcade abc --naomi mvsc2.zip] [--arcade-trace] [--cpu-team a,b,c] [--cpu-hp N] [--p1-hp N] [--draw-every N]
 *
 * --frames N quits after N game frames.  --shot F:path writes the 640x480
 * canvas after game frame F.  --press F:start (or cross, circle, square,
 * triangle, up, down, left, right, l1, r1, l2, r2, select) holds that button
 * on pad 1 from frame F for LEN frames (default 6): scripted input for
 * headless runs.  --script FILE: state-driven input (see script_step).  Web: the page's file picker / embedded disc calls
 * viewer_open_js(path) and the game boots then.
 *
 * Settings (port/docs/USER_GUIDE.md): natively SDL_GetPrefPath("mvc2-port",
 * "mvc2")/settings.ini (or --config FILE), on the web localStorage; --set
 * KEY=VALUE overrides one for this run.  Headless runs (--hidden) ignore the
 * user's file unless --config is given and never write it.
 * --arcade abc (any of a = frames + boxes, b = damage / hit data, c = CPU AI)
 * splices the user's own NAOMI tables from --naomi PATH (mvsc2.zip, MAME
 * Rev A set; web: /mvsc2.zip, written by the page) into each character
 * (port/host/arcade.c, port/docs/ARCADE_DIFF.md section 5).  Off by default.
 * --arcade-trace logs every player script run and hit (for checking it).
 */
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include "../host.h"
#include "../host_loop.h"
#include "../../platform/platform.h"
#include "../../platform/png_write.h"
#include "../../render/render.h"
#include "../../platform/settings.h"

void fe_ui_register(void);
int fe_ui_step(void);
void fe_ui_render(int w, int h);

void fe_render_init(void);
int fe_audio_init(int open_device);
void fe_audio_pause(int paused);
void fe_audio_shutdown(void);
void fe_audio_frame(void);

#define MAX_SHOTS 64
#define MAX_PRESS 64
static struct {
    int booted, frames_limit, shot_every;
    const char *shot_dir;
    struct { long frame; const char *path; } shot[MAX_SHOTS];
    int nshot;
    struct { long frame; int len; u16 bits; } press[MAX_PRESS];
    int npress;
    struct { long frame; const char *path; } wshot[MAX_SHOTS];
    int nwshot;
    struct { long frame; int len; int sc; } key[MAX_PRESS];
    int nkey;
    int draw_every; /* --draw-every N (testing): draw one game frame in N */
    int force_draw; /* the script's next shot needs this frame drawn */
    long ticks; /* display frames (counts while the menu holds the game) */
} A;

static const struct { const char *n; u16 bit; } BTN[] = {
    {"start", PS2_START}, {"select", PS2_SELECT}, {"cross", PS2_CROSS}, {"circle", PS2_CIRCLE},
    {"square", PS2_SQUARE}, {"triangle", PS2_TRIANGLE}, {"up", PS2_UP}, {"down", PS2_DOWN},
    {"left", PS2_LEFT}, {"right", PS2_RIGHT}, {"l1", PS2_L1}, {"r1", PS2_R1}, {"l2", PS2_L2},
    {"r2", PS2_R2},
};

/* --script FILE (testing): state-driven scripted input for headless runs.
 * One command per line ('#' comments):
 *   state S [MAX]          wait until the game state (g[0..2] as "a/b/c",
 *                          a prefix such as "2/1" is enough) matches; give
 *                          up after MAX frames (default 7200) with a log line
 *   wait N                 let N frames pass
 *   press B[+B..] [LEN]    hold buttons on pad 1 for LEN frames (default 6),
 *                          then release for 6 frames; "p2:" before a button
 *                          name puts it on pad 2
 *   until S B[+B..] [GAP]  press B every GAP frames (default 30) until the
 *                          state matches S (at most 200 presses)
 *   shot NAME              write NAME.png into --shot-dir
 *   quit                   end the run */
static struct {
    char **line;
    int n, pc, timer, phase, count;
    u16 hold0, hold1;
} S;

static int state_match(const char *want)
{
    char cur[32];
    int st = mvc2_game_state();
    snprintf(cur, sizeof cur, "%d/%d/%d", st >> 16, (st >> 8) & 0xFF, st & 0xFF);
    return strncmp(cur, want, strlen(want)) == 0 &&
           (cur[strlen(want)] == 0 || cur[strlen(want)] == '/' || want[strlen(want) - 1] == '/');
}

static void script_buttons(const char *spec, u16 *b0, u16 *b1)
{
    char buf[128], *t, *save = NULL;
    int k;
    *b0 = *b1 = 0;
    snprintf(buf, sizeof buf, "%s", spec);
    for (t = strtok_r(buf, "+", &save); t; t = strtok_r(NULL, "+", &save)) {
        int p2 = !strncmp(t, "p2:", 3);
        const char *nm = p2 ? t + 3 : t;
        for (k = 0; k < (int)(sizeof BTN / sizeof BTN[0]); k++)
            if (!strcmp(nm, BTN[k].n))
                *(p2 ? b1 : b0) |= BTN[k].bit;
    }
}

static void write_shot(const char *path);

static int script_load(const char *path)
{
    FILE *f = fopen(path, "r");
    char ln[256];
    if (!f)
        return -1;
    while (fgets(ln, sizeof ln, f)) {
        char *c = strchr(ln, '#');
        if (c) *c = 0;
        for (c = ln + strlen(ln); c > ln && (c[-1] == '\n' || c[-1] == ' ' || c[-1] == '\r' || c[-1] == '\t'); c--)
            c[-1] = 0;
        for (c = ln; *c == ' ' || *c == '\t'; c++)
            ;
        if (!*c)
            continue;
        S.line = (char **)realloc(S.line, sizeof(char *) * (S.n + 1));
        S.line[S.n++] = strdup(c);
    }
    fclose(f);
    return 0;
}

/* one frame of the script: sets the buttons to hold this frame */
static void script_step(u16 *b0, u16 *b1)
{
    static const char *shot_dir;
    char cmd[32] = "", a1[160] = "", a2[64] = "", a3[32] = "";
    *b0 = *b1 = 0;
    if (!shot_dir)
        shot_dir = A.shot_dir ? A.shot_dir : ".";
    while (S.pc < S.n) {
        sscanf(S.line[S.pc], "%31s %159s %63s %31s", cmd, a1, a2, a3);
        if (!strcmp(cmd, "state")) {
            int max = a2[0] ? atoi(a2) : 7200;
            if (state_match(a1)) { S.pc++; S.timer = 0; continue; }
            if (++S.timer > max) {
                host_log("script: line %d: state %s not reached in %d frames (now %06X)", S.pc + 1, a1, max, mvc2_game_state());
                S.pc++; S.timer = 0; continue;
            }
            return;
        } else if (!strcmp(cmd, "wait")) {
            if (S.timer++ < atoi(a1)) return;
            S.pc++; S.timer = 0; continue;
        } else if (!strcmp(cmd, "press")) {
            int len = a2[0] ? atoi(a2) : 6;
            if (S.timer < len) { script_buttons(a1, b0, b1); S.timer++; return; }
            if (S.timer++ < len + 6) return;
            S.pc++; S.timer = 0; continue;
        } else if (!strcmp(cmd, "until")) {
            int gap = a3[0] ? atoi(a3) : 30;
            if (S.timer == 0 && state_match(a1)) { S.pc++; S.count = 0; continue; }
            if (S.count > 200) {
                host_log("script: line %d: state %s not reached after 200 presses (now %06X)", S.pc + 1, a1, mvc2_game_state());
                S.pc++; S.count = 0; S.timer = 0; continue;
            }
            if (S.timer < 6) script_buttons(a2, b0, b1);
            if (++S.timer >= gap) { S.timer = 0; S.count++; }
            return;
        } else if (!strcmp(cmd, "shot")) {
            char path[512];
            if (A.draw_every > 1 && !S.phase) {
                A.force_draw = 1; /* draw this frame, write it at the next step */
                S.phase = 1;
                return;
            }
            S.phase = 0;
            snprintf(path, sizeof path, "%s/%s.png", shot_dir, a1);
            write_shot(path);
            S.pc++; continue;
        } else if (!strcmp(cmd, "quit")) {
            host_log("script: done at frame %ld", mvc2_host_frame);
            plat_request_quit();
            S.pc = S.n;
            return;
        } else {
            host_log("script: line %d: unknown command %s", S.pc + 1, cmd);
            S.pc++;
        }
    }
}

static int boot_game(const char *iso)
{
    if (host_disc_open(iso) != 0)
        return -1;
    mvc2_boot(1);
    A.booted = 1;
    return 0;
}

/* web: the shell's picker / embedded disc */
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
int viewer_open_js(const char *path)
{
    if (A.booted)
        return 0;
    return boot_game(path);
}

extern int fe_cnt[8];
static void write_shot(const char *path)
{
    uint8_t *rgba = (uint8_t *)malloc(FL_SCREEN_W * FL_SCREEN_H * 4);
    int i;
    r_read_canvas(rgba);
    for (i = 0; i < FL_SCREEN_W * FL_SCREEN_H; i++)
        rgba[4 * i + 3] = 255;
    png_write_rgba(path, FL_SCREEN_W, FL_SCREEN_H, rgba);
    free(rgba);
    host_log("wrote %s (frame %ld, game state %06X)", path, mvc2_host_frame, mvc2_game_state());
    {
        int d, v;
        r_stats(&d, &v);
        host_log("  draws: tri_tex %d tri %d sprite %d quad %d fill %d; rejected tri %d sprite %d quad %d; GL %d calls %d verts",
                 fe_cnt[0], fe_cnt[1], fe_cnt[2], fe_cnt[3], fe_cnt[4], fe_cnt[5], fe_cnt[6], fe_cnt[7], d, v);
    }
}

static void update(void *u)
{
    PadRaw p0, p1;
    int i;
    (void)u;
    if (!A.booted)
        return;
    if (fe_ui_step())
        return; /* the settings menu opened: this step's buttons were for it */
    p0 = *plat_pad(0);
    p1 = *plat_pad(1);
    for (i = 0; i < A.npress; i++)
        if (mvc2_host_frame >= A.press[i].frame && mvc2_host_frame < A.press[i].frame + A.press[i].len)
            p0.buttons |= A.press[i].bits;
    if (S.n && mvc2_host_frame >= 0) {
        u16 b0, b1;
        script_step(&b0, &b1);
        p0.buttons |= b0;
        p1.buttons |= b1;
    }
    p0.connected = p1.connected = 1;
    host_pad_set(0, &p0);
    host_pad_set(1, &p1);
    memset(fe_cnt, 0, sizeof fe_cnt);
    /* frame skip: when several steps run in one display frame only the last is drawn */
    r_set_discard((!plat_step_is_last() && A.nshot == 0 && A.shot_every == 0) ||
                  (A.draw_every > 1 && (mvc2_host_frame + 1) % A.draw_every != 0 && !A.force_draw));
    mvc2_frame();
    r_set_discard(0);
    fe_audio_frame();
    for (i = 0; i < A.nshot; i++)
        if (A.shot[i].frame == mvc2_host_frame)
            write_shot(A.shot[i].path);
    if (A.shot_every > 0 && A.shot_dir && mvc2_host_frame % A.shot_every == 0) {
        char path[512];
        snprintf(path, sizeof path, "%s/f%06ld.png", A.shot_dir, mvc2_host_frame);
        write_shot(path);
    }
    if (A.frames_limit > 0 && mvc2_host_frame >= A.frames_limit)
        plat_request_quit();
}

/* --key F:NAME[:LEN]: a real key event (through SDL's queue, so the menu and the
 * remapping see it) at display frame F; --wshot F:PATH: the window after present. */
static void scripted_keys(void)
{
    int i;
    for (i = 0; i < A.nkey; i++) {
        SDL_Event e;
        int down = A.ticks == A.key[i].frame, up = A.ticks == A.key[i].frame + A.key[i].len;
        if (!down && !up)
            continue;
        memset(&e, 0, sizeof e);
        e.type = down ? SDL_KEYDOWN : SDL_KEYUP;
        e.key.timestamp = SDL_GetTicks();
        e.key.state = down ? SDL_PRESSED : SDL_RELEASED;
        e.key.keysym.scancode = (SDL_Scancode)A.key[i].sc;
        SDL_PushEvent(&e);
    }
}

static void render(void *u)
{
    int W, H, i;
    (void)u;
    plat_drawable_size(&W, &H);
    if (A.draw_every <= 1 || mvc2_host_frame % A.draw_every == 0 || A.force_draw)
        fe_ui_render(W, H);
    A.force_draw = 0;
    for (i = 0; i < A.nwshot; i++)
        if (A.wshot[i].frame == A.ticks) {
            uint8_t *rgba = (uint8_t *)malloc((size_t)W * H * 4);
            r_read_window(W, H, rgba);
            png_write_rgba(A.wshot[i].path, W, H, rgba);
            free(rgba);
            host_log("wrote %s (window %dx%d, display frame %ld)", A.wshot[i].path, W, H, A.ticks);
        }
    A.ticks++;
    scripted_keys();
    if (A.frames_limit > 0 && A.ticks >= A.frames_limit + 3600)
        plat_request_quit(); /* --frames safety while the menu holds the game */
}

static void on_pause(void *u, int paused)
{
    (void)u;
    fe_audio_pause(paused);
}

int main(int argc, char **argv)
{
    const char *iso = getenv("MVC2_ISO");
    int w = 1280, h = 960, hidden = 0, desktop_gl = 0, fullscreen = -1, i;
    const char *config = NULL;
    const char *sets[64];
    int nsets = 0, no_unlock = 0;
    static PlatApp app = { NULL, update, render, on_pause };
    for (i = 1; i < argc; i++) {
        const char *a = argv[i], *n = i + 1 < argc ? argv[i + 1] : NULL;
        if (!strcmp(a, "--iso") && n) { iso = n; i++; }
        else if (!strcmp(a, "--frames") && n) { A.frames_limit = atoi(n); i++; }
        else if (!strcmp(a, "--shot") && n && A.nshot < MAX_SHOTS) {
            A.shot[A.nshot].frame = strtol(n, 0, 0);
            A.shot[A.nshot].path = strchr(n, ':') ? strchr(n, ':') + 1 : "shot.png";
            A.nshot++;
            i++;
        } else if (!strcmp(a, "--wshot") && n && A.nwshot < MAX_SHOTS) {
            A.wshot[A.nwshot].frame = strtol(n, 0, 0);
            A.wshot[A.nwshot].path = strchr(n, ':') ? strchr(n, ':') + 1 : "wshot.png";
            A.nwshot++;
            i++;
        } else if (!strcmp(a, "--key") && n && A.nkey < MAX_PRESS) {
            char nm[40] = "";
            long f = 0;
            int len = 4;
            if (sscanf(n, "%ld:%39[^:]:%d", &f, nm, &len) >= 2 && SDL_GetScancodeFromName(nm) != SDL_SCANCODE_UNKNOWN) {
                A.key[A.nkey].frame = f;
                A.key[A.nkey].len = len;
                A.key[A.nkey].sc = SDL_GetScancodeFromName(nm);
                A.nkey++;
            } else {
                fprintf(stderr, "mvc2: --key %s: unknown key\n", n);
            }
            i++;
        } else if (!strcmp(a, "--shot-every") && n) { A.shot_every = atoi(n); i++; }
        else if (!strcmp(a, "--shot-dir") && n) { A.shot_dir = n; i++; }
        else if (!strcmp(a, "--press") && n && A.npress < MAX_PRESS) {
            char nm[32] = "";
            long f = 0;
            int len = 6, k;
            if (sscanf(n, "%ld:%31[a-z0-9]:%d", &f, nm, &len) >= 2)
                for (k = 0; k < (int)(sizeof BTN / sizeof BTN[0]); k++)
                    if (!strcmp(nm, BTN[k].n)) {
                        A.press[A.npress].frame = f;
                        A.press[A.npress].len = len;
                        A.press[A.npress].bits = BTN[k].bit;
                        A.npress++;
                    }
            i++;
        } else if (!strcmp(a, "--script") && n) {
            if (script_load(n)) { fprintf(stderr, "mvc2: cannot read script %s\n", n); return 2; }
            i++;
        } else if (!strcmp(a, "--hidden")) hidden = 1;
        else if (!strcmp(a, "--desktop-gl")) desktop_gl = 1;
        else if (!strcmp(a, "--size") && n) { sscanf(n, "%dx%d", &w, &h); i++; }
        else if (!strcmp(a, "-v")) host_verbose++;
        else if (!strcmp(a, "-q")) mvc2_trace_state = 0;
        else if (!strcmp(a, "--no-unlock")) no_unlock = 1;
        else if (!strcmp(a, "--config") && n) { config = n; i++; }
        else if (!strcmp(a, "--set") && n) { if (nsets < 64) sets[nsets++] = n; i++; }
        else if (!strcmp(a, "--fullscreen")) fullscreen = 1;
        else if (!strcmp(a, "--cpu-team") && n) { setenv("MVC2_CPU_TEAM", n, 1); i++; } /* testing */
        else if (!strcmp(a, "--draw-every") && n) { A.draw_every = atoi(n); i++; }      /* testing */
        else if (!strcmp(a, "--p1-hp") && n) { setenv("MVC2_P1_HP", n, 1); i++; }        /* testing */
        else if (!strcmp(a, "--cpu-hp") && n) { setenv("MVC2_CPU_HP", n, 1); i++; }      /* testing */
        else if (!strcmp(a, "--p1-team") && n) { setenv("MVC2_P1_TEAM", n, 1); i++; }   /* testing */
        else if (!strcmp(a, "--arcade") && n) { setenv("MVC2_ARCADE", n, 1); i++; }      /* ARCADE_DIFF.md 5 */
        else if (!strcmp(a, "--naomi") && n) { setenv("MVC2_NAOMI", n, 1); i++; }
        else if (!strcmp(a, "--arcade-trace")) setenv("MVC2_ARCADE_TRACE", "1", 1);
        else if (!strcmp(a, "--arcade-play") && n) { setenv("MVC2_ARCADE_PLAY", n, 1); i++; } /* testing */
        else if (a[0] != '-') iso = a;
        else { fprintf(stderr, "unknown option %s\n", a); return 2; }
    }
    /* options: registered first, then the stored values, then this run's overrides */
    fe_ui_register();
#ifdef __EMSCRIPTEN__
    settings_load_web();
#else
    if (!config && !hidden) {
        static char path[1024];
        char *pref = SDL_GetPrefPath("mvc2-port", "mvc2");
        if (pref) {
            snprintf(path, sizeof path, "%ssettings.ini", pref);
            SDL_free(pref);
            config = path;
        }
    }
    if (hidden && !config)
        settings_set_autosave(0);
    if (config) {
        if (settings_load_file(config) == 0)
            host_log("mvc2: settings from %s", config);
        else
            host_log("mvc2: settings will be saved to %s", config);
    }
#endif
    for (i = 0; i < nsets; i++)
        if (settings_parse_assignment(sets[i], 1) != 0)
            fprintf(stderr, "mvc2: --set %s: expected KEY=VALUE\n", sets[i]);
    if (no_unlock)
        settings_override("game.unlock_all", "0");
    if (fullscreen >= 0)
        settings_override("video.fullscreen", "1");
    {
        PlatConfig cfg = { "Marvel vs. Capcom 2", w, h, hidden, !hidden && settings_get_int("video.vsync"),
                           desktop_gl, !hidden && settings_get_int("video.fullscreen") };
        if (plat_init(&cfg))
            return 1;
    }
    host_log("mvc2: %s", plat_gl_description());
    if (r_init())
        return 1;
    fe_render_init();
    fe_audio_init(!hidden);
    {
        extern void fe_arcade_register(void);
        fe_arcade_register();   /* "Arcade accuracy" options (fe_arcade.c) */
    }
    settings_apply_all();
    if (hidden)
        plat_set_fixed_step(1);
#ifndef __EMSCRIPTEN__
    if (!iso)
        iso = "private/disc/mvc2.iso";
    if (boot_game(iso) != 0) {
        fprintf(stderr, "mvc2: no disc image (--iso PATH)\n");
        return 1;
    }
#else
    if (iso)
        boot_game(iso);
#endif
    plat_run(&app);
    fe_audio_shutdown();
#ifndef __EMSCRIPTEN__
    r_shutdown();
    plat_shutdown();
#endif
    return 0;
}
