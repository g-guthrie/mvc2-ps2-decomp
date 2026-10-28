/* func_00414720: MW 3.0.3 -O3 -Op -sdatathreshold 8. opt_propagation/opt_common_subs off keep
   120000.0f/0.1f live in f21/f20 across func_003DE7D0 and the two 0.0f args rematerialised. */
#pragma opt_propagation off
#pragma opt_common_subs off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[6]; } S24;
extern S24 D_004F8020;
extern s32 D_004C2B2C;

void func_00414720(u8 *o) {
    extern s32 func_004148C0(f32, f32 *, f32 *, f32 *);
    extern void func_004149D0(f32, f32 *, f32 *, f32 *);
    extern f32 func_003DE790(f32);
    extern f32 func_003DE710(f32);
    extern f32 func_003DE7D0(f32);
    extern f32 func_003DE6F0(f32);
    extern void func_003DD2E0(s32, f32, f32, f32, f32);
    extern void func_003DF850(s32, u32);
    extern void func_003DDF20(f32 *, f32 *, f32 *, f32 *);
    f32 m[16];
    S24 buf;
    f32 a[4], b[4], c[4];
    f32 t;
    f32 k2, k1;

    buf = D_004F8020;
    a[0] = *(f32 *)(o + 0xC); a[1] = *(f32 *)(o + 0x10); a[2] = *(f32 *)(o + 0x14);
    b[0] = *(f32 *)(o + 0x54); b[1] = *(f32 *)(o + 0x58); b[2] = *(f32 *)(o + 0x5C);
    c[0] = func_003DE790(0.0f); c[1] = func_003DE710(0.0f); *(s32 *)&c[2] = 0;
    if (D_004C2B2C == 4) {
        if (func_004148C0(*(f32 *)(o + 0x6C), a, b, c) != 0) return;
    }
    D_004C2B2C = 4;
    func_004149D0(*(f32 *)(o + 0x6C), a, b, c);
    buf.x[1] = -0x10;
    buf.x[3] = 0x1E0;
    k1 = 120000.0f;
    k2 = 0.10000000149011612f;
    t = func_003DE7D0(0.3752457797527313f);
    t = func_003DE6F0(240.0f / (320.0f / t));
    t = 2.0f * t;
    func_003DD2E0(0x20, k1, k2, t, 1.0f);
    func_003DF850(0x18, (u32)&buf);
    func_003DDF20(m, a, b, c);
    func_003DF850(0x16, (u32)m);
}
