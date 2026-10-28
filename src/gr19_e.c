/* ./try30.sh (MW 3.0) "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G_b;
extern G_b *D_004C2794;
extern u16 D_00472A00[];
extern f32 D_004F1FC8[];
extern f32 D_004F1FD0[];

void func_003A01C0(u8 *p, u8 *q) {
    extern u32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    s32 v;
    s32 k;
    u8 *s;
    p[4]++;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    p[0x13C] = 1;
    s = p + 2;
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
    p[0x24] = 0;
    p[0x1B0] = 0x40;
    p[0x1B1] = 0;
    *(f32 *)(p + 0x34) = D_004F1FC8[0] + 1.6666666269302368f * (f32)(u32)D_00472A00[func_00174170() & 0x1F];
    *(f32 *)(p + 0x38) = D_004F1FD0[0];
    v = 0xB;
    k = 0;
    if (*(s16 *)(p + 0x140) == 0) { k = 0; v = -0xB; }
    *(f32 *)(p + 0x5C) = (f32)v;
    *(f32 *)(p + 0x60) = -12.857142448425293f - 2.142857074737549f * (f32)(func_00174170() & 0x1F);
    *(f32 *)(p + 0x68) = (f32)k;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 100;
    func_001757E0(p, 0x17, func_00174170() & 3);
    k = 0x5A;
    if (func_00174170() & 3) k = 0x5F;
    p[0x1B5] = k;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*s] += 1;
    p[0x14C] = p[0x14D] = p[0x14E] = p[0x14F] = 0x40;
    func_001E7F60(p);
}
