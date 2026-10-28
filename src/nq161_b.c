typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState FieldsB;
typedef struct { f32 x, y, z; } V3b;
typedef struct {
    u8 pad0[0x7C];
    s16 f7c[2];
} GB;
extern GB *D_004C2794;
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; } CSb;

#define Q (*(u8 **)(p + 0x18))

void residual_003472C0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00347220(u8 *, s32);
    u32 t;
    CSb *sa;

    Q[0x2B8] = 1;
    t = p[4];
    p[4] = t + 1;
    *(FieldsB *)(p + 0xEC) = *(FieldsB *)(Q + 0xEC);
    p[0x13C] = 1;
    p[2] = Q[2];
    p[1] = Q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(Q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(Q + 0x54);
    p[0x1B7] = Q[0x1B7];
    p[0x1B8] = Q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(Q + 0x30);
    *(V3b *)(p + 0x50) = *(V3b *)(Q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(Q + 0x24);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(s16 *)(p + 0x1C0) = 0x10;
    *(s16 *)(p + 0x1E) = 0;
    p[0x21] = 0x13;
    *(f32 *)(p + 0x34) = *(f32 *)(Q + 0x34);
    sa = (CSb *)p;
    if (*(s16 *)(p + 0x140) == 0) {
        sa->f34 -= 120.0f;
    } else {
        sa->f34 += 120.0f;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(Q + 0x38);
    *(f32 *)(p + 0x38) += 120.0f;
    *(f32 *)(p + 0x3C) = *(f32 *)(Q + 0x3C);
    *(f32 *)(p + 0x50) = 0.1f;
    *(f32 *)(p + 0x54) = 0.1f;
    *(s16 *)(p + 0x1C) = 0x82;
    p[0x14E] = 0xB0;
    p[0x14F] = 0xB0;
    *(s8 *)(p + 0x24) = 0xE;
    func_001757E0(p, 0x17, 4);
    func_00347220(p, 1);
}

typedef ActorState FieldsC;
typedef struct { f32 x, y, z; } V3c;
extern s16 D_00473B30[];

void residual_003ADC90(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    u32 t;
    s32 a;
    u8 d;
    f32 f;

    t = p[4];
    p[4] = t + 1;
    *(FieldsC *)(p + 0xEC) = *(FieldsC *)(Q + 0xEC);
    p[0x13C] = 1;
    p[2] = Q[2];
    p[1] = Q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(Q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(Q + 0x54);
    p[0x1B7] = Q[0x1B7];
    p[0x1B8] = Q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(Q + 0x30);
    *(V3c *)(p + 0x50) = *(V3c *)(Q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(Q + 0x24);
    *(V3c *)(p + 0x34) = *(V3c *)(Q + 0x34);
    d = p[0x22];
    a = 0;
    if (p[0x21] == 0) {
        p[0x24] = 0;
        f = 0.0f;
        *(u32 *)(p + 0x60) = 0x40092492;
        *(u32 *)(p + 0x6C) = 0x3F092492;
    } else {
        p[0x24] = 7;
        a = 4;
        if (p[5] == 0) {
            *(f32 *)(p + 0x38) += 34.28571319580078f;
        } else {
            *(f32 *)(p + 0x38) += 171.42855834960938f;
        }
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0x3F892492;
        f = -13.333333015441895f;
        d = ~(s8)d & 7;
    }
    f += 1.6666666269302368f * (f32)D_00473B30[d];
    if (*(s16 *)(p + 0x140) != 0) f = -f;
    *(f32 *)(p + 0x34) += f;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    func_00175910(p, 0x12, 5, a);
}
