#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern s16 *D_004BF748[2];

void residual_001A5BE0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, u8);
    u8 *o;
    s16 *e;
    s32 k;
    u8 v;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
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
    o = *(u8 **)(p + 0x14);
    p[4]++;
    *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
    *(s8 *)(p + 0x31) = *(s8 *)(o + 0x31) - 4;
    v = p[0x21];
    k = (s32)(v & 0x80) >> 5;
    e = D_004BF748[p[0x23]]; e += ((v & 0x7F) << 2) + (k >> 1);
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + 1.6666666269302368f * (f32)e[0];
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + 2.142857074737549f * (f32)e[1];
    func_001757E0(p, 0x17, k + 0x1F);
}
