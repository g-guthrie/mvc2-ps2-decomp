typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0036BB80(u8 *p)
{
    f32 v;
    s16 t;
    v = *(f32 *)(p + 0x118) - 0.05999999865889549f;
    *(f32 *)(p + 0x118) = v;
    if ((double)v < 0.1) {
        *(u32 *)(p + 0x118) = 0x3DCCCCCD;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x54) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((double)(*(f32 *)(p + 0x54)) < 0.01) {
        *(u32 *)(p + 0x54) = 0x3C23D70A;
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t < 0) {
        p[5]++;
        *(f32 *)(p + 0x60) /= 100.0f;
        *(f32 *)(p + 0x6C) /= 100.0f;
    }
}
