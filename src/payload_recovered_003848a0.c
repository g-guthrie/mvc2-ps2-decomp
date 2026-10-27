typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C29AC __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, s32, s32);
extern void func_003849C0(u8 *);


#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void func_003848A0(u8 *p)
{
    u32 t;

    t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
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
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    p[0x24] = 0;
    *(u16 *)D_004C29AC = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    func_001757E0(p, 0x17, 8);
    func_003849C0(p);
}
