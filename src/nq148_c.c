typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState FieldsC;
typedef struct { f32 x, y, z; } V3c;
typedef struct {
    u8 pad0[0x7C];
    s16 f7c[2];
} GC;
extern GC *D_004C2794;
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad3c[0x20]; f32 f5c; u8 pad60[8]; f32 f68; } CS;

void residual_003B3CF0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B3ED0(u8 *, u8 *);
    u32 t;
    u8 *r;
    CS *sa;

    t = p[4];
    p[4] = t + 1;
    *(FieldsC *)(p + 0xEC) = *(FieldsC *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3c *)(p + 0x50) = *(V3c *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x31] = 1;
    p[0x14F] = 0x22;
    p[0x14E] = 0x22;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    r = p + 2;
    sa = (CS *)p;
    if (*(s16 *)(p + 0x140) == 0) {
        sa->f34 -= 120.0f;
    } else {
        sa->f34 += 120.0f;
    }
    *(f32 *)(p + 0x38) += 120.0f;
    *(u32 *)(p + 0x5C) = 0xC0D55555;
    *(u32 *)(p + 0x68) = 0xBED55555;
    if (*(s16 *)(p + 0x140) != 0) {
        sa->f5c = -sa->f5c;
        sa->f68 = -sa->f68;
    }
    p[0x1B5] = 8;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*r]++;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    func_001757E0(p, 0x17, 0x1D);
    func_003B3ED0(p, q);
}
