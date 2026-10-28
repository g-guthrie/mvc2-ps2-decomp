#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
#include "actor_inherited_state.h"
typedef struct { u8 pad[0x7C]; s16 f7c[2]; } Gnq102a;
extern Gnq102a *D_004C2794;
extern u16 *D_004C29C8;

void residual_00391DE0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    f32 k;
    p[4]++;
    *(ActorState *)(p+0xEC) = *(ActorState *)(*(u8 **)(p+0x18)+0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p+0x50) = *(f32 *)(*(u8 **)(p+0x18)+0x50);
    *(f32 *)(p+0x54) = *(f32 *)(*(u8 **)(p+0x18)+0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p+0x30) = *(s8 *)(*(u8 **)(p+0x18)+0x30);
    *(V3 *)(p+0x50) = *(V3 *)(*(u8 **)(p+0x18)+0x50);
    *(s8 *)(p+0x24) = *(s8 *)(*(u8 **)(p+0x18)+0x24);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x42;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { u8 i = p[2]; s16 v = D_004C2794->f7c[i]; D_004C2794->f7c[i] = v + 1; }
    *D_004C29C8 = *(u16 *)(*(u8 **)(p+0x18)+0x168);
    *(f32 *)(p+0x34) = *(f32 *)(*(u8 **)(p+0x18)+0x34) + (*(s16 *)(p + 0x140) ? 106.66666412353516f : -106.66666412353516f);
    *(f32 *)(p+0x38) = *(f32 *)(*(u8 **)(p+0x18)+0x430);
    func_001757E0(p, 0x17, 3);
}

typedef struct { s32 w[0x31]; } BLnq102c;
extern f32 D_004730E0[];
typedef struct { u8 pad[0x50]; f32 f50, f54; } SAnq102c;

void func_003A9B80(u8 *a, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *t;
    a[4]++;
    *(BLnq102c *)(a + 0xEC) = *(BLnq102c *)(q + 0xEC);
    a[0x13C] = 1;
    a[2] = q[2];
    a[1] = q[1];
    *(f32 *)(a + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(q + 0x54);
    a[0x1B7] = q[0x1B7];
    a[0x1B8] = q[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(a + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(q + 0x24);
    t = a + 2;
    if (a[0x20] == 0) {
        f32 f;
        a[0x13C] = 0;
        *(u32 *)(a + 0x5C) = 0;
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x60) = 0x41700000;
        *(u32 *)(a + 0x6C) = 0;
        f = *(f32 *)(q + 0x34);
        *(f32 *)(a + 0x34) = f;
        *(f32 *)(a + 0x64) = f;
        *(f32 *)(a + 0x38) = *(f32 *)(q + 0x38);
        a[0x22] = 0;
        *(s16 *)(a + 0x1C) = 0;
    } else {
        f32 f;
        *(s8 *)(a + 0x31) = *(s8 *)(a + 0x1E);
        f = D_004730E0[a[0x22]];
        ((SAnq102c *)a)->f54 = f;
        ((SAnq102c *)a)->f50 = f;
        a[0x1B0] = 0x42;
        a[0x1B1] = 0x42;
        a[0x1B5] = 0x41;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        { u8 i = *t; s16 v = D_004C2794->f7c[i]; D_004C2794->f7c[i] = v + 1; }
        func_001757E0(a, 0x16, 6);
    }
}
