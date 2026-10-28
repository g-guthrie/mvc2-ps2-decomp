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

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_nq;
extern G_nq *D_004C2794;

void func_0035E7F0(u8 *p, u8 *q)
{
    extern s32 func_00174470(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *r = q + 0x2B8;
    u8 *o = *(u8 **)(p + 0x14);
    u8 *pb;
    p[4]++;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    p[0x13C] = 1;
    pb = p + 2;
    *pb = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -8;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    if (func_00174470(p) == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        *r = 1;
        return;
    }
    p[0x1B5] = 0x41;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*pb]++;
    func_001E7F60(p);
    func_001757E0(p, 0x17, 0x14);
}
