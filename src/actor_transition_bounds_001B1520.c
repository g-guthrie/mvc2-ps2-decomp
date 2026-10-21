#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct {u8 prefix[0x34]; f32 x;} ActorPosition;
extern f32 D_004F1FC8, D_004F1FCC;
extern int func_001754A0(u8 *, s32, s32);

void func_001B1520(u8 *p)
{
    u8 *q;
    ActorPosition *position = (ActorPosition *)p;
    u32 t = p[4];
    q = *(u8 **)(p + 0x18);
    p[4] = t + 1;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x24] = 9;
    position->x = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if ((*(u8 **)(p+0x18))[0x1B7] == 0)
        position->x += *(s16 *)(p+0x140) ? 186.666656494140625f : -186.666656494140625f;
    else
        position->x += *(s16 *)(p+0x140) ? 373.33331298828125f : -373.33331298828125f;
    if (*(s16 *)(p+0x140)) {
        f32 bound = D_004F1FCC;
        f32 x = position->x;
        if (bound < x)
            position->x = bound - 80.0f;
    } else {
        f32 bound = D_004F1FC8;
        f32 x = position->x;
        if (!(bound <= x))
            position->x = 80.0f + bound;
    }
    *(s16 *)(p+0x1C) = 40;
    func_001754A0(p, 0x1B, 4);
}
