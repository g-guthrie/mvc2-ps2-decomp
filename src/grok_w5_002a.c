typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

typedef void (*DispatchFn)(u8 *);

extern void func_00186A60(u8 *, int);
extern void func_0018C6E0(u8 *);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern int func_003D92F0(u8 *);

extern f32 D_004F1F4C[];
extern f32 D_004F1FE8[];
extern u8 D_004C0CB0;
extern u8 D_004C0CB8;
extern DispatchFn jtbl_004589C0[];
extern DispatchFn jtbl_00458C20[];
extern DispatchFn jtbl_00458C30[];
extern DispatchFn jtbl_00459230[];
extern DispatchFn jtbl_00458460[];
extern DispatchFn jtbl_00458850[];
extern DispatchFn jtbl_00459050[];
extern DispatchFn jtbl_00459390[];

void func_002BD610(u8 *p, u8 *out)
{
    F(out, 4) = D_004F1F4C[0] - F(p, 0x34);
    F(out, 8) = D_004F1FE8[0] - F(p, 0x38);
}

void func_002B23B0(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = (&D_004C0CB0)[(s8)p[0x4DD] + I(p, 0xD0) * 3];
    func_00186A60(p, 29);
}

void func_002B23F0(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = (&D_004C0CB8)[(s8)p[0x4DD] + I(p, 0xD0) * 3];
    p[0x1B7] = 1;
    func_00186A60(p, 29);
}

void func_002AB1A0(u8 *p)
{
    func_0018C6E0(p);
    jtbl_004589C0[p[0x20B] & 0x3F](p);
}

void func_002B7A90(u8 *p)
{
    func_0018C6E0(p);
    jtbl_00459230[p[0x20B] & 0x3F](p);
}

void func_002ACCB0(u8 *p)
{
    jtbl_00458C20[p[6]](p);
    if (I(p, 0xD0))
        func_00183D90(p);
}

void func_002AD010(u8 *p)
{
    jtbl_00458C30[p[6]](p);
    if (I(p, 0xD0))
        func_00183D90(p);
}

void func_002A2A80(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00458460[p[0x20]](p);
}

void func_002A8D20(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00458850[p[0x20]](p);
}

void func_002B4A30(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00459050[p[0x20]](p);
}

void func_002B9C00(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00459390[p[0x20]](p);
}

void func_002B9E60(u8 *p)
{
    S(p, 0x1E) = 60;
    p[0x2C7] = 0;
    if (F(p, 0x34) >= D_004F1F4C[0])
        p[0x1E6] = 0;
    else
        p[0x1E6] = 1;
    S(p, 0x140) = p[0x1E6];
    func_001757E0(p, 0, 0);
}
