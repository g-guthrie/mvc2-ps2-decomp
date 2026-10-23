#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern void (*const jtbl_0044A350[7])(u8 *, u8 *);
extern void func_0015E630(u8 *);

void func_00197920(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    p[0x24] = *(s8 *)(q + 0x24);
    jtbl_0044A350[p[4]](p, q);
}

void func_00197950(u8 *p, u8 *q)
{
    p[4]++;
    p[0x13C] = 0;
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
    (&jtbl_0044A350[4])[p[0x20]](p, q);
    func_0015E630(p);
    p[0] = 1;
}
