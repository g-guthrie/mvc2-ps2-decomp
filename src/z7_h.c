typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G4;
typedef struct { f32 x, y, z; } V3;

#include "actor_inherited_state.h"
typedef ActorState B49;


extern G4 *D_004C2794;

void func_003A2AE0(u8 *p, u8 *q) {
    u32 t = p[4];
    p[4] = t + 1;
    if (p[6] == 0) {
        *(B49 *)(p + 0xEC) = *(B49 *)(q + 0xEC);
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
    }
    p[0x1B1] = p[0x1B0] = 0x42;
    p[0x14C] = p[0x14D] = 0x16;
    p[0x14E] = p[0x14F] = 0x1E;
    p[0x1B4] = 0;
    p[0x13C] = 0;
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}
