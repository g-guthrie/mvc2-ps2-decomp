typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 D_0044F2D0[];
extern u8 D_00450610[];
extern u8 D_00451210[];
extern u8 D_00451CF0[];
extern u8 D_00452E30[];
extern u8 D_00453960[];
extern u8 D_0045A300[];
extern u8 D_0045A2E0[];
extern u8 D_0045DDE0[];
extern u8 D_0045DDB0[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);

int func_001E95B0(u8 *p)
{
    if (!func_00189310(p, D_0044F2D0, p + 0x3B0))
        return 0;
    if (*(s8 *)*(u8 **)(p + 0x420) < 3)
        return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 11, 29));
    return 1;
}

int func_00208C80(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (!func_00189310(p, D_00450610, p + 0x390))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    if (*q)
        return 0;
    p[0x26C] = 4;
    return 1;
}

int func_0021CF50(u8 *p)
{
    if (!func_00189310(p, D_00451210, p + 0x3A8))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[0x1B7] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 6, 29));
    return 1;
}

int func_0022CA70(u8 *p)
{
    if (!func_00189310(p, D_00451CF0, p + 0x378))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    p[0x1B7] = 2;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 5, 29));
    return 1;
}

int func_00248600(u8 *p)
{
    if (!func_00189310(p, D_00452E30, p + 0x388))
        return 0;
    if (p[0x2BD])
        return 0;
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 2, 21));
    return 1;
}

int func_0025C4F0(u8 *p)
{
    if (!func_00189310(p, D_00453960, p + 0x388))
        return 0;
    if (p[0x2CC])
        return 0;
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 2, 21));
    return 1;
}

int func_002D1670(u8 *p)
{
    if (!func_00189310(p, D_0045A300, p + 0x380))
        return 0;
    if (p[0x2B8])
        return 0;
    func_0018A990(p, p + 0x380);
    p[0x1FD] = 2;
    p[5] = 0;
    p[7] = 0;
    func_00186A60(p, (p[6] = 0, 21));
    return 1;
}

int func_002D1780(u8 *p)
{
    if (!func_00189310(p, D_0045A2E0, p + 0x378))
        return 0;
    if (p[0x2B8])
        return 0;
    func_0018A990(p, p + 0x378);
    p[0x1FD] = 1;
    p[5] = 0;
    p[7] = 0;
    func_00186A60(p, (p[6] = 0, 21));
    return 1;
}

int func_00322440(u8 *p)
{
    if (!func_00189310(p, D_0045DDE0, p + 0x3A0))
        return 0;
    if (*(s32 *)(p + 0x2B8) > 0)
        return 0;
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 7, 21));
    return 1;
}

int func_00322530(u8 *p)
{
    if (!func_00189310(p, D_0045DDB0, p + 0x388))
        return 0;
    if (*(s32 *)(p + 0x2B8) > 0)
        return 0;
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 1, 21));
    return 1;
}
