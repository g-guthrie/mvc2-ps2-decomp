typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern u32 D_0045AE20[];
extern u8 D_0045AFD0[];
extern void func_001861B0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);

void func_002E15C0(u8 *p)
{
    u8 t;
    func_001861B0(p);
    {
        u8 a = p[0x1FC];
        u8 b = p[0x212];
        *(u32 *)(p + 0x408) = (u32)(D_0045AE20 + a + b * 3);
    }
    p[0x1BB] = p[0x1FC];
    {
        s8 d = *(s8 *)(p + 0x20D);
        s8 e = *(s8 *)(p + 0x212);
        s8 f = *(s8 *)(p + 0x1FC);
        t = f + d * 6 + e * 3;
    }
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001757E0(p, (p[0x20D] * 2 + 7 + p[0x212]) & 0xFF, p[0x1FC]);
    if (D_0045AFD0[t])
        func_001E3710(p, D_0045AFD0[t]);
}
