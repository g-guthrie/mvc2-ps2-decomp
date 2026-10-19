typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef void (*Callback)(u8 *);

extern const u32 jtbl_00451340[5];
extern const u32 jtbl_004513D0[23];
extern const Callback jtbl_00451390[15];
extern void func_00221440(u8 *);
extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00186A20(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_0021F490(u8 *p)
{
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    ((Callback *)jtbl_00451340)[p[6]](p);
}

void func_00221850(u8 *p)
{
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    ((Callback *)jtbl_004513D0)[p[6]](p);
}

void func_002218B0(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00186A20(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 80;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00183D10(p);
    func_001757E0(p, 21, 47);
    if (p[0x1E6]) {
        *(float *)(p + 0x34) += 80.0f;
        *(float *)(p + 0x5C) = 6.666666507720947f;
        *(float *)(p + 0x68) = -0.1171875f;
    } else {
        *(float *)(p + 0x34) += -80.0f;
        *(float *)(p + 0x5C) = -6.666666507720947f;
        *(float *)(p + 0x68) = 0.1171875f;
    }
    *(float *)(p + 0x60) = 19.28571319580078f;
    *(float *)(p + 0x6C) = -0.8035714030265808f;
}

void func_00221310(u8 *p)
{
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    (jtbl_00451390 + 8)[p[6]](p);
}

void func_00221370(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    p[6]++;
    func_00183D10(p);
    p[0x2C3] = 100;
    func_001757E0(p, 21, 46);
    func_00186A20(p);
    *(float *)(p + 0x38) = *(float *)(p + 0x430);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 78;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_00221440(p);
}
