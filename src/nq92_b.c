typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

#include "actor_inherited_state.h"

typedef struct { float x, y, z; } V3B;
typedef struct { u8 pad[0x7C]; s16 t[0x40]; } GB;
extern GB *D_004C2794;
extern u8 *D_004C29FC;

void residual_0039A670(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    { u32 t4 = p[4]; p[4] = t4 + 1; }
    *(ActorState *)(p + 0xEC) = *(ActorState *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(float *)(p + 0x50) = *(float *)(*(u8 **)(p + 0x18) + 0x50);
    *(float *)(p + 0x54) = *(float *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3B *)(p + 0x50) = *(V3B *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    p[0x24] = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x22] = 0x14;
    *(s16 *)(p + 0x1C) = 0x32;
    *(s16 *)(p + 0x1E) = 2;
    D_004C29FC[2] = 2;
    D_004C29FC[1] = 6;
    p[0x1B5] = 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { u32 i = p[2]; s16 v = D_004C2794->t[i] + 1; D_004C2794->t[i] = v; }
    func_001757E0(p, 0x17, 3);
}
