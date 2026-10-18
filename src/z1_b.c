typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_002EE150(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern u8 D_0045B780[];
    if (func_00189310(p, D_0045B780, p + 0x3B0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 t = p[0x1E8];
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3B0);
    p[0x26C] = 8;
    return 1;
}

s32 func_0026F150(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    extern u8 D_00454750[];
    if (func_00189310(p, D_00454750, p + 0x398) == 0) return 0;
    if (p[0x20D] == 2) {
        if (*(s8 *)(p + 0x1E8) != 0 && p[0x210] == 0) return 0;
        p[0x1E8] = *(volatile s8 *)(p + 0x1E8) + 1;
    }
    func_0018A990(p, p + 0x398);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x15);
    if (p[0x20D] == 2) p[6] = 1; else p[6] = 0;
    return 1;
}

s32 func_0026EFA0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    extern u8 D_00454720[];
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_00454720, p + 0x380) == 0) return 0;
    if (q[4] != 0) return 0;
    if (p[0x20D] == 2) {
        if (*(s8 *)(p + 0x1E8) != 0 && p[0x210] == 0) return 0;
        p[0x1E8] = *(volatile s8 *)(p + 0x1E8) + 1;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
