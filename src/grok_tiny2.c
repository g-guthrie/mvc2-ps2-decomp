typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_00119AB8(void);
extern void func_00423750(void);
extern void func_00184540(u8 *);
extern void func_001CB5A0(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00178F20(u8 *, u8 *);
extern u8 D_0044DAC0[];
extern u8 D_0044DDA0[];
extern u8 *D_004C2840;

s32 func_00100240(void) { return func_00119AB8() < 0; }
s32 func_00100290(void) { return func_00119AB8() > 0; }

s32 func_0013BCE0(u8 *p)
{
    return p[33] == *(s8 *)(*(u8 **)(p + 20) + 1245);
}

s32 func_0040F1D0(s32 *p)
{
    s32 v = p[6];
    p[4] = 0;
    p[3] = v;
    return v;
}

s32 func_00419FC0(void)
{
    func_00423750();
    return 1;
}

void func_002C40D0(u8 *p)
{
    p[533] = 0;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 108) = 0xBF4DB6DB;
    func_00184540(p);
}

void func_002CAFA0(u8 *p)
{
    p[533] = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 108) = 0xBF4DB6DB;
    func_00184540(p);
}

void func_001CB180(u8 *p)
{
    func_001CB5A0(p, 27, D_0044DAC0[*(s32 *)(p + 208) >> 1]);
}

void func_001CCF40(u8 *p, s32 a1)
{
    func_001757E0(p, 23, D_0044DDA0[a1 & 0xff]);
}

void func_00239C80(u8 *p, u8 *q)
{
    if (p[6] == 0)
        p[520] = 2;
    func_00178F20(q, p);
}

void func_0041DB80(void)
{
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
}
