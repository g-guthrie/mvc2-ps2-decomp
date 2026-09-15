typedef unsigned char u8;
typedef signed char s8;

typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00459AC0[];
extern u8 *D_004C28D8;
extern u8 D_004C1048;
extern u8 D_004C104C;
extern u8 D_004C1050;
extern u8 D_004C1051;
extern u8 D_004C1058;
extern u8 D_004C1059;
extern void func_00186A60(u8 *, int);

void func_002C2570(u8 *p)
{
    D_004C28D8 = p + 696;
    jtbl_00459AC0[p[509]](p);
}

void func_002DC1E0(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1048)[(s8)p[1245]];
    func_00186A60(p, 29);
}

void func_002DC210(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C104C)[(s8)p[1245]];
    func_00186A60(p, 29);
}

void func_002DC240(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1050)[(s8)p[1245] * 2];
    p[439] = (&D_004C1051)[(s8)p[1245] * 2];
    func_00186A60(p, 21);
}

void func_002DC290(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1058)[(s8)p[1245] * 2];
    p[439] = (&D_004C1059)[(s8)p[1245] * 2];
    func_00186A60(p, 21);
}
