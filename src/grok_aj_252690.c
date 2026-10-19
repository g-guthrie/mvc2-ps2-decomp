typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, int, int);
extern int func_00189310(u8 *, void *, u8 *);
extern void func_00183D10(u8 *);
extern u8 D_004531D0[];

void func_00252690(u8 *p, u8 *q)
{
    if ((s8)q[0xB] < 0) {
        p[6] = 0xF;
        func_001757E0(p, 0x16, 0xD);
        return;
    }
    if ((s8)p[0x539] == 0)
        goto check;
    if (p[0x212] != 0)
        goto body;
check:
    {
        volatile u8 *tbl = D_004531D0;
        if (func_00189310(p, (void *)tbl, p + 0x3C8) == 0)
            return;
    }
body:
    if (*(s8 *)(*(u8 **)(p + 0x420)) == 0)
        return;
    p[6]++;
    p[0x1B5] = 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    q[0xC] = 1;
    func_001757E0(p, 0x16, 0xC);
    func_00183D10(p);
}
