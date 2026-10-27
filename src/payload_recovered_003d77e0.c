typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *, s32, s32);
extern void func_003D7970(u8 *);


#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void func_003D77E0(u8 *p)
{
    u8 *q;
    u32 t;
    s32 tag = 0x1D05;
    q = *(u8 **)(p + 0x18);
    t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x26) = (s16)tag;
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
    p[0x24] = 10;
    p[0x14C] = 0x20;
    p[0x14D] = 0x20;
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    if (*(s16 *)(p + 0x140) == 0)
        p[0x22] = 12;
    else
        p[0x22] = 4;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    if (p[0x20] == 0) {
        *(u32 *)(p + 0xD4) = 0;
        *(u32 *)(p + 0xD0) = 0;
        *(u32 *)(p + 0xD8) = 2;
        func_001757E0(p, 0x16, 0x1D);
    } else if (*(u32 *)(p + 0xD0) != 0) {
        func_001757E0(p, 0x16, 0x2A);
    } else {
        func_001757E0(p, 0x16, 0x29);
    }
    *(f32 *)(p + 0x50) = 1.0499999523162842f;
    func_003D7970(p);
}
