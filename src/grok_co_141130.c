typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 func_00417440(u32);

void func_00141130(u8 *p)
{
    f32 v;

    if (p[4] == 1) {
        v = 0.75f + 0.25f * func_00417440((u32)((double)*(s16 *)(p + 0x1C) * 65536.0 / 360.0 + 0.5) & 0xFFFF);
        *(f32 *)(p + 0x78) = v;
        *(f32 *)(p + 0x7C) = v;
        *(f32 *)(p + 0x80) = v;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 5;
        if (*(s16 *)(p + 0x1C) >= 0x168)
            *(s16 *)(p + 0x1C) = 0;
    } else if (p[4] == 0) {
        v = *(f32 *)(p + 0x78) + 0.009999999776482582f;
        if (!(v < 0.75f)) {
            v = 0.75f;
            p[4] = 1;
        }
        *(f32 *)(p + 0x78) = v;
        *(f32 *)(p + 0x7C) = v;
        *(f32 *)(p + 0x80) = v;
    }
}
