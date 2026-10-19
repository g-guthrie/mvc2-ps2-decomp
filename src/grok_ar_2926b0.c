typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern void func_001C5810(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00183D10(u8 *);
extern void func_00292790(u8 *);

void func_002926B0(u8 *p)
{
    u8 *q = p + 0x2B8;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    q[0x18] = 0;
    q[4] = 0xFF;
    q[0xA] = 0xFF;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 0x4E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001C5810(p, 1);
    func_001757E0(p, 0x16, 0x11);
    if (p[0x20D] != 2)
        func_00183D10(p);
    func_00292790(p);
}
