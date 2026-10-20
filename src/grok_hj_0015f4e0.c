typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern f32 D_004B3DC0[];

void residual_0015F4E0(u8 *p)
{
    f32 *tbl = D_004B3DC0;
    int n = *(s16 *)(p + 0x1C);
    f32 add = 0.029999995604157448f;
    f32 sub = 0.07999999821186066f;
    tbl += n;
    *(f32 *)(p + 0x78) = *tbl;
    *(f32 *)(p + 0x7C) = *tbl;
    *(f32 *)(p + 0x80) = *tbl;
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x50) + add;
    *(f32 *)(p + 0x54) = *(f32 *)(p + 0x54) - sub;
    n = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = n;
    if ((s16)n >= 10) {
        p[4] = 1;
        p = *(u8 **)(p + 0x14);
        *(s32 *)(p + 0xD4) = *(s32 *)(p + 0xD4) - 1;
    }
}
