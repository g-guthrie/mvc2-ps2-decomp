typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00459C70[];
s32 func_002C5410(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_002CAFC0(u8 *);
    extern void func_00186A60(u8 *, s32);
    if (!func_00189310(p, D_00459C70, p + 0x390)) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 v = *(s8 *)(p + 0x1E8);
            if (v != 0) {
                return 0;
            }
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x390);
    if (p[0x215] != 0) {
        func_002CAFC0(p);
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    if (p[0x20D] == 2) {
        p[6] = 1;
    }
    return 1;
}

extern u8 D_004598D0[];
s32 func_002C01D0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    if (!func_00189310(p, D_004598D0, p + 0x3B8)) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 v = *(s8 *)(p + 0x1E8);
            if (v != 0) {
                return 0;
            }
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x3B8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    if (p[0x20D] == 2) {
        p[0x1FD] = 0xC;
    } else {
        p[0x1FD] = 5;
    }
    func_00186A60(p, 0x1D);
    return 1;
}
