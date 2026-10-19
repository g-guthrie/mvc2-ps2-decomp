typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 D_004C0268 __attribute__((section(".sdata")));
extern u8 D_004C0270 __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00186A20(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_0023C450(u8 *, u8 *);

void func_0023C360(u8 *p, u8 *q)
{
    p[7]++;
    func_0018C4B0(p, 5);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00186A20(p);
    p[0x1B5] = (&D_004C0268)[p[0x20] + (p[0x21] << 1)];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    p[0x169] = 0x15;
    p[0x168] = (&D_004C0270)[p[0x20] + (p[0x21] << 1)];
    func_001757E0(p, p[0x169], p[0x168]);
    func_0023C450(p, q);
}
