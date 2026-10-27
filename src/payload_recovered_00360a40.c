typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s16 D_004C1BD8[] __attribute__((section(".sdata")));
extern s16 D_004C1BDA[] __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, s32, s32);
extern void func_00360BD0(u8 *, u8 *);


#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void func_00360A40(u8 *p, u8 *q)
{
    f32 *fp = (f32 *)p;
    u32 t;
    t = p[4];
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
    p[0x13C] = 1;
    *(s8 *)(p + 0x31) = -1;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    fp[23] = 1.6666666269302368f * (f32)D_004C1BD8[p[0x21] * 2];
    *(f32 *)(p + 0x60) = 2.1428570747375488f * (f32)D_004C1BDA[p[0x21] * 2];
    if (*(s16 *)(q + 0x140))
        fp[23] = -fp[23];
    if (p[0x21] == 0)
        p[0x168] = 0x18;
    else
        p[0x168] = 0x10;
    func_001757E0(p, 0x17, p[0x168]);
    func_00360BD0(p, q);
}
