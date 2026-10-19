typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
void func_00328530(u8 *p)
{
    p[4]++;
    *(u32 *)(p + 0x14C) = 0x80204040;
    p[0x24] = 0xF;
    *(s16 *)(p + 0x1C) = 0x3C;
}
