/* Asset viewer: a 3D stage (STGxxPOL/TEX through the mesh path, battle camera)
 * with a character (default Ryu PL00 frame 200) and HUD on top, drawn through
 * the fl render API. --stage -1 gives the older stage-texture backdrop.
 *
 *   viewer [--iso PATH] [--stage N] [--char N] [--frame F] [--pal P] [--stage-tex N]
 *          [--screenshot OUT.png] [--window-shot OUT.png] [--frames N]
 *          [--size WxH] [--desktop-gl] [--present integer|sharp] [--touch]
 *          [--stage-only] [--roots 0|world|all] [--nearest] [--fog] [--lit] [--cam-x X] [--plain]
 *
 * Controls (pad game word, so keyboard / controller / touch all work):
 *   RIGHT/LEFT frame +-1, UP/DOWN frame +-10, LP (A key / Square) palette +1,
 *   LK (Z key / Cross) next stage texture (backdrop mode), START (Enter) play/pause,
 *   HP (S key / Triangle) or R2 (W key) next stage, L2 (Q key) previous stage,
 *   HK (X key / Circle) toggle drawing every root tree (debug; see MESH_NOTES).
 *   Keyboard only: J/L pan the camera, F present mode, H touch overlay, Esc quit.
 */
#include "../platform/platform.h"
#include "../platform/fs.h"
#include "../platform/gl.h"
#include "../platform/png_write.h"
#include "../render/render.h"
#include "../render/decode.h"
#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define PAK_BASE_ID 209 /* AFS02 index of PL00PAK.BIN; PLxxPAK = 209 + xx */
#define STG00TEX_ID 802
#define STG00POL_ID 801 /* D_00446860[s] = 801 + 2s, D_00446810[s] = 802 + 2s */
#define N_STAGES 17

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
    /* 3D stage */
    int stage;              /* -1 = texture backdrop */
    FlModel *model;
    uint32_t model_tex[64];
    int n_model_tex;
    int roots_mode;         /* 0 = root 0, 1 = + world-scale roots (heuristic), 2 = all roots */
    int stage_only, nearest, fog, lit;
    uint8_t fog_tab[N_STAGES][12]; /* D_00477060, read from the disc's SLUS_204.86 */
    int have_fog_tab;
    float cam_x;
    FlCamera cam;
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

/* func_00170170 case 1 for stage s: STGxxPOL + STGxxTEX through func_0016F430 */
static int load_stage_model(int s)
{
    if (V.model) { fl_model_destroy(V.model); V.model = NULL; }
    for (int i = 0; i < V.n_model_tex; i++) if (V.model_tex[i]) fl_tex_release(V.model_tex[i]);
    V.n_model_tex = 0;
    if (s < 0 || !V.have_disc) return -1;
    size_t pn, tn, dn;
    uint8_t *pol = disc_load(&V.disc, 2, STG00POL_ID + 2 * s, &pn);
    uint8_t *raw = disc_load(&V.disc, 2, STG00TEX_ID + 2 * s, &tn);
    uint8_t *pack = raw ? texpack_decode(raw, tn, &dn) : NULL;
    free(raw);
    if (!pol || !pack) { free(pol); free(pack); return -1; }
    /* func_00415020(0xC10, records): one handle per record, in record order */
    FlTexRecord rec[64];
    int nr = texpack_records(pack, dn, rec, 64);
    for (int i = 0; i < nr; i++) {
        uint32_t h = 0;
        if ((rec[i].flags >> 16) == 1 && rec[i].offset < dn) h = fl_tex_load_tim2(pack + rec[i].offset, dn - rec[i].offset, 0);
        V.model_tex[V.n_model_tex++] = h;
    }
    free(pack);
    fl_set_render_state(1, 0); /* func_00170170: unlit build */
    fl_set_render_state(2, 0);
    FlModelLoad ld = { V.model_tex, V.n_model_tex, 4, 1, 0 }; /* D_004C2B34 = 4, D_004C2B30 = 1 */
    if (V.lit) {
        /* demo of the lit program (desc 0): format word 0x102 for every mesh and one
         * directional light; stages are never built this way by the game */
        static struct { uint32_t pad; float col[4]; float pad2[4]; float amb[4]; float dir[3]; float pad3[9]; } L[3];
        memset(L, 0, sizeof L);
        L[0].col[0] = L[0].col[1] = L[0].col[2] = 0.85f;
        L[0].amb[0] = L[0].amb[1] = L[0].amb[2] = 0.3f;
        L[0].dir[0] = 0.4f; L[0].dir[1] = -0.6f; L[0].dir[2] = -0.7f;
        L[1].dir[1] = -1.f; L[2].dir[1] = -1.f;
        for (int k = 0; k < 3; k++) fl_set_render_state(0x59 + k, (uintptr_t)&L[k]);
        fl_set_render_state(1, 1);
        fl_set_render_state(0x15, 2);
        fl_set_render_state(0x65, 0);
        fl_set_render_state(0x61, 0);
        fl_set_render_state(0x12, 0);
        fl_set_render_state(0xC, 0);
        fl_set_render_state(0xE, 0);
        ld.keep_state = 1;
    }
    V.model = fl_model_load(pol, pn, &ld);
    free(pol);
    if (!V.model) return -1;
    int desc_hist[49] = { 0 }, none = 0;
    for (int i = 0; i < fl_model_meshes(V.model); i++) {
        int d;
        fl_model_mesh_info(V.model, i, NULL, NULL, &d);
        if (d >= 0) desc_hist[d]++; else none++;
    }
    fprintf(stderr, "viewer: STG%02XPOL: %d meshes, %d roots, %d textures; descriptors:", s,
            fl_model_meshes(V.model), fl_model_roots(V.model), V.n_model_tex);
    for (int d = 0; d < 49; d++) if (desc_hist[d]) fprintf(stderr, " %d x%d", d, desc_hist[d]);
    fprintf(stderr, ", none x%d\n", none);
    V.stage = s;
    return 0;
}

/* Read `len` bytes at EE address `vaddr` from the ELF on the user's disc. */
static int elf_read(const uint8_t *e, size_t n, uint32_t vaddr, void *dst, size_t len)
{
#define RD32(o) ((uint32_t)e[o] | (uint32_t)e[(o) + 1] << 8 | (uint32_t)e[(o) + 2] << 16 | (uint32_t)e[(o) + 3] << 24)
    if (n < 52 || memcmp(e, "\177ELF", 4)) return -1;
    uint32_t phoff = RD32(28), phnum = (uint32_t)(e[44] | e[45] << 8), phsz = (uint32_t)(e[42] | e[43] << 8);
    for (uint32_t i = 0; i < phnum; i++) {
        size_t ph = phoff + (size_t)i * phsz;
        if (ph + 32 > n || RD32(ph) != 1) continue; /* PT_LOAD */
        uint32_t off = RD32(ph + 4), va = RD32(ph + 8), fsz = RD32(ph + 16);
        if (vaddr >= va && vaddr + len <= va + fsz && off + (vaddr - va) + len <= n) {
            memcpy(dst, e + off + (vaddr - va), len);
            return 0;
        }
    }
    return -1;
#undef RD32
}

static void load_stage_tables(void)
{
    size_t n;
    uint8_t *elf = iso_load(&V.disc.iso, "/SLUS_204.86", &n);
    V.have_fog_tab = elf && !elf_read(elf, n, 0x00477060, V.fog_tab, sizeof V.fog_tab);
    free(elf);
    fprintf(stderr, "viewer: stage fog table D_00477060 %s\n", V.have_fog_tab ? "read from SLUS_204.86" : "not found (fog off)");
}

/* func_003D1040 + func_0016D2A0: per-stage fog states 0xF / 0x10 / 0x11 (tint 1.0) */
static void apply_stage_fog(int s)
{
    int32_t id = -1;
    float far_v = 1e7f;
    if (V.have_fog_tab && V.fog && s >= 0 && s < N_STAGES) {
        memcpy(&id, V.fog_tab[s], 4);
        memcpy(&far_v, V.fog_tab[s] + 4, 4);
    }
    if (id == -1) {
        float big = 10000000.f; /* func_0016D460 */
        uint32_t u;
        fl_set_render_state(0xF, 0);
        memcpy(&u, &big, 4);
        fl_set_render_state(0x10, u);
        fl_set_render_state(0x11, u);
        return;
    }
    const uint8_t *t = V.fog_tab[s];
    float pw = powf(2.f, (float)(id >> 4));
    float nearv = far_v / ((float)((id & 0xF) + 0x10) * pw / 16.f);
    uint32_t c = ((uint32_t)(id & 0xFF) << 24) | (uint32_t)t[9] << 16 | (uint32_t)t[10] << 8 | t[11], u;
    fl_set_render_state(0xF, c);
    memcpy(&u, &nearv, 4);
    fl_set_render_state(0x10, u);
    memcpy(&u, &far_v, 4);
    fl_set_render_state(0x11, u);
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
    load_stage_tables();
    if (V.stage >= 0 && load_stage_model(V.stage)) set_status("stage model not loaded");
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
    if ((p & (0x0100 | 0x0008 | 0x0004)) && V.have_disc) {             /* TRIANGLE / R2 / L2 */
        int s = V.stage < 0 ? 0 : V.stage + ((p & 0x0004) ? N_STAGES - 1 : 1);
        if (load_stage_model(s % N_STAGES)) set_status("stage model not loaded");
    }
    if (p & 0x0020) V.roots_mode = (V.roots_mode + 1) % 3;            /* CIRCLE / HK */
    if (plat_key_held(SDL_SCANCODE_J)) V.cam_x -= 4.f;
    if (plat_key_held(SDL_SCANCODE_L)) V.cam_x += 4.f;
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

/* world point -> 640x480 canvas through the current view/projection/viewport
 * (the same maths as the mesh path; used to stand the character on the floor) */
static void project(const float p[3], float *sx, float *sy)
{
    const float *view = (const float *)fl_get_render_state(0x16), *proj = (const float *)fl_get_render_state(0x17);
    float vp[16], c[4];
    fl_mat_mul(vp, view, proj);
    for (int k = 0; k < 4; k++) c[k] = p[0] * vp[k] + p[1] * vp[4 + k] + p[2] * vp[8 + k] + vp[12 + k];
    if (c[3] <= 0.f) c[3] = 1e-6f;
    *sx = 320.f + c[0] / c[3] * 320.f / 1.333333f;
    *sy = 224.f - c[1] / c[3] * 240.f;
}

/* func_001527F0 order: camera, list 6 (stage), Z clear, then the 2D layers */
static void draw_stage(void)
{
    V.cam.eye[0] = V.cam_x;
    V.cam.at[0] = V.cam_x;
    /* func_00122FE0: far 2200000 for stages 1 and 0xA (D_004C27D0 & 0x1F), else 120000 */
    fl_camera_apply(&V.cam, (V.stage == 1 || V.stage == 10) ? 2200000.f : 120000.f, 1, 0, 0);
    apply_stage_fog(V.stage);
    fl_set_render_state(0x6C, 1);  /* Z GEQUAL + write */
    fl_set_render_state(0x62, V.nearest ? 0x10000 : 0); /* func_00152720 sets bilinear before list 6 */
    fl_set_render_state(0x66, 0xFFFFFFFF);              /* func_00152400 with an untinted object */
    float ident[16];
    fl_mat_identity(ident);
    int nr = fl_model_roots(V.model);
    for (int r = 0; r < nr; r++) {
        if (r > 0 && V.roots_mode == 0) break;
        if (r > 0 && V.roots_mode == 1) {
            /* heuristic stand-in for the per-stage object scripts: other roots are
             * object-local models placed by game code, except the world-sized
             * backdrops, which are authored in world coordinates */
            float lo[3], hi[3];
            if (!fl_model_root_bounds(V.model, r, lo, hi)) continue;
            float ext = 0.f;
            for (int k = 0; k < 3; k++) if (hi[k] - lo[k] > ext) ext = hi[k] - lo[k];
            if (ext < 20000.f) continue;
        }
        fl_model_draw(V.model, r, ident, 0x801, 0.f, 0.f); /* object flags as typical stage objects */
    }
    fl_set_render_state(0x5D, 0x32);
    fl_set_render_state(0x62, 0x10000);
    fl_fill_screen(0, 0); /* func_003ED1C0(0, 0): Z only */
}

static void render(void *u)
{
    (void)u;
    fl_frame_begin();
    float feet_x = 320, feet_y = 400, feet2_x = 520;
    if (V.model) {
        draw_stage();
        float p1[3] = { V.cam_x - 100.f, 0.f, 0.f }, p2[3] = { V.cam_x + 100.f, 0.f, 0.f }, dummy;
        project(p1, &feet_x, &feet_y);
        project(p2, &feet2_x, &dummy);
    }
    if (V.plain) {
        if (V.bank) {
            float m[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 320, 400, 0, 1 };
            fl_char_draw(V.bank, V.frame, m, 0xFFFFFFFF, V.pal);
        }
    } else if (V.model) {
        /* drawn above */
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
    if (!V.plain && !V.stage_only) {
    /* HUD bars: untextured gouraud triangles, then an additive highlight (blend 0x12) */
    tri(20, 20, 300, 20, 20, 36, 0xFFFFD000, 0xFFFF4000, 0xFFFFD000);
    tri(300, 20, 300, 36, 20, 36, 0xFFFF4000, 0xFFFF4000, 0xFFFFD000);
    fl_set_render_state(0x5D, 0x12);
    tri(20, 20, 300, 20, 20, 26, 0x80FFFFFF, 0x00FFFFFF, 0x80FFFFFF);
    fl_set_render_state(0x5D, 0x32);
    if (V.bank) {
        /* actor at (320, 400); the matrix is a plain translation (facing right) */
        float m[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, feet_x, feet_y, 0, 1 };
        /* shadow: translucent black copy, half-height via the matrix */
        float sh[16] = { 1, 0, 0, 0, 0, -0.15f, 0, 0, 0, 0, 1, 0, feet_x + 10, feet_y + 2, 0, 1 };
        fl_char_draw(V.bank, V.frame, sh, 0x60000000, V.pal);
        fl_char_draw(V.bank, V.frame, m, 0xFFFFFFFF, V.pal);
        /* mirrored copy (facing left) via a negative X scale, palette +1 */
        float mf[16] = { -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, feet2_x, feet_y, 0, 1 };
        fl_char_draw(V.bank, (V.frame + 1) % fl_char_frame_count(V.bank), mf, 0xFFFFFFFF, (V.pal + 1) & 15);
        char buf[96];
        snprintf(buf, sizeof buf, "PL%02X FRAME %3d/%d PAL %d", V.char_id, V.frame, fl_char_frame_count(V.bank), V.pal);
        text(20 + 1, 44 + 1, buf, 0xFF000000);
        text(20, 44, buf, 0xFFFFFFFF);
        int d, nv;
        r_stats(&d, &nv);
        static const char *rm[3] = { "ROOT 0", "WORLD ROOTS", "ALL ROOTS" };
        if (V.model) snprintf(buf, sizeof buf, "%d DRAWS %d VERTS  STAGE %02X %s", d, nv, V.stage, rm[V.roots_mode]);
        else snprintf(buf, sizeof buf, "%d DRAWS %d VERTS  STAGE TEX %d", d, nv, V.stage_sel);
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
    fl_camera_battle_default(&V.cam);
    V.roots_mode = 1; /* root 0 + world-scale roots (heuristic, see MESH_NOTES) */
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
        else if (!strcmp(a, "--stage") && n) { V.stage = (int)strtol(n, NULL, 0); i++; }
        else if (!strcmp(a, "--stage-only")) V.stage_only = 1;
        else if (!strcmp(a, "--all-roots")) V.roots_mode = 2;
        else if (!strcmp(a, "--roots") && n) { V.roots_mode = !strcmp(n, "all") ? 2 : !strcmp(n, "world") ? 1 : 0; i++; }
        else if (!strcmp(a, "--fog")) V.fog = 1;
        else if (!strcmp(a, "--lit")) V.lit = 1;
        else if (!strcmp(a, "--nearest")) V.nearest = 1;
        else if (!strcmp(a, "--cam-x") && n) { V.cam_x = (float)atof(n); i++; }
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
