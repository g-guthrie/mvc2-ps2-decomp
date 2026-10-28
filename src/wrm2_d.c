/* func_003502D0: MW 3.0 "-O3 -Op -fp off", exact when compiled in the same mwccps2 run after src/wrm1_a.c (warm-up: nearest preceding double-arithmetic function func_0034FBB0). */
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
extern f32 D_004F1F4C[];

void func_003502D0(u8 *p)
{
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    double k;
    f32 v;

    p[0x13C] = 1;
    n = 0x31;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
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
    *(f32 *)(p + 0x34) = (f32)((k = (double)D_004F1F4C[0] + k));
    *(f32 *)(p + 0x38) = 651.4285278320312f + *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s16 *)(p + 0x140) != 0) {
        v = 10.0f;
    } else {
        v = -10.0f;
    }
    *(f32 *)(p + 0x5C) = v;
    *(u32 *)(p + 0x60) = 0xBF892492;
    *(s16 *)(p + 0x1C) = 0x30;
    p[0x14C] = 0x40;
    p[0x14D] = 0x10;
    p[0x14E] = 0x60;
    p[0x14F] = 0x60;
    func_001757E0(p, 0x17, 0x23);
}

