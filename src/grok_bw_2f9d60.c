typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002F9D60(u8 *p, u8 *q)
{
    u8 n;
    u8 v;

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    if ((s8)func_00175700(p) >= 0)
        return;
    p[7]++;
    p[0x1FE] = 0;
    q[0xD] = 0;
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    v = p[0x20D];
    if (v == 1)
        n = 7;
    else if (v == 0)
        n = 7;
    else
        n = 8;
    p[0x168] = n;
    func_001757E0(p, 0x16, p[0x168]);
    (*(u8 **)(p + 0x1DC))[0x20A] = 6;
}
