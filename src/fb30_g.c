typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b, c, d; } E83;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad38[0x140 - 0x38]; s16 s140; u8 pad142[0x180 - 0x142]; E83 *tab; u8 pad184[0x1D4 - 0x184]; u16 *in; } O83;
typedef struct { u8 pad0[0x34]; f32 f34; u8 pad38[0x220 - 0x38]; O83 *o; u8 pad224[0x2AC - 0x224]; f32 f2AC; } P83;

void func_00183E30(P83 *p) {
    O83 *o; s32 dir; u16 *in; E83 *e, *t;
    f32 x3, x2, x1, x0, f6, f7, f8, f0;
    o = p->o;
    in = o->in;
    if (in[2] == 0 && in[3] == 0 && in[4] == 0 && (in[5] & 0x1FFF) == 0) {
        *(s32 *)&p->f2AC = 0;
        return;
    }
    f7 = p->f34;
    f6 = o->f34;
    dir = 0;
    x0 = x1 = x2 = x3 = -1.0f;
    if ((!(f7 <= f6) && o->s140 == 0) || (f7 <= f6 && o->s140 != 0)) {
        x0 = x1 = x2 = x3 = 0.0f;
        dir = -1;
    }
    if (in[2] != 0) {
        t = o->tab; e = t + in[2];
        f8 = 1.6666666269302368f;
        x0 = f8 * (f32)e->a;
        f0 = f8 * (f32)e->b;
        if (dir != 0) f0 = -f0;
        x0 -= f0;
    }
    if (in[3] != 0) {
        t = o->tab; e = t + in[3];
        f8 = 1.6666666269302368f;
        x1 = f8 * (f32)e->a;
        f0 = f8 * (f32)e->b;
        if (dir != 0) f0 = -f0;
        x1 -= f0;
    }
    if (in[4] != 0) {
        t = o->tab; e = t + in[4];
        f8 = 1.6666666269302368f;
        x2 = f8 * (f32)e->a;
        f0 = f8 * (f32)e->b;
        if (dir != 0) f0 = -f0;
        x2 -= f0;
    }
    if ((s16)in[5] > 0) {
        t = o->tab; e = t + (in[5] & 0x1FFF);
        f8 = 1.6666666269302368f;
        x3 = f8 * (f32)e->a;
        f0 = f8 * (f32)e->b;
        if (dir != 0) f0 = -f0;
        x3 -= f0;
    }
    if (dir == 0) {
        if (!(x0 < x1)) x0 = x1;
        if (!(x0 < x2)) x0 = x2;
        if (!(x0 < x3)) x0 = x3;
    } else {
        if (x0 <= x1) x0 = x1;
        if (x0 <= x2) x0 = x2;
        if (x0 <= x3) x0 = x3;
    }
    if (o->s140 != 0) x0 = -x0;
    x0 += f6;
    if (f7 < f6) f0 = x0 - f7;
    else f0 = f7 - x0;
    p->f2AC = f0;
}
