typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_002F8DE0(u8 *p) {
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 8.0f;
        *(f32 *)(p + 0x68) /= 8.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 8.0f;
    }
}
void func_002F9850(u8 *p, u8 *q) {
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F98F0(u8 *, u8 *);
    u32 t = p[6]; p[6] = t + 1;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    if (p[0x20D] != 2) func_00183D10(p);
    func_001757E0(p, 0x15, 7);
    func_002F8DE0(p);
    *(s16 *)(p + 0x1C) = 0x5A;
    func_002F98F0(p, q);
}

void func_002B9980(u8 *p) {
    extern void func_00175700(void);
    extern void func_001843A0(void);
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v > 0) {
        func_00175700();
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0();
    }
}

void func_00242F90(u8 *p) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0015D010(u8 *, f32 *);
    extern void func_0018C6E0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 v[4];
    func_001266A0(p, 5, 5);
    if ((*(u16 *)(p + 0x20E) & 0x400) != 0) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    *(u32 *)&v[0] = 0xC32D5555;
    *(u32 *)&v[1] = 0x435EDB6D;
    func_0015D010(p, v);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    p[6] = 0;
    p[7] = 0;
    func_001757E0(p, 15, 2);
}

extern s32 D_004C283C;

void func_00200270(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32, s32);
    f32 v[4];
    func_00175700(p);
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 300;
        *(u32 *)&v[0] = 0xC0D55555;
        *(u32 *)&v[1] = 0x433C9249;
        func_001830D0(p, v, 1, 300);
    }
}

extern u8 D_004502C0[];

void func_001C8150(u8 *p) {
    extern void func_001548D0(u8 *, f32 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    f32 v[4];
    s16 n = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = n;
    if (n == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x5C) = 0xC0555555;
        } else {
            *(u32 *)(p + 0x5C) = 0x40555555;
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(u32 *)&v[0] = 0;
        *(u32 *)&v[1] = 0x42092492;
        func_001548D0(p, v, 0);
        func_001757E0(p, 0x19, 0x14);
    } else {
        func_00175700(p);
    }
}

void func_001959F0(u8 *p, u8 *q) {
    extern s32 func_00197560(u8 *);
    extern void func_00194CA0(u8 *, u8 *);
    extern void func_00175670(u8 *);
    extern void func_001975C0(u8 *, u8 *);
    if (func_00197560(p) != 0) return;
    if (p[0x21] >= 4) return;
    {
        s16 h = *(s16 *)(p + 0x1C);
        if (h != 0) {
            *(s16 *)(p + 0x1C) = h - 1;
            return;
        }
    }
    {
        s16 n = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = n;
        if (n == 0) {
            func_00194CA0(p, q);
            return;
        }
    }
    func_00175670(p);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    func_001975C0(p, q);
}

extern s32 D_004C287C;
extern u8 D_004BFAE0;
extern u8 D_004CD1FA[];
extern u8 D_004CD20E[];
void func_001E2050(void) {
    extern void func_001E46B0(void);
    extern void func_001E4560(void);
    extern void func_0012DA40(s32, s32, s32);
    extern u8 func_001E5870(s32, s32);
    extern void func_003DCD40(s32, s32, s32);
    extern void func_001E3D10(void);
    extern void func_001E4260(s32);
    s32 s;
    func_001E46B0();
    func_001E4560();
    s = (D_004C287C + 0x3F) & -0x40;
    func_0012DA40(0x3B, s, 1);
    D_004CD1FA[0] = func_001E5870(s, 6);
    func_003DCD40(D_004C287C, 0, 4);
    func_0012DA40(0x3C, s, 1);
    D_004CD20E[0] = func_001E5870(s, 7);
    func_003DCD40(D_004C287C, 0, 4);
    func_001E3D10();
    if (D_004BFAE0 != 0) {
        func_001E4260(1);
    } else {
        func_001E4260(0);
    }
}

extern s32 D_004C283C;
s32 func_00335070(u8 *p) {
    extern void func_00335140(u8 *);
    s16 h = *(s16 *)(p + 0x1E);
    f32 v;
    if (h > 7) {
        *(s16 *)(p + 0x1C) = 0x3C;
        *(s16 *)(p + 0x1E) = 0;
        p[6] = 3;
        func_00335140(p);
        return 0;
    }
    if (*(s16 *)(p + 0x1C) == 0) {
        s16 t = h + 0x1B;
        if (t > 0x22) t = 0x22;
        *(s16 *)(p + 0xCC) = t;
        *(s32 *)(p + 0x84) = D_004C283C;
    }
    v = *(f32 *)(p + 0x74) - 0.0625f;
    *(f32 *)(p + 0x74) = v;
    if (v < 0.0f) *(f32 *)(p + 0x74) = 0.0f;
    {
        s16 n = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = n;
        if (n > 0) {
            *(s16 *)(p + 0x1C) = 0;
            *(s16 *)(p + 0x1E) += 1;
        }
    }
    return 0;
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G94;
extern G94 *D_004C2794;
void func_0022B470(u8 *p) {
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t = p[6];
    p[6] = t + 1;
    func_00175C00(p, 0);
    p[0x20D] = 2;
    *(f32 *)(p + 0x38) += 137.14285278320312f;
    {
        f32 z = -30.0f;
        if (p[0x1E6] != 0) z = -z;
        *(f32 *)(p + 0x5C) = z;
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x14, 0);
}

void func_00201630(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_00183D50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *a, *b, *c, *d;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864A0(p) != 0) {
        p[6] = 3;
        p[7] = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183D50(p);
        func_001757E0(p, 0x16, 0xC);
    }
}

void func_00231DB0(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern s32 func_0035AEA0(u8 *, s32, s32);
    extern void func_001830D0(u8 *, f32 *, s32);
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        if (func_0035AEA0(q, 0, 1) == 0) {
            u32 t2 = p[6];
            p[6] = t2 + 1;
        }
        p[0x404] = 0;
        p[0x405] = 0;
        *(u32 *)&v[0] = 0xC1D55555;
        *(u32 *)&v[1] = 0x431A4924;
        func_001830D0(p, v, 1);
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_004427B0[];
extern V3 D_004427B4[];
extern V3 D_004427B8[];
void func_00146710(u8 *p, s32 a1, s32 a2) {
    extern void func_00170DF0(s32);
    u32 t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
    *(s16 *)(p + 0xCC) = a2;
    *(s32 *)(p + 0x84) = a1;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0xD0) |= 0x800400;
    func_00170DF0(*(s32 *)(p + 0x84));
    *(u32 *)(p + 0xD4) = 0;
    *(f32 *)(p + 0x78) = *(f32 *)((u8 *)D_004427B0 + p[0x21] * 12);
    *(f32 *)(p + 0x7C) = *(f32 *)((u8 *)D_004427B4 + p[0x21] * 12);
    *(f32 *)(p + 0x80) = *(f32 *)((u8 *)D_004427B8 + p[0x21] * 12);
}

extern f32 D_0045A220[];

void func_00213790(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001863F0(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_00183D50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *a, *b, *c, *d;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_001864A0(p) != 0) {
        u32 t;
        func_00183D50(p);
        t = p[6];
        p[6] = t + 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001757E0(p, 0x14, 4);
    }
}

extern u8 D_004C1AB8[8];
extern u8 D_004C1AB0[8];
void func_00357A40(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u8 k;
    u8 *q;
    s32 m;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x14);
    k = 0;
    m = q[7];
    if (m != 0) {
        if ((u8)m < p[6]) p[0x13C] = 0;
        if ((*(u8 **)(p + 0x14))[7] == p[6]) k = 4;
    } else {
        if (q[6] < p[6]) p[0x13C] = 0;
        if ((*(u8 **)(p + 0x14))[6] == p[6]) k = 4;
    }
    if (p[6] == 1) {
        func_001757E0(p, 0x15, D_004C1AB8[p[0x21] + k]);
    } else {
        func_001757E0(p, 0x15, D_004C1AB0[p[0x21] + k]);
    }
}

s32 func_00165810(u8 *p, u8 *q) {
    extern s32 func_0016B240(u8 *, s32);
    extern void func_0016B0C0(u8 *, u8 *, s32);
    extern void func_00186CE0(u8 *, s32);
    s32 v;
    u16 h;
    u16 m;
    if (func_0016B240(p, 5) == 0) return 0;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    v = *(s32 *)(p + 0x4C8);
    switch (v) {
    case 0:
        h = 0x2800;
        break;
    case 255:
        h = 0x2000;
        break;
    case 1:
        h = 0x2400;
        break;
    }
    p[0x1E7] = v;
    *(u16 *)(p + 0x35E) = h;
    func_00186CE0(p, 0xD);
    m = h;
    *(u16 *)(p + 0x35E) = 0;
    if ((m & 0xC00) != 0) {
        h = m ^ (p[0x1E6] * 3 << 10);
    }
    *(u16 *)(p + 0x4F0) = h;
    return 0;
}

extern G94 *D_004C2794;
extern u8 D_004C0208[4];
extern u8 D_004C020C[4];
extern u8 D_004C0210[4];
void func_0023A670(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C0208;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C020C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C0210;
        p[0x1BB] = 2;
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}

void func_0017A580(u8 *p) {
    extern s32 func_00187D70(u8 *);
    extern s32 func_001884C0(u8 *);
    extern s32 func_00184B30(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_001853E0(u8 *);
    extern s32 func_00186030(u8 *);
    extern s32 func_00184C60(u8 *);
    extern s32 func_001846D0(u8 *, s32);
    extern s32 func_00175700(u8 *);
    extern void func_00186CE0(u8 *, s32);
    if (p[0x1E5] != 0x15 && func_00187D70(p) != 0) return;
    if (func_001884C0(p) != 0) return;
    if (func_00184B30(p) != 0) return;
    if (func_00184720(p) != 0) return;
    if (func_00185A90(p) != 0) return;
    if (func_001853E0(p) != 0) return;
    if (func_00186030(p) != 0) return;
    if (p[0x215] == 0) {
        if (func_00184C60(p) != 0) return;
        if (func_001846D0(p, 0) != 0) return;
    }
    if ((s8)func_00175700(p) < 0) func_00186CE0(p, 0);
}

extern s32 D_004C283C;
void func_0033D990(u8 *p) {
    extern s32 func_00153AA0(u8 *);
    extern void func_00170DA0(s32, s32, s32, s16);
    switch (p[4]) {
    case 0:
        *(s16 *)(p + 0x1C) += 1;
        if (*(s16 *)(p + 0x1C) >= 100) *(s16 *)(p + 0x1C) = 0;
        func_00170DA0(D_004C283C, 0x1F, func_00153AA0(p), *(s16 *)(p + 0xCC));
        *(u32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = -0.00999999978f * *(s16 *)(p + 0x1C);
        *(u32 *)(p + 0xD0) |= 0x20000;
        break;
    default:
        break;
    }
}

void func_0033E180(void);
void func_0033E090(u8 *p) {
    extern void func_00170E60(s32, s32, s32, s32, void (*)(void), s32);
    u32 arg[2];
    u8 *q;
    s32 **tab;
    switch (p[4]) {
    case 0:
    {
        s16 n = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = n;
        if (n >= 360) *(s16 *)(p + 0x1C) = 0;
    }
    {
        s16 n = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = n;
        if (n >= 2000) *(s16 *)(p + 0x1E) = 0;
    }
    q = *(u8 **)(p + 0x84);
    arg[0] = (u32)p;
    arg[1] = 0;
    tab = *(s32 ***)(q + 0x1C);
    func_00170E60(*(s32 *)(D_004C283C + 0x14), (s32)tab[2], *(s32 *)(q + 0x14), (s32)tab[*(s16 *)(p + 0xCC)], func_0033E180, (s32)arg);
    *(u32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -0.000500000023748725653f * *(s16 *)(p + 0x1E);
    *(u32 *)(p + 0xD0) |= 0x20000;
        break;
    default:
        break;
    }
}

extern f32 D_0045A220[];
static void func_002CF1D0(u8 *p) { p[0x10] = 1; }
void func_002CF350(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32);
    f32 v[4];
    s32 k;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    k = *(s8 *)(p + 0x151);
    if (k != 0) {
        k = (s8)k;
        if (k > 0) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430) - D_0045A220[k];
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            func_002CF1D0(p);
            p[0x404] = 0;
            p[0x405] = 0;
            *(u32 *)&v[0] = 0xC2200000;
            *(u32 *)&v[1] = 0x424DB6DB;
            *(u32 *)&v[2] = 0;
            func_001830D0(p, v, 1);
        }
    }
}

