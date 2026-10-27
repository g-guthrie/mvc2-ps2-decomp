#pragma padloop on
#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void (*D_00463C90[])(u8 *); /* 0x00463C90 */
extern void func_0036D7B0(u8 *);

void func_0036C190(u8 *p)
{
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(ActorState *)(p + 0xec) = *(ActorState *)(q + 0xec);
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
    D_00463C90[p[0x20]](p);
    func_0036D7B0(p);
}
