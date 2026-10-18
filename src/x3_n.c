typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00457CC0[];

s32 func_00295420(u8 *p) {
    extern s32 func_00189310();
    extern s32 func_0018AA10();
    extern void func_0018A990();
    extern void func_0011D8F8();
    extern void func_00186A60();
    s16 loc;
    if (func_00189310(p, D_00457CC0, p + 0x3B0) == 0) return 0;
    if (func_0018AA10(p, 0x300, &loc) == 0) {
        if (func_0018AA10(p, 0x60, &loc) == 0) return 0;
    }
    func_0018A990(p, p + 0x3B0);
    func_0011D8F8(p + 0x3A0, 0, 8);
    func_0011D8F8(p + 0x3C8, 0, 8);
    func_0011D8F8(p + 0x3E0, 0, 8);
    p[0x1FD] = 7;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
