typedef unsigned char u8;
typedef signed short s16;
void func_00327E20(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1C) = 0x2C;
}
