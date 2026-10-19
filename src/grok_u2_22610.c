typedef unsigned char u8;
typedef unsigned int u32;

void residual_00222610(u8 *p)
{
    p[6]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
