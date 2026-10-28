typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState W49_b;

typedef struct { f32 x, y, z; } V3_b;
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_b;
extern G_b *D_004C2794;

void residual_00382790(u8 *p)
{
    u32 t;
    u8 *q;
    extern s32 func_001757E0(u8 *, s32, u8);
    extern void func_001E7F60(u8 *);

    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(W49_b *)(p + 0xEC) = *(W49_b *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3_b *)(p + 0x50) = *(V3_b *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x1B5] = 0x31;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(s8 *)(p + 0x31) = -1;
    func_001757E0(p, 0x17, 9);
    if (p[0x21] == 0) {
        func_001E7F60(p);
    }
}
