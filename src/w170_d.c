#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState S49;
typedef struct { f32 x, y, z; } V3;

void func_001B0190(u8 *p) {
    extern void func_001754A0();
    u8 *s;
    f32 c;
    p[4]++;
    s = *(u8 **)(p + 0x18);
    *(S49 *)(p + 0xEC) = *(S49 *)(s + 0xEC);
    p[0x13C] = 1;
    p[2] = s[2];
    p[1] = s[1];
    *(f32 *)(p + 0x50) = *(f32 *)(s + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(s + 0x54);
    p[0x1B7] = s[0x1B7];
    p[0x1B8] = s[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(s + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(s + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(s + 0x24);
    p[0x13C] = 1;
    p[0x24] = 0xF;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) c = -175.0f; else c = 175.0f;
    *(f32 *)(p + 0x34) += c;
    *(f32 *)(p + 0x38) -= 17.142856597900391f;
    *(s16 *)(p + 0x1C) = 0x78;
    func_001754A0(p, 0x1B, 0xA);
}

void func_001A0400(u8 *p, u8 *q) {
    extern void func_00185960();
    s16 n = *(s16 *)(p + 0x1E);
    s32 i = 0;
    u8 *s0;
    if (0 < n) {
        do {
            s0 = p;
            *(S49 *)(p + 0xEC) = *(S49 *)(q + 0xEC);
            p[0x13C] = 1;
            i++;
            p[2] = q[2];
            p[1] = q[1];
            *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
            *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
            p[0x1B7] = q[0x1B7];
            p[0x1B8] = q[0x1B8];
            *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
            *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
            *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
            *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
            p[0x31] = 8;
            *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
            p[0x13C] = p[0x21] ? 1 : 0;
            p = *(u8 **)(p + 0xC);
        } while (i < n);
    }
    func_00185960(q, s0);
    s0[0x13C] = 1;
    *(s8 *)(s0 + 0x16A) = -1;
    *(s8 *)(s0 + 0x24) = *(s8 *)(*(u8 **)(s0 + 0x1DC) + 0x24);
    *(s8 *)(s0 + 0x31) = -2;
}
