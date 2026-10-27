typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct {
    s16 vx;
    s16 vy;
    u8 d0;
    s8 st;
    u8 arg;
    u8 pad;
} T70;

extern T70 D_00464A70[];
extern int func_001757E0(u8 *, s32, s32);
extern void func_00388A80(u8 *);


#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on
void func_00388930(u8 *p)
{
    u8 *q;
    s16 code;
    u32 t;

    code = 0x1C07;
    q = *(u8 **)(p + 0x18);
    t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x26) = code;
    *(Payload *)(p + 0xEC) = *(Payload *)(q + 0xEC);
    p[0x13C] = 1;
    {
        T70 *tbl;
        f32 a;
        f32 b;
        tbl = D_00464A70;
        a = 1.6666666269302368f;
        p[2] = q[2];
        b = 2.142857074737549f;
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(s16 *)(p + 0x1C) = 0;
        tbl = (T70 *)((u8 *)tbl + p[0x20] * 8);
        *(f32 *)(p + 0x5C) = a * (f32)tbl->vx;
        *(f32 *)(p + 0x60) = b * (f32)tbl->vy;
        *(u32 *)(p + 0xD0) = tbl->d0;
        *(s8 *)(p + 0x31) = tbl->st;
        func_001757E0(p, 0x16, tbl->arg);
        func_00388A80(p);
    }
}
