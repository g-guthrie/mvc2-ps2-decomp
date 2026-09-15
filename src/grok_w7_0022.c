typedef unsigned char u8;
typedef signed char s8;

typedef void (*DispatchFn)(u8 *);
typedef void (*DispatchFn2)(u8 *, u8 *);

extern DispatchFn jtbl_00451C10[];
extern DispatchFn2 jtbl_004527B0[];
extern u8 D_004C00C8;
extern u8 D_004C00C9;
extern u8 D_004C00D0;
extern u8 D_004C00D1;
extern void func_0022C5C0(u8 *);
extern void func_00186A60(u8 *, int);
extern void func_0023E0B0(u8 *, u8 *);

void func_0022C820(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C00C8)[(s8)p[1245] * 2];
    p[439] = (&D_004C00C9)[(s8)p[1245] * 2];
    func_00186A60(p, 21);
}

void func_0022C870(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C00D0)[(s8)p[1245] * 2];
    p[439] = (&D_004C00D1)[(s8)p[1245] * 2];
    func_00186A60(p, 21);
}

void func_0022BF60(u8 *p)
{
    func_0022C5C0(p);
    jtbl_00451C10[p[6]](p);
}

void func_0023E120(u8 *p, u8 *q)
{
    jtbl_004527B0[p[6]](p, q);
    func_0023E0B0(p, q);
}
