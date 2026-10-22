#include "runtime_state_types.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern const s32 D_004BEDC0[];

static s32 func_00416770(struct RuntimeOwner *owner, s32 scale)
{
    s32 factor = D_004BEDC0[owner->stateIndex];
    return (scale * factor) >> 3;
}

s32 func_004167A0(struct RuntimeOwner *p, s32 a1, s32 a2)
{
    s32 r = func_00416770(p, a1);
    return p->unk10 + r + a2 * p->unk0c;
}

typedef struct { u8 p[0x2C]; u32 f2c; } N13B2;
typedef struct { u8 p[0x18]; N13B2 *f18; } M13B2;
typedef struct { u8 p0[5]; u8 b5; u8 p6[0x12]; M13B2 *f18; u8 p1c[5]; u8 b21; u8 p22[0x11A]; s8 b13C; } P13B2;
void func_0013B620(P13B2 *p)
{
    extern void func_0013B6A0(P13B2 *);
    extern void func_0013B770(P13B2 *);
    u8 t = p->b5;
    switch (t) {
    case 0:
        p->b5 = t + 1;
    case 1:
        if (p->b21 != p->f18->f18->f2c) p->b13C = 0; else p->b13C = 1;
        func_0013B6A0(p);
        func_0013B770(p);
        break;
    default:
        break;
    }
}
