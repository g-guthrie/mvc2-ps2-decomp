typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

#include "actor_inherited_state.h"
typedef ActorState Payload;

#pragma padloop on

typedef struct { u8 prefix[0x7C]; s16 count[2]; } GameState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
extern f32 D_004F1FD4;
extern s32 func_00174170(void);
extern s32 func_00118FA8(f32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_003C2260(u8 *, u8 *);

void func_003C2010(u8 *p, u8 *q)
{
    f32 *fp = (f32 *)p;
    s16 *t1 = (s16 *)(p + 0xD0);
    p[4]++;
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
    {
    u8 *team = p + 2;
    p[0x13C] = 0;
    *(s8 *)(p + 0x31) = -1;
    p[0x1B0] = 3;
    p[0x1B1] = 0x42;
    if (p[0x21] == 0) {
        p[0x1B5] = 0x36;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[team[0]]++;
    } else {
        p[0x1B5] = 0x4A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->count[team[0]]++;
    }
    }
    *(u16 *)(p + 0x1C0) |= 0x40;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    {
        s32 r = (u8)func_00174170();
        *(f32 *)(p + 0x38) = D_004F1FD4 + 2.142857074737548828125f * (f32)((s16)r + 0x40);
    }
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) = D_004F1FCC;
        *t1 = (s16)func_00118FA8(D_004F1FC8);
    } else {
        *(f32 *)(p + 0x34) = D_004F1FC8;
        *t1 = (s16)func_00118FA8(D_004F1FCC);
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0xC1D55555;
    *(u32 *)(p + 0x60) = 0xC1092492;
    if (*(s16 *)(p + 0x140) != 0)
        fp[23] = -fp[23];
    func_001757E0(p, 0x16, 5);
    func_003C2260(p, q);
}
