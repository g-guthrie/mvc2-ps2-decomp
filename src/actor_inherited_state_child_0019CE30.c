#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern void func_0019CDD0(u8 *);
extern void func_00175C00(u8 *, s32);
extern void *func_003DA750(void *, s32, s32);
typedef struct Object Object;
extern void func_003DAA40(Object *);
extern s32 func_00174170(void);
extern s8 *D_004C2840;

void func_0019CE30(u8 *p, u8 *q)
{
    u8 *o;

    p[0x13C] = 0;
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
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(q + 0x1DC) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(q + 0x1DC) + 0x38);
        *(s16 *)(p + 0x1E) = 10;
    } else {
        if (q[0x23E] != 0) {
            func_003DAA40((Object *)p);
        } else if (q[5] == 3 || q[5] == 2) {
            func_00175C00(*(u8 **)(p + 0x18), 7);
            if (*(s16 *)(p + 0x1E) != 0) {
                if ((o = func_003DA750(0, 3, 0)) != 0) {
                    *(void (**)(u8 *))(o + 0x10) = func_0019CDD0;
                    o[0x20] = (D_004C2840[0x1C] & 3) + 1;
                    o[0x21] = 0;
                    *(u8 **)(o + 0x18) = *(u8 **)(p + 0x18);
                    o[1] = (*(u8 **)(q + 0x1DC))[1];
                    *(s16 *)(o + 0x26) = 0x905;
                    *(s32 *)(o + 0xD0) = (func_00174170() & 0x3F) - 0x20;
                    *(s32 *)(o + 0xD4) = 0x40 - (func_00174170() & 0x3F);
                }
                *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
            }
        } else {
            func_00175C00(*(u8 **)(p + 0x18), 1);
            func_003DAA40((Object *)p);
        }
    }
}
