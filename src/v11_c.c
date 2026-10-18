typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004598B0[];

s32 func_002C0040(u8 *p) {
    extern s32 func_00189310();
    extern void func_00186A60();
    extern void func_0011D8F8();
    if (func_00189310(p, D_004598B0, p + 0x3A8) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 v = *(s8 *)(p + 0x1E8);
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    p[0x1B7] = 2;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    func_0011D8F8(p + 0x3B8, 0, 8);
    func_0011D8F8(p + 0x3C0, 0, 8);
    return 1;
}
