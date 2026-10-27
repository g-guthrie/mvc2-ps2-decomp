#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef ActorState B24;
typedef struct { f32 x, y, z; } V3;
extern void func_003AD6E0();
void *func_003AD600(u8 *p) {
    extern u8 *func_003DA750();
    u8 *o;
    if ((o = func_003DA750(0, 1, 1)) != 0) {
        *(void (**)())(o + 0x10) = func_003AD6E0;
        o[0x20] = 4;
        *(u8 **)(o + 0x18) = p;
        *(B24 *)(o + 0xEC) = *(B24 *)(p + 0xEC);
        o[0x13C] = 1;
        o[2] = p[2];
        o[1] = p[1];
        *(f32 *)(o + 0x50) = *(f32 *)(p + 0x50);
        *(f32 *)(o + 0x54) = *(f32 *)(p + 0x54);
        o[0x1B7] = p[0x1B7];
        o[0x1B8] = p[0x1B8];
        *(s8 *)(o + 0x30) = *(s8 *)(p + 0x30);
        *(V3 *)(o + 0x50) = *(V3 *)(p + 0x50);
        *(s8 *)(o + 0x24) = *(s8 *)(p + 0x24);
    }
    return o;
}

typedef ActorState B20;
typedef struct S20 {
    u8 pad0; u8 b1; u8 b2; u8 pad3[0x15]; struct S20 *parent; u8 pad1c[4]; u8 b20;
} S20;
void func_003B7ED0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(B20 *)(p + 0xEC) = *(B20 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x14D] = 0x20;
    p[0x14C] = 0x20;
    p[0x14F] = 0x24;
    p[0x14E] = 0x24;
    p[0x24] = 0;
}

