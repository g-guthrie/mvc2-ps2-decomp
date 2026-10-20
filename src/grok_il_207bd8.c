typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

void residual_00207BE0(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1C);
    t--;
    *(s16 *)(p + 0x1C) = t;
    if (t != 0)
        return;
    p[6]++;
    *(s16 *)(p + 0x1C) = 6;
    *(f32 *)(p + 0x70) = -*(f32 *)(p + 0x64) / 8.0f;
}
