typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x36]; s8 f36[8]; s8 f3e; u8 pad1[0x7C - 0x3F]; s16 f7c[1]; } G4;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b; } V2;


extern G4 *D_004C2794;
extern u8 D_004C2A1C;
extern f32 D_004743E0[];
extern f32 D_004743E4[];
extern f32 D_00474420[];
extern f32 D_00474424[];
extern u8 D_0044FEC0[];
extern void (*D_004C0DF8[8])(u8 *);
extern u32 D_004C2838;
extern u32 D_004BF440[8];
extern V3 D_00444EF0[];
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_001B8120(u8 *p)
{
    extern s32 func_001754A0(u8 *, s32, s32);
    extern s32 func_00175670(u8 *);
    extern void func_001B81D0(u8 *);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x1B2) == 0)
        func_001754A0(p, 0x1B, 2);
    else
        func_001754A0(p, 0x1B, 3);
    for (;;) {
        if (*(s8 *)(*(u8 **)(p + 0x18) + 0x161) == *(s8 *)(p + 0x150)) {
            p[0x13C] = 1;
            return;
        }
        if ((s8)func_00175670(p) < 0) {
            func_001B81D0(p);
            return;
        }
    }
}

void func_002191A0(u8 *p)
{
    extern void func_001865B0(u8 *);
    extern void func_00175700(u8 *);
    u32 *a, *b, *c, *d;
    a = (u32 *)(p + 0x5C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    d = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001865B0(p);
    } else {
        func_00175700(p);
    }
}

void func_00257430(u8 *p)
{
    extern void func_001820A0(u8 *);
    extern void func_00182300(u8 *);
    extern void func_00257520(u8 *);
    extern void func_002574E0(u8 *);
    extern s32 func_001864a0(u8 *);
    extern void func_001865B0(u8 *);
    func_001820A0(p);
    func_00182300(p);
    if (p[0x212] == 1) {
        func_00257520(p);
        switch (p[0x1FC]) {
        case 2:
            if (*(u16 *)(p + 0x20E) & 0x1000)
                return;
            break;
        case 0:
            break;
        case 1:
            break;
        }
    } else {
        func_002574E0(p);
    }
    if (func_001864a0(p) != 0)
        func_001865B0(p);
}

void func_0023ECE0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    if ((s8)func_00175700(p) < 0) {
        *(s16 *)(p + 0x140) ^= 1;
        func_001843A0(p);
        return;
    }
    {
        s8 t = *(s8 *)(p + 0x151) & 1;
        *(s8 *)(p + 0x151) = t;
        if (t != 0) {
            u8 *q;
            *(s8 *)(p + 0x151) = 0;
            q = *(u8 **)(p + 0x1DC);
            q[0x20A] = 1;
            q[0x20D] = 2;
            q[0x1B5] = *(s8 *)(p + 0x1B7) + 0x22;
            p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x22;
            q[0x1E6] = p[0x1E6];
            p[0x1E6] ^= 1;
        }
    }
}

s32 func_00233030(u8 *p)
{
    extern s32 func_001757E0(u8 *, s32, s32);
    u8 *q = p + 0x2B8;
    u8 *v;
    if (p[1] != 0xB)
        return 0;
    if (q[0xE] != 0)
        return 0;
    if (*(s8 *)(q + 0x10) == 0)
        return 0;
    v = *(u8 **)q;
    if (v == 0)
        return 0;
    if (*(f32 *)(p + 0x38) + 102.85713958740234f > *(f32 *)(v + 0x38))
        func_001757E0(p, 0x14, 0);
    else
        func_001757E0(p, 0x14, 1);
    return 1;
}

void func_003B8F40(u8 *p)
{
    extern s32 func_00174170(void);
    p[6]++;
    D_004C2A1C = func_00174170() & 7;
    *(f32 *)(p + 0x5C) = D_004743E0[D_004C2A1C * 2];
    *(f32 *)(p + 0x68) = D_004743E4[D_004C2A1C * 2];
    D_004C2A1C = func_00174170() & 7;
    *(f32 *)(p + 0x60) = D_00474420[D_004C2A1C * 2];
    *(f32 *)(p + 0x6C) = D_00474424[D_004C2A1C * 2];
}

void func_002C25D0(u8 *p)
{
    extern void func_00183D50(u8 *);
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            if (p[0x21] == 0) {
                func_00183D50(p);
                p[0x21] = 1;
            }
        }
    }
    D_004C0DF8[p[6]](p);
}

void func_002C3B10(u8 *p)
{
    extern s32 func_00175700(u8 *);
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= 0.5357142686843872f) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1E) = 0x10;
        *(u32 *)(p + 0x60) = 0x40092492;
        *(u32 *)(p + 0x6C) = 0xBE092492;
    }
}

void func_002A8350(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_002A8420(u8 *);
    extern void func_002A8580(u8 *);
    switch (p[0x1FC]) {
    case 2:
        if (p[6] == 1) {
            func_002A8420(p);
        } else if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p[6] == 2) {
            func_002A8580(p);
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0)
            func_001843A0(p);
        break;
    }
}

void func_0018F730(u8 *p)
{
    extern void func_0018B500(u8 *, u32);
    extern void func_0016CE90();
    extern void func_00190C60(u8 *, u32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_0018C6F0(u8 *);
    *(u32 *)(p + 0x1CC) = *(u32 *)(p + 0x1DC);
    p[0x1B6] = p[0x1B5];
    func_0018B500(p, *(u32 *)(p + 0x1CC));
    if (p[0x247] == 0x15) {
        p[0x247] = 2;
        p[0x24A] = 0;
    }
    if (p[0x243] < 0xB)
        p[0x243] = 0xB;
    if (*(s16 *)(p + 0x434) == 0) {
        if (p[0x1F0] == 0) {
            p[0x1F0] = 0xFF;
            func_0016CE90();
            if (D_004C2794->f36[p[2]] < 3)
                func_00190C60(p, *(u32 *)(p + 0x1CC));
            func_001E3210(p, 0);
        }
    }
    func_00175C00(p, 1);
    func_0018C6F0(p);
}

void func_00159F50(V3 *v, s32 idx)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00159EA0(void);
    u8 *o;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00159EA0;
        *(s16 *)(o + 0xCC) = 0xC;
        *(u32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *v;
        *(u32 *)(o + 0x44) = D_004BF440[idx];
        *(V3 *)(o + 0x5C) = D_00444EF0[idx];
        *(u32 *)(o + 0xD0) = 0x800515;
    }
}

void func_002E7850(u8 *p)
{
    extern void func_00185770(u8 *, u8 *);
    extern void func_001E3C40(u8 *);
    extern void func_00186A60(u8 *, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q = *(u8 **)(p + 0x1C4);
    *(s16 *)(p + 0x2C2) = 1;
    p[0x1FE] = 1;
    p[0x20B] = 0xC4;
    func_00185770(p, q);
    func_001E3C40(p);
    func_00186A60(p, 0x1D);
    p[6] = 3;
    p[7] = 0;
    p[0x1FD] = 3;
    q[6] = 0;
    q[7] = 0;
    q[0x24A] = 0;
    func_001266A0(p, 5, 0);
    func_001757E0(p, 0xF, (u8)(p[0x20D] + 3));
    p[0x40D] = 0xFF;
    p[0x40C] = 0x10;
    p[0x33B] = 1;
    ((u8 *)D_004C2794)[0x76] = (*(s8 *)(p + 2) << 4) | 1;
    p[0x33C] = 0x10;
}

void func_0021EA40(u8 *p)
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
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_002A2210(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    switch (p[0x1FC]) {
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            p[0x1B5] = 0x1D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 0:
    case 2:
        if ((s8)func_00175700(p) < 0)
            func_00184540(p);
        break;
    }
}

void func_00191C60(s32 *o1, s32 *o2)
{
    extern void func_00191A00(s32 *, s32 *);
    extern void func_00191840(s32 *, s32, s32);
    extern void func_00191B60(s32 *, s32 *);
    extern void func_00191BF0(s32 *, s32 *);
    extern void func_001917F0(u8 *, s32, s32);
    extern u8 D_004F2668[];
    extern u8 D_004F20B0[];
    struct { s32 a, b; } s;
    s32 c, d;
    s8 g;
    s.b = 0;
    s.a = 0;
    func_00191A00(&c, &d);
    func_00191840((s32 *)&s, c, d);
    func_00191B60(&c, &d);
    func_00191840((s32 *)&s, c, d);
    func_00191BF0(&c, &d);
    func_00191840((s32 *)&s, c, d);
    *o1 = s.b;
    *o2 = s.a;
    g = D_004C2794->f3e;
    if (g >= 0) {
        func_001917F0(g == 0 ? D_004F20B0 : D_004F2668, s.b, s.a);
    }
}

s32 func_001754A0(u8 *p, s32 a1, s32 a2)
{
    u8 *base;
    p[0x169] = a1;
    p[0x168] = a2;
    base = *(u8 **)(p + 0x178);
    *(u8 **)(p + 0x164) = base + *(u32 *)(base + *(u32 *)(base + *(u16 *)(p + 0x142) + (u8)a1 * 4) + (u8)a2 * 4);
    *(V2 *)(p + 0x150) = **(V2 **)(p + 0x164);
    *(u32 *)(p + 0x158) = 0;
    *(u32 *)(p + 0x15C) = 0;
    *(u32 *)(p + 0x160) = 0;
    if (*(s8 *)(p + 0x152) == 0) {
        do {
            *(u8 **)(p + 0x164) = *(u8 **)(p + 0x164) + 8;
            if (*(s8 *)(p + 0x153) & 0x80)
                *(u8 **)(p + 0x164) = *(u8 **)(p + 0x178) + **(u32 **)(p + 0x164);
            *(V2 *)(p + 0x150) = **(V2 **)(p + 0x164);
            *(u32 *)(p + 0x158) = 0;
            *(u32 *)(p + 0x15C) = 0;
            *(u32 *)(p + 0x160) = 0;
        } while (*(s8 *)(p + 0x152) == 0);
    }
    return 0;
}

void func_0012AD00(u8 *p)
{
    extern f32 func_00417500(u32);
    f32 v;
    *(s16 *)(p + 0x1E) += 9;
    if (*(s16 *)(p + 0x1E) >= 0x168)
        *(s16 *)(p + 0x1E) = 0;
    v = 0.5f + 0.5f * func_00417500((u16)((u32)(s32)(0.5 + 65536.0 * *(s16 *)(p + 0x1E) / 360.0)));
    *(f32 *)(p + 0x74) = v;
    if (v < 0.0f)
        *(f32 *)(p + 0x74) = 0.0f;
    if (*(f32 *)(p + 0x74) > 1.0f)
        *(f32 *)(p + 0x74) = 1.0f;
}

void func_00315D40(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001DD8A0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) == 0) {
        if (*(s8 *)(p + 0x211) != 2)
            return;
    } else {
        if (*(s8 *)(p + 0x211) != 1)
            return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x208] = 3;
        *(u32 *)(p + 0x60) = 0x41F00000;
        func_001757E0(p, 0xF, 9);
        D_004F1F45[0] = 3;
        D_004F1F46[0] = 1;
        func_001E3710(p, 0x2F);
        func_001DD8A0(p, 8, 1);
    }
}

void func_00228080(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0022C6B0(u8 *);
    f32 z = 0.0f;
    if (*(f32 *)(p + 0x60) < z) {
        *(f32 *)(p + 0x68) = z;
        *(f32 *)(p + 0x5C) = z;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        func_00175700(p);
    } else {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 3));
        func_0022C6B0(p);
    }
}

void func_00245940(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001A70B0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    func_00175700(p);
    if (p[7] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if (*(f32 *)(p + 0x2AC) <= 106.66666412353516f) {
            u32 t = p[7];
            p[7] = t + 1;
            func_001757E0(p, 0x13, 0);
            func_001A70B0(p, 2, 0);
            func_001A70B0(p, 2, 1);
            func_001A70B0(p, 2, 2);
            func_001A70B0(p, 2, 3);
            func_001E3210(p, 0x10);
        }
    }
}

extern u8 D_004C2A20;
extern f32 D_00474360[], D_00474364[], D_004743A0[], D_004743A4[];

void residual_003B8DE0(u8 *p)
{
    extern s32 func_00174170(void);
    p[6]++;
    D_004C2A20 = func_00174170() & 7;
    *(f32 *)(p + 0x5C) = D_00474360[D_004C2A20 * 2];
    *(f32 *)(p + 0x68) = D_00474364[D_004C2A20 * 2];
    D_004C2A20 = func_00174170() & 7;
    *(f32 *)(p + 0x60) = D_004743A0[D_004C2A20 * 2];
    *(f32 *)(p + 0x6C) = D_004743A4[D_004C2A20 * 2];
}
