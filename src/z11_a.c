typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u32 x, y, z; } V3i;

void func_002C36C0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, V3 *, s32, s32);
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v = *(V3 *)(p + 0x34);
        ((V3i *)&v)->x = 0x40555555;
        ((V3i *)&v)->y = 0x43160000;
        func_001830D0(p, &v, 1, t + 1);
    }
}

void func_00241720(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        p[0x20D] = 2;
        *(s8 *)(q + 1) = -1;
        func_00175C00(p, 1);
    } else {
        s16 v = *(s16 *)(p + 0x1E) ^ 1;
        *(s16 *)(p + 0x1E) = v;
        if (v != 0) {
            func_00175C00(p, 8);
        } else {
            func_00175C00(p, 1);
        }
    }
}


void func_00272580(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001830D0(u8 *, V3 *, s32);
    V3 v;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    {
        s16 c = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = c;
        if (c == 0) {
            p[0x404] = 0;
            p[0x405] = 0;
            t = p[7];
            p[7] = t + 1;
            func_001757E0(p, 0x16, 1);
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            v = *(V3 *)(p + 0x34);
            ((V3i *)&v)->x = 0xC2555555;
            ((V3i *)&v)->y = 0x434DB6DB;
            func_001830D0(p, &v, 1);
        }
    }
}

void func_002644E0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00174240(u8 *);
    extern void func_001E3210(u8 *, s32);
    s32 k;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if ((*(s8*)(p + 0x151) = 2) != 0) p[0x151] = 0;
    if (func_00174240(p) == 0) {
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x60) = 0xC14DB6DB;
        *(u32 *)(p + 0x6C) = 0x3D892492;
        func_001E3210(p, 0x1E);
        if (p[2] == 0) {
            *(s16 *)(p + 0x140) = 0;
            *(u32 *)(p + 0x5C) = 0xC1A00000;
            *(u32 *)(p + 0x68) = 0;
        } else {
            *(s16 *)(p + 0x140) = 1;
            *(u32 *)(p + 0x5C) = 0x41A00000;
            *(u32 *)(p + 0x68) = 0;
        }
    }
}

void func_003C7E60(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174240(u8 *);
    extern void func_003C80A0(u8 *, u8 *);
    u32 t;
    if (p[5] == 0) {
        if (func_00175700(p) < 0) {
            t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x140) ^= 1;
            *(u32 *)(p + 0x5C) = 0x40555555;
            *(u32 *)(p + 0x60) = 0x42700000;
            func_001757E0(p, 0x14, 3);
        }
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (func_00174240(p) == 0) func_003C80A0(p, q);
    }
}

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_002D77A0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_0039EF90();
    s8 i;
    s8 n;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        D_004F1F45[0] = 3;
        D_004F1F46[0] = 1;
        *(s16 *)(p + 0x1C) = (p[0x1B7] != 0) ? 0x38 : 0x2E;
        func_0039EF90(p, 0, 0);
        n = (p[0x1B7] != 0) ? 5 : 3;
        for (i = 0; i < n; i++) {
            func_0039EF90(p, 1, (u8)i);
        }
        p[0x28F] = 0;
        p[0x28E] = 0x10;
    }
}

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_0025BB50(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001E3A40(u8 *);
    extern void func_001843A0(u8 *);
    u8 *q;
    if (*(s8 *)(p + 0x151) == 2) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (*(s8 *)(p + 0x151) == 1) {
        func_001266A0(p, 0, 0);
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x21;
        q[0x20A] = 1;
        D_004F1F45[0] = 2;
        D_004F1F46[0] = 1;
        func_001E3A40(q);
    } else {
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}

s32 func_0036EB40(u8 *p, u8 *q, s32 *r) {
    extern void func_00185490(u8 *);
    extern void func_00178F20(u8 *, u8 *);
    extern void func_001843A0(u8 *);
    u8 *s;
    s16 c;
    u32 t;
    if (r[1] != 0) {
        s = *(u8 **)(q + 0x220);
        if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) != p) {
            func_00185490(s);
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
            return 0;
        }
        func_00178F20(p, s);
        if (*(s8 *)(s + 0x1B3) != 0) {
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
            s[0x20A] = 0;
            func_00185490(s);
            return 0;
        }
        c = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = c - 1;
        if (c <= 0) {
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
            func_00185490(s);
            if (*(s16 *)(s + 0x434) != 0) {
                func_001843A0(s);
            }
            return 0;
        }
    }
    return r[1];
}

typedef struct { u8 pad[0x5B8]; } S5B8;
typedef struct { u8 pad[28]; } S28;
extern S5B8 D_004F20B0[];

void func_001E7BB0(u8 *a, u8 *b) {
    u8 *e, *g;
    S28 *t;
    u32 i;
    if ((*(s8 *)(a + 0x1B0) & 0x80) == 0) {
        i = a[0x1B5]; t = *(S28 **)(a + 0x184); t = t + (i & 0x7F); e = (u8 *)t;
        *(u8 **)(a + 0x1D0) = e;
        a[0x1B4] = e[5];
        if ((*(s8 *)(a + 0x1B0) & 1) != 0) {
            g = (u8 *)&D_004F20B0[a[0x1B8]];
            *(s8 *)(g + 0x1B2) = *(s8 *)(a + 0x1B2);
            *(u8 **)(g + 0x1C4) = b;
        }
    }
    if ((*(s8 *)(b + 0x1B1) & 0x80) == 0) {
        i = a[0x1B5]; t = *(S28 **)(a + 0x184); t = t + (i & 0x7F); e = (u8 *)t;
        *(u8 **)(b + 0x1D0) = e;
        b[0x1B4] = e[5];
        *(u8 **)(b + 0x1CC) = (u8 *)&D_004F20B0[a[0x1B8]];
        b[0x1B6] = a[0x1B5];
        if ((*(s8 *)(b + 0x1B1) & 1) != 0) {
            g = (u8 *)&D_004F20B0[b[0x1B8]];
            *(u8 **)(g + 0x1C8) = a;
            *(s8 *)(g + 0x1B3) = *(s8 *)(b + 0x1B3);
        }
    }
}

void func_003B9C80(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B9310(u8 *, s32, s32);
    u8 *q = p + 0xD0;
    u32 t;
    s16 c;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    c = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = c;
    if (c == 0) {
        if (p[0x21] != 0) {
            t = p[4];
            p[4] = t + 1;
            p[5] = 0;
            p[0x13C] = 0;
        } else {
            t = p[5];
            p[5] = t + 1;
            p[0x13C] = 1;
            p[0x24] = 0xD;
            *(f32 *)(p + 0x34) = *(f32 *)(q + 4);
            *(f32 *)(p + 0x38) = *(f32 *)(q + 8);
            func_001757E0(p, 0x15, 0xF);
            func_003B9310(p, 1, 0);
        }
    }
}

void func_00266730(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    f32 *a, *b, *c, *d;
    u32 t;
    func_00175700(p);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_001757E0(p, 0x16, 6);
        *(s16 *)(p + 0x1C) = 0x14;
        func_001266A0(p, 0, 0);
    }
}

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_003B4D40(u8 *a, u8 *b) {
    extern void func_003B54E0(u8 *);
    extern void func_003B5530(u8 *, u8 *);
    extern s32 func_003B55C0(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    u8 *s;
    u32 t;
    func_003B54E0(a);
    if (*(s8 *)(a + 0x1B2) != 0) {
        s = *(u8 **)(a + 0x1C4);
        *(s16 *)(a + 0x1C) = 3;
        t = a[5];
        a[5] = t + 1;
        func_003B5530(a, b);
        if (s[3] == 0) {
            D_004F1F45[0] = 1;
            D_004F1F46[0] = 1;
            func_001E3710(b, 0x30);
        }
        return;
    }
    {
        if (func_003B55C0(a, 0) != 0) {
            *(s16 *)(a + 0x1C) = 3;
            t = a[5];
            a[5] = t + 1;
        } else if ((*(u16 *)(b + 0x362) & 0x300) != 0) {
            if ((*(u16 *)(b + 0x35E) & 0x400) != 0) {
                *(s16 *)(a + 0x1C) = 3;
                t = a[5];
                a[5] = t + 1;
            }
        }
        func_003B5530(a, b);
    }
}
