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
    }
    return r;
}
