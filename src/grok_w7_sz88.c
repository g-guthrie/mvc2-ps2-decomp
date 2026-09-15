typedef unsigned char u8;
typedef signed char s8;

extern u8 D_0044FB48[];
extern u8 D_0044FB80[];
extern u8 D_00453140[];
extern u8 D_00453580[];
extern u8 D_004558D0[];
extern u8 D_00457C60[];
extern u8 D_00458730[];
extern u8 D_00458F30[];
extern u8 D_0045AEA0[];
extern u8 D_0045BA60[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern int func_00189660(u8 *, u8 *, u8 *);
extern int func_00189EE0(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);

int func_001F7490(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (!func_00189660(p, D_0044FB48, p + 0x380))
        return 0;
    func_0018A990(p, p + 0x380);
    if (q[2])
        return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 21));
    return 1;
}

int func_001F7650(u8 *p)
{
    if (!func_00189310(p, D_0044FB80, p + 0x398))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    func_0018A990(p, p + 0x398);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 3, 29));
    p[0x1B7] = 1;
    return 1;
}

int func_0024D920(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (!func_00189310(p, D_00453140, p + 0x380))
        return 0;
    if (*q)
        return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 21));
    return 1;
}

int func_002549C0(u8 *p)
{
    if (!func_00189EE0(p, D_00453580, p + 0x3A8))
        return 0;
    if (*(s8 *)*(u8 **)(p + 0x420) < 3)
        return 0;
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 8, 29));
    return 1;
}

int func_00281320(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (!func_00189310(p, D_004558D0, p + 0x380))
        return 0;
    if (*q)
        return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 21));
    return 1;
}

int func_00294FD0(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (!func_00189310(p, D_00457C60, p + 0x378))
        return 0;
    if (q[2])
        return 0;
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 21));
    return 1;
}

int func_002A72E0(u8 *p)
{
    u8 *q = p + 0x2B8;

    if (!func_00189660(p, D_00458730, p + 0x380))
        return 0;
    if (q[2])
        return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 0, 21));
    return 1;
}

int func_002B2860(u8 *p)
{
    if (!func_00189EE0(p, D_00458F30, p + 0x3C0))
        return 0;
    if (*(s8 *)*(u8 **)(p + 0x420) < 3)
        return 0;
    func_0018A990(p, p + 0x3C0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 16, 29));
    return 1;
}

int func_002E0F20(u8 *p)
{
    if (!func_00189310(p, D_0045AEA0, p + 0x378))
        return 0;
    if (!*(s8 *)*(u8 **)(p + 0x420))
        return 0;
    func_0018A990(p, p + 0x378);
    func_00186A60(p, (p[5] = 0, 29));
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 2;
    p[0x213] = 0;
    return 1;
}

int func_002F24E0(u8 *p)
{
    if (!func_00189310(p, D_0045BA60, p + 0x390))
        return 0;
    func_0018A990(p, p + 0x390);
    if (p[0x1B7] == 1)
        p[0x1B7] = 1;
    else
        p[0x1B7] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, (p[0x1FD] = 4, 21));
    return 1;
}
