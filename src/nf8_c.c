typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern s32 func_001754A0(u8 *, s32, s32);

void func_001BC210(u8 *p, u8 *q)
{
    f32 off, add, v;
    p[4] = 1;
    p[0x13C] = 1;
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
    p[0x24] = 7;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(s16 *)(p + 0x1C) = 0x1E;
    switch (p[0x23]) {
    case 3:
        if (*(s16 *)(p + 0x140) != 0) off = 65.0f; else off = -65.0f;
        add = 248.0f;
        *(f32 *)(p + 0x34) += off;
        *(f32 *)(p + 0x38) += add;
        break;
    case 4:
        if (*(s16 *)(p + 0x140) != 0) off = 13.0f; else off = -13.0f;
        add = 258.0f;
        *(f32 *)(p + 0x34) += off;
        *(f32 *)(p + 0x38) += add;
        break;
    case 5:
        if (*(s16 *)(p + 0x140) != 0) off = -13.0f; else off = 13.0f;
        add = 275.0f;
        *(f32 *)(p + 0x34) += off;
        *(f32 *)(p + 0x38) += add;
        break;
    case 6:
        if (*(s16 *)(p + 0x140) != 0) off = 65.0f; else off = -65.0f;
        add = 248.0f;
        *(f32 *)(p + 0x34) += off;
        *(f32 *)(p + 0x38) += add;
        *(f32 *)(p + 0x118) = 0.699999988079071f;
        break;
    }
    if (*(s16 *)(p + 0x140) != 0) v = -20.0f; else v = 20.0f;
    *(f32 *)(p + 0x5C) = v;
    if (*(s16 *)(p + 0x140) != 0) v = 0.20000000298023224f; else v = -0.20000000298023224f;
    *(f32 *)(p + 0x68) = v;
    *(f32 *)(p + 0x60) = 10.0f;
    *(f32 *)(p + 0x6C) = -1.0f;
    *(s32 *)(p + 0xD4) = 0x78;
    if (p[0x23] == 6)
        *(f32 *)(p + 0x118) = 0.4000000059604645f;
    func_001754A0(p, 0x1B, 0xA);
}
