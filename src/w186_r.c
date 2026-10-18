typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18EC[];

s32 func_00164300(u8 *p, s32 k) {
    extern s32 func_0016B240();
    extern void func_0016B0C0();
    extern void func_00186CE0(u8 *, s32);
    extern s32 func_00164480();
    u8 *q;
    u32 u;
    f32 y, x, a, s;
    if (func_0016B240(p, 0) == 0) return 0;
    func_0016B0C0(p, k, 0);
    func_0016B0C0(p, k, 3);
    q = *(u8 **)(p + 0x220);
    u = q[0x14E];
    s = *(f32 *)(p + 0x4C8);
    *(f32 *)(p + 0x460) = s + 1.6666666269302368f * (f32)u;
    p[0x1E7] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    if (D_004D18EC[0] != 0) return 0;
    y = *(f32 *)(p + 0x460);
    if (q[0x1E6] == 0) y = -y;
    y += *(f32 *)(q + 0x34);
    x = *(f32 *)(p + 0x34);
    a = x;
    if (p[0x1E6] != 0) {
        a = y;
        y = x;
    }
    if (y > a) {
        return 0;
    } else {
        u32 t = p[0x451];
        p[0x451] = t + 1;
        *(s32 *)(p + 0x468) = 1;
        *(s32 *)(p + 0x46C) = (p[0x1E6] * 3 << 10) ^ 0x800;
        *(s16 *)(p + 0x4F0) = *(s16 *)(p + 0x46C);
        *(s16 *)(p + 0x35E) = 0x800;
        func_00186CE0(p, 1);
        *(s16 *)(p + 0x35E) = 0;
        return func_00164480(p, k);
    }
}
