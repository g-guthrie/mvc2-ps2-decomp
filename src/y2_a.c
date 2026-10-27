typedef struct SA37_J0 SA37_J0;
typedef struct SA37_R SA37_R;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_0020DF00(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        if (p[0x1E6] != 0) v = 13.33333301544f; else v = -13.33333301544f;
        *(f32 *)(p + 0x5C) = v;
        *(s32 *)(p + 0x68) = 0;
        *(s16 *)(p + 0x1C) = 0x18;
        func_001757E0(p, 0x16, 0x1E);
    }
}

void func_0023B720(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *a, *b;
    func_00175700(p);
    a = (s32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    b = (s32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38)) return;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *a = 0;
    *b = 0;
    func_001757E0(p, 2, 2);
    p[6]++;
}


void func_00321600(u8 *p, u8 *q)
{
    extern void func_00179160();
    extern void func_003216C0(u8 *, u8 *);
    V3 v;
    p[0x151] = 12;
    v = *(V3 *)(p + 0x34);
    func_00179160(p);
    *(f32 *)(p + 0x5C) = (*(f32 *)(p + 0x34) - v.x) / 16.0f;
    *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x38) - v.y) / 16.0f;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(V3 *)(p + 0x34) = v;
    *(s16 *)(p + 0x1C) = 16;
    func_003216C0(p, q);
}

void func_00228230(u8 *p)
{
    extern void func_00183D10();
    extern void func_0022C700(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern f32 D_004518F0[];
    extern f32 D_004518FC[];
    f32 a, b;
    p[6]++;
    func_00183D10(p);
    func_0022C700(p);
    func_0018C4B0(p, 5);
    a = *(f32 *)((u8 *)D_004518F0 + (p[0x1B7] << 3));
    b = 0.7291666269f;
    if (*(s16 *)(p + 0x140) != 0) { a = -a; b = -b; }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;
    *(f32 *)(p + 0x60) = *(f32 *)((u8 *)D_004518FC + (p[0x1B7] << 3));
    *(u32 *)(p + 0x6C) = 0xBF892492;
    func_001757E0(p, 0x15, (u8)((p[0x1B7] << 1) + 0x12));
}

void func_002BBCD0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    f32 a, b;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        p[0x20D] = 2;
        if (p[0x1E6] != 0) a = 33.33333206f; else a = -33.33333206f;
        *(f32 *)(p + 0x5C) = a;
        if (p[0x1E6] != 0) b = -2.083333254f; else b = 2.083333254f;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x60) = 0x422B6DB6;
        *(u32 *)(p + 0x6C) = 0xBFAB6DB6;
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2;
extern G2 *D_004C2794;

void func_002F3170(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001843A0(u8 *);
    u8 t = p[0x1FC];
    switch (t) {
    case 2:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            p[0x1B5] = 8;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_002136C0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001863F0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *s0, *s1;
    f32 z;
    func_00175700(p);
    s0 = (f32 *)(p + 0x5C);
    s1 = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    z = 0.0f;
    if (*(f32 *)(p + 0x60) <= z) {
        p[6]++;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *s0 = z;
        *s1 = z;
        func_001757E0(p, 0x14, 3);
    }
}

void func_003C7AC0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C76C0(u8 *, u8 *);
    u8 *r;
    f32 v;
    r = *(u8 **)(p + 0x14);
    if (r[5] != 2) {
        p[5] = 2;
        func_001757E0(p, 0x14, 0xF);
        v = 3.333333254f;
        *(u32 *)(p + 0x60) = 0x42700000;
        *(s32 *)(p + 0x6C) = 0;
        if (*(s16 *)(p + 0x140) != 0) v = -v;
        *(f32 *)(p + 0x5C) = v;
        func_003C76C0(p, q);
        return;
    }
    if (r[0x20A] != 0 && !(*(f32 *)(r + 0x38) < 411.4285583f)) {
        p[5] = 3;
        func_001757E0(p, 0x14, 0x14);
    }
}

void func_003C1630(u8 *p, u8 *q)
{
    extern void (*const jtbl_00475CE0[10])(u8 *, void *);
    u8 *r = (u8 *)((s32)q + 0x2B8);
    if (q[5] != 0) { p[4]++; return; }
    if (q[0x169] != 0x16) { p[4]++; return; }
    if (r[0xE] != 0) p[0x13C] = 0;
    jtbl_00475CE0[p[5] + 4](p, q);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
}

void func_002619E0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_001864a0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s0, *s1, *s2, *s3;
    func_00175700(p);
    s0 = (s32 *)(p + 0x5C);
    s2 = (s32 *)(p + 0x68);
    s1 = (s32 *)(p + 0x60);
    s3 = (s32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        p[6]++;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001757E0(p, 0x14, 1);
    }
}

void func_002B76F0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    s32 *s1, *s2, *s3, *s4;
    p[0x40C] = 2;
    p[0x33C] = 5;
    s1 = (s32 *)(p + 0x5C);
    s3 = (s32 *)(p + 0x68);
    s2 = (s32 *)(p + 0x60);
    s4 = (s32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        *s4 = 0;
        func_001843A0(p);
    }
}

extern s16 D_004C27A4;
s32 func_00348D60(u8 *p)
{
    extern u8 *func_003DA750();
    extern void func_00348F20();
    u8 *o, *q;
    if (D_004C27A4 < 2) return 0;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = func_00348F20;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = 3;
        o[0x21] = 0;
        *(s16 *)(o + 0x26) = 0x301;
    }
    if ((q = func_003DA750(o, 1, 2)) != 0 && o != 0) {
        *(void **)(q + 0x10) = func_00348F20;
        *(s32 *)(q + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(q + 0x14) = o;
        q[1] = p[1];
        q[0x20] = 4;
        q[0x21] = 0;
        *(s16 *)(q + 0x26) = 0x301;
        *(u8 **)(p + 0x14) = q;
    }
    return 0;
}

s32 func_00167620(u8 *p, u8 *q)
{
    extern s32 func_0016B250();
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(SA37_J0 *, SA37_R *, s32);
    u16 v;
    if (func_0016B250(p, 2) == 0) return 0;
    if (func_0016B360(p, q) == 0) return 0;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 0);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    v = (*(s32 *)(p + 0x4C8) != 0) ? 0x100 : 0x200;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    v |= ((*(s16 *)(p + 0x4C8) * 256) & 0x3C00);
    if ((v & 0xC00) != 0) v = v ^ (p[0x1E6] * 3 << 10);
    *(u16 *)(p + 0x4F0) = v;
    return 0;
}

void func_00234A30(u8 *p)
{
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s0, *s1, *s2, *s3;
    s3 = (s32 *)(p + 0x6C);
    s2 = (s32 *)(p + 0x68);
    s1 = (s32 *)(p + 0x60);
    s0 = (s32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_002C5CF0(u8 *p)
{
    extern void func_001757E0();
    extern void func_002CAFA0();
    u8 *a2 = (u8 *)((s32)p + 0x2B8);
    u8 *t;
    if (p[0x1B5] == 0x39 && *(s8 *)(p + 0x1B4) != 0 && *(s8 *)(p + 0x1B2) != 0 && p[5] == 0) {
        t = *(u8 **)(p + 0x1C4);
        if (t[3] == 0 && (t[0x1E4] == 0x12 || t[5] == 3)) {
            p[0x1B4] = 0;
            func_001757E0(p, 0x15, 9);
            return;
        }
    }
    if (p[0x215] != 0 && p[5] == 0) {
        s16 v = *(s16 *)(a2 + 0xA) - 1;
        *(s16 *)(a2 + 0xA) = v;
        if (v < 0) {
            if (p[0x1E4] != 0x15 && p[0x1E4] != 0x1D) func_002CAFA0(p);
        }
    }
}

void func_002705C0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *v1, *a0, *a1, *a2;
    f32 z;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    a1 = (f32 *)(p + 0x68);
    z = 0.0f;
    a0 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a2 = (f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *v1 = z;
        *a1 = z;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(s32 *)a0 = 0;
        *(s32 *)a2 = 0;
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 2, 3);
    }
}

void func_0020C9D0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s0, *s1, *s2, *s3;
    func_00175700(p);
    s0 = (s32 *)(p + 0x5C);
    s2 = (s32 *)(p + 0x68);
    s1 = (s32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    s3 = (s32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[7]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001757E0(p, 0x14, 0xD);
    }
}

void func_0029CDF0(u8 *p)
{
    extern void func_00175700();
    f32 a, b;
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        if (p[0x1E6] != 0) a = 4.166666508f; else a = -4.166666508f;
        *(f32 *)(p + 0x5C) = a;
        if (p[0x1E6] != 0) b = -0.2864583135f; else b = 0.2864583135f;
        *(f32 *)(p + 0x68) = b;
        p[6]++;
        *(s16 *)(p + 0x1C) = 8;
    }
}

void func_0029D060(u8 *p)
{
    extern s32 func_00175700();
    f32 a, b;
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        if (p[0x1E6] != 0) a = -4.166666508f; else a = 4.166666508f;
        *(f32 *)(p + 0x5C) = a;
        if (p[0x1E6] != 0) b = 0.2864583135f; else b = -0.2864583135f;
        *(f32 *)(p + 0x68) = b;
        p[6]++;
        *(s16 *)(p + 0x1C) = 8;
    }
}

void func_003715E0(u8 *p)
{
    extern void func_001757E0();
    extern void func_001E3210();
    extern void func_0036C0B0();
    extern void func_0036C050();
    extern void func_00175700();
    u8 *a2 = *(u8 **)(p + 0x18);
    if (a2[0x1E4] != 0x1D || a2[0x1FD] != 5) { p[5]++; return; }
    if (*(u8 *)(*(u8 **)(p + 0x14) + 5) >= 5) {
        p[5]++;
        func_001757E0(p, 0x17, 3);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (p[0x23] != 0) {
            func_001E3210(p, 0x20);
            func_0036C0B0(p, 0x12, 0);
        } else {
            func_001E3210(p, 0x20);
            func_0036C0B0(p, 0x12, 1);
        }
        func_0036C050(p, 0x14);
    }
    func_00175700(p);
}

u8 func_00185290(u8 *p)
{
    extern void func_0015D310(u8 *);
    extern void func_001917F0(u8 *, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00184540(u8 *);
    extern void func_00126400();
    extern s32 func_00186CE0(u8 *, s32);
    u8 *s0;
    s16 t;
    func_0015D310(p + 0x34);
    func_001917F0(p, 0, 0x700000);
    s0 = *(u8 **)(p + 0x1DC);
    p[0x1E6] = 0;
    if (!(*(f32 *)(s0 + 0x34) <= *(f32 *)(p + 0x34))) p[0x1E6] = 1;
    *(s16 *)(p + 0x140) = p[0x1E6];
    t = p[0x1E6] ^ 1;
    *(s16 *)(s0 + 0x140) = t;
    s0[0x1E6] = t;
    s0[5] = 0;
    s0[0x1E5] = s0[0x1E4];
    s0[6] = 0;
    *(s32 *)(s0 + 0x5C) = 0;
    *(s32 *)(s0 + 0x60) = 0;
    *(s32 *)(s0 + 0x68) = 0;
    *(s32 *)(s0 + 0x6C) = 0;
    *(u32 *)(s0 + 0x6C) = 0xBF4DB6DB;
    s0[0x1EA] = 0;
    func_00175C00(s0, 1);
    func_00184540(s0);
    func_00126400();
    p[5] = 0;
    p[0x201] = 4;
    p[0x20] = 0;
    return (u8)func_00186CE0(p, 0x1B);
}

void func_0024C710(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00183920(u8 *, u32 *);
    u32 v[3];
    u16 n;
    if ((s8)func_00175700(p) < 0) { func_001843A0(p); return; }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = 0xC2055555;
        v[1] = 0x42CDB6DB;
        func_00183920(p, v);
    }
    n = *(u16 *)(p + 0x160);
    if (n != 0) {
        if (*(s16 *)(p + 0x140) == 0) *(f32 *)(p + 0x34) += 1.666666627f * (f32)(s16)n;
        else *(f32 *)(p + 0x34) -= 1.666666627f * (f32)(s16)n;
        *(u16 *)(p + 0x160) = 0;
    }
}

void func_002DD930(u8 *p)
{
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s0, *s1, *s2, *s3;
    s3 = (s32 *)(p + 0x6C);
    s2 = (s32 *)(p + 0x68);
    s1 = (s32 *)(p + 0x60);
    s0 = (s32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001757E0(p, 2, 3);
    }
}
