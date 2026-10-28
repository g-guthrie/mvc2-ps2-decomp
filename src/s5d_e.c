/* s5d: MW 3.0.3, ./try.sh src/s5d_e.c "-O3 -Op -sdatathreshold 0" (also 3.0). static func_0018E970 is the real callee (credited in src/wave33.c); func_0018F130/func_0018F000 take the u8 index as their second argument, which is why retail andi goes to a1. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_00446D40[];
extern s16 D_00446C40[];
#include "actor_selector_api.h"

static u8 func_0018E970(G18E970 *p) {
    s8 n = p->b243;
    if ((p->w1d0[0x12] & 4) == 0) {
        G18E970 *t = p->w1cc;
        if (t == 0) t = p->w220;
        n = n + D_00446D40[(p->b21b - t->b21b + 7) & 0xF];
        if (n < 0) n = 0;
        if (n > 15) n = 15;
    }
    return n;
}

void func_0018EF20(u8 *p)
{
    extern void func_0018F130(u8 *, s32);
    extern void func_0018F000(u8 *, s32);
    u8 i;
    u8 *q;
    i = func_0018E970((G18E970 *)p);
    *(f32 *)(p + 0x234) = 1.6666666269302368f * (f32)*(s16 *)((u32)D_00446C40 + (i << 1)) / 256.0f;
    *(u32 *)(p + 0x238) = 0x3FFD5555;
    q = *(u8 **)(p + 0x1DC);
    if (q == 0)
        q = *(u8 **)(p + 0x220);
    if (q[0x1E6] != 0) {
        *(f32 *)(p + 0x234) = -*(f32 *)(p + 0x234);
        *(f32 *)(p + 0x238) = -*(f32 *)(p + 0x238);
    }
    if (p[5] == 2 || ((*(u8 **)(p + 0x1D0))[1] & 0x40) != 0)
        func_0018F130(p, i);
    else
        func_0018F000(p, i);
}
