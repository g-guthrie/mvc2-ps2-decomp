/* MW 3.0.3 -O3 -Op -fp off -sdatathreshold 8, built after src/fr1_a.c (func_00413F50, nearest preceding double-arithmetic function). */
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

void func_004142F0(u8 *o) {
    extern s32 func_004148C0(f32, f32 *, f32 *, f32 *);
    extern void func_004149D0(f32, f32 *, f32 *, f32 *);
    extern s32 fptosi(f32);
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

    buf = D_004F8020;
    a[0] = 0.10000000149011612f * *(f32 *)(o + 0x0C);
    a[1] = 0.10000000149011612f * *(f32 *)(o + 0x10);
    a[2] = 0.10000000149011612f * *(f32 *)(o + 0x14);
    b[0] = 0.10000000149011612f * *(f32 *)(o + 0x54);
    b[1] = 0.10000000149011612f * (*(f32 *)(o + 0x58) - 240.0f * *(f32 *)(o + 0x80));
    b[2] = 0.10000000149011612f * *(f32 *)(o + 0x5C);
    c[0] = func_003DE790((f32)(6.283185307179586 * (s32)((u32)(s32)*(s32 *)(o + 0x84) & 0xFFFF) / 65536.0));
    c[1] = func_003DE710((f32)(6.283185307179586 * (s32)((u32)(s32)*(s32 *)(o + 0x84) & 0xFFFF) / 65536.0));
    c[2] = 0.0f;
    if (D_004C2B2C == 2) {
        if (func_004148C0(*(f32 *)(o + 0x6C), a, b, c) != 0) return;
    }
    D_004C2B2C = 2;
    func_004149D0(*(f32 *)(o + 0x6C), a, b, c);
    { s32 *pb = (s32 *)&buf; pb[1] = fptosi((f32)buf.x[1] - 16.0f); }
    t = func_003DE7D0((f32)(3.141592653589793 * (*(f32 *)(o + 0x6C) / 2.0f / 180.0)));
    t = func_003DE6F0(240.0f / (320.0f / t));
    t = 2.0f * t;
    func_003DD2E0(0x20, 120000.0f, 0.10000000149011612f, t, 1.0f);
    func_003DF850(0x18, (u32)&buf);
    func_003DDF20(m, (f32 *)(u32)a, (f32 *)(u32)b, (f32 *)(u32)c);
    func_003DF850(0x16, (u32)m);
}
