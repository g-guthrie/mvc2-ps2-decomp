typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

void func_0016C3F0(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1c) = 0x10;
    *(s16 *)(p + 0x1e) = 0xF0;
    *(s32 *)(p + 0x104) = 0;
    *(f32 *)(p + 0x10c) = 0.9375f;
    *(s32 *)(p + 0x108) = 0;
    *(f32 *)(p + 0x110) = 1.0f;
    *(s32 *)(p + 0x118) = 0;
}
