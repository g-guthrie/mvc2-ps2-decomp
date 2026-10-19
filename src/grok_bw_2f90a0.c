typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002F8DE0(u8 *);
extern void func_002F9160(u8 *, u8 *);

void residual_002F90A0(u8 *p, u8 *q)
{
    p[6]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[0x20D] != 2)
        func_00183D10(p);
    p[0x1B5] = 0x32;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 0x15, 1);
    func_002F8DE0(p);
    func_002F9160(p, q);
}
