typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern void func_00178F20();
extern void func_0011D8F8();
extern s32 func_00175700();
extern void func_001757E0();
extern void func_00175C00();
extern void func_00184540();
extern s32 func_00176160();
extern s32 func_002803A0();
extern void func_00299010();
extern void func_0029C1E0();
extern void func_0029C080();
extern void func_00289570();
extern void func_00290E30();
extern void func_00297D50();
extern void func_00297F90();
extern void func_0038A040();
extern u8 D_00455C90[];
extern u8 D_00456D80[];

void func_00285FF0(u8 *p)
{
    if ((p[0x20B] & 0x3F) != 2)
        func_00178F20(*(void **)(p + 0x1DC), p);
}

void func_0028D9F0(u8 *p)
{
    u8 *q = p + 0x2B8;
    u8 v = *q;
    func_0011D8F8(p + 0x2B8, 0, 0x80);
    *q = v;
}

void func_00294D00(u8 *p)
{
    u8 *q = p + 0x2B8;
    u8 v = *q;
    func_0011D8F8(p + 0x2B8, 0, 0x80);
    *q = v;
}

s32 func_00280350(u8 *p, s32 flag)
{
    if (((flag ? H(p, 0x35C) : H(p, 0x354)) & 0xC00) == 0)
        return 0;
    func_002803A0(p, 1);
    return 1;
}

void func_00299230(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[6]++;
    func_001757E0(p, 0x16, 7);
    func_00299010(p);
}

void func_0029C030(u8 *p)
{
    func_00175C00(p, 0);
    if (p[0x212] == 1)
        func_0029C1E0(p);
    else
        func_0029C080(p);
}

void func_0028C320(u8 *p)
{
    func_00289570(p);
    if ((s8)func_00175700() < 0) {
        I(p, 0x60) = 0;
        I(p, 0x6C) = 0;
        func_00184540(p);
    }
}

void func_002911B0(u8 *p)
{
    func_00290E30(p);
    if ((s8)func_00175700() < 0) {
        I(p, 0x60) = 0;
        I(p, 0x6C) = 0;
        func_00184540(p);
    }
}

void func_00293690(u8 *p)
{
    func_00290E30(p);
    if ((s8)func_00175700() < 0) {
        I(p, 0x60) = 0;
        I(p, 0x6C) = 0;
        func_00184540(p);
    }
}

void func_00297F20(u8 *p)
{
    func_00297D50(p);
    if ((s8)func_00175700() < 0) {
        I(p, 0x60) = 0;
        I(p, 0x6C) = 0;
        func_00184540(p);
    }
}

void func_0028D610(u8 *p)
{
    func_00289570(p);
    if ((s8)func_00175700() < 0)
        func_00184540(p);
}

void func_00294920(u8 *p)
{
    func_00290E30(p);
    if ((s8)func_00175700() < 0)
        func_00184540(p);
}

void func_00298320(u8 *p)
{
    func_00297F90(p);
    if ((s8)func_00175700() < 0)
        func_00184540(p);
}

s32 func_0028D910(u8 *p, s32 idx)
{
    u8 *t = D_00455C90 + (idx << 3);
    return func_00176160(p, t[1], t[2] + p[0x25] * 0x57, t[3]);
}

s32 func_00294C20(u8 *p, s32 idx)
{
    u8 *t = D_00456D80 + (idx << 3);
    return func_00176160(p, t[1], t[2] + p[0x25] * 0x57, t[3]);
}

void func_00290FD0(u8 *p)
{
    func_00175700(p);
    if (!*(s8 *)(p + 0x151)) {
        p[7]++;
        p[0x151] = 0;
        func_0038A040(p, p[0x1B7]);
    }
}


