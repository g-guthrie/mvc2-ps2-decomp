typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002F8DE0(u8 *);
extern void func_002F9B20(u8 *, u8 *);

void residual_002F9A70(u8 *p, u8 *q)
{
    p[7]++;
    func_00185490(p);
    if (p[0x20D] != 2)
        func_00183D10(p);
    p[0x1B5] = 0x33;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 0x16, 0);
    func_002F8DE0(p);
    func_002F9B20(p, q);
}
