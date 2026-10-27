typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_004F1F4C[], D_004F1F58[], D_004F1F94[], D_004F1FA0[];
extern u8 D_004F1F48;
extern void func_001234D0(u8);
extern int func_00175700(u8 *);
extern int func_00175670(u8 *, u8 *);
static void func_0019EA00(u8 *a0, u8 *owner_unused) {
    u8 *v1 = *(u8 **)(a0 + 20);
    *(s16 *)(a0 + 320) = *(s16 *)(v1 + 320);
    *(s8 *)(a0 + 49) = -2;
    *(f32 *)(a0 + 52) = *(f32 *)(v1 + 52);
    *(f32 *)(a0 + 56) = *(f32 *)(v1 + 56);
}
extern void func_0019F3A0(u8 *, u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_0034B040(u8 *);
extern void *func_00346A60(u8 *);
extern void func_001843A0(u8 *);
extern void *func_003DA750(void *, int, int);
extern void func_001CCD40();
extern void func_001BAE90();
extern void func_0018C6E0(void *);
extern u32 D_0045BCF0[];
extern void func_00176160(u8 *, int, int, int);
extern void func_0039FD10(u8 *);
extern void func_003A00F0(u8 *, u8 *);
extern void func_00212DE0(u8 *, u8 *);
extern void func_0015B200(u8 *, u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_001A60D0(u8 *, u8 *);
extern void func_001A6A70(u8 *);
extern void func_001A6940(u8 *, u8 *);
extern void func_001A6350(u8 *, u8 *);
extern void func_001A62B0(u8 *, u8 *);
extern u8 D_0044B3D0[];
extern int func_00416730(u8 *);
extern int func_004166B0(u8 *);
extern void func_0015D010(u8 *, u32 *);
extern void func_00179160(u8 *, u8 *);
extern void func_003C4A20(u8 *);
extern void func_00390CB0(u8 *, u8 *);
extern void func_00391620(u8 *, u8 *);
extern void func_001830D0(u8 *, u32 *, int);
extern void func_00299500(u8 *);

extern f32 func_00119C90(double);

void func_0019EAA0(u8 *p, u8 *q)
{
    func_0019EA00(p, q);
    if ((s8)func_00175700(p) < 0) {
        p[5] = 0;
        p[0x13C] = 0;
    } else {
        func_0019F3A0(p, q);
    }
}

void func_0020FE60(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC1AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
}

void func_001BEB60(u8 *p, u8 *q)
{
    if ((s8)func_00175670(p, q) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        {
            u8 *a = q + 0x2B8;
            t = q[0x2BB];
            if (t)
                a[3] = t - 1;
        }
    }
}

void func_0034AE40(u8 *p)
{
    func_0034B040(p);
    if ((s8)func_00175700(p) < 0) {
        *(s16 *)(p + 0x140) ^= 1;
        {
            u32 t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x16, 0x18);
        }
    }
}

void func_001F5950(u8 *p)
{
    u8 *q = p + 0x2B8;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t;
        *(s8 *)(p + 0x151) = 0;
        t = p[6];
        p[6] = t + 1;
        q[3] = 0;
        if (!func_00346A60(p))
            func_001843A0(p);
    }
}

void func_001BAE10(u8 *a, u8 *b, u8 c)
{
    u8 *r = func_003DA750(0, 4, 0);
    if (r) {
        *(u32 *)(r + 0x10) = (u32)func_001BAE90;
        *(u32 *)(r + 0x18) = (u32)b;
        *(u32 *)(r + 0x14) = (u32)a;
        *(s16 *)(r + 0x26) = 0x1700;
        r[1] = b[1];
        r[0x23] = c;
    }
}

void func_00212630(u8 *p, u8 *q)
{
    q[4] = 0xFF;
    func_00212DE0(p, q);
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t = p[6];
            p[6] = t + 1;
            q[1] = 0;
            *(s16 *)(p + 0x1C) = 8;
        }
    }
}

void func_003B24E0(u8 *p, u8 *owner_unused)
{
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[5]++;
            func_0015B200(p, p + 0x34, 1, 8);
            func_001E3710(p, 0x49);
            *(s16 *)(p + 0x1C) = 10;
        }
    }
}

void func_001A5E90(u8 *p, u8 *q)
{
    u32 t;
    func_001A60D0(p, q);
    t = p[4];
    p[4] = t + 1;
    p[5] = 0;
    *(u8 **)(p + 0x1C4) = D_0044B3D0;
    func_001A6A70(p);
    func_001A6940(p, q);
    func_001A6350(p, q);
    func_001A62B0(p, q);
}

void func_001E6B00(s32 *a, u8 *b)
{
    a[0] = 0;
    a[1] = *(u16 *)(*(u8 **)(b + 8) + 0x14);
    a[2] = *(u16 *)(*(u8 **)(b + 8) + 0x16);
    a[4] = *(s32 *)(b + 0x10);
    a[3] = func_00416730(b);
    a[5] = func_004166B0(b) >> 3;
    a[0x12] = *(s32 *)(b + 0x14);
}

void func_00221710(u8 *p)
{
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 1, 9);
    }
}

void func_00322140(u8 *p, u8 *q)
{
    u32 v[3];
    p[0x151] = 2;
    v[0] = 0xC1D55555;
    v[1] = 0x42892492;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_00179160(p, q);
}

void func_002F6200(u8 *p)
{
    s32 v;
    func_0018C6E0(p);
    v = *(s8 *)(p + 0x140) ^ 1;
    (*(u8 **)(p + 0x1DC))[0x1E6] = v;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = (u8)v;
    p[0x1B4] = 10;
    ((void (*)(u8 *))D_0045BCF0[p[0x20B] & 0x3F])(p);
}

void func_00357830(u8 *p)
{
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v < 0) {
        s32 t;
        *(s16 *)(p + 0x1E) = 1;
        t = *(s32 *)(p + 0xD0) + 1;
        *(s32 *)(p + 0xD0) = t;
        if (t > 3)
            *(s32 *)(p + 0xD0) = 0;
        func_00176160(p, 2, *(s32 *)(p + 0xD0) + (p[0x25] << 2), 1);
    }
}

void func_003C4910(u8 *a, u8 b, u8 c)
{
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void (**)(u8 *))(r + 0x10) = func_003C4A20;
        r[0x20] = b;
        r[0x21] = c;
        *(u8 **)(r + 0x18) = a;
        r[1] = a[1];
        *(s16 *)(r + 0x26) = r[0x20] | 0x3800;
        *(u16 *)(r + 0xD8) = *(u16 *)(a + 0x168);
    }
}

void func_003914C0(u8 *p, u8 *q)
{
    if (*(s32 *)(p + 0xD0) == 0) {
        s16 v;
        func_00175700(p);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0)
            return;
    }
    func_00390CB0(p, q);
    p[4]++;
    p[5] = 0;
    func_00391620(p, q);
}

void func_0029D740(u8 *p)
{
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    {
        u8 x;
        if (p[0x269] == 6)
            x = 2;
        else
            x = 0;
        p[0x405] = x;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    p[0x404] = 0;
    p[0x405] = 0;
    v[1] = 0x4322DB6D;
    v[0] = 0;
    v[2] = 0;
    func_001830D0(p, v, 1);
}

void func_00299480(u8 *p)
{
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x68);
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x68) * *(f32 *)(p + 0x5C) > 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        *a = 0.0f;
        *b = 0.0f;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
    func_00299500(p);
}

void func_00135FF0(u8 *p)
{
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 12;
        *(f32 *)(p + 0x64) = func_00119C90(-(double)*(f32 *)(p + 0x3C) / 12.0);
    }
}

void func_001233B0(void)
{
    *D_004F1F58 = *D_004F1F4C;
    *D_004F1FA0 = *D_004F1F94;
    func_001234D0(D_004F1F48);
}

void func_003A0070(u8 *p, u8 *q)
{
    if (p[1] == q[1] && !*(s8 *)(p + 0x1B2)) {
        if ((s8)func_00175700(p) < 0)
            func_0039FD10(p);
        else
            return;
    }
    func_003A00F0(p, q);
}
