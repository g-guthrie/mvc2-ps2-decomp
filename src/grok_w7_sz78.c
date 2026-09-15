typedef unsigned char u8;
typedef signed char s8;

extern u8 D_00451680[];
extern u8 D_004551D0[];
extern u8 D_00458080[];
extern u8 D_0045A360[];
extern u8 D_0045A370[];
extern u8 D_0045BA00[];
extern u8 D_0044F2B0[];
extern u8 D_004531B0[];
extern u8 D_00454780[];
extern u8 D_00458390[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_00186A60(u8 *, int);

int func_00226530(u8 *p)
{
    if (!func_00189310(p, D_00451680, p + 0x398))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[0x1FD] = 20;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 29);
    return 1;
}

int func_0027D160(u8 *p)
{
    if (!func_00189310(p, D_004551D0, p + 0x378))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 29));
    return 1;
}

int func_0029B280(u8 *p)
{
    if (!func_00189310(p, D_00458080, p + 0x378))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 29));
    return 1;
}

int func_002D1490(u8 *p)
{
    if (!func_00189310(p, D_0045A360, p + 0x3B8))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[0x1FD] = 10;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 29);
    return 1;
}

int func_002D1510(u8 *p)
{
    if (!func_00189310(p, D_0045A370, p + 0x3C0))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[0x1FD] = 14;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 29);
    return 1;
}

int func_002F2160(u8 *p)
{
    if (!func_00189310(p, D_0045BA00, p + 0x378))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 29));
    return 1;
}

int func_001ED6E0(u8 *p)
{
    if (!func_00189310(p, D_0044F2B0, p + 0x3A0))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    if (p[0x20D] == 2)
        return 0;
    p[0x26C] = 5;
    return 1;
}

int func_0024E030(u8 *p)
{
    if (!func_00189310(p, D_004531B0, p + 0x3B0))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    if (p[0x20D] == 2)
        return 0;
    p[0x26C] = 6;
    return 1;
}

int func_0026F4A0(u8 *p)
{
    if (!func_00189310(p, D_00454780, p + 0x3A8))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    if (p[0x20D] == 2)
        return 0;
    p[0x26C] = 5;
    return 1;
}

int func_002A12D0(u8 *p)
{
    if (!func_00189310(p, D_00458390, p + 0x3B8))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    if (p[0x20D] == 2)
        return 0;
    p[0x26C] = 7;
    return 1;
}
