/* func_00174F60, func_00179170: MW 3.0 (MWCCPS2_30) "-O3 -Op -fp off -sdatathreshold 8", compiled after src/e080_a.c (func_0016E080) in the same mwccps2 invocation (soft-float warm rule). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00632480[];

s32 func_00174F60(u8 *p)
{
    extern void func_003DD260(f32 *);
    extern void func_003DF850(s32, f32 *);
    extern void func_003DE680(f32 *, f32 *);
    extern f32 func_003DE770(f32);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern void func_003DDAD0(f32 *, f32, f32, f32);
    extern void func_003DDB20(f32 *, f32, f32, f32);
    extern void func_003DDC30(f32 *, f32);
    extern void func_003DDD00(f32 *, f32);
    extern void func_00413DF0(u8 *, s32, s32, u32);
    s16 ny;
    double d;
    f32 m[16];
    f32 out[4];
    f32 v[4];
    f32 a;
    f32 fx;
    f32 fy;
    s16 x0;
    s16 y0;
    s16 nx;
    s16 t1;
    s16 t2;
    s32 rot;
    f32 *mp;
    s32 i;
    s32 idx;
    s32 lvl;
    u32 fl;

    if (*(s32 *)(p + 0x154) == -1) {
        return 0;
    }
    func_003DD260(m);
    mp = m;
    func_003DF850(0x19, mp);
    v[0] = 0;
    v[1] = 0;
    v[2] = -*(f32 *)(p + 0xF8);
    x0 = 0;
    y0 = 0;
    func_003DE680(out, v);
    *(f32 *)(p + 0xF8) = out[2];
    a = 255.0f * *(f32 *)(p + 0x118);
    if (a > 255.0f) {
        a = 255.0f;
    }
    if (*(s32 *)(p + 0x114) == 0) {
        fx = (s32)(func_003DE770(*(f32 *)(p + 0xF0)));
        fy = (s32)(func_003DE770(*(f32 *)(p + 0xF4)));
        nx = 0;
        ny = 0;
    } else {
        if (*(s32 *)(p + 0x120) == 0) {
            x0 = *(s16 *)(p + 0x144);
        } else {
            x0 = -*(s16 *)(p + 0x144);
        }
        y0 = *(s16 *)(p + 0x146);
        fx = x0 * *(f32 *)(p + 0xFC) + (s32)(func_003DE770(*(f32 *)(p + 0xF0)));
        fy = y0 * *(f32 *)(p + 0x100) + (s32)(func_003DE770(*(f32 *)(p + 0xF4)));
        nx = -x0;
        ny = -y0;
    }
    if (*(u32 *)(p + 0x154) & 0x8000) {
        if (*(s32 *)(p + 0x120) == 0) {
            rot = *(s32 *)(p + 0x114);
        } else {
            rot = -*(s32 *)(p + 0x114);
        }
        t1 = (s32)(nx * *(f32 *)(p + 0xFC));
        t2 = (s32)(ny * *(f32 *)(p + 0x100));
    } else {
        if (*(s32 *)(p + 0x120) == 0) {
            rot = *(s32 *)(p + 0x114);
            nx = nx - x0;
            ny = ny - y0;
        } else {
            nx = nx - x0;
            ny = ny - y0;
            rot = -*(s32 *)(p + 0x114);
        }
        t1 = (s32)(*(f32 *)(p + 0xFC) * (nx + x0));
        t2 = (s32)(*(f32 *)(p + 0x100) * (ny + y0));
    }
    if (rot == 0) {
        fx += t1;
        fy += t2;
    } else {
        fx += t1 * func_00417500(rot);
        fx += t2 * func_00417440(rot);
        fy -= t1 * func_00417440(rot);
        fy += t2 * func_00417500(rot);
    }
    func_003DDAD0(m, fx, fy, *(f32 *)(p + 0xF8));
    func_003DDB20(m, *(f32 *)(p + 0xFC), *(f32 *)(p + 0x100), 1.0f);
    if (*(s32 *)(p + 0x120) != 0) {
        func_003DDC30(m, 3.1415927f);
        if (*(s32 *)(p + 0x114) != 0) {
            d = (s32)(u16)*(s32 *)(p + 0x114);
            d = 6.283185307179586 * d / 65536.0;
            func_003DDD00(m, (f32)d);
        }
    } else {
        if (*(s32 *)(p + 0x114) != 0) {
            d = (s32)(u16)*(s32 *)(p + 0x114);
            d = 6.283185307179586 * d / 65536.0;
            func_003DDD00(m, (f32)-d);
        }
    }
    idx = p[0x170];
    func_003DF850(0x19, mp);
    lvl = 0;
    if (*(s8 *)(p + 0x13D) == 1) {
        lvl = *(s16 *)(p + 0x13E);
    }
    fl = *(u32 *)(p + 0x154);
    if (fl & 0x8000) {
        func_00413DF0(D_00632480 + (u8)idx * 20, fl & 0x1FF, lvl, ((u8)(u32)a << 24) | 0xFFFFFF);
        return 0x14;
    } else {
        func_00413DF0(D_00632480 + (u8)idx * 20, fl & 0x7FFF, lvl, ((u8)(u32)a << 24) | 0xFFFFFF);
        return 0x14;
    }
}
typedef struct {
    s16 h0;
    s16 h2;
    u8 b4;
    u8 b5;
    s8 b6;
    u8 b7;
} E179;
typedef struct { u8 p0[0x34]; f32 f34; u8 p38[0x108]; s16 h140; } BB;

void func_00179170(u8 *a, u8 *b, s32 flag)
{
    extern void func_001823C0(), func_001757E0(), func_00178EB0();
    E179 *e;
    s8 *s1 = (s8 *)(a + 0x160);
    u8 *base;
    s32 t;
    f32 fa;

    base = *(u8 **)(a + 0x188);
    e = (E179 *)(base + (b[1] << 10)); e += s1[0];
    if (*(s16 *)(b + 0x140) != 0) {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 1.6666666269302368f * (f32)e->h0;
    } else {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + 1.6666666269302368f * (f32)e->h0;
    }
    if (flag != 0) {
        func_001823C0(a);
        if (*(s8 *)(a + 0x211) != 0) {

            *(f32 *)(b + 0x34) = *(f32 *)(a + 0x34);
            if (*(s16 *)(b + 0x140) != 0) {
                ((BB *)b)->f34 += 1.6666666269302368f * (f32)e->h0;
            } else {
                ((BB *)b)->f34 -= 1.6666666269302368f * (f32)e->h0;
            }
        }
    }
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) - 2.142857074737549f * (f32)e->h2;
    b[0x168] = e->b4;

    *(s16 *)(b + 0x140) = *(s16 *)(a + 0x140) ^ (s16)(e->b5 & 1);
    if (e->b6 > 0) {
        s8 v1 = a[0x24];
        s8 v0 = b[0x24];
        if (v0 < v1) {
            b[0x24] = v1;
            a[0x24] = v0;
        }
    } else {
        s8 v1 = a[0x24];
        s8 v0 = b[0x24];
        if (v1 < v0) {
            b[0x24] = v1;
            a[0x24] = v0;
        }
    }
    fa = (f32)(e->b7 << 8);
    *(s32 *)(b + 0x48) = (s32)((f32)*(s32 *)(a + 0x48) + fa);
    if (s1[0] != *(s8 *)(b + 0x16A)) {
        func_001757E0(b, 0x10, b[0x168]);
        b[0x16A] = a[0x160];
    }
    func_00178EB0(b);
}
