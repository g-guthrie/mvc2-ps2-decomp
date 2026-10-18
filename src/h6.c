typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern void func_00175700(u8 *);
extern s32 func_0032C180(s32);
extern void func_00123760(s32);
extern void func_001E3CE0(s32);
extern u8 D_00583B9B[];
extern s8 *D_004C2840;
void func_0032C630(void) {
    if (func_0032C180(0) == 0 && D_00583B9B[0] == 2) {
        D_004C2840[4]++;
        func_00123760(2);
        func_001E3CE0(0x49);
    }
}
extern void func_001757E0(u8 *, s32, s32);
extern void *func_003DA750(s32, s32, s32);
void func_0038A0A0(void);
void func_0038A040(u8 *a0, s32 a1) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_0038A0A0;
        *(u8 **)(r + 0x18) = a0;
        r[0x20] = a1;
        a0[0x2D5]++;
    }
}
void func_0036D920(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18) + 0x2B8;
    *(f32 *)(p + 0x118) -= 0.059999999f;
    if (*(f32 *)(p + 0x118) < 0.0f) *(f32 *)(p + 0x118) = 0.0f;
    {
        s16 v = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = v - 1;
        if (v < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
            *q = 0;
        }
    }
}
extern void func_0016B0C0(u8 *, void *, s32);
extern void func_00166C80(u8 *, void *, s32);
void func_00168130(u8 *p, void *q) {
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    func_00166C80(p, q, (*(u8 **)(p + 0x220))[0x20D] == *(s32 *)(p + 0x4C8));
}
extern void func_001928E0(u8 *, s32, s32);
void func_00192420(u8 *p) {
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0x18;
            func_001928E0(p, 0x3E8, 0xA);
        }
    }
}
s32 func_0018AA50(u8 *p, u16 a1, s16 *a2, s32 a3) {
    s32 r;
    if (*(s8 *)(p + 0x539) != 0) {
        if (p[0x471] != 0 && *(s8 *)(p + 0x45C) == (u8)a3) r = 1; else r = 0;
    } else {
        u16 t = *(s16 *)(p + 0x35C) & a1;
        *a2 = t;
        r = (a1 == t);
        r = r != 0;
    }
    return r;
}
extern void (*D_0044A1E0[])(u8 *, u8 *);
void func_00194BB0(u8 *p, u8 *q) {
    s8 *r = (s8 *)(p + 0x88);
    if (*(s8 *)(q + 0x13C) == 0) {
        p[0x13C] = 0;
    } else if (r[0] != r[1]) {
        p[7] = 0;
        p[6] = 0;
        p[5] = 0;
        r[1] = r[0];
    } else {
        D_0044A1E0[r[0] & 0xF](p, q);
    }
}
extern void *func_003DA750(s32, s32, s32);
void func_0039AD80(void);
void func_0039AD00(u8 *p) {
    u8 i;
    for (i = 0; i < 2; i++) {
        u8 *r = func_003DA750(0, 2, 0);
        if (r) {
            *(void **)(r + 0x10) = func_0039AD80;
            *(u8 **)(r + 0x18) = p;
            r[0x20] = i;
            *(s16 *)(r + 0x26) = 0x2601;
        }
    }
}
extern void *func_003DA750(s32, s32, s32);
void func_001D01B0(void);
void func_001D0130(u8 *p, s32 a1) {
    if (*(s8 *)(p + 0x23D) < 7) {
        u8 *r = func_003DA750(0, 3, 0);
        if (r) {
            *(void **)(r + 0x10) = func_001D01B0;
            *(u8 **)(r + 0x18) = p;
            r[0x20] = a1;
            *(s16 *)(r + 0x26) = 0x2800;
            (*(s8 *)(p + 0x23D))++;
        }
    }
}
extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, u32 *);
extern void func_0018C6E0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
void func_001F63B0(u8 *p) {
    u32 v[4];
    p[0x1B4] = 10;
    p[7] = 0;
    p[6] = 0;
    func_001266A0(p, 5, 5);
    v[0] = 0xC3200000;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}
void func_001C08D0(u8 *p) {
    *(f32 *)(p + 0x50) += *(f32 *)(p + 0x88);
    *(f32 *)(p + 0x54) *= 0.75f;
    *(f32 *)(p + 0x118) -= 0.0333333351f;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    }
}
extern void func_00175670(u8 *);
void func_001B2FF0(u8 *p) {
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x1E4) != 0x16) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        *(f32 *)(p + 0x118) += 0.0299999993f;
        if (*(f32 *)(p + 0x118) > 1.0f) *(f32 *)(p + 0x118) = 1.0f;
        if (*(s8 *)(p + 0x153) >= 0) func_00175670(p);
    }
}
extern f32 D_004B3390[];
extern V3 D_004B338C[];
void func_00144FC0(u8 *p) {
    s16 c = *(s16 *)(p + 0x1C);
    f32 d;
    *(s16 *)(p + 0x1C) = c + 1;
    d = 0.0500000007f;
    if (*(s16 *)(p + 0x1C) & 1) d = -d;
    *(f32 *)(p + 0x38) = D_004B3390[0] + d;
    if (*(s16 *)(p + 0x1C) == 0x14) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0;
        *(V3 *)(p + 0x34) = D_004B338C[0];
    }
}
extern void func_003A8B10(u8 *);
extern void func_002F0600(u8 *);
void func_002F0570(u8 *p) {
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        f32 v;
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x5A;
        *(s32 *)(p + 0x2EC) = 8;
        v = -10.0f;
        if (p[0x1E6] != 0) v = -v;
        *(f32 *)(p + 0x5C) = v;
        *(s32 *)(p + 0x68) = 0;
        func_003A8B10(p);
        func_002F0600(p);
    }
}
extern void *func_003DA750(s32, s32, s32);
void func_00397610(void);
u8 *func_00397580(u8 *p, s32 a1, s32 a2) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00397610;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = a1;
        r[0x21] = a2;
        *(s16 *)(r + 0x26) = 0x2300;
        r[1] = p[1];
        *(u16 *)(r + 0xD0) = *(u16 *)(p + 0x168);
        return r;
    }
    return 0;
}
typedef struct { s32 a, b, c; } E12;
extern u8 D_004C27D0;
extern E12 D_004B8880[], D_004B8884[];
extern void func_00122860(s32, s32);
extern void func_00122840(s32);
void func_003D14F0(void) {
    s32 v = D_004C27D0;
    if (v == 3 || v == 0xC) {
        func_00122860(D_004B8880[(u8)v].a, D_004B8884[(u8)v].a);
    } else {
        func_00122840(D_004B8880[(u8)v].a);
    }
}
extern void func_00183d50(u8 *);
void func_002BE260(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 0x16, 0x11);
    }
}
void func_00310FC0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC0C80000;
        *(u32 *)(p + 0x68) = 0x3DD55555;
        *(u32 *)(p + 0x60) = 0x41809249;
        *(u32 *)(p + 0x6C) = 0xBF676DB6;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
void func_00315AE0(u8 *p) {
    u32 t;
    *(u32 *)(p + 0x5C) = 0x41195555;
    *(u32 *)(p + 0x68) = 0xBD555555;
    *(u32 *)(p + 0x60) = 0x413C9249;
    *(u32 *)(p + 0x6C) = 0xBF22DB6D;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 0xF, 4);
    t = p[6];
    p[6] = t + 1;
}
extern u8 D_004B6BE0[];
extern u8 func_001E3940(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001E24E0(u8 *, s32);
void func_001E38B0(u8 *p) {
    u32 v = D_004B6BE0[(*(u8 **)(p + 0x1D0))[0xD]];
    if (v != 0xFF) {
        if (p[3] == 0) {
            u8 r = func_001E3940(p, v);
            if (r) v = r & 0xFF;
        }
        func_001E3710(p, v);
        func_001E24E0(p, 0x2A);
        func_001E24E0(p, 0x2B);
    }
}
extern void *func_003DA780(s32, s32, s32);
extern void func_00160AF0(void);
extern void func_00160B80(u8 *);
extern s32 D_004C2838;
extern f32 D_004F1F4C[], D_004F1FE8[];
void func_00160680(void) {
    u8 *r;
    if ((r = func_003DA780(0, 0xA, 1)) != 0) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_00160AF0;
        *(s16 *)(r + 0xCC) = 0xF0;
        *(s32 *)(r + 0x84) = D_004C2838;
        *(f32 *)(r + 0x34) = D_004F1F4C[0];
        *(f32 *)(r + 0x38) = D_004F1FE8[0];
        *(u32 *)(r + 0x3C) = 0xC71C4000;
        *(u32 *)(r + 0xD0) = 0x80002B;
        *(s16 *)(r + 0x1C) = 0;
        *(u32 *)(r + 0x74) = 0x3F800000;
        func_00160B80(r);
    }
}
