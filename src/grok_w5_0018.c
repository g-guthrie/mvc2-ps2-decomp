typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_001E3A70(u8 *);
extern void func_00154390(f32 *, s32);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern int func_00186CE0(u8 *, s32);
extern void func_0018A920(u8 *, u8 *);
extern void func_0018D6F0(u8 *, s32, void *);
extern void func_00163930(f32 *, s16);
extern void func_001E3710(u8 *, s32);
extern int func_0018BF90(u8 *, u8 *);
extern void func_0018D660(u8 *, u8 *);
extern void func_0018C8A0(u8 *);
extern void func_0018E810(u8 *, u8 *);
extern void func_0018E6C0(u8 *);
extern void func_0018C970(u8 *);

extern u8 D_004D18A1;
extern void (*D_00448E30[])(u8 *);

void func_00183D50(u8 *p)
{
    f32 t[3];
    t[0] = *(f32 *)(p + 0x34);
    t[1] = *(f32 *)(p + 0x430);
    t[2] = *(f32 *)(p + 0x3C);
    func_001E3A70(p);
    func_00154390(t, 0);
}

void func_00180DD0(u8 *p)
{
    void (*cb)(u8 *) = *(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x5C);
    if (!cb)
        func_0011D8F8(p + 0x2B8, 0, 0x80);
    else
        cb(p);
}

void func_001870C0(u8 *p)
{
    p[0x20D] = 0;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_00185490(p);
    func_001757E0(p, 4, 0);
}

void func_00187110(u8 *p)
{
    p[0x20D] = 1;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_00185490(p);
    func_001757E0(p, 4, 1);
}

int func_001846D0(u8 *p, s32 a1)
{
    u16 v;
    if (a1)
        v = *(u16 *)(p + 0x35C);
    else
        v = *(u16 *)(p + 0x354);
    if (!(v & 0xC00))
        return 0;
    func_00186CE0(p, 1);
    return 1;
}

int func_00189390(u8 *p, u8 *a1, u8 *a2)
{
    a2[2] = 0;
    if ((*(u16 *)(p + 0x35E) & 0x3C00) == *(u16 *)(a1 + 8)) {
        func_0018A920(p, a2);
        a2[0] = 1;
        a2[2] = 1;
    }
    return 0;
}

int func_00189F60(u8 *p, u8 *a1, u8 *a2)
{
    a2[2] = 0;
    if ((*(u16 *)(p + 0x362) & 0x3F60) == *(u16 *)(a1 + 8)) {
        func_0018A920(p, a2);
        a2[0] = 1;
        a2[2] = 1;
    }
    return 0;
}

void func_0018D620(u8 *p, s32 a1)
{
    f32 buf[4];
    func_0018D6F0(p, a1, buf);
    func_00163930(buf, *(s16 *)(p + 0x140));
    func_001E3710(p, 0x3F);
}

void func_00187A20(u8 *p)
{
    p[0x268] = 0;
    if (!(D_004D18A1 & 4) && !p[0x425])
        ((void (*)(u8 *))(*(u32 *)(*(u8 **)(p + 0x43C) + 4)))(p);
}

int func_00185010(u8 *p)
{
    if ((*(s8 **)(p + 0x1DC))[0x1B4])
        return 0;
    D_00448E30[p[7]](p);
}

int func_0018BEE0(u8 *p, u8 *q)
{
    if (func_0018BF90(p, q))
        return 0;
    func_0018D660(p, q);
    return 1;
}

void func_0018DA70(u8 *p, u8 *q)
{
    p[0x247] = 0;
    p[0x248] = 0;
    func_0018C8A0(p);
    func_0018E810(p, q);
    func_0018E6C0(p);
}

int func_00186030(u8 *p)
{
    if (p[0x20D] == 2)
        return 0;
    if (!(*(u16 *)(p + 0x354) & 0x1000))
        return 0;
    func_00186CE0(p, 5);
    return 1;
}

void func_0018D240(u8 *p)
{
    f32 saved = *(f32 *)(p + 0x68);
    func_0018C970(p);
    *(f32 *)(p + 0x2A4) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x2A8) = *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x68) = saved;
    p[0x296] = 5;
}
