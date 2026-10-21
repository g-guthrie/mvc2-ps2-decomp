typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern void func_003850A0(u8 *);

#pragma padloop on
void func_00384FC0(u8 *p)
{
    u32 count = p[4];
    count += 1;
    p[4] = count;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x13C] = 0;
    *(s16 *)(p + 0x1C) = 10;
    *(s16 *)(p + 0x1E) = 16;
    func_003850A0(p);
}
