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
extern u16 *D_004C29C8;
extern f32 D_00471BB0[];
extern f32 D_00471BB4[];
extern f32 D_00471BB8[];
extern f32 D_00471BBC[];

void residual_00391770(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    p[4]++;
    *(ActorState *)(p+0xEC) = *(ActorState *)(*(u8 **)(p+0x18)+0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p+0x50) = *(f32 *)(*(u8 **)(p+0x18)+0x50);
    *(f32 *)(p+0x54) = *(f32 *)(*(u8 **)(p+0x18)+0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p+0x30) = *(s8 *)(*(u8 **)(p+0x18)+0x30);
    *(V3 *)(p+0x50) = *(V3 *)(*(u8 **)(p+0x18)+0x50);
    *(s8 *)(p+0x24) = *(s8 *)(*(u8 **)(p+0x18)+0x24);
    p[0x1B3] = 0;
    p[2] ^= 1;
    p[0x1B0] = 0;
    p[0x1B1] = 0x44;
    p[0x14E] = 0x28;
    p[0x14F] = 0x28;
    *(f32 *)(p+0x34) = *(f32 *)(*(u8 **)(p+0x18)+0x34) + (*(s16 *)(p + 0x140) ? 13.333333015441895f : -13.333333015441895f);
    *(f32 *)(p+0x38) = 68.57142639160156f + *(f32 *)(*(u8 **)(p+0x18)+0x38);
    *(f32 *)(p+0x5C) = *(s16 *)(p + 0x140) ? D_00471BB0[p[0x1B7] * 4] : -D_00471BB0[p[0x1B7] * 4];
    *(f32 *)(p+0x68) = *(s16 *)(p + 0x140) ? D_00471BB4[p[0x1B7] * 4] : -D_00471BB4[p[0x1B7] * 4];
    *(f32 *)(p+0x60) = D_00471BB8[p[0x1B7] * 4];
    *(f32 *)(p+0x6C) = D_00471BBC[p[0x1B7] * 4];
    *D_004C29C8 = *(u16 *)(*(u8 **)(p+0x18)+0x168);
    func_001757E0(p, 0x17, 0);
}
