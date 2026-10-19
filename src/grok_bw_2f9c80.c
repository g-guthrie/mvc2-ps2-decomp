typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, int, int);
extern void func_002F8D80(u8 *);
extern void func_001E3C40(void);
extern void func_002F9D60(u8 *, u8 *);

void residual_002F9C80(u8 *p, u8 *q)
{
    u8 v;
    u8 n;

    p[0x40D] = 0xFF;
    p[0x40C] = 0x10;
    p[0x33B] = 1;
    D_004C2794[0x76] = ((s8)p[2] << 4) | 1;
    p[0x33C] = 0x10;
    p[0x33C] = 0x10;
    p[7]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    v = p[0x20D];
    if (v == 1)
        n = 8;
    else if (v == 0)
        n = 7;
    else
        n = 9;
    p[0x168] = n;
    func_001757E0(p, 0xF, p[0x168]);
    func_002F8D80(p);
    func_001E3C40();
    func_002F9D60(p, q);
}
