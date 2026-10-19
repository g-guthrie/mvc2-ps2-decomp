typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

void residual_0016C3F0(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1C) = 16;
    *(s16 *)(p + 0x1E) = 240;
    *(u32 *)(p + 0x104) = 0;
    *(f32 *)(p + 0x10C) = 0.9375f;
    *(u32 *)(p + 0x108) = 0;
    *(f32 *)(p + 0x110) = 1.0f;
    *(u32 *)(p + 0x118) = 0;
}
