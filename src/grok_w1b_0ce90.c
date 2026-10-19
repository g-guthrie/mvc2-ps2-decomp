typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern void func_0020CF40(u8 *, u8 *);
extern u8 *D_004C2794;

void func_0020CE90(u8 *p, u8 *q)
{
    p[7]++;
    p[0x1B5] = 67;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    q[12] = 28;
    *(u32 *)(p + 0x60) = 0xC14DB6DB;
    *(u32 *)(p + 0x6C) = 0x3E892492;
    func_001757E0(p, 20, 14);
    func_0020CF40(p, q);
}
