#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G151c;
extern G151c *D_004C2794;
extern s16 D_004C27A4;
typedef struct { u8 pad[0x34]; f32 f34; } P34;

void residual_00375EC0(u8 *p)
{
    extern void func_00375E10(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003760B0(u8 *);
    P34 *sa = (P34 *)p;
    p[4]++;
    if (D_004C27A4 < 3) {
        p[4] = 2;
        return;
    }
    func_00375E10(p, 2);
    func_00375E10(p, 1);
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
    p[0x1B5] = 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[2] ^= 1;
    p[0x1B0] = 0x66;
    p[0x1B1] = 6;
    *(s16 *)(p + 0x1C) = 0x78;
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    if (*(s16 *)(p + 0x140) != 0) {
        sa->f34 += 141.66665649414062f;
    } else {
        sa->f34 -= 141.66665649414062f;
    }
    p[0x24] = 0;
    func_001757E0(p, 0x17, 0);
    func_003760B0(p);
}
