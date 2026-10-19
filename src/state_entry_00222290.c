typedef unsigned char u8;
typedef unsigned int u32;

void func_00222290(u8 *p)
{
    p[6]++;
    if (p[0x1E6] != 0)
        *(u32 *)(p + 0x5C) = 0x40D55555;
    else
        *(u32 *)(p + 0x5C) = 0xC0D55555;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x20D] = 2;
}
