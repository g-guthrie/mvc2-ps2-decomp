/*
 * Frontend: the game's render-library entry points drive the port's GL
 * renderer (port/render) (Port J).
 *
 * Each wrapper runs the game's own body first (func_X__game, hostify R17)
 * so every piece of game-visible state stays as on the PS2 (render-state
 * globals, texture/palette records, the VRAM bookkeeping, the batch writer),
 * then draws the same primitive with GL.  The GS packets the original builds
 * are discarded at the flip (boot.c, func_003DC720).
 *
 * Textures: the port's texture and palette handles are the game's own
 * (D_006207A0 / D_0061C7A0 record numbers).  A record is converted to a GL
 * texture when it is bound (state 4..7) or made resident (func_003EA660)
 * and its pixels changed: a signature of (pool address, format, size,
 * sampled contents), plus an explicit dirty mark from the unlock calls.
 *
 * Coordinates: the game's 640x480 space; the scroll origin D_0062BF8C/90 is
 * applied by the port at each primitive.  Scissor rectangles are in the
 * 640x224 frame buffer (half height) and are doubled vertically.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "host.h"
#include "host_render.h"
#include "../../render/render.h"

extern int func_003E0DB0(unsigned int, void *, void *, unsigned int);
extern int func_003DD030(int);

static int fe_log_tex, fe_log_state;
/* per-frame draw counters (MVC2_LOG_DRAW=1 or the shot log) */
int fe_cnt[8]; /* tri_tex, tri, sprite, quad, fill, tri_tex rejected, sprite rejected, quad rejected */

/* ---------------- texture / palette records -> GL ---------------- */
#define NTEX 0x181
#define NPAL 0x101
typedef struct { u32 sig; int used; } Sync;
static Sync tsync[NTEX], psync[NPAL];

static u32 sample_sig(const u8 *p, u32 n, u32 seed)
{
    u32 h = 2166136261u ^ seed, i, step;
    if (!p || !n)
        return h;
    step = n > 256 ? n / 256 : 1;
    for (i = 0; i < n; i += step)
        h = (h ^ p[i]) * 16777619u;
    h = (h ^ p[n - 1]) * 16777619u;
    return h;
}

static u8 gs_alpha(u8 a) { return a >= 0x80 ? 255 : (u8)(a * 2); }

static int swap34(int i) { return (i & ~0x18) | ((i & 0x08) << 1) | ((i & 0x10) >> 1); }

static void sync_pal(u32 pi)
{
    u8 *e, *src, rgba[256 * 4];
    int n, cpsm, i;
    u32 sig;
    if (pi == 0 || pi >= NPAL)
        return;
    e = (u8 *)EE_BSS_PTR(0x0061C7A0) + (pi - 1) * 64;
    if (*(s16 *)(e + 0x2C) == 0 || *(s32 *)(e + 0x28) == 0)
        return;
    n = *(s16 *)(e + 0x18) * *(s16 *)(e + 0x1A);
    if (n <= 0 || n > 256)
        n = 16;
    cpsm = *(s32 *)(e + 0x1C);
    src = (u8 *)(uintptr_t)func_003DD030(*(s32 *)(e + 0x28));
    sig = sample_sig(src, (u32)(cpsm == 2 ? n * 2 : n * 4), (u32)n << 8 | (u32)cpsm);
    if (psync[pi].used && psync[pi].sig == sig)
        return;
    for (i = 0; i < n; i++) {
        int s = n == 256 ? swap34(i) : i;
        u8 *o = rgba + 4 * i;
        if (cpsm == 2 || cpsm == 0xA) { /* CT16 */
            u16 v = (u16)(src[2 * s] | src[2 * s + 1] << 8);
            o[0] = (u8)((v & 31) << 3);
            o[1] = (u8)(((v >> 5) & 31) << 3);
            o[2] = (u8)(((v >> 10) & 31) << 3);
            o[3] = (v & 0x8000) ? 255 : 0;
        } else {
            o[0] = src[4 * s];
            o[1] = src[4 * s + 1];
            o[2] = src[4 * s + 2];
            o[3] = gs_alpha(src[4 * s + 3]);
        }
    }
    fl_pal_define(pi << 16, n, rgba);
    psync[pi].sig = sig;
    psync[pi].used = 1;
}

static void sync_tex(u32 ti)
{
    u8 *e, *src, *pix;
    int w, h, psm, fmt, i, n;
    u32 size, sig;
    if (ti == 0 || ti >= NTEX)
        return;
    e = (u8 *)EE_BSS_PTR(0x006207A0) + (ti - 1) * 64;
    if (*(s16 *)(e + 0x2C) == 0 || *(s32 *)(e + 0x28) == 0)
        return;
    w = *(s16 *)(e + 0x18);
    h = *(s16 *)(e + 0x1A);
    psm = *(s32 *)(e + 0x1C);
    size = *(u32 *)(e + 8);
    if (w <= 0 || h <= 0 || w > 1024 || h > 1024)
        return;
    src = (u8 *)(uintptr_t)func_003DD030(*(s32 *)(e + 0x28));
    sig = sample_sig(src, size, (u32)psm << 24 ^ (u32)w << 12 ^ (u32)h);
    if (tsync[ti].used && tsync[ti].sig == sig)
        return;
    if (*(s32 *)(e + 0x20) != 0)
        HOST_ONCE("texture %u: swizzled pool data (func_003EB210) is not converted", ti);
    n = w * h;
    switch (psm) {
    case 0x14: /* PSMT4 */
        fmt = FL_TEX_IDX4;
        pix = (u8 *)malloc((size_t)n);
        for (i = 0; i < n; i++)
            pix[i] = (u8)((src[i >> 1] >> ((i & 1) * 4)) & 15);
        break;
    case 0x13: /* PSMT8 */
        fmt = FL_TEX_IDX8;
        pix = (u8 *)malloc((size_t)n);
        memcpy(pix, src, (size_t)n);
        break;
    case 1: /* PSMCT24 */
        fmt = FL_TEX_RGBA32;
        pix = (u8 *)malloc((size_t)n * 4);
        for (i = 0; i < n; i++) {
            pix[4 * i] = src[3 * i];
            pix[4 * i + 1] = src[3 * i + 1];
            pix[4 * i + 2] = src[3 * i + 2];
            pix[4 * i + 3] = 255;
        }
        break;
    case 2: /* PSMCT16 */
        fmt = FL_TEX_RGBA32;
        pix = (u8 *)malloc((size_t)n * 4);
        for (i = 0; i < n; i++) {
            u16 v = (u16)(src[2 * i] | src[2 * i + 1] << 8);
            pix[4 * i] = (u8)((v & 31) << 3);
            pix[4 * i + 1] = (u8)(((v >> 5) & 31) << 3);
            pix[4 * i + 2] = (u8)(((v >> 10) & 31) << 3);
            pix[4 * i + 3] = (v & 0x8000) ? 255 : 0;
        }
        break;
    case 0: /* PSMCT32 */
    default:
        fmt = FL_TEX_RGBA32;
        pix = (u8 *)malloc((size_t)n * 4);
        for (i = 0; i < n; i++) {
            pix[4 * i] = src[4 * i];
            pix[4 * i + 1] = src[4 * i + 1];
            pix[4 * i + 2] = src[4 * i + 2];
            pix[4 * i + 3] = gs_alpha(src[4 * i + 3]);
        }
        break;
    }
    fl_tex_define(ti, w, h, fmt, pix);
    free(pix);
    if (fe_log_tex)
        host_log("texture %u: %dx%d psm %#x", ti, w, h, psm);
    tsync[ti].sig = sig;
    tsync[ti].used = 1;
}

/* the first 16 colours of palette record pi as RGBA8 (GS alpha 0x80 = 255) */
int fe_pal_rgba16(u32 pi, u8 rgba[64])
{
    u8 *e, *src;
    int cpsm, i;
    if (pi == 0 || pi >= NPAL)
        return -1;
    e = (u8 *)EE_BSS_PTR(0x0061C7A0) + (pi - 1) * 64;
    if (*(s16 *)(e + 0x2C) == 0 || *(s32 *)(e + 0x28) == 0)
        return -1;
    cpsm = *(s32 *)(e + 0x1C);
    src = (u8 *)(uintptr_t)func_003DD030(*(s32 *)(e + 0x28));
    if (!src)
        return -1;
    for (i = 0; i < 16; i++) {
        u8 *o = rgba + 4 * i;
        if (cpsm == 2 || cpsm == 0xA) {
            u16 v = (u16)(src[2 * i] | src[2 * i + 1] << 8);
            o[0] = (u8)((v & 31) << 3);
            o[1] = (u8)(((v >> 5) & 31) << 3);
            o[2] = (u8)(((v >> 10) & 31) << 3);
            o[3] = (v & 0x8000) ? 255 : 0;
        } else {
            o[0] = src[4 * i];
            o[1] = src[4 * i + 1];
            o[2] = src[4 * i + 2];
            o[3] = gs_alpha(src[4 * i + 3]);
        }
    }
    return 0;
}

void fe_sync_handle(u32 hnd)
{
    sync_tex(hnd & 0xFFFF);
    sync_pal(hnd >> 16);
}

static void sync_origin(void)
{
    fl_set_origin(EE_BSS(s32, 0x0062BF8C), EE_BSS(s32, 0x0062BF90));
    fl_sync_mode_words(EE_BSS(u32, 0x004C2AD0), EE_BSS(u32, 0x004C2AD4));
}

void fe_sync_state(void)
{
    sync_origin();
}

/* ---------------- render state ---------------- */
int func_003DF850(int id, int v)
{
    int r = func_003DF850__game(id, v);
    if (fe_log_state && (id == 0x5D || id == 0xD || id == 0x6C || id == 0x6B || id == 0x62 || id == 0x63)) {
        /* MVC2_LOG_STATE=1: each distinct render-state value once, with the frame it was first set */
        static u32 seen[512];
        static int nseen;
        u32 key = (u32)id << 24 ^ (u32)v, k;
        extern volatile long mvc2_host_frame;
        for (k = 0; k < (u32)nseen && seen[k] != key; k++)
            ;
        if (k == (u32)nseen && nseen < 512) {
            seen[nseen++] = key;
            host_log("state %#x = %#x first at frame %ld (D_004C2AD0 %08X)", id, v, mvc2_host_frame, EE_BSS(u32, 0x004C2AD0));
        }
    }
    fl_set_render_state(id, (uintptr_t)(u32)v);
    fl_sync_mode_words(EE_BSS(u32, 0x004C2AD0), EE_BSS(u32, 0x004C2AD4));
    if (id >= 4 && id <= 7)
        fe_sync_handle((u32)v);
    return r;
}

int func_003DF7D0(void)
{
    int r = func_003DF7D0__game();
    fl_default_state();
    return r;
}

int func_003E00D0(int x, int y, int w, int h, int mode)
{
    int r = func_003E00D0__game(x, y, w, h, mode);
    int fw = EE_BSS(s32, 0x004C2AE4), fh = EE_BSS(s32, 0x004C2AE0);
    if (x < 0) x = 0;
    if (fw < x + w) w = fw - x;
    if (y < 0) y = 0;
    if (fh < y + h) h = fh - y;
    /* frame buffer is half height (FRAME mode): the 640x480 canvas doubles y */
    fl_set_scissor(x, y * 2, w, h * 2);
    return r;
}

void func_003E00B0(int v)
{
    static u32 last = 0xDEADBEEF;
    func_003E00B0__game(v);
    fl_set_clear_color((u32)v);
    if (host_verbose && (u32)v != last) {
        extern volatile long mvc2_host_frame;
        host_log("frame %ld: clear colour %08X", mvc2_host_frame, (u32)v);
        last = (u32)v;
    }
}

/* ---------------- frame ---------------- */
void func_00170D30(void)
{
    {   /* MVC2_MESH_DUMP=F (fe_mesh.c): mark where the frame's begin falls among the mesh draws */
        extern volatile long mvc2_host_frame;
        static long at = -2;
        if (at == -2) at = getenv("MVC2_MESH_DUMP") ? atol(getenv("MVC2_MESH_DUMP")) : -1;
        if (at == mvc2_host_frame) fprintf(stderr, "[mesh] frame begin %ld\n", mvc2_host_frame);
    }
    fl_frame_begin();
    func_00170D30__game();
}

void func_00170D70(void)
{
    func_00170D70__game();
    fl_frame_end();
}

/* ---------------- residency / locks ---------------- */
void func_003EA660(int n, void *list)
{
    u32 *l = (u32 *)list;
    int i;
    func_003EA660__game(n, list);
    for (i = 0; i < n; i++)
        fe_sync_handle(l[i]);
}

int func_003EA070(int tex) /* texture unlock: the pixels changed */
{
    int r = func_003EA070__game(tex);
    if (tex > 0 && tex < NTEX)
        tsync[tex].used = 0;
    sync_tex((u32)tex);
    return r;
}

int func_003EA0D0(int pal) /* palette unlock */
{
    int r = func_003EA0D0__game(pal);
    if (pal > 0 && pal < NPAL)
        psync[pal].used = 0;
    sync_pal((u32)pal);
    return r;
}

/* ---------------- primitives ---------------- */
static int tex_ok(void)
{
    u8 t0[8], t1[8];
    u32 cur = EE_BSS(u32, 0x004C2AEC);
    if (func_003E0DB0(cur, t0, t1, EE_BSS(u32, 0x004C2AD0)) == 0)
        return 0;
    fe_sync_handle(cur);
    fl_set_render_state(4, cur);
    sync_origin();
    return 1;
}

int func_003DF0C0(void *v) /* textured gouraud triangle */
{
    int r = func_003DF0C0__game(v);
    if (r && tex_ok()) {
        fl_tri_tex((const FlTri *)v);
        fe_cnt[0]++;
    } else
        fe_cnt[5]++;
    return r;
}

int func_003DEE00(void *v) /* untextured gouraud triangle */
{
    int r = func_003DEE00__game(v);
    sync_origin();
    fl_tri((const FlTri *)v);
    fe_cnt[1]++;
    return r;
}

static int fe_sprite(const void *v)
{
    if (!tex_ok()) {
        fe_cnt[6]++;
        return 0;
    }
    fe_cnt[2]++;
    return fl_sprite_tex((const FlSprite *)v);
}

static int fe_fill(int mode, uint32_t c)
{
    return fl_fill_screen(mode, c);
}

int func_003ED1C0(int mode, int c) /* fill: 0 = Z only, 1 = colour + Z */
{
    int r = func_003ED1C0__game(mode, c);
    fl_fill_screen(mode, (u32)c);
    fe_cnt[4]++;
    return r;
}

int func_00420BF0(void *writer, void *quad) /* batch-writer textured quad (text) */
{
    int r = func_00420BF0__game(writer, quad);
    if (r && tex_ok()) {
        fl_quad_tex((const FlQuad *)quad);
        fe_cnt[3]++;
    } else
        fe_cnt[7]++;
    return r;
}

static const HostRenderOps fe_ops = { fe_sprite, 0, 0, 0, fe_fill, 0 };

/* func_003ECD00 (flip).  The display size comes from the game's own display
 * environment (D_0062BC50, built by sceGsSetDefDispEnv = func_00100590 in
 * func_001020E0): DISPLAY.DW / (MAGH + 1) pixels by DH + 1 lines.  With the
 * 640x224 FRAME-mode buffer drawn at Y/2, each display line is one canvas
 * row, so the PS2 shows canvas rows 0..447 of the 640x480 canvas.  The rest
 * of the environment (PMODE, SMODE2, DISPFB, DX/DY, BGCOLOR) only steers the
 * TV encoder and has no host counterpart; nothing else reads it. */
static void fe_flip(void)
{
    static unsigned long long last = ~0ull;
    unsigned long long d = EE_BSS(unsigned long long, 0x0062BC68); /* disp[0].display */
    if (d != last) {
        int magh = (int)((d >> 23) & 0xF), dw = (int)((d >> 32) & 0xFFF), dh = (int)((d >> 44) & 0x7FF);
        last = d;
        if (d && dw && dh) {
            fl_set_display((dw + 1) / (magh + 1), dh + 1);
            if (host_verbose)
                host_log("display: %dx%d (DISPLAY %016llX)", (dw + 1) / (magh + 1), dh + 1, d);
        }
    }
    fl_frame_flip();
}

void fe_render_init(void)
{
    fl_set_flip_clear(1);
    host_present_hook = fe_flip;
    fe_log_tex = getenv("MVC2_LOG_TEX") != 0;
    fe_log_state = getenv("MVC2_LOG_STATE") != 0;
    host_render_ops = &fe_ops;
}
