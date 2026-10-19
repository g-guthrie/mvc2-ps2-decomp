typedef unsigned char u8;
typedef signed short s16;
void func_00328140(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1C) = 0x14;
    *(s16 *)(p + 0x1E) = 0x14;
}
