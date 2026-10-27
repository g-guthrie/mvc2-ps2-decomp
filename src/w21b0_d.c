typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3a;

void func_00229670(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s32 h;
    f32 a, b;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (*(s8 *)(p + 0x1B2) == 0) {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if ((s16)h != 0) return;
    } else {
        q = *(u8 **)(p + 0x1C4);
        if (func_00185980(p) != 0) {
            p[6]++;
            a = -3.3333332538604736f;
            b = 106.66666412353516f;
            if (p[0x1E6] != 0) {
                a = -a;
                b = -b;
            }
            *(f32 *)(p + 0x5C) = a;
            *(s32 *)(p + 0x68) = 0;
            q[0x20D] = 0;
            *(f32 *)(q + 0x38) = *(f32 *)(p + 0x430);
            *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) - b;
            func_001757E0(p, 0x16, 3);
            return;
        }
    }
    p[6] = 6;
    a = -16.66666603088379f;
    b = 0.5208333134651184f;
    if (p[0x1E6] != 0) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;
    func_001757E0(p, 0x16, 2);
}

#include "actor_inherited_state.h"
typedef ActorState S49;

void func_001BB140(u8 *p, u8 *q) {
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001BB2B0(u8 *, u8 *);
    f32 v;
    p[4] = 1;
    p[0x13C] = 1;
    *(S49 *)(p + 0xEC) = *(S49 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3a *)(p + 0x50) = *(V3a *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x24) = 7;
    *(V3a *)(p + 0x34) = *(V3a *)(q + 0x34);
    if (p[0x23] == 1) {
        if (*(s16 *)(q + 0x140) != 0) {
            v = -60.0f;
        } else {
            v = 60.0f;
        }
        *(f32 *)(p + 0x34) += v;
    }
    *(f32 *)(p + 0x38) += 160.0f;
    func_001754A0(p, 0x1B, 7);
    *(s16 *)(p + 0x1C) = 10;
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x54) = 0;
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_001E3210(q, 0x1E);
    func_001BB2B0(p, q);
}
