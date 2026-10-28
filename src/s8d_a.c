/* s8d_a: MW 3.0 (try30.sh) -O3 -Op -sdatathreshold 8: residual_003A8EF0, residual_003C96D0. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 pad[0x7C]; s16 f7c[2]; } G207c;
extern G207c *D_004C2794;
extern s16 D_00473090[];
typedef struct { s16 x, y, f, an; } E8;
extern E8 D_00473040[];


void residual_003C96D0(u8 *a, u8 *b)
{
    extern s8 func_00175700();
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_001E7F60(u8 *);
    f32 x;
    f32 y;
    u8 t;
    s8 c;
    s32 k;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    *(s8 *)(a + 0x31) = -8;
    if (func_00175700(a) >= 0) {
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        func_001E7F60(a);
        return;
    }
    { u32 u = a[5]; a[5] = u + 1; }
    a[0xD9] = 1;
    b[0x152] = 2;
    a[0x22] = 0;
    y = *(f32 *)(a + 0x60) = 342.85711669921875f;
    x = 13.333333015441895f;
    if (*(s16 *)(a + 0x140) != 0) x = -x;
    *(f32 *)(a + 0x5C) = x;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + x;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + y;
    func_00175910(a, 0x16, 3, 0);
    t = a[0x15B];
    c = t;
    if (c != 0) {
        if (t == 0x3C) {
            k = b[0x269];
            if (k > 3) {
                if (k < 6) c = 0x2F;
            }
        }
        a[0x1B5] = c;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
    }
    func_001E7F60(a);
}
