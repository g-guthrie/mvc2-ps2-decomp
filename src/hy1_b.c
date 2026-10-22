typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_0016AA00(u8 *a, u8 *b, s32 c, s32 d) {
    extern f32 func_0016ABA0(u8 *, u8 *, s32);
    u8 *s0, *s1;
    f32 f20, f1;
    s32 t;
    if (d == 0) return 0;
    {
        s0 = *(u8 **)(a + 0x180);
        s1 = *(u8 **)(b + 0x180);
        s0 += c * 8;
        s1 += d * 8;
        f20 = func_0016ABA0(a, s0, 0);
        f1 = f20 - func_0016ABA0(b, s1, 0);
        if (f1 < 0) f1 = -f1;
        t = *(s16 *)(s1 + 2);
        if (t == 0) return 0;
        if (f1 > 1.6666666269302368f * (f32)((s16)t + *(s16 *)(s0 + 2))) return 0;
        f20 = func_0016ABA0(a, s0, 1);
        f1 = f20 - func_0016ABA0(b, s1, 1);
        if (f1 < 0) f1 = -f1;
        t = *(s16 *)(s1 + 6);
        if (t == 0) return 0;
        return !(f1 > 1.6666666269302368f * (f32)((s16)t + *(s16 *)(s0 + 6)));
    }
}
