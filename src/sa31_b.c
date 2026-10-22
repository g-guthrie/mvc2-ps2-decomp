typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004521C0[];
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);

s32 func_002336B0(u8 *p) {
    u8 k;
    f32 a;
    f32 b;
    if (func_00189310(p, D_004521C0, p + 0x3A0) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0 && *(s8 *)(p + 0x1E8) != 0) {
            return 0;
        }
        k = p[0x1E4];
        if (k == 0xA || k == 0xB || (*(f32 *)(p + 0x38) >= 25.714284896850586f + *(f32 *)(p + 0x430) && *(f32 *)(p + 0x38) <= 925.7142333984375f + *(f32 *)(p + 0x430))) {
        } else {
            return 0;
        }
    }
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 4;
    func_00186A60(p, 0x1D);
    return 1;
}
