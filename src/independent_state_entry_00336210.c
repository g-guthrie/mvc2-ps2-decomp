typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
void func_00336210(u8 *p)
{
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0x44) = *(s16 *)(p + 0x140) != 0 ? 0 : 0x8000;
    p[7]++;
    *(s16 *)(p + 0x1C) = 0xA;
}
