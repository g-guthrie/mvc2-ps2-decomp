typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_002CC0A0(u8 *p) {
    extern s32 func_00189310();
    extern double func_00119058(f32);
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_0045A020[];
    if (func_00189310(p, D_0045A020, p + 0x390) == 0) return 0;
    if (func_00119058(*(f32 *)(p + 0x60)) < 0.0) {
        if (*(f32 *)(p + 0x38) - *(f32 *)(p + 0x430) < 102.857140f) return 1;
    }
    if (p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x390);
    p[0x1FD] = 3;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

s32 func_002C57E0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_002CAFC0();
    extern void func_00186A60();
    extern u8 D_00459CC0[];
    if (func_00189310(p, D_00459CC0, p + 0x3B0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3B0);
    if (p[0x215] != 0) func_002CAFC0(p);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x1D);
    if (p[0x20D] == 2) {
        p[6] = 1;
    }
    return 1;
}

s32 func_002C55E0(u8 *p) {
    extern s32 func_00189660();
    extern void func_0018A990();
    extern void func_002CAFC0();
    extern void func_00186A60();
    extern u8 D_00459CA0[];
    u8 *o = p + 0x2B8;
    if (func_00189660(p, D_00459CA0, p + 0x3A0) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    if (*(s8 *)(p + 0x539) != 0 && p[0x215] != 0) return 0;
    func_0018A990(p, p + 0x3A0);
    if (p[0x215] != 0) func_002CAFC0(p);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x15);
    o[3] = (p[0x20D] == 2) ? 1 : 0;
    return 1;
}
