typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


s32 func_00182E20(u8 *p) {
    extern s32 func_00182E80();
    s32 d = func_00182E80(p);
    s16 v = *(s16 *)(p + 0x270) - d;
    *(s16 *)(p + 0x270) = v;
    if (v > 0) return 0;
    ((s16 *)p)[0x138] = *(s16 *)(p + 0x272);
    return 1;
}

s32 func_002BFEB0(u8 *p) {
    extern u8 D_00459890[];
    extern s32 func_00189310();
    extern void func_00186A60();
    extern void func_0011D8F8();
    s32 t;
    if (func_00189310(p, D_00459890, p + 0x398) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    p[0x1B7] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    func_0011D8F8(p + 0x3B8, 0, 8);
    func_0011D8F8(p + 0x3C0, 0, 8);
    return 1;
}
