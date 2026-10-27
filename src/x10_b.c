typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x36]; s8 f36[8]; s8 f3e; u8 pad1[0x7C - 0x3F]; s16 f7c[1]; } G4;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b; } V2;

#include "actor_inherited_state.h"
typedef ActorState B49;


extern G4 *D_004C2794;
extern u8 D_004C2A1C;
extern f32 D_004743E0[];
extern f32 D_004743E4[];
extern f32 D_00474420[];
extern f32 D_00474424[];
extern u8 D_0044FEC0[];
extern void (*D_004C0DF8[8])(u8 *);
extern u32 D_004C2838;
extern u32 D_004BF440[8];
extern V3 D_00444EF0[];
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001982F0(u8 *p, u8 *q)
{
    extern s32 func_001754A0(u8 *, s32, s32);
    u8 *t = *(u8 **)(p + 0x14);
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
    *(s16 *)(p + 0x140) = *(s16 *)(t + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(t + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(t + 0x38);
    func_001754A0(p, 0x1B, 2);
}

s32 func_001FC5C0(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    if (func_00189310(p, D_0044FEC0, p + 0x3B8) == 0)
        return 0;
    if (*(s8 *)(*(u8 **)(p + 0x420)) == 0)
        return 0;
    if (p[0x20D] == 2) {
        if (*(s8 *)(p + 0x1E8) != 0) {
            if (p[0x210] == 0)
                return 0;
        }
        *(s8 *)(p + 0x1E8) = 1;
        p[0x20] = 1;
    } else {
        p[0x20] = 0;
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x1D);
    return 1;
}
