typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001E1B70(u8 *p, u8 *q)
{
    extern s32 func_00174170();
    extern void func_001757E0();
    u32 r;
    f32 k, v;
    if (q[5] == 0 && q[0x1E4] == 0x1D) return 0;
    p[5] = 2;
    *(s16 *)(p + 0x140) ^= 1;
    r = ((func_00174170() & 7) + 4);
    v = (f32)r;
    k = 1.6666666f * v;
    if (*(s16 *)(p + 0x140) == 0) k = -k;
    *(f32 *)(p + 0x5C) = k;
    *(s32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x17, 0x2B);
    return 1;
}

typedef struct {
    u8 pad0[0x34]; f32 f34, f38, f3c; u8 pad1[0x1C]; f32 f5c, f60, f64, f68, f6c;
} S751a0;

void func_002751A0(S751a0 *p)
{
    extern void func_00175700();
    extern void func_001757E0();
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    {
        s16 v = *(s16 *)((u8 *)p + 0x1C) - 1;
        *(s16 *)((u8 *)p + 0x1C) = v;
        if (v == 0) {
            u32 t = *((u8 *)p + 6);
            f32 k;
            *((u8 *)p + 6) = t + 1;
            if (*((u8 *)p + 0x1E6) != 0) k = 0.2083333283662796f;
            else k = -0.2083333283662796f;
            p->f68 = k;
            *((u8 *)p + 0x168) = 3;
            func_001757E0(p, *((u8 *)p + 0x169), *((u8 *)p + 0x168));
        }
    }
}


typedef struct { f32 x, y, z; } V3_3aa;

void func_003AA2E0(u8 *p, s16 *a, s32 n)
{
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_003AA4D0(u8 *);
    s32 i = 0;
    u8 *o;
    if (0 < n) do {
        o = func_003DA750(p, 1, 2);
        *(void (**)(u8 *))(o + 0x10) = func_003AA4D0;
        i++;
        *(V3_3aa *)(o + 0x34) = *(V3_3aa *)(p + 0x34);
        o[0x20] = 1;
        *(u8 **)(o + 0x18) = p;
        *(s32 *)(o + 0x14) = *(s32 *)(p + 0x14);
        o[0x22] = p[0x22];
        *(s16 *)(o + 0x26) = 0x3001;
        *(s16 *)(o + 0x88) = a[0];
        *(s16 *)(o + 0x8A) = a[1];
        *(s16 *)(o + 0x8C) = a[2];
        *(s16 *)(o + 0x8E) = a[3];
    } while (i < n);
}

void func_0024BE20(u8 *p)
{
    extern void func_00175700();
    extern void func_00362460();
    extern void func_001ACD40();
    V3_3aa v;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_00362460(p, p[0x1B7]);
        v = *(V3_3aa *)(p + 0x34);
        if (*(s16 *)(p + 0x140) == 0) v.x += -133.3333282470703f;
        else v.x += 133.3333282470703f;
        v.y += 240.0f;
        func_001ACD40(&v, p[0x140], 0);
    }
}

void func_00284F40(u8 *p)
{
    extern void func_00175700();
    extern void func_001830D0();
    u32 v[3];
    u32 t;
    f32 k;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (!(*(s8 *)(p + 0x151) != 0) == 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        *(s16 *)(p + 0x1C) = 0xE;
        if (p[0x1E6] != 0) k = 23.333332061767578f;
        else k = -23.333332061767578f;
        *(f32 *)(p + 0x5C) = k;
        v[0] = 0x41200000;
        v[1] = 0x433C9249;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G34b;
extern G34b *D_004C2794;

void func_0034B7B0(u8 *p)
{
    extern void func_001757E0();
    *(s16 *)(p + 0x1C) = 0x60;
    *(u32 *)(p + 0x34) = 0x43200000;
    *(u32 *)(p + 0x38) = 0x431A4924;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x40855555;
    *(u32 *)(p + 0x60) = 0xC02B6DB6;
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) == 0) {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x32;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x13));
}

extern s16 D_004C00A0[4];
extern f32 D_004519B8[];

void func_00229130(u8 *p)
{
    extern void func_00185490();
    extern void func_00183D10();
    extern void func_0018C4B0();
    extern void func_0022C700();
    extern void func_001757E0();
    f32 k;
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_00183D10(p);
    func_0018C4B0(p, 5);
    func_0022C700(p);
    *(s16 *)(p + 0x1C) = 2;
    *(s16 *)(p + 0x1E) = D_004C00A0[p[0x1B7]];
    p[0x20] = 0;
    p[0x21] = 0;
    p[0x1B5] = 0x62;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    k = D_004519B8[p[0x1B7]];
    if (*(s16 *)(p + 0x140) != 0) k = -k;
    *(f32 *)(p + 0x5C) = k;
    func_001757E0(p, 0x15, 0x25);
}

void func_0037B220(u8 *p, u8 *q, f32 *r)
{
    extern void func_00185870();
    extern void func_00178F20();
    extern void func_00328E60();
    u8 *s = *(u8 **)(p + 0x1C4);
    s[0x20B] = 0xC1;
    q[0x20B] = 0xC1;
    *(s8 *)(q + 0x16A) = -1;
    func_00185870(p, s);
    s[0x20A] = 6;
    *(s16 *)(p + 0x1C) = 0x3C;
    *(V3_3aa *)(p + 0x34) = *(V3_3aa *)(*(u8 **)(q + 0x1DC) + 0x34);
    *(f32 *)(p + 0x38) += 102.0f;
    p[0x160] = 0x2A;
    *(s8 *)(p + 0x16A) = -1;
    func_00178F20(p, *(u8 **)(p + 0x1DC));
    r[1] = *(f32 *)(*(u8 **)(q + 0x1DC) + 0x38);
    s[0x23E] = 3;
    s[0x23C] = 3;
    func_00328E60(s);
}

typedef struct { s16 a, b; } S4_33d;
typedef struct { f32 x, y, z; u8 pad[12]; } E24_33d;
extern S4_33d D_0045EF18[];
extern E24_33d D_0045EEC0[];
extern u32 D_004C283C;

void func_0033D3B0(s32 idx)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0033D490(u8 *);
    extern s32 func_00417A40();
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_0033D490;
        *(s16 *)(o + 0xCC) = D_0045EF18[idx].a;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(V3_3aa *)(o + 0x34) = *(V3_3aa *)&D_0045EEC0[idx];
        *(f32 *)(o + 0x34) += (f32)(func_00417A40() % 0x14A);
        *(u32 *)(o + 0xD0) = 0x801;
        o[0x20] = idx;
    }
}

void func_0025BEC0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001548D0();
    extern void func_001E3710();
    extern void func_001266A0();
    extern void func_001843A0();
    u32 v[4];
    u8 *q;
    f32 k;
    if (func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            v[0] = 0xC3555555;
            v[1] = 0x433C9249;
            func_001548D0(p, v, 2);
            func_001E3710(p, 3);
            func_001266A0(p, 0, 0);
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x1E6] = p[0x1E6];
            q[0x1B5] = 0x23;
            q[0x20A] = 1;
        }
    } else {
        if (*(s16 *)(p + 0x140) != 0) k = 106.66666412353516f;
        else k = -106.66666412353516f;
        *(f32 *)(p + 0x34) += k;
        func_001843A0(p);
    }
}

void func_0024EBC0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001843A0();
    f32 f, k, z;
    switch (p[0x1FC]) {
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            f = (f32)*(s8 *)(p + 0x151);
            z = 0.0f;
            if (f != z) {
                p[0x151] = 0;
                if (p[0x1E6] != 0) k = 1.6666666269302368f;
                else k = -1.6666666269302368f;
                f *= k;
                *(f32 *)(p + 0x34) += f;
            }
        }
        break;
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_00209690(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0();
    f32 f, k, z;
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            f = (f32)*(s8 *)(p + 0x151);
            z = 0.0f;
            if (f != z) {
                p[0x151] = 0;
                if (p[0x1E6] != 0) k = 1.6666666269302368f;
                else k = -1.6666666269302368f;
                f *= k;
                *(f32 *)(p + 0x34) += f;
            }
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_002097F0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0();
    f32 f, k, z;
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            f = (f32)*(s8 *)(p + 0x151);
            z = 0.0f;
            if (f != z) {
                p[0x151] = 0;
                if (p[0x1E6] != 0) k = 1.6666666269302368f;
                else k = -1.6666666269302368f;
                f *= k;
                *(f32 *)(p + 0x34) += f;
            }
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

extern u8 data_s8_004BFE80[4];
extern u8 D_004BFE84[4];
extern u8 D_004BFE88[4];

void func_00210D60(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = data_s8_004BFE80;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = D_004BFE84;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004BFE88;
        p[0x1BB] = 2;
        break;
    }
    { u8 t = *(volatile u8 *)(p + 0x1B5); p[0x1B5] = t; }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
