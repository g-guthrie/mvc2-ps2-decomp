typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z, w; } V4a;
typedef struct { f32 x, y, z; } V3;
extern V3 D_004425A0;
extern V3 D_0044269C[];
extern void *func_003DA750(void *, s32, s32);
extern void func_00146BD0(u8 *);
extern V4a D_004425B0;
extern u8 *D_004C2804;

u8 *func_001461F0(u8 *a, u8 b, s16 c) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00146BD0;
        o[0x23] = b;
        o[0x20] = a[0x20];
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(s16 *)(o + 0xCC) = c;
        *(u8 **)(o + 0x84) = D_004C2804;
        *(V4a *)(o + 0x74) = D_004425B0;
        *(u32 *)(o + 0xD0) = 0x800431;
    }
    return o;
}

u8 *func_002394F0(u8 *p) {
    extern u8 *func_001E7FD0(u8 *);
    u8 *r;
    if ((*(u16 *)(p + 0x20E) & 0xC00) == 0) {
        return 0;
    }
    if (p[0x1B7] == 0) {
        return 0;
    }
    r = 0;
    if (p[0x20D] == 1) {
        return r;
    }
    {
        {
            if (p[0x212] != 0) {
                if (p[0x20D] == 2) {
                    return r;
                }
                r = func_001E7FD0(p);
                if (r != 0) {
                    p[0x20B] = 0;
                }
            } else if (p[0x20D] != 2) {
                r = func_001E7FD0(p);
                if (r != 0) {
                    p[0x20B] = 1;
                }
            } else {
                r = func_001E7FD0(p);
                if (r != 0) {
                    p[0x20B] = 2;
                }
            }
        }
    }
    return r;
}

typedef struct { f32 x, y, z; } V3e;
void func_0034F6F0(u8 *p) {
    extern void func_00175700();
    extern int func_00174470(const void *);
    extern void func_0034F7D0(u8 *);
    extern void func_0015B200();
    extern void func_001E7F60();
    V3e v;
    func_00175700();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        func_0034F7D0(p);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        v = *(V3e *)(p + 0x34);
        func_0015B200(p, &v, 1, 0xC9);
        func_0034F7D0(p);
    }
    func_001E7F60(p);
}

void func_00321BE0(u8 *p, u8 *q) {
    extern void func_001266A0();
    extern void func_0015D010();
    extern void func_001E3210();
    f32 v[3];
    s32 t = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x24) = t - 1;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        p[0x152] = 1;
        if (*(s8 *)(p + 0x151) == 0xC) {
            func_001266A0(p, 1, 1);
            v[0] = 0;
            v[1] = 0;
            func_0015D010(p, v);
            p[0x1B4] = 10;
            func_001E3210(p, 3);
        }
    }
}

void func_0029D7C0(u8 *p) {
    extern void func_00175700();
    extern void func_001CB610();
    extern void func_00176160();
    extern void func_001757E0();
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    if (*(s16 *)(p + 0x1C) == 0xF) {
        func_001CB610(p, 4);
        func_00176160(p, 3, 2, 1);
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0xF;
        func_001757E0(p, 0x16, 1);
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(u32 *)(p + 0x68) = 0x3DD55555;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

void func_002641D0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    u32 *a1, *a2;
    func_00175700();
    a1 = (u32 *)(p + 0x60);
    a2 = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38)) {
        return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *a1 = 0;
    *a2 = 0;
    *(u32 *)(p + 0x5C) = 0x40855555;
    *(u32 *)(p + 0x68) = 0xBEA6AAAA;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 2, 3);
}

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } Gh;
extern Gh *D_004C2794;
void func_00311580(u8 *p) {
    extern void func_00175700();
    s32 v;
    s16 d, e;
    func_00175700();
    v = *(s8 *)(p + 0x151);
    if (v & 1) {
        p[0x151] = v & -2;
        *(u32 *)(p + 0x5C) = 0xC13AAAAA;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC14DB6DB;
        *(u32 *)(p + 0x6C) = 0;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        d = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = d - 1;
        if (d == 0) {
            *(s16 *)(p + 0x1E) = 2;
            e = *(s16 *)(p + 0x1C);
            if (e != 0) {
                *(s16 *)(p + 0x1C) = e - 1;
                p[0x1B5] = 0x12;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            }
        }
    }
}

typedef struct { f32 x, y, z; } V3i;
extern V3i D_0043DF64[];
extern u8 *D_004C2834;
void func_00132310(u8 *a, u8 *b) {
    extern void func_00133020();
    u8 *o;
    if ((o = func_003DA750(0, 0xE, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00133020;
        *(s16 *)(o + 0xCC) = 0x50;
        *(u8 **)(o + 0x84) = D_004C2834;
        *(V3i *)(o + 0x34) = D_0043DF64[(b[2] << 1) + b[0x425]];
        *(V3i *)(o + 0x68) = *(V3i *)(o + 0x34);
        *(u32 *)(o + 0xD0) = 0x10801;
        o[0x20] = a[0x20];
        o[0x21] = b[0x425];
        *(u8 **)(o + 0x18) = b;
        *(u8 **)(o + 0x14) = a;
        *(u32 *)(o + 0xC8) = *(u32 *)(a + 0xC8);
        *(s16 *)(o + 0x1C) = 0;
    }
}

extern u8 *D_004C2840;
extern u16 D_00584BC0[];
extern u16 D_00584BC2[];
extern u16 D_00584BC4[];
extern u16 D_00584BC6[];
extern u16 D_00584BC8[];
void func_0038CBB0(void) {
    switch (*(s8 *)(D_004C2840 + 0x4C)) {
    case 0:
        if (D_00584BC0[0] < 0x270F) {
            D_00584BC0[0] = D_00584BC0[0] + 1;
        }
        break;
    case 1:
        if (D_00584BC2[0] < 0x270F) {
            D_00584BC2[0] = D_00584BC2[0] + 1;
        }
        break;
    case 2:
        if (D_00584BC6[0] < 0x270F) {
            D_00584BC6[0] = D_00584BC6[0] + 1;
        }
        break;
    case 5:
        if (D_00584BC8[0] < 0x270F) {
            D_00584BC8[0] = D_00584BC8[0] + 1;
        }
        break;
    case 7:
        if (D_00584BC4[0] < 0x270F) {
            D_00584BC4[0] = D_00584BC4[0] + 1;
        }
        break;
    }
}

extern u8 D_004C0F30[4];
extern u8 D_004C0F34[4];
extern u8 D_004C0F38[4];
void func_002D1C50(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = D_004C0F30;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = D_004C0F34;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C0F38;
        p[0x1BB] = 2;
        func_001E3710(p, 0x16);
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}

void func_00284320(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    u32 *q5c, *q60, *q68, *q6c;
    q6c = (u32 *)(p + 0x6C);
    q68 = (u32 *)(p + 0x68);
    q60 = (u32 *)(p + 0x60);
    q5c = (u32 *)(p + 0x5C);
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700() < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *q5c = 0;
        *q60 = 0;
        *q68 = 0;
        *q6c = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 0x16, 8);
    }
}


u8 *func_00146040(s32 a, s32 b, s32 c)
{
    u8 *p;
    u8 *q;

    if ((s8)a == 0)
        p = func_003DA750(0, 0xD, 1);
    else
        p = func_003DA750(0, 0xD, 0);
    if (p != 0) {
        p[0x13C] = 0;
        *(void (**)(u8 *))(p + 0x10) = func_00146BD0;
        p[0x23] = a;
        p[0x20] = b;
        p[0x21] = c;
        *(V3 *)(p + 0x50) = D_004425A0;
        *(V4a *)(p + 0x74) = D_004425B0;
        *(u32 *)(p + 0xD0) = 0x800431;
    }
    if ((s8)a == 0) {
        q = func_001461F0(p, 1, 6);
        *(V3 *)(q + 0x50) = D_0044269C[p[0x20]];
        *(f32 *)(q + 0x3C) = -0.1f;
        q = func_001461F0(p, 1, 7);
        *(V3 *)(q + 0x50) = D_0044269C[p[0x20]];
        q[0x21] = 1;
        *(f32 *)(q + 0x3C) = -0.12f;
    }
    return p;
}
