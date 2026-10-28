typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3b;
#include "actor_inherited_state.h"
extern G3b *D_004C2794;
extern s16 D_00475AB4[];
extern s16 D_00475AB6[];

void residual_003BDAA0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003BD9A0(u8 *, u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_003BDC80(u8 *, u8 *);
    f32 a, b;
    p[4]++;
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
    p[0x24] = 0;
    *(s32 *)(p + 0xD0) = 6;
    *(s32 *)(p + 0xD4) = 0;
    *(s32 *)(p + 0xD8) = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x42;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x14F] = 0xF0;
    p[0x14E] = 0xF0;
    p[0x14D] = 0xF0;
    p[0x14C] = 0xF0;
    *(u32 *)(p + 0x54) = 0x3E800000;
    *(u32 *)(p + 0x50) = 0x3E800000;
    a = D_00475AB4[0];
    b = D_00475AB6[0];
    if (*(s16 *)(q + 0x140) != 0) a = -a;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * a;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737549f * b;
    func_001757E0(p, 0x16, 0xD);
    func_003BD9A0(p, q);
    func_001E3210(p, 0x24);
    func_003BDC80(p, q);
}
