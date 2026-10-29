/*
 * Render-library entry points that touch the GS, the GIF or the scratchpad
 * (Port J).  On the host nothing is ever sent to a GS: the frontend's GL
 * renderer (port/render, bound through host_render_ops) draws each primitive
 * when the game submits it.  Without a frontend these keep the game-visible
 * results (return values, render state) and draw nothing.
 */
#include <string.h>
#include "host.h"
#include "host_render.h"

const HostRenderOps *host_render_ops;

extern int func_003E0DB0(unsigned int, void *, void *, unsigned int);

/* func_003DF7B0 (end of scene): T0_COUNT sample for the profiler + state. */
int func_003DF7B0(void)
{
    EE_BSS(u16, 0x004C2A78) = (u16)(host_frame_count * 0x2580u); /* ~one frame of T0 ticks */
    EE_BSS(s32, 0x0062BFD4) = 2;
    return 1;
}

/* func_003DBBF0: immediate GIF A+D send (display registers at flip). */
void func_003DBBF0(void *src, unsigned int n)
{
    (void)src; (void)n;
}

/* func_003DF490: textured sprite (0x34-byte vertex struct).  The texture
 * check is the original's: no VRAM record -> 0, nothing drawn. */
int func_003DF490(void *p)
{
    u8 tex0[8], clamp[8];
    if (func_003E0DB0(EE_BSS(u32, 0x004C2AEC), tex0, clamp, EE_BSS(u32, 0x004C2AD0)) == 0)
        return 0;
    if (host_render_ops && host_render_ops->sprite_tex)
        host_render_ops->sprite_tex(p);
    return 1;
}
