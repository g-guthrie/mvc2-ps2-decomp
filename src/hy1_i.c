typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044AC20[];
extern s16 D_0044AC22[];
extern s16 D_0044AC24[];
extern s16 D_0044AC26[];
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];

void func_0019E0F0(u8 *p) {
    extern s32 func_00417A40(void);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *s0;
    s16 idx;
    s32 r;
    f32 g, t;
    s0 = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x31) = -2;
    idx = func_00417A40() & 0xF;
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)D_0044AC20[idx * 4] / 256.0f;
    *(f32 *)(p + 0x68) = 1.6666666269302368f * (f32)D_0044AC22[idx * 4] / 256.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)D_0044AC24[idx * 4] / 256.0f;
    *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)D_0044AC26[idx * 4] / 256.0f;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) = D_004F1FC8[0] - 26.66666603088379f;
    } else {
        *(f32 *)(p + 0x34) = 26.66666603088379f + D_004F1FCC[0];
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    r = func_00417A40() & 0x7F;
    g = (f32)(r << 8);
    t = 2.142857074737549f * g / 256.0f;
    *(f32 *)(p + 0x38) = 171.42855834960938f + *(f32 *)(s0 + 0x430) - t;
    func_001757E0(p, 0x17, 0x1D);
}
