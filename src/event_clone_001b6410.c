#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#pragma padloop on
void func_001B6410(u8 *p)
{
    u8 *q;
    extern void func_001B6740(u8 *);
    extern void func_00175580(u8 *, s32, s32, s32);
    p[0x13C] = 0;
    if (p[4] == 0) {
        u32 t;
        t = p[4]; p[4] = t + 1;
        q = *(u8 **)(p + 0x18);
        *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = (*(u8 **)(p + 0x18))[2];
        p[1] = (*(u8 **)(p + 0x18))[1];
        *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
        p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
        p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
        p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
        p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
        p[0x1B8] = *(*(u8 **)(*(u8 **)(p + 0x18) + 0x1DC) + 0x1B8);
        p[0x24] = 7;
        p[0x21] = 0xFF;
    }
    q = *(u8 **)(p + 0x18);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    q = *(u8 **)(p + 0x18);
    if (q[0x150] == 0 || q[0x169] != 0x0F) {
        func_001B6740(p);
        return;
    }
    {
        u8 raw = q[0x150];
        u32 value = raw & 0xFF;
        p[0x13C] = 1;
        if (value != p[0x21]) {
            p[0x21] = raw;
            func_00175580(p, 0x1B, 0, value - 1);
        }
    }
}
