typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004C1D50[2])(u8 *p);
extern void func_00381550(u8 *p);

void func_00381920(u8 *a) {
    if ((*(u8 **)(a + 24))[4] >= 2) {
        u32 t = a[4];
        a[4] = t + 1;
        a[316] = 0;
    } else {
        D_004C1D50[a[5]](a);
        func_00381550(a);
    }
}

extern u8 func_001748C0(f32 *p, f32 *v);
extern void func_001CAD00(u8 *p);

void func_001CAC90(u8 *a) {
    f32 v[3];
    u8 *s = *(u8 **)(a + 24);
    v[0] = *(f32 *)(s + 52) + *(f32 *)(a + 92);
    v[1] = *(f32 *)(s + 56) + *(f32 *)(a + 96);
    a[34] = ((func_001748C0((f32 *)(a + 52), v) + 4) >> 3) & 31;
    func_001CAD00(a);
}

extern void func_00186CE0(u8 *p, s32 n);
extern void func_001845F0(u8 *p, s32 n);
extern void func_00186A60();
extern void func_00184650(u8 *p);

void func_00184570(u8 *a) {
    a[316] = 1;
    if (a[533]) {
        func_00186CE0(a, 24);
    } else if (a[528]) {
        func_001845F0(a, 3);
    } else {
        func_00186A60(a);
        a[6] = 1;
        func_00184650(a);
    }
}

extern void func_001266A0(u8 *p, s32 a, s32 b);
extern void func_0018C6E0(u8 *p);
extern void func_0015D010(u8 *p, f32 *v);
extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_0020F490(u8 *a) {
    f32 v[3];
    func_001266A0(a, 5, 5);
    a[436] = 10;
    func_0018C6E0(a);
    v[0] = -71.66666412353516f;
    v[1] = 137.14285278320312f;
    v[2] = 0.0f;
    func_0015D010(a, v);
    func_001757E0(a, 15, 3);
}

extern void func_0038E3A0(u8 *p);
extern void (*D_00471A40[4])(u8 *p);
extern void (*D_00471A50[4])(u8 *p);

void func_0038DB70(u8 *a) {
    func_0038E3A0(a);
    if (a[32] == 0) {
        D_00471A40[a[4]](a);
    } else {
        D_00471A50[a[4]](a);
    }
}

extern void func_002F4710(u8 *p);
extern s8 func_00175700(u8 *p);
extern s32 func_003AA280(u8 *p);
extern void func_001E3210(u8 *p, s32 n);

void func_002F47B0(u8 *a) {
    u16 x = *(s16 *)(a + 866) & 864;
    *(u16 *)(a + 870) |= x;
    func_002F4710(a);
    func_00175700(a);
    if (*(s8 *)(a + 337)) {
        if (func_003AA280(a) == 0) {
            a[6] = 3;
        } else {
            u32 t = a[6];
            a[6] = t + 1;
            func_001E3210(a, 32);
        }
    }
}

void func_0013FC20(u8 *a) {
    s16 t = *(s16 *)(a + 30);
    if (t != 0) {
        *(s16 *)(a + 30) = t - 1;
    } else {
        a[316] = 1;
        if (*(s16 *)(a + 28) == 30) {
            *(f32 *)(a + 80) = 128.2f;
        } else {
            *(s16 *)(a + 28) = *(s16 *)(a + 28) + 1;
            *(f32 *)(a + 80) = 1.0f + 127.2f * (f32)*(s16 *)(a + 28) / 30.0f;
        }
    }
}

extern void func_001820A0(u8 *p);
extern void func_00182300(u8 *p);
extern void func_00184540(u8 *p);
extern void func_0030D3E0(u8 *p);
extern s32 func_001864A0(u8 *p);
extern void func_001865B0(u8 *p);

void func_0030D350(u8 *a) {
    func_001820A0(a);
    func_00182300(a);
    if (*(s32 *)(a + 820) == 0) {
        if (func_00175700(a) < 0) {
            func_00184540(a);
            return;
        }
    } else {
        func_0030D3E0(a);
    }
    if (func_001864A0(a)) {
        func_001865B0(a);
    }
}

typedef struct { f32 x, y, z; } V3;
extern void func_001754A0(u8 *p, s32 a, u8 b);

void func_00198890(u8 *a) {
    u8 *s = *(u8 **)(a + 24);
    *(V3 *)(a + 52) = *(V3 *)(s + 52);
    *(f32 *)(a + 52) += *(f32 *)(s + 100);
    if (a[34] == 0) {
        a[36] = 10;
        func_001754A0(a, 27, a[439] + 6);
    } else {
        a[36] = 12;
        func_001754A0(a, 27, a[439] + 9);
    }
}

extern void func_001C3290(u8 *a, u8 *b);

void func_001C3200(u8 *a, u8 *b) {
    u32 t = a[7];
    a[7] = t + 1;
    *(s32 *)(a + 92) = 0;
    *(s32 *)(a + 104) = 0;
    *(s32 *)(a + 96) = 0;
    *(s32 *)(a + 108) = 0;
    if (*(f32 *)(b + 52) <= *(f32 *)(a + 52)) {
        *(s16 *)(a + 320) = 0;
    } else {
        *(s16 *)(a + 320) = 1;
    }
    func_001757E0(a, 25, 14);
    func_001C3290(a, b);
}

extern void func_0016CED0(void);
extern s32 D_004F1CB8[3];

void func_002AE520(u8 *a) {
    s16 t;
    u32 u;
    a[1036] = 2;
    a[828] = 5;
    a[510] = 1;
    a[513] = 2;
    a[521] = 2;
    t = *(s16 *)(a + 28) - 1;
    *(s16 *)(a + 28) = t;
    if (t <= 0) {
        u = a[6];
        a[6] = u + 1;
        *(s16 *)(a + 28) = 64;
        *(s16 *)(a + 30) = 4;
        func_001757E0(a, 15, 7);
        func_0016CED0();
        D_004F1CB8[0] = 2;
    }
}

extern void func_00185490(u8 *p);
extern void func_00175910(u8 *p, s32 a, s32 b, s32 c);

void func_00220F70(u8 *a) {
    func_00185490(a);
    if (a[486]) {
        *(f32 *)(a + 92) = -0.8333333134651184f;
        *(f32 *)(a + 104) = 0.0032552082557231188f;
    } else {
        *(f32 *)(a + 92) = 0.8333333134651184f;
        *(f32 *)(a + 104) = -0.0032552082557231188f;
    }
    *(f32 *)(a + 96) = 13.928570747375488f;
    *(f32 *)(a + 108) = -0.8035714030265808f;
    func_00175910(a, 1, 2, 1);
}

void func_00271930(u8 *a) {
    u32 t;
    if (*(s8 *)(a + 337) == 0) func_00175700(a);
    *(f32 *)(a + 52) += *(f32 *)(a + 92);
    *(f32 *)(a + 92) += *(f32 *)(a + 104);
    *(f32 *)(a + 56) += *(f32 *)(a + 96);
    *(f32 *)(a + 96) += *(f32 *)(a + 108);
    if (*(f32 *)(a + 96) < 0.0f) {
        t = a[7];
        a[7] = t + 1;
    }
}

extern s16 D_004C27A4;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003544F0(void);

/* Callers pass a signed halfword state; truncation occurs at the byte store. */
s32 func_00354460(u8 *a, s32 b) {
    s32 i;
    u8 *p;
    if (D_004C27A4 < 3) return 0;
    i = 0;
    do {
        p = func_003DA750(0, 1, 1);
        *(s16 *)(p + 38) = 0x700;
        p[32] = b;
        p[33] = i;
        *(void **)(p + 16) = func_003544F0;
        i++;
        *(u8 **)(p + 24) = a;
    } while (i < 2);
    return 1;
}

extern void func_001E7F60(u8 *p);

void func_003B07D0(u8 *a) {
    s8 t;
    if (*(s8 *)(a + 435)) {
        a[4] = 2;
        a[6] = 1;
        a[7] = 0;
    } else {
        func_001E7F60(a);
        t = *(s8 *)(a + 434);
        if (t) {
            if ((t & 1) || (t & 16)) {
                a[4] = 2;
                a[6] = 1;
                a[7] = 0;
            } else {
                a[4] = 2;
                a[6] = 2;
                a[7] = 0;
            }
        }
    }
}

extern void func_001843A0(u8 *p);
extern void func_00183920(u8 *p, f32 *v);
extern void func_001E3710(u8 *p, s32 n);

void func_002325E0(u8 *a) {
    f32 v[3];
    if (func_00175700(a) < 0) {
        func_001843A0(a);
        return;
    }
    if (*(s8 *)(a + 337)) {
        a[337] = 0;
        v[0] = 26.66666603088379f;
        v[1] = 102.85713958740234f;
        func_00183920(a, v);
    }
    if (a[347]) {
        a[347] = 0;
        func_001E3710(a, 22);
    }
}

void func_001C2200(u8 *a, u8 *b) {
    if (b[0] && b[1061] == 0) {
        a[6] = 2;
        a[7] = 0;
        a[0] = 1;
        a[316] = 1;
        if (*(s16 *)(b + 320) == 0) {
            *(f32 *)(a + 52) = 80.0f + *(f32 *)(b + 52);
        } else {
            *(f32 *)(a + 52) = *(f32 *)(b + 52) - 80.0f;
        }
        *(f32 *)(a + 56) = *(f32 *)(b + 1072);
        func_001757E0(a, 25, 0);
    }
}

extern void (*D_0044C220[])(u8 *a, u8 *b);

void func_001BCAC0(u8 *a, u8 *b) {
    D_0044C220[a[5]](a, b);
    if ((*(s16 *)(a + 320) = *(s16 *)(b + 320)) == 0) {
        *(f32 *)(a + 52) = *(f32 *)(b + 52) + *(f32 *)(a + 92);
    } else {
        *(f32 *)(a + 52) = *(f32 *)(b + 52) - *(f32 *)(a + 92);
    }
    *(f32 *)(a + 56) = *(f32 *)(b + 56) + *(f32 *)(a + 96);
    *(s8 *)(a + 36) = *(s8 *)(b + 36) - 1;
}

extern struct { s32 pad0; s32 n; s32 pad[2]; f32 f[129]; } D_004F1D20;

void func_0016D1C0(void) {
    s32 i;
    for (i = 0; i < D_004F1D20.n; i++) {
        D_004F1D20.f[i] = 1.0f - (f32)i / (f32)D_004F1D20.n;
    }
    for (; i < 129; i++) {
        *(s32 *)&D_004F1D20.f[i] = 0;
    }
}

extern s32 func_0016B250(u8 *a, s32 n);
extern void func_0016B0C0(u8 *a, u8 *b, s32 n);
extern u8 *func_0016A3F0(u8 *a);
extern s32 func_0016A8B0(u8 *a, u8 *r, s32 n);
extern s32 func_00166C80(u8 *a, u8 *b, s32 n);

s32 func_00166090(u8 *a, u8 *b) {
    u8 *r;
    if (func_0016B250(a, 4) == 0) return 0;
    func_0016B0C0(a, b, 0);
    r = func_0016A3F0(a);
    if (r == 0) {
        return func_00166C80(a, b, 0);
    }
    return func_00166C80(a, b, func_0016A8B0(a, r, r[437] & 127));
}

extern s32 func_00184B30(u8 *a);
extern s32 func_00184720(u8 *a);
extern s32 func_00185A90(u8 *a);
extern s32 func_00184C60(u8 *a);
extern void func_00186120(u8 *a);

void func_00179FC0(u8 *a) {
    if (func_00184B30(a)) return;
    if (func_00184720(a)) return;
    if (func_00185A90(a)) return;
    if (func_00184C60(a)) return;
    if ((*(u8 **)(a + 476))[484]) {
        *(s8 *)(a + 487) = -1;
        func_00186CE0(a, 2);
    } else {
        func_00175700(a);
        func_00186120(a);
    }
}
