/* func_003504B0: MW 3.0 "-O3 -Op -fp off -sdatathreshold 0", exact when compiled in the same mwccps2 run after src/wrm2_d.c (warm-up: nearest preceding double-arithmetic function func_003502D0). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState Fields;
typedef struct { f32 x, y, z; } V3;
extern f32 D_004F1F4C;

void func_003504B0(u8 *p)
{
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    double k;
    f32 v;

    p[0x13C] = 1;
    *(Fields *)(p + 0xEC) = *(Fields *)(*(u8 **)(p + 0x18) + 0xEC);
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
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    p[0x24] = 0;
    if (*(s16 *)(p + 0x140) != 0) {
        k = -426.66666412353516;
    } else {
        k = 426.66666412353516;
    }
    *(f32 *)(p + 0x34) = (f32)((double)D_004F1F4C + k);
    *(f32 *)(p + 0x38) = 240.0f + *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
    if (*(s16 *)(p + 0x140) != 0) {
        v = 10.0f;
    } else {
        v = -10.0f;
    }
    *(f32 *)(p + 0x5C) = v;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_0015E630(p);
    p[0] = 1;
    func_001757E0(p, 0x17, 0x24);
}
