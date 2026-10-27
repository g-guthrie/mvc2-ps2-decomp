typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct { u8 prefix[0x7C]; s16 count[2]; } GameState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, s32, s32);
extern void func_003C32F0(u8 *, u8 *);


#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void func_003C3140(u8 *p, u8 *q)
{
    u8 *o;
    u32 t = p[4];
    o = *(u8 **)(q + 0x220);
    p[4] = t + 1;
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    {
        u8 *pp = p + 2;
    p[0x13C] = 0;
    *(s8 *)(p + 0x31) = -1;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    if (p[0x21] == 0) {
        p[0x1B5] = 0x48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[pp[0]]++;
    } else {
        p[0x1B5] = 0x49;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[pp[0]]++;
    }
    }
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    *(f32 *)(p + 0x38) += 68.5714263916015625f;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    func_001757E0(p, 0x16, 0x1C);
    *(s16 *)(p + 0x1C) = 4;
    func_003C32F0(p, q);
}
