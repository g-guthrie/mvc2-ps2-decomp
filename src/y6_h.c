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

void func_00327CF0(u8 *p, u8 q) {
    extern u8 *func_003DA780();
    extern void func_00327DE0();
    u8 *o;
    if ((o = func_003DA780(0, 4, 1)) != 0) {
        *(void **)(o + 0x10) = func_00327DE0;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = q;
        *(S49 *)(o + 0xEC) = *(S49 *)(p + 0xEC);
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
        o[0x13C] = 0;
    }
}

extern V3 D_00442AA0;

void func_00147660(void) {
    extern u8 *func_003DA750();
    extern void func_00148950();
    u8 *o;
    s32 i = 0;
    do {
        if ((o = func_003DA750(0, 0xD, 1)) != 0) {
            o[0x13C] = 0;
            *(void **)(o + 0x10) = func_00148950;
            o[0x23] = 0;
            o[0x20] = i;
            *(V3 *)(o + 0x50) = D_00442AA0;
            *(s32 *)(o + 0xD0) = 0x431;
        }
        i++;
    } while (i < 4);
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = func_00148950;
        o[0x23] = 1;
        o[0x20] = 0;
        *(V3 *)(o + 0x50) = D_00442AA0;
        *(s32 *)(o + 0xD0) = 0x800431;
    }
}
