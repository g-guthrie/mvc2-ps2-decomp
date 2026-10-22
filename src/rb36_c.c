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

void func_004145A0(u8 *o) {
    extern s32 func_004148C0(f32, f32 *, f32 *, f32 *);
    extern void func_004149D0(f32, f32 *, f32 *, f32 *);
    extern s32 fptosi(f32);
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
    a[0] = 0.0f; a[1] = 0.0f; a[2] = 0.0f;
    b[0] = 0.0f; b[1] = 0.0f; b[2] = -1.0f;
    c[0] = 0.0f; c[1] = 1.0f; c[2] = 0.0f;
    if (D_004C2B2C == 3) {
        if (func_004148C0(*(f32 *)(o + 0x6C), a, b, c) != 0) return;
    }
    D_004C2B2C = 3;
    func_004149D0(*(f32 *)(o + 0x6C), a, b, c);
    { s32 *pb = (s32 *)&buf; pb[1] = fptosi((f32)buf.x[1] - 16.0f); }
    buf.x[3] = 0x1E0;
    t = func_003DE7D0(0.7853981852531433f);
    t = func_003DE6F0(240.0f / (320.0f / t));
    t = 2.0f * t;
    func_003DD2E0(0x20, 120000.0f, 0.10000000149011612f, t, 1.0f);
    func_003DF850(0x18, (u32)&buf);
    func_003DDF20(m, a, b, c);
    func_003DF850(0x16, (u32)m);
}
