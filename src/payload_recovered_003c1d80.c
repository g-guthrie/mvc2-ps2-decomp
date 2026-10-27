typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern f32 D_004F1FC8;
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern s32 func_00174170(void);
extern int func_001757E0(u8 *, s32, s32);
extern void func_003C1F30(u8 *, u8 *);


#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void func_003C1D80(u8 *p, u8 *q)
{
    s16 r;
    u32 t = p[4];
    p[4] = t + 1;
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
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
    *(s8 *)(p + 0x31) = -1;
    r = (u8)func_00174170();
    r = r * 1.66666662693023681640625f;
    r += D_004F1FC8;
    r += 106.66666412353515625f;
    *(f32 *)(p + 0x34) = (f32)(s16)r;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if ((func_00174170() & 3) == 0) {
        D_004F1F45 = 1;
        D_004F1F46 = 1;
    }
    func_001757E0(p, 0x16, 4);
    func_003C1F30(p, q);
}
