#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern s32 func_001754A0(u8 *, s32, s32);
extern s32 func_00175670(u8 *);
typedef struct Object Object;
extern void func_003DAA40(Object *);

void func_0019D050(u8 *p, u8 *q)
{
    s16 direction;

    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (p[4] == 0) {
        p[4]++;
        *(ActorState *)(p + 0xEC) = *(ActorState *)(*(u8 **)(q + 0x1DC) + 0xEC);
        p[0x13C] = 1;
        p[2] = (*(u8 **)(q + 0x1DC))[2];
        p[1] = (*(u8 **)(q + 0x1DC))[1];
        *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(q + 0x1DC) + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(q + 0x1DC) + 0x54);
        p[0x1B7] = (*(u8 **)(q + 0x1DC))[0x1B7];
        p[0x1B8] = (*(u8 **)(q + 0x1DC))[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(q + 0x1DC) + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(q + 0x1DC) + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(q + 0x1DC) + 0x24);
        *(s8 *)(p + 0x31) = -1;
        func_001754A0(p, 0x1B, (u8)(p[0x20] - 1));
        *(s16 *)(p + 0x1C) = 0x12C;
        p[0x13C] = 0;
        direction = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = direction;
        if (direction == 0)
            return;
        *(s32 *)(p + 0xD0) = -*(s32 *)(p + 0xD0);
        return;
    }
    if (p[5] == 0) {
        if (q[0x23E] != 0) {
            func_003DAA40((Object *)p);
            return;
        }
        if (q[5] == 3) goto d050_state_7;
    if (q[5] != 2) goto d050_transition;
d050_state_7:
            p[0x13C] = 1;
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34)
                + 1.6666666269302368f * (f32)*(s32 *)(p + 0xD0);
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38)
                + 2.142857074737549f * (f32)*(s32 *)(p + 0xD4);
            func_00175670(p);
            return;

d050_transition:
        p[5] = p[5] + 1;
        func_001754A0(p, 0x1B, 4);
        return;
    }
    if ((s8)func_00175670(p) < 0)
        func_003DAA40((Object *)p);
}
