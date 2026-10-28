/* sLa2_a: MW 3.0 (./try30.sh src/sLa2_a.c "-O3 -Op -sdatathreshold 8").
 * residual_003A8EF0: opt_lifetimes off + a/b written as 'a = e->x; a = d4 + a;' fixes the addu operand order. */
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

#pragma push
#pragma opt_lifetimes off
void residual_003A8EF0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174170(void);
    extern void func_003A91C0(u8 *);
    u8 *q;
    u8 *team;
    E8 *e;
    s16 b;
    s16 a;
    s32 k;
    u32 t;

    t = p[4];
    q = *(u8 **)(p + 0x18);
    p[4] = t + 1;
    *(s16 *)(p + 0x1C) = 5;
    *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
    p[0x13C] = 1;
    team = p + 2;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = *(s8 *)(p + 0x20) & 1;
    *(s8 *)(p + 0x24) = 8;
    p[0x22] = *(s16 *)(p + 0x140) = p[0x20] >> 1;
    *(s16 *)(p + 0x140) &= 1;
    k = 0x10;
    if (*(s16 *)(q + 0x140) != 0) k = -0x10;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)k;
    *(f32 *)(p + 0x38) = 291.4285583496094f + *(f32 *)(q + 0x38);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    { s16 v = D_00473090[func_00174170() & 0xF]; p[0x1B5] = v; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[team[0]]++;
    e = &D_00473040[*(s32 *)(p + 0xDC)];
    a = e->x; a = *(s16 *)(p + 0xD4) + a;
    b = e->y; b = *(s16 *)(p + 0xD8) + b;
    if (e->f != 0) *(s16 *)(p + 0x140) ^= 1;
    func_001757E0(p, 0x15, (u8)(e->an + ((p[0x22] & 2) << 2)));
    if (p[0x22] & 1) a = -a;
    if (p[0x22] & 2) {
        b = -b;
        *(s16 *)(p + 0x140) ^= 1;
    }
    *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)a;
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)b;
    func_003A91C0(p);
}
#pragma pop
