#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

#include "actor_inherited_state.h"

typedef struct { float x, y, z; } V3a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Ga;
extern Ga *D_004C2794;

void func_003A9760(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, u8);
    extern s32 func_00174470(u8 *);
    extern void func_003A9600(u8 *, u8 *);
    ++p[4];
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(float *)(p + 0x50) = *(float *)(q + 0x50);
    *(float *)(p + 0x54) = *(float *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    p[0x30] = *(s8 *)(q + 0x30);
    *(V3a *)(p + 0x50) = *(V3a *)(q + 0x50);
    p[0x24] = *(s8 *)(q + 0x24);
    p[0x24] = 8;
    *(s16 *)(p + 0x1C) = 0x20;
    p[0x1B0] = 0x43;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x14F] = 0x20;
    p[0x14E] = 0x20;
    p[0x14D] = 0x20;
    p[0x14C] = 0x20;
    func_001757E0(p, 0x16, p[0x21] + 8);
    if (func_00174470(p))
        func_003A9600(p, q);
}
