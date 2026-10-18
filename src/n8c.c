typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00161240(u8 *p)
{
    *(f32 *)(p + 0xE4) = -(f32)(1.0 - 0.0125 * (double)*(s16 *)(p + 0x1E));
}
