typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00453990[];
extern int func_00189310(u8 *, u8 *, u8 *);
static int func_0025C240(u8 *p) {
    if (p[0x20D] != 2) return 1;
    if (p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) return 0;
        *(s8 *)(p + 0x1E8) += 1;
    }
    return 1;
}
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);

s32 func_0025C6C0(u8 *p) {
    if (func_00189310(p, D_00453990, p + 0x3A0) == 0) {
        return 0;
    }
    if (func_0025C240(p) == 0) {
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

extern u8 D_004511D0[];

s32 func_0021CCA0(u8 *p) {
    s32 t;
    if (func_00189310(p, D_004511D0, p + 0x388) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            t = *(s8 *)(p + 0x1E8);
            if (t != 0) {
                return 0;
            }
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    *(s16 *)(p + 0x2DA) = 1;
    return 1;
}
