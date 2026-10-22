#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 prefix[0x7c]; s16 count[2]; } GameState_a;
extern GameState_a *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);
extern void func_00176160(u8 *, s32, s32, s32);

void func_00374AC0(u8 *p)
{
    u8 *q, *team;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
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
    p[0x24] = 0xB;
    team = p + 2;
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        p[2] ^= 1;
        p[0x1B0] = 0x66;
        p[0x1B1] = 0;
        p[0x1B5] = 0x46;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->count[team[0]]++;
        p[0x13C] = 0;
        func_001757E0(p, 0x15, 0x14);
        func_00176160(p, 2, 2, 2);
    }
}
