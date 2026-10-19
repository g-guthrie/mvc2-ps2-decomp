/* ./try.sh src/grok_bg_0031FEE0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00183D10(u8 *);
extern void func_00185490(u8 *);
extern void func_00176160(u8 *, int, int, int);
extern void func_001757E0(u8 *, int, int);

void residual_0031FEE0(u8 *p)
{
    int a = 11;

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[7]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 68;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    if (p[0x20D] == 2) {
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        a = a + 1;
    } else {
        func_00183D10(p);
        func_00185490(p);
        func_00176160(p, 2, 0, 1);
    }
    func_001757E0(p, 22, a);
}
