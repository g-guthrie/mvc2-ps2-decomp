typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0045B100[];

s32 func_002E41E0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_0045B100, p + 0x3A0) == 0) return 0;
    if (**(s8 **)(p + 0x420) <= 0) return 0;
    if (*(s8 *)(q + 9) != 0) return 0;
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    return 1;
}

extern u8 D_0045B780[];

s32 func_002EDB00(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    s8 v;
    if (func_00189310(p, D_0045B780, p + 0x3B0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        v = *(s8 *)(p + 0x1E8);
        if (v != 0) return 0;
        p[0x1E8] = v + 1;
    }
    if (p[0x20D] == 2 && *(s32 *)(p + 0x2D4) != 1) return 0;
    func_0018A990(p, p + 0x3B0);
    p[0x1FD] = 8;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x1D);
    return 1;
}
