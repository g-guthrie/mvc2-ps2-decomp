typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

void residual_00209980(u8 *p)
{
    f32 x, y;
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x20;
    if (p[0x1E6] != 0)
        x = 13.33333301544189453125f;
    else
        x = -13.33333301544189453125f;
    *(f32 *)(p + 0x5C) = x;
    if (p[0x1E6] != 0)
        y = -0.2083333283662796f;
    else
        y = 0.2083333283662796f;
    *(f32 *)(p + 0x68) = y;
}
