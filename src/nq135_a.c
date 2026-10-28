#pragma padloop on
/* flags: -O3 -Op -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"
typedef struct { u8 pad0[0x7C]; s16 h7c[2]; } G2b;
extern G2b *D_004C2794;
typedef struct { u8 pad[0x34]; f32 f34, f38; } Sx;

void func_0039DE90(u8 *p)
{
    extern void func_001757E0();
    f32 c, k;
    Sx *P = (Sx *)p;
    u8 *d;
    p[4]++;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    c = 222.8571319580078f;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x1B5] = 0x47;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->h7c[x]; D_004C2794->h7c[x] = y + 1; }
    P->f34 = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    P->f38 = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    P->f38 += c;
    p[0x1B0] = 0x44;
    d = p + 0x88;
    if ((*(u8 **)(p + 0x18))[0x1E6] != 0) {
        *(u32 *)(d + 0x14) = 0xFFE80000;
        k = -40.0f;
        *(f32 *)(p + 0x5C) = k;
        P->f34 += k;
        *(u32 *)(p + 0x5C) = 0x3F555555;
    } else {
        *(u32 *)(d + 0x14) = 0x00180000;
        k = 40.0f;
        *(f32 *)(p + 0x5C) = k;
        P->f34 += k;
        *(u32 *)(p + 0x5C) = 0xBF555555;
    }
    *(u32 *)(p + 0x60) = 0x41CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    func_001757E0(p, 0x16, 2);
}
