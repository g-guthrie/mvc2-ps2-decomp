typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u8 func_003EE690(s16 a, s16 b)
{
    extern u8 D_00478D10[];
    s32 y = ((b + 127) / 32) * 8;
    return D_00478D10[y + (a + 127) / 32];
}
