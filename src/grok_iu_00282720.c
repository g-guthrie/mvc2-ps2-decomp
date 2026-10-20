typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

void residual_00282720(u8 *p)
{
    f32 vx;

    p[7]++;
    p[0x20D] = 2;
    if (p[0x1E6] != 0)
        vx = 3.3333332538604736f;
    else
        vx = -3.3333332538604736f;
    *(f32 *)(p + 0x5C) = vx;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    *(s16 *)(p + 0x1E) = 0;
}
