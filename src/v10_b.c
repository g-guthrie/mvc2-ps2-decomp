typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

extern u8 D_00458B50[];
s32 func_002AC0E0(u8 *p) {
    extern s32 func_00189310();
    extern s32 func_0018AA10();
    extern void func_0018A990();
    extern void func_00186A60();
    s16 x;
    if (func_00189310(p, D_00458B50, p + 0x3B0) == 0) {
        return 0;
    }
    if (func_0018AA10(p, 0x300, &x) == 0) {
        if (func_0018AA10(p, 0x60, &x) == 0) {
            return 0;
        }
    }
    func_0018A990(p, p + 0x3B0);
    p[0x1FD] = 0x11;
    p[5] = 0;
    func_00186A60(p, 0x1D);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

extern u8 D_00452180[];
s32 func_002334A0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_00452180, p + 0x388) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) {
            return 0;
        }
        p[0x1E8] = t + 1;
    }
    if (*q != 0) {
        return 0;
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_0045A8C0[];
s32 func_002D9170(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_0045A8C0, p + 0x380) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) {
                return 0;
            }
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x380);
    p[0x1FD] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x1D);
    return 1;
}
