typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G;
extern G *D_004C2794;
typedef struct { f32 f[4]; } F4;
extern F4 D_00444240[1];
extern s32 D_004C27FC;
extern void D_0014C0D0();
typedef struct { f32 x, y, z; } V3;
typedef struct { u32 a, b, c; } W3;
typedef struct { u8 pad[0x5B8]; } Big;
extern V3 D_0043FFF0[];
extern W3 D_00440010[];
extern Big D_004F20B0[];
extern s32 D_004C2830;

void func_002849E0(u8 *a, u8 *b)
{
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00383B80(u8 *, s32, s32);
    a[6]++;
    a[0x1B5] = 0x4D;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_0018C4B0(a, 7);
    func_00185490(a);
    b[5] = 0xF;
    if (a[0x20D] == 2) {
        *(f32 *)(a + 0x5C) /= 16.0f;
        *(f32 *)(a + 0x60) /= 8.0f;
        *(f32 *)(a + 0x6C) /= 64.0f;
        *(s32 *)(a + 0x68) = 0;
        a[0x168] = a[0x1B7] ? 0xF : 0xD;
    } else {
        a[0x20D] = 0;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        a[0x168] = a[0x1B7] ? 9 : 7;
        func_00183D10(a);
    }
    func_001757E0(a, 0x15, a[0x168]);
    *(s16 *)(a + 0x1C) = *(s8 *)(a + 0x151);
    *(s16 *)(a + 0x1E) = 0x3C;
    func_00383B80(a, 4, 3);
}

void func_001F5A70(u8 *p)
{
    extern void func_001F0420(u8 *);
    extern void func_001757E0(u8 *, s32, s32);

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 16;
    }
    p[6]++;
    func_001F0420(p);
    p[0x1B5] = 40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 21, 11);
}

void func_001F5FA0(u8 *p)
{
    extern void func_00175C00(u8 *, u32);
    extern void func_001757E0(u8 *, s32, s32);

    func_00175C00(p, 0);
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0x4162AAAA;
    *(u32 *)(p + 0x68) = 0x3F555555;
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 54;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 21, 6);
}

void func_002174F0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern void func_0019B110(u8 *, s32);
    extern void func_001855D0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_001864a0(u8 *);
    extern void func_001865B0(u8 *);
    switch (p[0x1FC]) {
    case 0:
    case 2:
        if (func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_0019B110(p, 4);
        }
        break;
    case 1:
        if (func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0 && ((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x200) && p[0x210] != 0) {
            *(u16 *)(p + 0x366) = 0;
            p[0x1B5] = 0x1D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            func_001855D0(p);
            func_001E3210(p, 0x1F);
            func_001757E0(p, 0xB, 4);
        }
        break;
    }
    if (func_001864a0(p) != 0) {
        func_001865B0(p);
    }
}

void func_0014CE20(u8 **a, s32 idx)
{
    extern u8 *func_003DA750(s32, s32, s32);
    F4 v;
    u8 *o;
    f32 x;
    v = D_00444240[0];
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = D_0014C0D0;
        *(s16 *)(o + 0xCC) = 0xA4;
        *(s32 *)(o + 0x84) = D_004C27FC;
        *(s32 *)(o + 0xD0) = 1;
        x = v.f[idx];
        *(f32 *)(o + 0x34) = x;
        *(s32 *)(o + 0x38) = 0;
        *(u32 *)(o + 0x3C) = 0xC1500000;
        a[0] = o;
        if ((o = func_003DA750(0, 0xD, 1)) != 0) {
            o[0x13C] = 0;
            *(void **)(o + 0x10) = D_0014C0D0;
            *(s16 *)(o + 0xCC) = 0xA5;
            *(s32 *)(o + 0x84) = D_004C27FC;
            o[0x20] = idx;
            *(s32 *)(o + 0xD0) = 1;
            *(f32 *)(o + 0x34) = x;
            *(u32 *)(o + 0x38) = 0x3F800000;
            *(u32 *)(o + 0x3C) = 0xC14E147B;
            a[1] = o;
        }
    }
}

void func_00139EE0(u8 *p)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0013A210();
    extern void func_0013A610(u8 *);
    extern void func_0013A4A0(u8 *, s32);
    extern void func_001E3CE0(u8);
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0013A210;
        *(u8 **)(o + 0x18) = p;
        *(Big **)(o + 0x14) = &D_004F20B0[*(s8 *)(p + 0x538) + *(s16 *)(p + 0x1E) * 2];
        o[0x20] = *(s8 *)(p + 0x538);
        o[0x21] = *(s8 *)(p + 0x1E);
        if (o[0x20] != 0) {
            *(s16 *)(o + 0xCC) = 0x69;
            *(s32 *)(o + 0x84) = D_004C2830;
        } else {
            *(s16 *)(o + 0xCC) = 0x62;
            *(s32 *)(o + 0x84) = D_004C2830;
        }
        *(V3 *)(o + 0x34) = D_0043FFF0[o[0x20]];
        *(u32 *)(o + 0x40) = D_00440010[o[0x20]].a;
        *(u32 *)(o + 0x44) = D_00440010[o[0x20]].b;
        *(u32 *)(o + 0x48) = D_00440010[o[0x20]].c;
        *(s32 *)(o + 0xD0) = 0x80F;
        func_0013A610(o);
        func_0013A4A0(o, 0);
        func_001E3CE0(o[0x20] + 0x4C);
    }
}

void func_001F4590(u8 *p)
{
    extern void func_001F0420(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001906C0(u8 *, s16, u8, u8);

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 16;
    }
    p[6]++;
    func_001F0420(p);
    func_001757E0(p, 15, 53);
    func_001906C0(p, 10, 60, 60);
}

extern void func_0018C4B0(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_001F9A40(u8 *);

void func_001F9990(u8 *p)
{
    p[6]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = p[0x1B7] ? 50 : 51;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(s16 *)(p + 0x1C) = 0;
    func_001757E0(p, 21, (u8)(p[0x1B7] + 6));
    func_001F9A40(p);
}

void func_001FFAE0(u8 *p)
{
    extern void func_00175C00(u8 *, u32);
    extern void func_001FED30(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_001933B0(u8 *);
    extern void func_001FFBA0(u8 *);

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 16;
    }
    func_00175C00(p, 0);
    p[6]++;
    p[0x1B5] = 69;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001FED30(p);
    func_00183D10(p);
    *(s16 *)(p + 0x1C) = 114;
    func_001933B0(p);
    func_001757E0(p, 22, 25);
    func_001FFBA0(p);
}

void func_001FA450(u8 *p)
{
    extern void func_001F9490(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_00185490(u8 *);
    extern void func_001FA520(u8 *);

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 16;
    }
    p[6]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001F9490(p);
    func_00183D10(p);
    p[0x1B5] = 60;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_00185490(p);
    p[0x20] = 120;
    *(s16 *)(p + 0x1C) = 0;
    func_001757E0(p, 22, 0);
    func_001FA520(p);
}

void func_001F9630(u8 *p)
{
    extern void func_001F9490(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_00185490(u8 *);
    extern void func_001F9720(u8 *);

    p[6]++;
    func_001F9490(p);
    func_00183D10(p);
    if (p[0x269] == 3) {
        p[0x1B5] = 61;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        p[0x1B5] = p[0x1B7] ? 50 : 51;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_0018C4B0(p, 5);
    }
    func_00185490(p);
    func_001757E0(p, 21, (u8)(p[0x1B7] + 2));
    func_001F9720(p);
}

extern void func_001F9490(u8 *);
extern void func_00183D10(u8 *);
extern void func_00347AA0(u8 *);

void func_001F9D10(u8 *p)
{
    p[6]++;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 16;
    }
    func_001F9490(p);
    p[0x1B5] = 53;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(s16 *)(p + 0x1C) = 0;
    if (p[0x1E6])
        *(u32 *)(p + 0x5C) = 0x41055555;
    else
        *(u32 *)(p + 0x5C) = 0xC1055555;
    func_00183D10(p);
    func_00347AA0(p);
    func_001757E0(p, 22, 1);
}
