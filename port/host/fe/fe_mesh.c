/*
 * Frontend: the 3D mesh path (the VU1 microcode path) on GL (Port J).
 *
 * The game builds every mesh itself: func_00415590 -> func_003F2A50 ->
 * func_003F2B70(clay, chunk) converts a POL mesh chunk into a "clay", and
 * func_003EE6F0(clay, fmt) makes the clay handle (VU1 packets).  Here the
 * same chunk also becomes a GL mesh under that handle (port/render
 * fl_clay_build, with the format word the game has at that moment), and
 * func_003F0500(handle) draws it with the current render state after the
 * game's own body has run (texture residency, matrices).  When the format
 * word changed since the build, func_003F0500 rebuilds the packets and so
 * does the GL side.
 *
 * Vertex writes: effects deform a model by writing new positions, colours
 * or UVs straight into its VU1 packet (func_0041C010 / func_0041BEC0 and
 * callbacks such as func_001412D0, func_00341DF0), through the per-clay
 * tables func_0041B3C0 builds (logical vertex -> packet offsets), and end
 * each pass with func_0041BB30 (write back the D-cache over the packet).
 * Here func_0041B3C0 also records, per POL vertex, where its first copy
 * lives in the packet (the game's own func_0041B7E0 / func_0041B8B0 give
 * both lists in packet order), and func_0041BB30 marks the clay so the
 * next func_003F0500 re-reads those vertices from the packet into the GL
 * buffer.  Whatever wrote the packet, the GL mesh shows it.
 */
#include <stdlib.h>
#include <string.h>
#include "../host.h"
#include "../../render/render.h"

void fe_sync_state(void);
void fe_sync_handle(u32 hnd);
#define MAX_CLAY 0x402
static const u8 *last_chunk;
static const void *last_clay;
static const u8 *clay_chunk[MAX_CLAY];
extern u8 data_mcdesc_004779F0[];

/* per clay: packet byte offset of each POL vertex's first copy (0xFFFF = none) */
typedef struct {
    u16 *off;
    int nv;
    u32 fl;     /* packet vertex layout (A41C w4): 1 pos, 2 normal, 4 colour, 8 uv (0x35 only) */
    u32 fmt;    /* slot format the packet was laid out with */
    u8 kind;    /* 0x25 / 0x35 */
    u8 dirty, ever;
} ClayMap;
static ClayMap cmap[MAX_CLAY];

extern int func_003DD030(int);
extern int func_0041B710(void *);
extern void func_0041B7E0(void *, void *);
extern void func_0041B8B0(void *, void *);

static u8 *clay_slot(int h) { return (u8 *)EE_BSS_PTR(0x005BF2F0) + (h - 1) * 0x170; }

static void cmap_free(int h)
{
    free(cmap[h].off);
    memset(&cmap[h], 0, sizeof cmap[h]);
}


/* copy the packet's vertices into the GL mesh's CPU copy; returns the
 * number of vertices that differed */
static int cmap_pull(int h, int count_only)
{
    ClayMap *m = &cmap[h];
    int nv = 0, i, diff = 0;
    FlMeshVtx *v = fl_clay_vertices(h, &nv);
    const u8 *base;
    if (!v || !m->off) return -1;
    base = (const u8 *)(uintptr_t)func_003DD030(*(s32 *)(clay_slot(h) + 0x1C));
    if (!base) return -1;
    if (nv > m->nv) nv = m->nv;
    for (i = 0; i < nv; i++) {
        const u8 *p;
        int d = 0;
        if (m->off[i] == 0xFFFF) continue;
        p = base + m->off[i];
        if (m->fl & 1) {
            float q[3];
            memcpy(q, p, 12);
            if (memcmp(q, v[i].pos, 12)) { d = 1; if (!count_only) memcpy(v[i].pos, q, 12); }
            p += 0x10;
        }
        if (m->fl & 2) p += 0x10;
        if (m->fl & 4) {
            /* the packet holds GS units: func_003EEC30 halves rgba of textured
             * meshes and alpha of untextured ones; the GL buffer holds byte units */
            float c[4];
            int k;
            memcpy(c, p, 16);
            for (k = 0; k < 4; k++)
                if (m->kind == 0x35 || k == 3) c[k] *= 2.f;
            if (memcmp(c, v[i].col, 16)) { d = 1; if (!count_only) memcpy(v[i].col, c, 16); }
            p += 0x10;
        }
        if (m->kind == 0x35 && (m->fl & 8)) {
            float t[2];
            memcpy(t, p, 8);
            if (memcmp(t, v[i].uv, 8)) { d = 1; if (!count_only) memcpy(v[i].uv, t, 8); }
        }
        diff += d;
    }
    if (diff && !count_only) fl_clay_vertices_changed(h);
    return diff;
}

void func_0041B3C0(void *a, void *b, int c)
{
    int n, cap, k, nv = 0, bad = 0;
    u16 *pairs;
    u32 tmp[16];
    func_0041B3C0__game(a, b, c);
    if (c <= 0 || c >= MAX_CLAY || !clay_chunk[c] || !fl_clay_vertices(c, &nv))
        return;
    cmap_free(c);
    /* func_0041B710 counts the indexed packet vertices; func_0041B8B0 walks the
     * packet and may see up to b->w14 + 1 of them (the game sizes its list so) */
    n = func_0041B710(b);
    cap = n;
    if (*(s32 *)((u8 *)b + 0x14) + 1 > cap) cap = *(s32 *)((u8 *)b + 0x14) + 1;
    if (n <= 0 || cap > 0x100000) return;
    /* func_0041B8B0 writes one entry per packet vertex whatever the count;
     * the packet offsets are u16, so a packet holds at most 0x10000 / 0x10 */
    if (cap < 0x1000) cap = 0x1000;
    pairs = (u16 *)calloc((size_t)cap + 16, 4);
    for (k = 0; k < cap; k++) pairs[2 * k] = 0xFFFF;
    func_0041B7E0(pairs, b);          /* .a = POL vertex index, packet order */
    memset(tmp, 0, sizeof tmp);
    tmp[0] = (u32)c;
    func_0041B8B0(tmp, pairs);        /* .b = packet byte offset, packet order */
    cmap[c].off = (u16 *)malloc((size_t)nv * 2);
    memset(cmap[c].off, 0xFF, (size_t)nv * 2);
    cmap[c].nv = nv;
    cmap[c].fl = ((u32 *)a)[1];
    cmap[c].fmt = *(u32 *)(clay_slot(c) + 0xC);
    cmap[c].kind = (u8)*(s32 *)(clay_slot(c) + 8);
    for (k = 0; k < n; k++) {
        u16 vi = pairs[2 * k];
        if (vi < nv) { if (cmap[c].off[vi] == 0xFFFF) cmap[c].off[vi] = pairs[2 * k + 1]; }
        else bad++;
    }
    free(pairs);
    if (bad || (cmap[c].kind != 0x25 && cmap[c].kind != 0x35)) {
        HOST_ONCE("clay %d: vertex map unusable (%d indices out of %d, kind %#x); packet writes not followed",
                  c, bad, nv, cmap[c].kind);
        cmap_free(c);
        return;
    }
    if (host_verbose) {   /* the freshly built packet must match the GL mesh built from the chunk */
        int d = cmap_pull(c, 1);
        if (d) {
            FlMeshVtx *v = fl_clay_vertices(c, &nv);
            const u8 *base = (const u8 *)(uintptr_t)func_003DD030(*(s32 *)(clay_slot(c) + 0x1C));
            host_log("clay %d: %d of %d packet vertices differ from the POL chunk (fl %X kind %X)", c, d, nv, cmap[c].fl, cmap[c].kind);
            for (k = 0; k < 2 && k < nv; k++) {
                const float *f = (const float *)(base + cmap[c].off[k]);
                host_log("  v%d off %X pkt %g %g %g %g | %g %g %g %g | %g %g %g %g | %g %g; gl %g %g %g col %d %d %d %d uv %g %g",
                    k, cmap[c].off[k], f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9], f[10], f[11], f[12], f[13],
                    v[k].pos[0], v[k].pos[1], v[k].pos[2], (int)v[k].col[0], (int)v[k].col[1], (int)v[k].col[2], (int)v[k].col[3], v[k].uv[0], v[k].uv[1]);
            }
        }
    }
}

/* func_0041BB30: end of a packet vertex write pass (SyncDCache over the packet) */
void func_0041BB30(void *a)
{
    int h = *(s32 *)a;
    func_0041BB30__game(a);
    if (h > 0 && h < MAX_CLAY && cmap[h].off) cmap[h].dirty = cmap[h].ever = 1;
}

int func_003F2B70(void *clay, void *chunk)
{
    last_clay = clay;
    last_chunk = (const u8 *)chunk;
    return func_003F2B70__game(clay, chunk);
}

int func_003EE6F0(void *clay, unsigned int flags)
{
    int h = func_003EE6F0__game(clay, flags);
    if (h > 0 && h < MAX_CLAY) {
        fe_sync_state();
        clay_chunk[h] = clay == last_clay ? last_chunk : 0;
        cmap_free(h);
        if (clay_chunk[h] && !fl_clay_build(h, clay_chunk[h], 16u << 20, flags) && host_verbose) {
            u8 *slot = (u8 *)EE_BSS_PTR(0x005BF2F0) + (h - 1) * 0x170;
            u32 d = *(u32 *)(slot + 0x40);
            host_log("clay %d: chunk type %08X fmt %08X game desc %d", h, *(u32 *)clay_chunk[h],
                     EE_BSS(u32, 0x004C2AD4), d ? (int)((d - (u32)(uintptr_t)data_mcdesc_004779F0) / 48) : -1);
        }
    }
    return h;
}

int func_003F0500(int h)
{
    int r = func_003F0500__game(h);
    if (r && h > 0 && h < MAX_CLAY && clay_chunk[h]) {
        /* the format the game's packets were built with: slot +0xC */
        u32 fmt = *(u32 *)((u8 *)EE_BSS_PTR(0x005BF2F0) + (h - 1) * 0x170 + 0xC);
        if (fl_clay_fmt(h) != fmt) {
            fl_sync_mode_words(EE_BSS(u32, 0x004C2AD0), fmt);
            fl_clay_build(h, clay_chunk[h], 16u << 20, 0);
            if (cmap[h].ever) cmap[h].dirty = 1;  /* the packet still holds the game's writes */
        }
        if (cmap[h].dirty) {
            static int off = -1;
            if (off < 0) off = getenv("MVC2_NO_VTXWRITE") != 0; /* A/B testing */
            cmap[h].dirty = 0;
            if (off) ;
            else if (cmap[h].fmt == fmt) cmap_pull(h, 0);
            else HOST_ONCE("clay %d: packet rebuilt with format %08X (map %08X); vertex writes not followed",
                           h, fmt, cmap[h].fmt);
        }
        fe_sync_state();
        {   /* textures the game (re)loaded into a record since it was last synced */
            uint32_t tx[64];
            int k, n = fl_clay_textures(h, tx, 64);
            for (k = 0; k < n; k++)
                fe_sync_handle(tx[k]);
        }
        /* the game also writes these directly (func_003DD2E0 builds the
         * projection in place): hand the renderer the game's current ones */
        fl_set_render_state(0x16, (uintptr_t)EE_BSS_PTR(0x0061C720));
        fl_set_render_state(0x17, (uintptr_t)EE_BSS_PTR(0x0061C6E0));
        fl_set_render_state(0x19, (uintptr_t)EE_BSS_PTR(0x0061BEE0));
        fl_set_render_state(0x1A, (uintptr_t)EE_BSS_PTR(0x0061BF20));
        fl_set_render_state(0x59, (uintptr_t)EE_BSS_PTR(0x0061B2F0));
        fl_set_render_state(0x5A, (uintptr_t)EE_BSS_PTR(0x0061B354));
        fl_set_render_state(0x5B, (uintptr_t)EE_BSS_PTR(0x0061B3B8));
        {
            static long dump_at = -2;
            extern volatile long mvc2_host_frame;
            if (dump_at == -2) {
                const char *e = getenv("MVC2_MESH_DUMP");
                dump_at = e ? atol(e) : -1;
            }
            {
                extern int fl_mesh_debug;
                fl_mesh_debug = dump_at == mvc2_host_frame;
            }
            if (dump_at == mvc2_host_frame) {
                const float *w = (const float *)EE_BSS_PTR(0x0061BEE0);
                host_log("clay %d fmt %08X world %.3f %.3f %.3f | %.3f %.3f %.3f | %.3f %.3f %.3f | t %.2f %.2f %.2f",
                         h, fmt, w[0], w[1], w[2], w[4], w[5], w[6], w[8], w[9], w[10], w[12], w[13], w[14]);
            }
        }
        if (host_verbose > 1) {
            static long last = -1;
            extern volatile long mvc2_host_frame;
            if (mvc2_host_frame % 60 == 0 && last != mvc2_host_frame) {
                const float *v = (const float *)EE_BSS_PTR(0x0061C720), *pj = (const float *)EE_BSS_PTR(0x0061C6E0),
                            *w = (const float *)EE_BSS_PTR(0x0061BEE0);
                int k;
                last = mvc2_host_frame;
                host_log("mesh %d frame %ld fmt %08X", h, mvc2_host_frame, fmt);
                for (k = 0; k < 4; k++)
                    host_log("  view %8.3f %8.3f %8.3f %8.3f | proj %8.3f %8.3f %8.3f %8.3f | world %8.3f %8.3f %8.3f %8.3f",
                             v[4 * k], v[4 * k + 1], v[4 * k + 2], v[4 * k + 3], pj[4 * k], pj[4 * k + 1], pj[4 * k + 2],
                             pj[4 * k + 3], w[4 * k], w[4 * k + 1], w[4 * k + 2], w[4 * k + 3]);
            }
        }
        fl_clay_draw(h);
    }
    return r;
}

int func_003F0860(int h)
{
    int r = func_003F0860__game(h);
    if (h > 0 && h < MAX_CLAY) {
        fl_clay_release(h);
        clay_chunk[h] = 0;
        cmap_free(h);
    }
    return r;
}
