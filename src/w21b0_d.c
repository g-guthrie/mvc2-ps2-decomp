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
