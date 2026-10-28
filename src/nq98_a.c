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
extern void func_0035D850(u8 *, u8 *);
extern void func_0035DD10(u8 *, u8 *);
extern void func_003A69B0(u8 *, u8 *);

#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void residual_0035D6F0(u8 *p, u8 *q)
{
    u8 *o;
    u32 t = p[4];
    o = *(u8 **)(p + 0x14);
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
    p[0x1B5] = 0x51;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 index; s16 count; index = p[2]; count = D_004C2794->count[index]; D_004C2794->count[index] = count + 1; }
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(o + 0x3C);
    *(f32 *)(p + 0x60) = 10.714284896850586f;
    *(f32 *)(p + 0x6C) = -0.6696428060531616f;
    func_001757E0(p, 0x15, 0x1C);
    func_0035D850(p, q);
}

void residual_0035DBB0(u8 *p, u8 *q)
{
    u8 *o;
    u32 t = p[4];
    o = *(u8 **)(p + 0x14);
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
    p[0x1B5] = 0x4F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 index; s16 count; index = p[2]; count = D_004C2794->count[index]; D_004C2794->count[index] = count + 1; }
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(o + 0x3C);
    *(f32 *)(p + 0x60) = 25.714284896850586f;
    *(f32 *)(p + 0x6C) = -1.3392856121063232f;
    func_001757E0(p, 0x16, 0xB);
    func_0035DD10(p, q);
}

void residual_003A6850(u8 *p, u8 *q)
{
    u32 t = p[4];
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
    p[0x21] = 0;
    p[0x1B5] = 0x3D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 index; s16 count; index = p[2]; count = D_004C2794->count[index]; D_004C2794->count[index] = count + 1; }
    p[0x1B0] = 0x41;
    p[0x1B1] = 0x41;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    *(f32 *)(p + 0x38) += 308.5714111328125f;
    func_001757E0(p, 0x17, 0x1E);
    func_003A69B0(p, q);
}
