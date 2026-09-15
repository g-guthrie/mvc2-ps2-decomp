typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern int func_001266A0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00176090(u8 *, int, int, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_001821D0(u8 *);
extern void func_00182380(u8 *);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00186A60(u8 *, int);

extern void func_001D9D80(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_00301200(u8 *);
extern void func_00301380(u8 *);
extern void func_00301C40(u8 *);
extern void func_003039A0(u8 *);
extern void func_0030E6B0(u8 *);
extern void func_0030F450(u8 *);
extern void func_0030F560(u8 *);
extern void func_00313120(u8 *);
extern void func_003182F0(u8 *);
void func_003031B0(u8 *p);

extern u8 D_004C1668;
extern u8 D_004C1669;
extern u8 D_004C1670;
extern u8 D_004C1671;
extern u8 *D_004C2840;

void func_003011B0(u8 *p)
{
    func_003039A0(p);
    if (p[0x212] == 1)
        func_00301380(p);
    else
        func_00301200(p);
}

void func_00301BF0(u8 *p)
{
    if (p[0x215])
        func_00301C40(p);
    else {
        func_00182380(p);
        func_001821D0(p);
        func_00301C40(p);
    }
}

void residual_00301CF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
    else if (*(s8 *)(p + 0x151))
        p[0x151] = 0;
}

void func_00302D80(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        S(p, 0x1C) = 10;
        func_001D9D80(p, 2, 0);
    }
}

void func_00303140(u8 *p)
{
    func_003031B0(p);
    func_00175700(p);
    if (S(p, 0x1C)-- == 0)
        func_00184540(p);
}

void func_003031B0(u8 *p)
{
    f32 lim;
    if (!p[0x215]) {
        F(p, 0x38) += F(p, 0x60);
        F(p, 0x60) += F(p, 0x6C);
    }
    lim = *(f32 *)(p + 0x430);
    if (!(lim <= *(f32 *)(p + 0x38)))
        *(f32 *)(p + 0x38) = lim;
}

void func_00303340(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0x15, 8);
    }
}

void func_00308680(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001266A0(p, 0, 0);
        func_001843A0(p);
    }
}

void func_00308800(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001266A0(p, 0, 0);
        func_00184540(p);
    }
}

void func_003092C0(u8 *p)
{
    if (!(p[0x25] & 1))
        func_00176160(p, 3, 4, 1);
    else
        func_00176160(p, 3, 0x10, 1);
}

void func_0030C240(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0xF, 3);
    }
}

void func_0030C3A0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0xF, 5);
    }
}

void func_0030E440(u8 *p, int a1)
{
    if (I(D_004C2840, 28) & 1)
        func_00176090(p, 0, 0, 1);
    else
        func_00176160(p, 0, a1, 1);
}

void func_0030E660(u8 *p)
{
    p[6]++;
    func_001E3210(p, 0x25);
    func_001E3710(p, 0x4D);
    func_0030E6B0(p);
}

void func_0030F400(u8 *p)
{
    p[0x1FE] = 1;
    if ((p[0x20B] & 0x3F) == 0)
        func_0030F450(p);
    else
        func_0030F560(p);
}

void func_0030F700(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = (&D_004C1668)[(s8)p[0x4DD] * 2];
    p[0x1B7] = (&D_004C1669)[(s8)p[0x4DD] * 2];
    func_00186A60(p, 0x15);
}

void func_0030F750(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = (&D_004C1670)[(s8)p[0x4DD] * 2];
    p[0x1B7] = (&D_004C1671)[(s8)p[0x4DD] * 2];
    func_00186A60(p, 0x15);
}

void func_003111F0(u8 *p)
{
    func_00183D90(p);
    func_00175700(p);
    if (S(p, 0x1C)-- == 0) {
        p[6]++;
        func_001757E0(p, 0xA, 3);
    }
}

void func_00312210(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        q[6] = 0;
        p[5]++;
    }
}

void func_003131A0(u8 *p, u8 *q)
{
    if (!q[8])
        func_00176160(p, 0, p[0x25] * 6 + 0x29, 1);
}

void func_00314EF0(u8 *p)
{
    func_00313120(p);
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}

void func_00318230(u8 *p)
{
    func_003182F0(p);
    p[6]++;
    func_001757E0(p, 0x12, 1);
    func_00175C00(p, 0);
}


