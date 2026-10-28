typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

#include "actor_inherited_state.h"

typedef struct { float x, y, z; } V3C;
typedef struct { u8 pad[0x7C]; s16 t[0x40]; } GC;
extern GC *D_004C2794;
extern u8 D_004C20C8[8];
extern void (*D_00475B90[])(u8 *, u8 *);

void func_003BF080(u8 *p, u8 *q)
{
    u8 *b;
    { u32 t4 = p[4]; p[4] = t4 + 1; }
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    b = p + 2;
    p[0x13C] = 1;
    *b = q[2];
    p[1] = q[1];
    *(float *)(p + 0x50) = *(float *)(q + 0x50);
    *(float *)(p + 0x54) = *(float *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    p[0x30] = *(s8 *)(q + 0x30);
    *(V3C *)(p + 0x50) = *(V3C *)(q + 0x50);
    p[0x24] = *(s8 *)(q + 0x24);
    *(s32 *)(p + 0xD0) = *(float *)(*(u8 **)(q + 0x18) + 0x430);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = D_004C20C8[p[0x21] * 2];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { u32 i = *b; s16 v = D_004C2794->t[i] + 1; D_004C2794->t[i] = v; }
    D_00475B90[p[0x20]](p, q);
}
