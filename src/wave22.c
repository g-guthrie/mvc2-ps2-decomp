typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175670(void *);
extern int func_00174470(const void *);
extern void func_00186A60(void *, s32);
extern void *func_003DA750(s32, s32, s32);
extern void func_00170DF0(u32);
extern void func_0033CAB0(void);
extern s32 D_004C283C;



void func_0015F2B0(u8 *a0) {
    f32 *f = (f32 *)a0;
    s16 t = *(s16 *)(a0 + 0x1E) - 1;
    *(s16 *)(a0 + 0x1E) = t;
    if (t != 0) {
        f[0x54 / 4] = f[0x54 / 4] - 0.05f;
    } else {
        f[0x50 / 4] = 1.0f;
        f[0x54 / 4] = 1.0f;
        { u32 q = a0[4]; a0[4] = q + 1; }
        *(s16 *)(a0 + 0x1E) = 0x28;
    }
}


void func_0033CA40(void) {
    u8 *p = func_003DA750(0, 6, 1);
    if (p != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_0033CAB0;
        *(s16 *)(p + 0xCC) = 2;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(s32 *)(p + 0xD0) = 0x800820;
        *(f32 *)(p + 0x74) = 0.5f;
        func_00170DF0((u32)*(s32 *)(p + 0x84));
    }
}

extern u8 *D_004C2840;
extern void (*D_00440600[])(u8 *);
extern void func_003DAA40(void);

void func_0013DD10(u8 *a0) {
    u8 *g = D_004C2840;
    if (*(s8 *)(g + 3) != 2 || *(s16 *)(g + 0xE) == 3) {
        func_003DAA40();
    } else {
        D_00440600[a0[5]](a0);
    }
}

void func_003D8F90(u8 *a0) {
    a0[0x30] = 6;
    a0[0x31] = 1;
    a0[0x32] = 0;
    switch (*(s8 *)(D_004C2840 + 0x8D)) {
    case 0:
        a0[0x30] = 6;
        a0[0x31] = 1;
        break;
    case 1:
        a0[0x30] = 4;
        a0[0x31] = 1;
        break;
    case 2:
        a0[0x30] = 2;
        a0[0x31] = 1;
        break;
    }
}

extern s32 func_00175700(void *);
extern void func_001E3240(void *, s32);
extern void func_00184540(void *);
extern void func_001843A0(void *);

void func_00212760(u8 *a0) {
    s8 r = func_00175700(a0);
    if (r < 0) {
        func_001E3240(a0, 0x1F);
        func_001E3240(a0, 0x20);
        if (a0[0x20D] == 2) {
            func_00184540(a0);
        } else {
            func_001843A0(a0);
        }
    }
}

extern u8 D_004F20B0[];
extern void func_001806B0(void *, void *);
extern void func_00326A30(void);

void func_00180640(void *a0) {
    u8 i;
    s32 off = 0;
    for (i = 0; i < 6; i++) {
        func_001806B0(D_004F20B0 + off, a0);
        off += 0x5B8;
    }
    func_00326A30();
}

extern s32 func_0018A460();

s32 func_0018A290(void *a0, u8 *a1, u8 *a2, s16 a3) {
    u16 m = a3 & *(s16 *)(a1 + 8);
    if (m != 0) return 0;
    if (func_0018A460(a0, a1, a2, m)) {
        a2[0] = 0;
        return 1;
    }
    { u32 q = a2[0]; a2[0] = q + 1; }
    a2[1] = 10;
    return 0;
}

extern void func_002CDA00(void *);
extern s32 func_00100240(double, s32);

void func_002CDD70(u8 *a0) {
    f32 *f = (f32 *)a0;
    f32 old, nw;
    func_002CDA00(a0);
    old = f[0x5C / 4];
    f[0x34 / 4] += old;
    f[0x5C / 4] += f[0x68 / 4];
    nw = f[0x5C / 4];
    if (func_00100240((double)(nw * old), 0)) {
        u32 q = a0[6];
        a0[6] = q + 1;
    }
    func_00175700(a0);
}

extern void func_00185870(void *, void *);
extern void func_003C0240(void *, void *);

void func_003C01C0(u8 *a0, u8 *a1) {
    u32 q = a0[5];
    u8 *c = *(u8 **)(a0 + 0x1C4);
    a0[5] = q + 1;
    {
    a0[0x24] = *(s8 *)(c + 0x24);
    a1[0x1B1] = 0;
    a1[0x20B] = 0xC3;
    func_00185870(a0, c);
    }
    *(s32 *)(a0 + 0xD4) = *(s32 *)(a1 + 0x1DC);
    *(s16 *)(a0 + 0x1C) = 0x78;
    *(s16 *)(a0 + 0x1E) = 0;
    func_003C0240(a0, a1);
}

extern void func_001B9B40(void);

u8 *func_001B9AC0(u8 *a0, u8 a1) {
    u8 *p = func_003DA750(0, 3, 0);
    if (p != 0) {
        *(void **)(p + 0x10) = func_001B9B40;
        *(u8 **)(p + 0x18) = a0;
        p[0x20] = a1;
        *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
        *(s16 *)(p + 0x26) = 0x1700;
        *(u16 *)(p + 0xD0) = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    } else {
        p = 0;
    }
    return p;
}

extern void func_003C64C0(void *);
extern void func_001757E0(void *, s32, s32);
extern void func_001E7F60(void *);

void func_003C62C0(u8 *a0) {
    if (*(s8 *)(a0 + 0x1B3) != 0) {
        func_003C64C0(a0);
    } else {
        s8 r = func_00175700(a0);
        if (r < 0) {
            u32 q = a0[5];
            a0[5] = q + 1;
            a0[0x1B1] = 0;
            func_001757E0(a0, 0x15, 0x19);
        }
        func_001E7F60(a0);
    }
}

extern void func_00183920(void *, void *);

void func_003150A0(u8 *a0) {
    s8 r = func_00175700(a0);
    if (r < 0) {
        func_001843A0(a0);
    } else {
        s8 b = *(s8 *)(a0 + 0x151);
        if (b & 1) {
            f32 v[4];
            *(s8 *)(a0 + 0x151) = b & ~1;
            v[0] = 61.666664123535156f;
            v[1] = 117.85713958740234f;
            func_00183920(a0, v);
        }
    }
}

extern s8 D_00448AE0[];

void func_0017A060(u8 *a0) {
    s8 t = *(s8 *)(a0 + 0x251) - 1;
    *(s8 *)(a0 + 0x251) = t;
    if (t < 0) {
        *(s8 *)(a0 + 0x251) = 1;
        *(f32 *)(a0 + 0x38) = *(f32 *)(a0 + 0x38) - 2.14285707473755f * (f32)D_00448AE0[*(s8 *)(a0 + 0x252)];
        *(s8 *)(a0 + 0x252) = (*(s8 *)(a0 + 0x252) + 1) % 40;
    }
}

extern void (*D_004C19B0[2])(void *, void *);

void func_00348BB0(u8 *a0, u8 *a1) {
    u8 *s = a1 + 0x2B8;
    *(s8 *)(a0 + 0x31) = -6;
    if (func_00174470(a0) == 0) {
        s[0x1A] = 0;
        { u32 q = a0[4]; a0[4] = q + 1; }
        a0[0x13C] = 0;
    } else {
        D_004C19B0[a0[5]](a0, a1);
    }
}

typedef struct { f32 x, y, z; } V3;
extern void func_001754A0(void *, s32, s32);

void func_0019A730(u8 *a0, u8 *a1) {
    f32 *d = (f32 *)a0;
    f32 *s = (f32 *)a1;
    *(s8 *)(a0 + 0x31) = -1;
    *(V3 *)(a0 + 0x34) = *(V3 *)(a1 + 0x34);
    if (*(s16 *)(a0 + 0x140) != 0) {
        d[0x34 / 4] += 30.0f;
    } else {
        d[0x34 / 4] = d[0x34 / 4] - 30.0f;
    }
    d[0x38 / 4] += 212.14285278320312f;
    func_001754A0(a0, 0x1B, 4);
}

void func_002C77A0(u8 *a0) {
    u8 *p = a0 + 0x2B8;
    a0[0x33A] = 0xFF;
    if (*(s8 *)(a0 + 0x161) != 0) p[4] = 1;
    if (*(s8 *)(a0 + 0x151) != 0) *(s8 *)(a0 + 0x151) = 0;
    if ((s8)func_00175700(a0) < 0) {
        u32 q = a0[6];
        a0[6] = q + 1;
        *(s16 *)(a0 + 0x1E) = 10;
        a0[0x13C] = 0;
        a0[0x209] = 1;
    }
}

extern void func_001865B0(void *);

void func_002399C0(u8 *a0) {
    f32 *f = (f32 *)a0;
    f[0x34 / 4] += f[0x5C / 4];
    f[0x5C / 4] += f[0x68 / 4];
    f[0x38 / 4] += f[0x60 / 4];
    f[0x60 / 4] += f[0x6C / 4];
    func_00175700(a0);
    if (f[0x38 / 4] < f[0x430 / 4]) {
        f[0x38 / 4] = f[0x430 / 4];
        a0[0x20D] = 0;
        func_001865B0(a0);
    }
}

extern void func_001E3710(void *, s32);
extern void func_00183D50(void *);

void func_00221A90(u8 *a0) {
    f32 *f = (f32 *)a0;
    func_00175700(a0);
    if (!(f[0x430 / 4] < f[0x38 / 4])) {
        u32 q = a0[6];
        a0[6] = q + 1;
        f[0x38 / 4] = f[0x430 / 4];
        a0[0x210] = 0;
        func_001E3710(a0, 0x34);
        a0[0x20D] = 0;
        *(s32 *)(a0 + 0x5C) = 0;
        *(s32 *)(a0 + 0x60) = 0;
        *(s32 *)(a0 + 0x68) = 0;
        *(s32 *)(a0 + 0x6C) = 0;
        func_001757E0(a0, 0x15, 0xE);
        func_00183D50(a0);
    }
}

extern void func_00396E30(void);

void func_00396C80(u8 *a0, f32 x, f32 y) {
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        *(void **)(p + 0x10) = func_00396E30;
        p[0x20] = 0;
        *(u8 **)(p + 0x18) = a0;
        *(s16 *)(p + 0x26) = 0x2201;
        if (a0[0x1E6] != 0) x = -x;
        *(u16 *)(p + 0x9A) = *(u16 *)(a0 + 0x168);
        p[0x98] = 0;
        *(f32 *)(p + 0x90) = x;
        *(f32 *)(p + 0x94) = y;
    }
}

void func_00267600(u8 *a0) {
    if ((s8)func_00175700(a0) < 0) {
        u16 b = *(u16 *)(a0 + 0x354);
        if ((b & 0x3000) == 0 || (b & 0x2000) != 0) {
            a0[7] = 1;
            func_001757E0(a0, 0x16, 0x29);
        }
        if ((*(u16 *)(a0 + 0x354) & 0x1000) != 0) {
            a0[7] = 5;
            func_001757E0(a0, 0x16, 0x2C);
        }
    }
}

extern void func_00344E00(u8 *);
extern V3 D_00460DE0[];

void func_00344FF0(s32 a0) {
    u8 *p = func_003DA750(0, 6, 1);
    if (p != 0) {
        p[0x13C] = 1;
        *(void **)(p + 0x10) = func_00344E00;
        *(s16 *)(p + 0xCC) = a0 + 0xC;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(s32 *)(p + 0xD0) = 0xD01;
        *(V3 *)(p + 0x34) = D_00460DE0[a0];
    }
}

extern void func_0018F630(void *, s32);

void func_0018F4C0(u8 *a0) {
    a0[5] = 3;
    a0[7] = 0;
    a0[6] = 0;
    a0[0x24C] = 0;
    a0[0x13C] = 1;
    *(s32 *)(a0 + 0x48) = 0;
    *(V3 *)(a0 + 0x50) = *(V3 *)(a0 + 0x298);
    *(f32 *)(a0 + 0x118) = 1.0f;
    func_00186A60(a0, 0x20);
    a0[0x247] = 2;
    a0[0x242] = 0x1E;
    a0[0x243] = 5;
    a0[0x248] = 1;
    func_0018F630(a0, 5);
}

extern s32 func_00174170(void);
extern s16 D_004C2040[4];

void func_003B8EA0(u8 *a0) {
    f32 *f = (f32 *)a0;
    f[0x34 / 4] += f[0x5C / 4];
    f[0x5C / 4] += f[0x68 / 4];
    f[0x38 / 4] += f[0x60 / 4];
    f[0x60 / 4] += f[0x6C / 4];
    if (f[0x60 / 4] < 0.0f) {
        u32 q = a0[6];
        a0[6] = q + 1;
        *(s16 *)(a0 + 0x1C) = D_004C2040[func_00174170() & 3];
    }
}

typedef struct { s32 n; s32 m; u8 p1[8]; f32 x; u8 p2[0x10]; f32 a; f32 b; u8 p3[2]; u8 c; u8 p4; } S32D;
extern void func_0032D2F0(S32D *);

void func_0032D4E0(u8 *a0, s32 n, f32 x, u8 c) {
    S32D s;
    s.n = n;
    s.m = s.n + s.n * (s.n - 1) / 2;
    s.x = x - *(f32 *)(a0 + 0x3C);
    s.c = c;
    if (s.n == 0) {
        s.b = 0;
        s.a = 0;
    } else {
        func_0032D2F0(&s);
    }
    *(f32 *)(a0 + 0x64) = s.a;
    *(f32 *)(a0 + 0x70) = s.b;
}
