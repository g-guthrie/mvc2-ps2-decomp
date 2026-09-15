typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_00175700();
extern void func_001757E0(u8 *, s32, s32);
extern void func_00183D10(u8 *);
extern void func_00183D50(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00185490(u8 *);
extern void func_00186A20(u8 *);
extern void func_00178F20();
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);

extern void func_00234580(u8 *);
extern void func_002345E0(u8 *);
extern s32 func_0023F4C0(u8 *);
extern s32 func_0023F520(u8 *);
extern void func_0022E7E0(u8 *);
extern void func_0022EB50(u8 *);

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern u8 D_004D18A0;

void func_002221E0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 2) {
        p[6]++;
        p[0x1e6] ^= 1;
    }
}

void func_00224560(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        *(s16 *)(p + 0x140) = p[0x1e6];
    }
}

void func_00228AF0(u8 *p)
{
    if (!*(s8 *)(p + 0x151)) {
        p[6]++;
        func_00186A20(p);
    }
    func_00175700(p);
}

void func_0022C5D0(u8 *p)
{
    if (p[0x20d] == 2)
        func_00184540(p);
    else {
        *(s32 *)(p + 0x5c) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6c) = 0;
        func_001843A0(p);
    }
}

void func_0022A250(u8 *p)
{
    *(s32 *)(p + 0x2dc) = 4;
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 0x2dc) = 0;
        func_0022C5D0(p);
    }
}

void func_00230AA0(u8 *p)
{
    p[0x40c] = 2;
    p[0x33c] = 5;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_0022C6B0(u8 *p)
{
    func_00183D50(p);
    if (p[0x216] == 0x80) {
        D_004F1F45 = 1;
        D_004F1F46 = 1;
    }
}

void func_0022F190(u8 *p)
{
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6c) = 0;
    p[0x20d] = 0;
    p[0x210] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_00185490(p);
    func_00183D10(p);
}

void func_00234530(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (!p[0x212])
        func_00234580(p);
    else
        func_002345E0(p);
}

s32 func_0023F480(u8 *p)
{
    if (func_0023F4C0(p))
        return 1;
    return func_0023F520(p) != 0;
}

void func_0022E8C0(u8 *p)
{
    if (D_004D18A0 < 2)
        p[0x13c] = 0;
    else {
        p[7]++;
        p[0x13c] = 1;
        func_0022E7E0(p);
    }
}

void func_0022EBD0(u8 *p)
{
    if (D_004D18A0 != 2)
        func_00175700(p);
    else {
        p[7]++;
        func_0022EB50(p);
    }
}

void func_00239C80(u8 *p, u8 *q)
{
    if (!p[6])
        p[0x208] = 2;
    func_00178F20(q, p);
}

void func_0022A780(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 0x1c) <= 0) {
        (*(u8 **)(p + 0x220))[0x201] = 0x30;
        func_0022C5D0(p);
    }
}

void func_00231800(u8 *p)
{
    p[7]++;
    p[0x20d] = 2;
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = 0x424db6db;
    *(s32 *)(p + 0x6c) = 0xbf4db6db;
    func_001757E0(p, 0x16, 6);
}
