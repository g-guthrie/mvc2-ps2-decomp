/* try30.sh "-O3 -Op -sdatathreshold 8" */
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

typedef struct { u8 pad[0x5C]; u32 w5c; } Sw;
void residual_003979E0(u8 *p)
{
    extern void func_001757E0();
    u8 *d, *q;
    f32 c, k;
    Sx *P = (Sx *)p;
    Sw *W = (Sw *)p;
    d = p + 0xD0;
    p[5]++;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(*(u8 **)(p + 0x18) + 0xEC);
    q = p + 2;
    p[0x13C] = 1;
    c = 139.28570556640625f;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    d[2] = 2;
    d[3] = 8;
    p[0x24] = 0;
    P->f34 = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    P->f38 = c + *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140) != 0) {
        k = -123.33332824707031f;
        P->f34 -= k;
        W->w5c = 0x40200000;
    } else {
        k = 123.33332824707031f;
        P->f34 -= k;
        W->w5c = 0xC0200000;
    }
    *(s16 *)(p + 0x1C) = 0x3C;
    p[0x1B5] = 0x3F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->h7c[x]; D_004C2794->h7c[x] = y + 1; }
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    func_001757E0(p, 0x17, 3);
}
