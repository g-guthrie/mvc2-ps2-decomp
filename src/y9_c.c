typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static s32 func_00254480(u8 *p) {
    if (p[0x20D] != 2) return 1;
    if (p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) return 0;
        *(s8 *)(p + 0x1E8) += 1;
    }
    return 1;
}

s32 func_00254910(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_00453570[];
    if (*(s16 *)(p + 0x2B8) > 0) {
        return 0;
    }
    if (func_00189310(p, D_00453570, p + 0x3A0) == 0) {
        return 0;
    }
    if (func_00254480(p) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_002623E0(u8 *p) {
    extern s32 func_00189950();
    extern s32 func_0018A580();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_004540A0[];
    if (func_00189950(p, D_004540A0, p + 0x380) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 v = *(s8 *)(p + 0x1E8);
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}

s32 func_002262B0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    extern u8 D_004516A0[];
    s32 t;
    u8 v;
    if (func_00189310(p, D_004516A0, p + 0x3B8) == 0) return 0;
    t = *(s32 *)(p + 0x2BC);
    if (t != 0x27) {
        if (t != 7 && t != 0x39 && t != 0x24) return 0;
    }
    func_0018A990(p, p + 0x3B8);
    t = *(s32 *)(p + 0x2BC);
    v = 8;
    if (t == 7) v = 0x12;
    if (t == 0x39) v = 0x12;
    if (t == 0x24) v = 0x11;
    p[0x1FD] = v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

void func_001ECBF0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001ECF90();
    f32 *v1, *a0;
    f32 z;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    a0 = (f32 *)(p + 0x68);
    z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < z) {
        t = p[6];
        p[6] = t + 1;
        *v1 = z;
        *a0 = z;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        if (*(s16 *)(p + 0x1E) == 0) {
            func_001757E0(p, 0x16, 0xB);
        } else {
            func_001757E0(p, 0x16, 0xE);
        }
    }
    func_001ECF90(p);
}
