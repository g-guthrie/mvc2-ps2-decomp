typedef unsigned char u8;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);

void func_00238C00(u8 *p)
{
    p[6]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 21, 30);
}
