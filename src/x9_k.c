typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern char D_00454A90[];

s32 func_00273840(u8 *p) {
    extern s32 func_00189310();
    extern s32 func_00273C20();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_00454A90, p + 0x380) == 0) {
        return 0;
    }
    if (func_00273C20(p) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x2E4) != 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x2D8) != 0) {
        return 0;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x1D);
    *(s32 *)(p + 0x2D8) = 1;
    p[0x205] = 2;
    *(s32 *)(p + 0x2E8) = 0;
    return 1;
}
