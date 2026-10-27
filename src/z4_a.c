typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G4;

typedef struct { f32 x, y, z; } V3;
extern G4 *D_004C2794;
extern u8 *D_004C2840;
extern u16 D_00456810[];
extern u8 D_004D18E6[];
extern s8 D_004D1900[];
extern V3 D_00444BA0[];
extern u8 D_00458A40[], D_00458A50[], D_00458AE0[], D_00458AF0[];
extern u32 D_004C0318, D_004C031C, D_004C0320;
extern void (*D_004522D0[])(u8 *, u8 *);
typedef struct { s16 pad0; s16 pad2; s16 f4; s16 f6; s16 f8; s16 fa; } S1800;
extern S1800 D_004D1800[];
extern s16 D_004D1806[];
extern u8 *D_00446A60[];
extern s16 D_004F25D2[];
extern s16 D_004F2B8A[];
extern u16 D_004F4480[];
extern u16 D_004F4494[];

void func_0023DF90(u8 *p, u8 *context)
{
    extern void func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *a, *b, *c, *d;
    func_00175700(p);
    a = (u32 *)(p + 0x5C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    d = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x20D] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183d50(p);
        p[0x169] = 0x16;
        p[0x168] = 5;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}

void func_002449F0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    u8 k = p[0x1FC];
    switch (k) {
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    default:
        break;
    }
}

void func_002B0E80(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00395990(u8 *, s32);
    extern void func_001830D0(u8 *, f32 *, s32, s32);
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 2) {
        s8 t = *(s8 *)(p + 0x151);
        *(s8 *)(p + 0x151) = t & ~2;
        func_00395990(p, 4);
    }
    if (*(s8 *)(p + 0x151) & 1) {
        u32 u;
        *(s8 *)(p + 0x151) &= ~1;
        u = p[6];
        p[6] = u + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        *(u32 *)&v[0] = 0x41555555;
        *(u32 *)&v[1] = 0x42F44924;
        v[2] = 0;
        func_001830D0(p, v, 1, u + 1);
    }
}

void func_00219BD0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00183D90(void);
    extern void func_001757E0(u8 *, s32, s32);
    f32 z = 0.0f;
    if (!(z == *(f32 *)(p + 0x5C))) {
        if (*(u32 *)(D_004C2840 + 0x1C) & 1)
            func_00183D90();
        p[0x206] = 3;
    }
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        p[0x206] = 0;
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x68) = z;
    }
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x29));
    }
}

void func_00136480(u8 *p)
{
    extern void func_00136560(u8 *);
    s32 c;
    u8 *q;
    if (p[0x21] == 0)
        return;
    {
        s8 f = *(s8 *)(D_004C2840 + 0x18);
        if (((f & 1) && (D_004F4480[0] & 0x360)) || ((f & 2) && (D_004F4494[0] & 0x360))) {
            if (*(s16 *)(p + 0x1E) >= 0x1E)
                *(s16 *)(p + 0x1E) = 0x1E;
        }
    }
    {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v > 0)
            return;
    }
    c = 1;
    if (*(u32 *)(p + 0x14) != 0) {
        do {
            q = *(u8 **)(p + 0xC);
            if (*(u32 *)(q + 0x14) == 0)
                c = 0;
            func_00136560(q);
        } while (c != 0);
    }
    func_00136560(p);
}

void func_003AB180(u8 *p, u8 *q)
{
    extern s32 func_00185980(u8 *);
    extern void func_003AADA0(u8 *, u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00185870(u8 *, s32);
    extern s32 func_003AD600(u8 *);
    extern void func_003AB270(u8 *, u8 *);
    u8 *o;
    s32 r;
    o = *(u8 **)(p + 0x18);
    r = *(s32 *)(o + 0x1C4);
    if (!func_00185980(o)) {
        if (!func_00185980(p)) {
            func_003AADA0(p, q);
            return;
        }
        r = *(s32 *)(p + 0x1C4);
    }
    o[0x1B0] = 0;
    o[6] = 5;
    p[5] = 3;
    *(s16 *)(p + 0x1C) = 0x2D;
    func_001266A0(o, 0xD, 5);
    o[0x1B1] = 0;
    o[0x201] = 3;
    o[0x206] = 3;
    o[0x20B] = 0xC0;
    if (o[0x1FD] == 10)
        o[0x20B] = 0xC0;
    func_00185870(p, r);
    *(s32 *)(q + 0x28) = func_003AD600(o);
    func_003AB270(p, q);
}

void func_00170FD0(void)
{
    S1800 *g;
    if (*(s8 *)(D_004C2840 + 0x8F) != 0)
        return;
    g = D_004D1800;
    {
        s16 t = D_004D1806[0] - 1;
        D_004D1806[0] = t;
        if (t >= 0)
            return;
    }
    g->f6 = 0x3B;
    g->f4 = g->f4 + 1;
    {
        s16 w = g->f8 + 1;
        g->f8 = w;
        if (w < 5)
            return;
    }
    g->f8 = 0;
    if (g->f4 < 0xA0)
        g->fa = (g->fa + 1) & 0x1F;
    {
        u8 *t = D_00446A60[*(s8 *)(D_004C2840 + 0x29)];
        D_004F25D2[0] = D_004F25D2[0] + t[g->fa];
        D_004F2B8A[0] = D_004F2B8A[0] + t[g->fa];
    }
}

void func_0020DBE0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *a, *b, *c, *d;
    d = (u32 *)(p + 0x6C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    a = (u32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x1B);
    }
}

void func_0024B8C0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00184540(u8 *);
    f32 z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430))
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    if (z == *(f32 *)(p + 0x5C) || !(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= z)) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
    }
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001E3210(p, 0x2B);
        func_00184540(p);
    }
}

void func_002CE0D0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_002CDEB0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x150) != 0) {
        *(s8 *)(p + 0x150) = 0;
        {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v <= 0) {
                u32 t = p[6];
                p[6] = t + 1;
                if (*(s8 *)(p + 0x1B2) != 0) {
                    p[0x1B5] = 0x57;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(u32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                    func_001757E0(p, 0x15, 0x19);
                    return;
                }
            }
        }
    }
    func_00175700(p);
    func_002CDEB0(p);
}

void func_00244090(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(u32 **)(p + 0x408) = &D_004C0318;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(u32 **)(p + 0x408) = &D_004C031C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(u32 **)(p + 0x408) = &D_004C0320;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}

void func_0023CC40(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *a, *b, *c, *d;
    d = (u32 *)(p + 0x6C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    a = (u32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) >= 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        p[0x210] = 2;
        p[0x169] = 0x15;
        p[0x168] = 0xC;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}

void func_003AE160(u8 *p)
{
    extern void func_00175700(u8 *);
    u8 *a1 = *(u8 **)(p + 0xD0);
    u8 *a2 = *(u8 **)(p + 0x18);
    u8 *a3 = *(u8 **)(p + 0x14);
    p[0x13C] = 0;
    *(s8 *)(p + 0x24) = *(s8 *)(a3 + 0x24);
    if (a1[5] != 0 || a1[0x1E4] != 0x15 || a3[5] != 5) {
        u32 t = p[4];
        p[4] = t + 1;
        return;
    }
    if (**(s16 **)(p + 0xD4) == 2) {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            return;
        }
        a2 = *(u8 **)(a2 + 0xC);
        *(u8 **)(p + 0x18) = a2;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(a2 + 0x34);
    if (*(u32 *)(D_004C2840 + 0x1C) & 1) {
        func_00175700(p);
        p[0x13C] = 1;
    }
}

void func_00288EE0(u8 *p)
{
    extern s32 func_00174170(void);
    if ((*(u16 *)(p + 0x4F0) & 0x3F0) != 0) {
        p[0x20] = 5;
        if (*(u16 *)(p + 0x4F0) & 0x100)
            p[0x20] = 6;
        if (*(u16 *)(p + 0x4F0) & 0x80)
            p[0x20] = 7;
        if (*(u16 *)(p + 0x4F0) & 0x40)
            p[0x20] = 8;
        if (*(u16 *)(p + 0x4F0) & 0x20)
            p[0x20] = 9;
        if (*(u16 *)(p + 0x4F0) & 0x10)
            p[0x20] = 0xA;
    } else {
        p[0x20] = ((u8 *)D_00456810)[(func_00174170() & 0xF) << 1];
    }
    if (D_004D18E6[0] == 0) {
        u8 t = p[0x20];
        if (t == 6 || t == 9 || t == 0xA)
            p[0x20] = 5;
    }
}

void func_00156650(V3 *v, s32 b, s32 flag, s32 c, s32 e)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00156750(void);
    extern void func_001567A0(u8 *, s32);
    extern void func_001568A0(u8 *, s32);
    extern void func_001569C0(u8 *, s32);
    extern void func_00156AD0(u8 *, s32);
    u8 *o;
    if ((o = func_003DA750(0, e, 1)) != 0) {
        D_004D1900[0] = D_004D1900[0] + 1;
        o[0x13C] = 0;
        *(void (**)(void))(o + 0x10) = func_00156750;
        *(V3 *)(o + 0x34) = *v;
        *(s32 *)(o + 0xD0) = 0x181;
        if (flag == 1) {
            *(s32 *)(o + 0xD0) |= 0x10;
            *(V3 *)(o + 0x50) = D_00444BA0[0];
        }
        func_001567A0(o, e);
        func_001568A0(o, e);
        func_001569C0(o, e);
        func_00156AD0(o, e);
    }
}

void func_00156520(V3 *v, s32 unused, s32 flag, s32 c, s32 e)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00156750(u8 *);
    extern void func_001567A0(u8 *, s32);
    extern void func_001568A0(u8 *, s32);
    extern void func_001569C0(u8 *, s32);
    extern void func_00156AD0(u8 *, s32);
    extern void func_001550D0(V3 *, s32, s32, s32);
    u8 *o;
    if ((o = func_003DA750(0, e, 1)) != 0) {
        D_004D1900[0] = D_004D1900[0] + 1;
        o[0x13C] = 0;
        *(void (**)(u8 *))(o + 0x10) = func_00156750;
        *(V3 *)(o + 0x34) = *v;
        *(s32 *)(o + 0xD0) = 0x800181;
        if (flag == 1) {
            *(s32 *)(o + 0xD0) |= 0x10;
            *(V3 *)(o + 0x50) = D_00444BA0[0];
        }
        func_001567A0(o, e);
        func_001568A0(o, e);
        func_001569C0(o, e);
        func_00156AD0(o, e);
        func_001550D0(v, flag, c, e);
    }
}
