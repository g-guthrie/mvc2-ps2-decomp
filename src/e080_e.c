/* func_001827B0: MW 3.0 (MWCCPS2_30) "-O3 -Op -fp off -sdatathreshold 0", compiled after src/e080_b.c (func_00174F60) in the same mwccps2 invocation (soft-float warm rule). */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern volatile f32 D_004F1F4C;
extern f32 D_004F1F40[];

void func_001827B0(u8 *p) {
    extern void func_00182BD0(u8 *);
    extern void func_00182AA0(u8 *, u8 *, f32 *);
    extern void func_00182970(u8 *, u8 *, f32 *);
    f32 *d;
    u8 *q;
    f32 x;
    f32 lim;
    f32 t;
    s32 a;
    u8 st;

    if (*(s16 *)(p + 0x434) == 0) return;
    st = p[0x1E4];
    if (st == 0x1C || st == 0x17) return;
    lim = 35.0f + (D_004F1F4C - 320.0f);
    d = D_004F1F40;
    q = *(u8 **)(p + 0x220);
    x = *(f32 *)(p + 0x34);
    a = (s32)x;
    if (a < (s32)lim) {
        t = 35.0f + (16.0f + d[0x98 / 4]);
        if (x < t) {
            *(f32 *)(p + 0x34) = t;
            return;
        }
        {
            func_00182BD0(p);
            func_00182AA0(p, q, d);
            return;
        }
    }
    if ((s32)((320.0f + d[0xC / 4]) - 35.0f) < a) {
        t = (d[0x9C / 4] - 16.0f) - 35.0f;
        if (!(x <= t)) {
            *(f32 *)(p + 0x34) = t;
            return;
        }
        {
            func_00182BD0(p);
            func_00182970(p, q, d);
            return;
        }
    }
    if (q[5] == 0) q[0x249] = 0;
}
