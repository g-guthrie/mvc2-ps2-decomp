typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState B197;

typedef struct { f32 x, y, z; } V197;

void func_001D3830(u8 *p, u8 *q) {
    extern void func_003DAA40(u8 *);
    extern s8 func_00175670(u8 *);
    extern void func_001754A0(u8 *, s32, s32);
    u32 t = p[4];
    if (t == 0) {
        if (q[0x20D] == 2) {
            func_003DAA40(p);
            return;
        }
        p[4] = t + 1;
        *(B197 *)(p + 0xEC) = *(B197 *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V197 *)(p + 0x50) = *(V197 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        func_001754A0(p, 0x1B, (u8)(p[0x20] + 2));
    }
    if (func_00175670(p) < 0) {
        func_003DAA40(p);
    }
}
