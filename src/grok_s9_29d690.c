typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_0029D5E0(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void residual_0029D690(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    *(s16 *)(p + 0x1C) = 15;
    func_0029D5E0(p);
    p[0x1B5] = 57;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    *(u16 *)(p + 0x1C0) |= 0x200;
    func_001757E0(p, 22, 0);
}
