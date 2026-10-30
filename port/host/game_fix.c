/*
 * Credited functions whose C is right for MIPS but not for a host compiler
 * (Port J).  Each row has `ret` set in host_impl.csv: the credited C says
 * void, but the function tail-calls a value-returning function and its
 * callers use $v0 (found by following $v0 after every `jal` in the asm).
 * The other 18 such functions are kernel syscall stubs (handled as stubs).
 */
#include <stdio.h>
#include <stdlib.h>
#include "host.h"

extern int func_003F5270(void *, int, int);

/* TIM2: pointer to picture 0's image data (func_003F5270(p, 0, 0)). */
int func_003F5070(void *p)
{
    return func_003F5270(p, 0, 0);
}

extern int func_003F5440(void *);

/* TIM2: pointer to picture 0's CLUT (func_003F5440(p)). */
int func_003F5080(int a0, int a1, int a2, int a3)
{
    (void)a1; (void)a2; (void)a3;
    return func_003F5440((void *)(uintptr_t)a0);
}

extern void *func_003DA750(void *, int, int);
extern void func_00391710(void *, int, int, int); /* R22-widened dispatch head */

/* src/h2.c, returning the object as the EE code does in $v0 (func_00391FD0
 * tests it). */
void *func_003916B0(void *pv, int v)
{
    u8 *p = (u8 *)pv;
    u8 *o = (u8 *)func_003DA750(p, 1, 3);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_00391710;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        o[0x20] = (u8)v;
        *(s16 *)(o + 0x26) = 0x2000;
    }
    return o;
}

/* src/vector_frame_compare_004148C0.c reads the last camera vectors through
 * literal EE addresses (0x00632710..0x00632738, BSS): the same compare on
 * the host BSS blob. */
int func_004148C0(void *av, void *bv, void *cv, float marker)
{
    const float *a = (const float *)av, *b = (const float *)bv, *c = (const float *)cv;
    const float *last = (const float *)EE_BSS_PTR(0x00632710);
    return a[0] == last[8] && a[1] == last[9] && a[2] == last[10] &&
           b[0] == last[4] && b[1] == last[5] && b[2] == last[6] &&
           c[0] == last[0] && c[1] == last[1] && c[2] == last[2] &&
           marker == EE_BSS(float, 0x004C2B28);
}

/* func_0032DF90(side): the CPU team pick is the game's own C
 * (src/r13_05_b.c).  Testing hook only: with --cpu-team a,b,c
 * (MVC2_CPU_TEAM) the picks are then replaced the way the game writes them
 * (+0x540 character, +1 copy, +0x4DD = D_004405A0[character]); without it
 * nothing changes. */
extern s8 D_004405A0[];
void func_0032DF90(int side)
{
    const char *force = getenv("MVC2_CPU_TEAM");
    func_0032DF90__game(side);
    if (force && *force) {
        int ids[3] = { -1, -1, -1 }, t;
        u8 *base = (u8 *)EE_BSS_PTR(0x004F20B0);
        sscanf(force, "%i,%i,%i", &ids[0], &ids[1], &ids[2]);
        for (t = 0; t < 3; t++) {
            u8 *rec = base + ((s8)side + t * 2) * 0x5B8;
            if (ids[t] < 0 || ids[t] > 0x3A)
                continue;
            rec[0x540] = (u8)ids[t];
            rec[1] = (u8)ids[t];
            rec[0x4DD] = (u8)D_004405A0[ids[t]];
        }
    }
    for (int t = 0; t < 3; t++)
        host_log("CPU pick %d: character %#x", t,
                 ((u8 *)EE_BSS_PTR(0x004F20B0))[((s8)side + t * 2) * 0x5B8 + 0x540]);
}
