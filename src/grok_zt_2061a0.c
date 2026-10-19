typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002061A0(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0x14) = 0;
    func_00185490(p);
    if (p[0x20D] == 2) {
        p[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        p[0x1B5] = 0x40;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 22, 3);
    } else {
        p[0x20D] = 0;
        func_00183D10(p);
        p[0x1B5] = 0x40;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 22, 0);
    }
}
