/* Asset viewer: a character frame (default Ryu PL00 frame 200) over a stage
 * texture, drawn through the fl render API.
 *
 *   viewer [--iso PATH] [--char N] [--frame F] [--pal P] [--stage-tex N]
 *          [--screenshot OUT.png] [--window-shot OUT.png] [--frames N]
 *          [--size WxH] [--desktop-gl] [--present integer|sharp] [--touch]
 *
 * Controls (pad game word, so keyboard / controller / touch all work):
 *   RIGHT/LEFT frame +-1, UP/DOWN frame +-10, LP (A key / Square) palette +1,
 *   LK (Z key / Cross) next stage texture, START (Enter) play/pause animation.
 *   Keyboard only: F present mode, H touch overlay, Esc quit.
 */
#include "../platform/platform.h"
#include "../platform/fs.h"
#include "../platform/gl.h"
#include "../platform/png_write.h"
#include "../render/render.h"
#include "../render/decode.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define PAK_BASE_ID 209 /* AFS02 index of PL00PAK.BIN; PLxxPAK = 209 + xx */
#define STG00TEX_ID 802

typedef struct Viewer {
    GameDisc disc;
    int have_disc;
    uint8_t *pak;
    size_t pak_size;
    FlCharBank *bank;
    uint8_t *stage_pack;
    uint32_t stage_tex[32];
    int n_stage_tex, stage_sel;
    uint32_t font_tex;
    int char_id, frame, pal;
    int playing, tick;
    PadEdge pad;
    int present_mode;
    int plain; /* character only on black: for pixel comparisons */
    /* capture */
    const char *shot, *window_shot;
    int frames_left;
    int frames_run;
    char status[160];
} Viewer;

static Viewer V;

static void set_status(const char *s) { snprintf(V.status, sizeof V.status, "%s", s); fprintf(stderr, "viewer: %s\n", s); }

static int load_char(int id)
{
    if (V.bank) { fl_char_bank_destroy(V.bank); V.bank = NULL; }
    free(V.pak);
    V.pak = disc_load(&V.disc, 2, PAK_BASE_ID + id, &V.pak_size);
    if (!V.pak || V.pak_size < 4) return -1;
    uint32_t sec0 = V.pak[0] | V.pak[1] << 8 | V.pak[2] << 16 | (uint32_t)V.pak[3] << 24;
    if (sec0 >= V.pak_size) return -1;
    V.bank = fl_char_bank_create(V.pak + sec0, V.pak_size - sec0);
    if (!V.bank) return -1;
    V.char_id = id;
    fprintf(stderr, "viewer: PL%02XPAK: %d tiles, %d frames\n", id, fl_char_tile_count(V.bank), fl_char_frame_count(V.bank));
    return 0;
}

static int load_stage(void)
{
    size_t n, dn;
    uint8_t *raw = disc_load(&V.disc, 2, STG00TEX_ID, &n);
    if (!raw) return -1;
    V.stage_pack = texpack_decode(raw, n, &dn);
    free(raw);
    if (!V.stage_pack) return -1;
    FlTexRecord rec[32];
    int nr = texpack_records(V.stage_pack, dn, rec, 32);
    for (int i = 0; i < nr && i < 32; i++) {
        if ((rec[i].flags >> 16) != 1 || rec[i].offset >= dn) continue;
        uint32_t h = fl_tex_load_tim2(V.stage_pack + rec[i].offset, dn - rec[i].offset, 0);
        if (h) V.stage_tex[V.n_stage_tex++] = h;
    }
    fprintf(stderr, "viewer: STG00TEX: %d records, %d textures\n", nr, V.n_stage_tex);
    V.stage_sel = V.n_stage_tex > 1 ? 1 : 0; /* record 1: 512x512 plank wall */
    return V.n_stage_tex ? 0 : -1;
}

static void load_font(void)
{
    size_t n;
    uint8_t *f = iso_load(&V.disc.iso, "/FONT8_8.TM2", &n);
    if (f) { V.font_tex = fl_tex_load_tim2(f, n, 0); free(f); }
}

int viewer_open(const char *path)
{
    if (V.have_disc) { disc_close(&V.disc); V.have_disc = 0; }
    if (disc_open(&V.disc, path)) { set_status("could not open disc image"); return -1; }
    V.have_disc = 1;
    if (load_stage()) set_status("STG00TEX not found");
    load_font();
    if (load_char(V.char_id)) { set_status("character bank not found"); return -1; }
    if (V.frame >= fl_char_frame_count(V.bank)) V.frame = 0;
    set_status("disc loaded");
    return 0;
}
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE int viewer_open_js(const char *path) { return viewer_open(path); }
#endif

/* ---- update ---- */
static void update(void *u)
{
    (void)u;
    pad_edge_update(&V.pad, pad_game_word(plat_pad(0)));
    uint16_t p = V.pad.pressed;
    int nf = V.bank ? fl_char_frame_count(V.bank) : 1;
    if (p & 0x0400) V.frame++;          /* RIGHT */
    if (p & 0x0800) V.frame--;          /* LEFT */
    if (p & 0x2000) V.frame += 10;      /* UP */
    if (p & 0x1000) V.frame -= 10;      /* DOWN */
    if (p & 0x0200) V.pal = (V.pal + 1) & 15;                        /* SQUARE / LP */
    if ((p & 0x0040) && V.n_stage_tex) V.stage_sel = (V.stage_sel + 1) % V.n_stage_tex; /* CROSS / LK */
    if (p & 0x8000) V.playing = !V.playing;                          /* START */
    if (V.playing && (++V.tick % 4) == 0) V.frame++;
    if (V.bank) V.frame = ((V.frame % nf) + nf) % nf; /* keep --frame until a bank is loaded */
    if (plat_key_hit(SDL_SCANCODE_F)) V.present_mode ^= 1;
    if (plat_key_hit(SDL_SCANCODE_H)) plat_set_touch_visible(!plat_touch()->visible);
    if (plat_key_hit(SDL_SCANCODE_ESCAPE)) plat_request_quit();
}

/* ---- drawing helpers through the fl API ---- */
static void sprite(float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1, uint32_t argb)
{
    FlSprite s;
    memset(&s, 0, sizeof s);
    s.v[0] = (FlVec4){ x0, y0, 0, 1 };
    s.v[1] = (FlVec4){ x1, y1, 0, 1 };
    s.argb = argb;
    s.uv[0][0] = u0; s.uv[0][1] = v0;
    s.uv[1][0] = u1; s.uv[1][1] = v1;
    fl_sprite_tex(&s);
}

static void text(float x, float y, const char *str, uint32_t argb)
{
    /* FONT8_8.TM2: 128x64, 16 x 8 cells of 8x8, ASCII order; drawn with the
     * batch-writer quad path (func_00420BF0) like the game's text */
    if (!V.font_tex) return;
    fl_set_render_state(4, V.font_tex);
    for (; *str; str++, x += 8) {
        int c = (unsigned char)*str & 0x7F;
        float u0 = (c % 16) * 8 / 128.f, v0 = (c / 16) * 8 / 64.f, u1 = u0 + 8 / 128.f, v1 = v0 + 8 / 64.f;
        FlQuad q;
        memset(&q, 0, sizeof q);
        float xs[4] = { x, x + 8, x, x + 8 }, ys[4] = { y, y, y + 8, y + 8 };
        float us[4] = { u0, u1, u0, u1 }, vs[4] = { v0, v0, v1, v1 };
        FlTri *t0 = &q.t[0], *t1 = &q.t[1];
        for (int k = 0; k < 3; k++) {
            t0->v[k] = (FlVec4){ xs[k], ys[k], 0, 1 };
            t0->argb[k] = argb;
            t0->uv[k][0] = us[k]; t0->uv[k][1] = vs[k];
        }
        t1->v[2] = (FlVec4){ xs[3], ys[3], 0, 1 };
        t1->argb[2] = argb;
        t1->uv[2][0] = us[3]; t1->uv[2][1] = vs[3];
        fl_quad_tex(&q);
    }
}

static void tri(float x0, float y0, float x1, float y1, float x2, float y2, uint32_t c0, uint32_t c1, uint32_t c2)
{
    FlTri t;
    memset(&t, 0, sizeof t);
    t.v[0] = (FlVec4){ x0, y0, 0, 1 };
    t.v[1] = (FlVec4){ x1, y1, 0, 1 };
    t.v[2] = (FlVec4){ x2, y2, 0, 1 };
    t.argb[0] = c0; t.argb[1] = c1; t.argb[2] = c2;
    fl_tri(&t);
}

static void draw_touch_overlay(int W, int H)
{
    TouchPad *t = plat_touch();
    if (!t->visible) return;
    if (t->w != W || t->h != H) touch_layout(t, W, H);
    r_overlay_begin(W, H);
    float ring = t->dr * 0.06f;
    r_overlay_disc(t->dcx, t->dcy, t->dr, 0x40FFFFFF);
    r_overlay_ring(t->dcx, t->dcy, t->dr, ring, 0x90FFFFFF);
    if (t->dpad_bits) {
        float dx = (t->dpad_bits & PS2_RIGHT ? 1.f : 0.f) - (t->dpad_bits & PS2_LEFT ? 1.f : 0.f);
        float dy = (t->dpad_bits & PS2_DOWN ? 1.f : 0.f) - (t->dpad_bits & PS2_UP ? 1.f : 0.f);
        r_overlay_disc(t->dcx + dx * t->dr * 0.55f, t->dcy + dy * t->dr * 0.55f, t->dr * 0.3f, 0xA0FFFFFF);
    }
    static const uint32_t colors[TB_COUNT] = { 0xFF3070FF, 0xFF3070FF, 0xFF30C060, 0xFFE04040, 0xFFE04040, 0xFF30C060, 0xFFC0C0C0 };
    for (int k = 0; k < TB_COUNT; k++) {
        TouchButton *b = &t->b[k];
        uint32_t c = colors[k] & 0x00FFFFFF;
        r_overlay_disc(b->cx, b->cy, b->r, (b->held ? 0xC0000000u : 0x50000000u) | c);
        r_overlay_ring(b->cx, b->cy, b->r, b->r * 0.1f, 0xB0000000u | c);
    }
    r_overlay_end();
}

static void capture_window(const char *path, int W, int H)
{
    uint8_t *px = (uint8_t *)malloc((size_t)W * H * 4), *fl = (uint8_t *)malloc((size_t)W * H * 4);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, px);
    for (int y = 0; y < H; y++) memcpy(fl + (size_t)y * W * 4, px + (size_t)(H - 1 - y) * W * 4, (size_t)W * 4);
    for (size_t i = 0; i < (size_t)W * H; i++) fl[4 * i + 3] = 255;
    png_write_rgba(path, W, H, fl);
    fprintf(stderr, "viewer: wrote %s (%dx%d window)\n", path, W, H);
    free(px);
    free(fl);
}

static void render(void *u)
{
    (void)u;
    fl_frame_begin();
    if (V.plain) {
        if (V.bank) {
            float m[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 320, 400, 0, 1 };
            fl_char_draw(V.bank, V.frame, m, 0xFFFFFFFF, V.pal);
        }
    } else if (V.n_stage_tex) {
        /* stage texture tiled over the canvas (exercises REPEAT wrap) */
        uint32_t h = V.stage_tex[V.stage_sel];
        int tw = 256, th = 256;
        fl_tex_info(h, &tw, &th, NULL);
        fl_set_render_state(4, h);
        fl_set_render_state(0x63, 0);
        sprite(0, 0, 640, 480, 0, 0, 640.f / tw, 480.f / th, 0xFFFFFFFF);
        /* a floor strip from another record, darkened by vertex colour */
        if (V.n_stage_tex > 3) {
            fl_set_render_state(4, V.stage_tex[3]);
            sprite(0, 400, 640, 480, 0, 0, 640.f / 256, 80.f / 256, 0xFF909090);
        }
    } else {
        /* no disc: gouraud backdrop */
        tri(0, 0, 640, 0, 0, 480, 0xFF203050, 0xFF203050, 0xFF101018);
        tri(640, 0, 640, 480, 0, 480, 0xFF203050, 0xFF101018, 0xFF101018);
    }
    if (!V.plain) {
    /* HUD bars: untextured gouraud triangles, then an additive highlight (blend 0x12) */
    tri(20, 20, 300, 20, 20, 36, 0xFFFFD000, 0xFFFF4000, 0xFFFFD000);
    tri(300, 20, 300, 36, 20, 36, 0xFFFF4000, 0xFFFF4000, 0xFFFFD000);
    fl_set_render_state(0x5D, 0x12);
    tri(20, 20, 300, 20, 20, 26, 0x80FFFFFF, 0x00FFFFFF, 0x80FFFFFF);
    fl_set_render_state(0x5D, 0x32);
    if (V.bank) {
        /* actor at (320, 400); the matrix is a plain translation (facing right) */
        float m[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 320, 400, 0, 1 };
        /* shadow: translucent black copy, half-height via the matrix */
        float sh[16] = { 1, 0, 0, 0, 0, -0.15f, 0, 0, 0, 0, 1, 0, 330, 402, 0, 1 };
        fl_char_draw(V.bank, V.frame, sh, 0x60000000, V.pal);
        fl_char_draw(V.bank, V.frame, m, 0xFFFFFFFF, V.pal);
        /* mirrored copy (facing left) via a negative X scale, palette +1 */
        float mf[16] = { -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 520, 400, 0, 1 };
        fl_char_draw(V.bank, (V.frame + 1) % fl_char_frame_count(V.bank), mf, 0xFFFFFFFF, (V.pal + 1) & 15);
        char buf[96];
        snprintf(buf, sizeof buf, "PL%02X FRAME %3d/%d PAL %d", V.char_id, V.frame, fl_char_frame_count(V.bank), V.pal);
        text(20 + 1, 44 + 1, buf, 0xFF000000);
        text(20, 44, buf, 0xFFFFFFFF);
        int d, nv;
        r_stats(&d, &nv);
        snprintf(buf, sizeof buf, "%d DRAWS %d VERTS  STAGE TEX %d", d, nv, V.stage_sel);
        text(20, 56, buf, 0xFFC0FFC0);
    }
    }
    fl_frame_end();
    int W, H;
    plat_drawable_size(&W, &H);
    r_present(W, H, V.present_mode);
    draw_touch_overlay(W, H);
    V.frames_run++;
    if (V.frames_left > 0 && --V.frames_left == 0) {
        if (V.shot) {
            uint8_t *rgba = (uint8_t *)malloc(FL_SCREEN_W * FL_SCREEN_H * 4);
            r_read_canvas(rgba);
            for (int i = 0; i < FL_SCREEN_W * FL_SCREEN_H; i++) rgba[4 * i + 3] = 255;
            png_write_rgba(V.shot, FL_SCREEN_W, FL_SCREEN_H, rgba);
            fprintf(stderr, "viewer: wrote %s (640x480 canvas) after %d frames\n", V.shot, V.frames_run);
            free(rgba);
        }
        if (V.window_shot) capture_window(V.window_shot, W, H);
        plat_request_quit();
    }
}

static void on_pause(void *u, int paused)
{
    (void)u;
    fprintf(stderr, "viewer: %s\n", paused ? "paused" : "resumed");
}

int main(int argc, char **argv)
{
    const char *iso = NULL;
    int w = 1280, h = 960, desktop_gl = 0, touch = 0, frames = 0;
    V.frame = 200;
    V.present_mode = R_PRESENT_INTEGER;
#ifdef __EMSCRIPTEN__
    V.present_mode = R_PRESENT_SHARP_FIT;
#endif
    for (int i = 1; i < argc; i++) {
        const char *a = argv[i], *n = i + 1 < argc ? argv[i + 1] : NULL;
        if (!strcmp(a, "--iso") && n) { iso = n; i++; }
        else if (!strcmp(a, "--char") && n) { V.char_id = (int)strtol(n, NULL, 0); i++; }
        else if (!strcmp(a, "--frame") && n) { V.frame = atoi(n); i++; }
        else if (!strcmp(a, "--pal") && n) { V.pal = atoi(n) & 15; i++; }
        else if (!strcmp(a, "--stage-tex") && n) { V.stage_sel = atoi(n); i++; }
        else if (!strcmp(a, "--screenshot") && n) { V.shot = n; i++; }
        else if (!strcmp(a, "--window-shot") && n) { V.window_shot = n; i++; }
        else if (!strcmp(a, "--frames") && n) { frames = atoi(n); i++; }
        else if (!strcmp(a, "--size") && n) { sscanf(n, "%dx%d", &w, &h); i++; }
        else if (!strcmp(a, "--desktop-gl")) desktop_gl = 1;
        else if (!strcmp(a, "--touch")) touch = 1;
        else if (!strcmp(a, "--plain")) V.plain = 1;
        else if (!strcmp(a, "--present") && n) { V.present_mode = !strcmp(n, "sharp"); i++; }
        else if (a[0] != '-') iso = a;
        else { fprintf(stderr, "unknown option %s\n", a); return 2; }
    }
    int stage_sel = V.stage_sel;
    int capture = V.shot || V.window_shot;
    if (capture && frames <= 0) frames = 1;
    PlatConfig cfg = { "MvC2 port viewer", w, h, capture, !capture, desktop_gl };
    if (plat_init(&cfg)) return 1;
    fprintf(stderr, "viewer: %s\n", plat_gl_description());
    if (r_init()) return 1;
    if (touch) plat_set_touch_visible(1);
    if (iso) {
        if (viewer_open(iso) && capture) return 1;
        if (stage_sel && stage_sel < V.n_stage_tex) V.stage_sel = stage_sel;
    } else {
        set_status("no disc image: pass --iso PATH (web: use the file picker)");
    }
    V.frames_left = frames;
    if (capture) plat_set_fixed_step(1);
    static PlatApp app = { NULL, update, render, on_pause };
    plat_run(&app);
#ifndef __EMSCRIPTEN__
    r_shutdown();
    plat_shutdown();
#endif
    return 0;
}
