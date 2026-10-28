typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"
typedef ActorState Payload;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G116;
extern u8 *D_004C29A8 __attribute__((section(".sdata")));
extern u8 *D_004C29AC __attribute__((section(".sdata")));
extern G116 *D_004C2794 __attribute__((section(".sdata")));

#pragma padloop on
void residual_00384090(u8 *p)
{
    extern void func_00384410(u8 *);
    extern int func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u32 t;

    t = p[4];
    p[4] = t + 1;
    *(Payload *)(p + 0xEC) = *(Payload *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x24] = 0;
    D_004C29A8[1] = 1;
    *(u16 *)D_004C29AC = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    p[7] = 0;
    *(s16 *)(p + 0x1C) = 8;
    *(s16 *)(*(u8 **)(p + 0x18) + 0x1E) = 8;
    p[0x1B0] = 0x43;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    func_00384410(p);
    func_001757E0(p, 0x14, 2);
    func_001E7F60(p);
}
#pragma padloop on
