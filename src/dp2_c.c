typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0035B1A0(u8 *a, u8 *b) {
    extern f32 func_00417440(s32);
    extern f32 func_00417500(s32);
    extern s32 func_003CE510(s32, s32);
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_0035B160(u8 *, u8 *);
    u8 *s2;
    u8 *p88;
    u8 *s3;
    s16 x, y;
    s16 s5;
    s32 s6;
    s32 t;
    f32 r440, r500, fa, fb, fc, fd, fe;

    s2 = *(u8 **)(a + 0x18);
    p88 = *(u8 **)(b + 0x88);
    if (*(u16 *)(s2 + 0x160) == 0) {
        a[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p88 + 5) == 0) {
        a[0x13C] = 0;
        return;
    }
    if (a[0x21] != 0) {
        s3 = p88 + 0xC;
    } else {
        s3 = p88 + 8;
    }
    *(s8 *)(a + 0x31) = *(s8 *)(s3 + 2);
    *(f32 *)(a + 0x34) = *(f32 *)(s2 + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(s2 + 0x38);
    *(s16 *)(a + 0x140) = *(s16 *)(s2 + 0x140);
    *(s32 *)(a + 0x48) = *(s32 *)(s2 + 0x48);
    x = (s8)s3[0] + *(s16 *)p88;
    y = (s8)s3[1] + *(s16 *)(p88 + 2);
    if (*(s16 *)(a + 0x140) != 0) {
        x = (x ^ 0xFFFF) + 1;
    }
    s5 = *(s16 *)(s2 + 0x4C);
    s6 = (s16)(s32)(2.142857074737549f * (f32)(-y));
    fa = (f32)(s6 + (*(s16 *)(s2 + 0x4E) << 1));
    r440 = func_00417440(*(s32 *)(a + 0x48));
    fb = fa * r440;
    r500 = func_00417500(*(s32 *)(a + 0x48));
    x = (s32)(1.6666666269302368f * (f32)x);
    fa = (f32)(x + s5);
    fa *= r500;
    fa += fb;
    s5 = (s32)(fa - (f32)s5);
    r440 = func_00417440(*(s32 *)(a + 0x48));
    fe = (f32)(-(x + *(s16 *)(s2 + 0x4C)));
    fa = fe * r440;
    r500 = func_00417500(*(s32 *)(a + 0x48));
    t = *(s16 *)(s2 + 0x4E) << 1;
    fd = (f32)(s6 + t);
    fb = fd * r500;
    fc = fa + fb;
    y = (s32)(fc - (f32)t); fa = (f32)s5;
    *(f32 *)(a + 0x34) += fa;
    *(f32 *)(a + 0x38) += (f32)y;
    if (func_003CE510(0, 9) != 0) {
        a[0x13C] = 0;
    } else {
        a[0x13C] = 1;
        a[0x169] = 0x1C;
        a[0x168] = 0;
        func_00175910(a, a[0x169], a[0x168], (s8)s3[3]);
    }
    func_0035B160(a, b);
}
