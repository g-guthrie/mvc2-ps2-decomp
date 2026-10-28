/* residual_003AE9A0: try30.sh "-O4,p -fp off -sdatathreshold 8" (3.0, cold, no warm). fptosi via (s32) casts. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"
extern s16 D_004C27A4 __attribute__((section(".sdata")));
extern s16 D_00473BF0[];
extern s16 D_00473220[];

void residual_003AE9A0(u8 *p, u8 *r)
{
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_003AF770(u8 *, u8 *, u8 *);
    extern void func_003AF760(u8 *, u8 *);
    extern void func_003AE900(u8 *);
    extern void func_00175580(u8 *, s32, s32, u8);
    extern void func_003AEF10(u8 *, u8 *);
    s32 i;
    u8 *qec;
    u8 *q2;
    u8 *q;
    u8 *b;
    u8 *q1;
    u8 *q50;
    u8 *q54;
    u8 *q1b7;
    u8 *q1b8;
    u8 *v;
    s16 *t;
    u8 *c;
    u32 ang;
    u8 *q30;
    u8 *q24;

    q = *(u8 **)(p + 0x18);
    qec = q + 0xec;
    *(ActorState *)(p + 0xec) = *(ActorState *)qec;
    p[0x13C] = 1;
    q2 = q + 2;
    q1 = q + 1;
    p[2] = *q2;
    q54 = q + 0x54;
    q1b7 = q + 0x1B7;
    q1b8 = q + 0x1B8;
    q30 = q + 0x30;
    q24 = q + 0x24;
    p[1] = *q1;
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)q54;
    p[0x1B7] = *q1b7;
    p[0x1B8] = *q1b8;
    *(s8 *)(p + 0x30) = *(s8 *)q30;
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)q24;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    q50 = q + 0x50;
    if (*(s16 *)(q + 0x140) != 0) {
        *(s8 *)(p + 0x22) = -*(s8 *)(p + 0x22);
    }
    func_003AF770(p, r, q);
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x5C) = 0;
    *(s8 *)(p + 0x31) = -1;
    *(s16 *)(r + 8) = 1;
    r[0x28] = 0;
    if (D_004C27A4 < 3) {
        func_003AF760(p, r);
        return;
    }
    v = func_003DA750(p, 1, 2);
    *(void (**)(u8 *))(v + 0x10) = func_003AE900;
    v[0x20] = 2;
    *(u8 **)(v + 0x18) = q;
    *(u8 **)(v + 0x14) = p;
    *(ActorState *)(v + 0xec) = *(ActorState *)qec;
    v[0x13C] = 1;
    v[2] = *q2;
    v[1] = *q1;
    *(f32 *)(v + 0x50) = *(f32 *)q50;
    *(f32 *)(v + 0x54) = *(f32 *)q54;
    v[0x1B7] = *q1b7;
    v[0x1B8] = *q1b8;
    *(s8 *)(v + 0x30) = *(s8 *)q30;
    *(V3 *)(v + 0x50) = *(V3 *)q50;
    *(s8 *)(v + 0x24) = *(s8 *)q24;
    *(s8 *)(v + 0x31) = -2;
    v[0xB2] = r[0x2A];
    v[4] = 1;
    *(u8 **)(r + 0x24) = v;
    i = 0;
    do {
        c = func_003DA750(p, 1, 2);
        *(void (**)(u8 *))(c + 0x10) = func_003AE900;
        c[0x20] = 1;
        *(u8 **)(c + 0x18) = q;
        *(u8 **)(c + 0x14) = p;
        *(ActorState *)(c + 0xec) = *(ActorState *)qec;
        c[0x13C] = 1;
        c[2] = *q2;
        c[1] = *q1;
        *(f32 *)(c + 0x50) = *(f32 *)q50;
        *(f32 *)(c + 0x54) = *(f32 *)q54;
        c[0x1B7] = *q1b7;
        c[0x1B8] = *q1b8;
        *(s8 *)(c + 0x30) = *(s8 *)q30;
        *(V3 *)(c + 0x50) = *(V3 *)q50;
        *(s8 *)(c + 0x24) = *(s8 *)q24;
        c[0x22] = p[0x22];
        ang = (u8)((s32)((c[0x22] + 4) & 0xF8) / 8);
        func_00175580(c, 0x1B, 1, ang);
        *(s16 **)(c + 0x164) = D_00473BF0;
        b = c + 0x88;
        *(s32 *)(c + 0x1D4) = *(s32 *)(c + 0x17C) + (*(u16 *)(*(u8 **)(p + 0x164) + 0x12) << 4);
        *(s8 *)(c + 0x24) = 0;
        *(s8 *)(c + 0x31) = -1;
        t = &D_00473220[(u8)ang * 4];
        *(s16 *)(b + 0) = (s32)(1.6666666269302368f * (f32)t[0]);
        *(s16 *)(b + 2) = (s32)(2.142857074737549f * (f32)t[1]);
        *(s16 *)(b + 4) = (s32)(1.6666666269302368f * (f32)t[2]);
        *(s16 *)(b + 6) = (s32)(2.142857074737549f * (f32)t[3]);
        i++;
        b[0x2A] = r[0x2A];
        *(s16 *)(c + 0x140) = 0;
        c[4] = 1;
    } while (i < 2);
    p[4]++;
    func_003AEF10(p, r);
}
