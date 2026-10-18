typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_00164180(u8 *p, s32 x) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern s32 func_0016A3F0();
    extern void func_00186CE0();
    extern s32 func_001642A0();
    s32 r;
    s32 t;
    u32 u;
    if (func_0016B240(p, 0) == 0) return 0;
    func_0016B0C0(p, x, 0);
    func_0016B0C0(p, x, 3);
    if ((r = func_0016A3F0(p)) != 0) return 0;
    *(float *)(p + 0x460) = *(float *)(p + 0x4C8);
    *(float *)(p + 0x464) = *(float *)(p + 0x34);
    *(float *)(p + 0x38) = *(float *)(p + 0x430);
    p[0x1E7] = 1;
    t = *(s8 *)(p + 0x211);
    if (t != 0 && ((s8)t & (1 << p[0x1E6])) != 0) return 0;
    u = p[0x451];
    p[0x451] = u + 1;
    *(s32 *)(p + 0x468) = 1;
    *(s32 *)(p + 0x46C) = ((p[0x1E6] * 3) << 10) ^ 0x400;
    *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x46C);
    *(s16 *)(p + 0x35E) = 0x400;
    func_00186CE0(p, 1);
    *(s16 *)(p + 0x35E) = 0;
    return func_001642A0(p, x);
}
