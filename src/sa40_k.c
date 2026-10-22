typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00447CC0[];
extern s16 D_00447550[];

void func_00181D90(u8 *p) {
    s16 *t;
    f32 a;
    f32 b;
    f32 k1;
    f32 k2;
    f32 d;
    if (p[0x210] == 0) {
        t = D_00447550;
    } else {
        t = D_00447CC0;
    }
    t = t + ((*(s8 *)(p + 0x1E7) + 1) * 4 + p[1] * 12);
    k1 = 2.142857074737549f;
    d = 256.0f;
    k2 = 1.666666626930237f;
    *(f32 *)(p + 0x60) = k1 * (f32)t[0] / d;
    *(f32 *)(p + 0x6C) = k1 * (f32)t[1] / d;
    a = k2 * (f32)t[2] / d;
    b = k2 * (f32)t[3] / d;
    if (p[0x1E6] != 0) {
        a = -a;
        b = -b;
    }
    if (p[0x214] != 0 && p[0x210] == 0) {
        *(f32 *)(p + 0x60) *= 1.25f;
        *(f32 *)(p + 0x6C) *= 1.5f;
        a *= 1.100000023841858f;
        b *= 1.100000023841858f;
    }
    if (p[0x1E5] == 10 && *(s8 *)(p + 0x1E7) == 0) {
        *(f32 *)(p + 0x5C) += a;
    } else {
        *(f32 *)(p + 0x5C) = a;
    }
    *(f32 *)(p + 0x68) = b;
}
