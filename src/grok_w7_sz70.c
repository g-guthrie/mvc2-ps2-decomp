typedef unsigned char u8;
typedef unsigned short u16;

extern u8 D_0045CAF0[];
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, int);
extern int func_0016B250(u8 *, int);
extern void func_0016B0C0(u8 *, u8 *, int);

int func_00304EB0(u8 *p)
{
    if (!func_00189310(p, D_0045CAF0, p + 0x3B8))
        return 0;
    func_0018A990(p, p + 0x3B8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 21);
    p[0x1B7] = 2;
    return 1;
}

int func_00167EE0(u8 *p, u8 *q)
{
    if (!func_0016B250(p, 3))
        return 0;
    func_0016B0C0(p, q, 0);
    p[0x471] = 1;
    p[0x45C] = 0x7B;
    p[0x4BF] = 0;
    p[0x4BE] = 0;
    *(u16 *)(p + 0x4C0) = 0;
    return 0;
}

int func_00168050(u8 *p, u8 *q)
{
    if (!func_0016B250(p, 3))
        return 0;
    func_0016B0C0(p, q, 0);
    p[0x471] = 1;
    p[0x45C] = 0x7A;
    p[0x4BF] = 0;
    p[0x4BE] = 0;
    *(u16 *)(p + 0x4C0) = 0;
    return 0;
}

int func_001680C0(u8 *p, u8 *q)
{
    if (!func_0016B250(p, 3))
        return 0;
    func_0016B0C0(p, q, 0);
    p[0x471] = 1;
    p[0x45C] = 0x7E;
    p[0x4BF] = 0;
    p[0x4BE] = 0;
    *(u16 *)(p + 0x4C0) = 0;
    return 0;
}

