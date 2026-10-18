typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310();
extern u8 D_00459CC0[];

s32 func_002C5BA0(u8 *p) {
    if (func_00189310(p, D_00459CC0, p + 0x3B0) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        return 0;
    }
    if (p[0x215] != 0) {
        return 0;
    }
    p[0x26C] = 6;
    return 1;
}

extern u8 D_0045BA50[];
extern void func_00186A60();

extern u8 D_0044F2A0[];
extern void func_0018A990();

s32 func_001E93D0(u8 *p) {
    if (func_00189310(p, D_0044F2A0, p + 0x398) == 0) {
        return 0;
    }
    if (p[0x210] == 0) {
        s32 w = *(s8 *)(p + 0x1E8);
        if (w != 0) {
            return 0;
        }
        p[0x1E8] = w + 1;
    }
    func_0018A990(p, p + 0x398);
    p[0x1FD] = 4;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
