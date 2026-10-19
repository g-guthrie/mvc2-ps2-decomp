typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 func_00417440(u32);

void D_00141130(u8 *p)
{
    u8 st = p[4];
    f32 v;

    if (st == 1) {
        v = 0.75f + 0.25f * func_00417440((unsigned short)(unsigned int)((double)*(s16 *)(p + 0x1C) * 65536.0 / 360.0 + 0.5));
        *(f32 *)(p + 0x78) = v;
        *(f32 *)(p + 0x7C) = v;
        *(f32 *)(p + 0x80) = v;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 5;
        if (*(s16 *)(p + 0x1C) >= 360)
            *(s16 *)(p + 0x1C) = 0;
        return;
    }
    if (st != 0)
        return;
    v = *(f32 *)(p + 0x78) + 0.01f;
    if (!(v < 0.75f)) {
        v = 0.75f;
        p[4] = (u8)(st + 1);
    }
    *(f32 *)(p + 0x78) = v;
    *(f32 *)(p + 0x7C) = v;
    *(f32 *)(p + 0x80) = v;
}
