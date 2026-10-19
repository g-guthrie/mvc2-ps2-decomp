typedef unsigned char u8;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern void func_001C4710(u8 *, u8 *);

void residual_001C46B0(u8 *p, u8 *q)
{
    p[7]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x19, 0x16);
    func_001C4710(p, q);
}
