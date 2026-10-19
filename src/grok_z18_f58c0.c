typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_001F0420(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void residual_001F58C0(u8 *p)
{
    p[6]++;
    func_001F0420(p);
    func_00183D10(p);
    func_0018C4B0(p, 8);
    p[0x1B5] = 0x2B;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 0x15, 9);
}
