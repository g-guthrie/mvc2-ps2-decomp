typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_001757E0(void *a, s32 b, u8 c);
void func_0036CD00(u8 *a0) {
    a0[0x13C] = 1;
    *(f32 *)(a0 + 0x34) = (*(f32 **)(a0 + 0x18))[0x34 / 4];
    *(f32 *)(a0 + 0x38) = (*(f32 **)(a0 + 0x18))[0x38 / 4];
    *(f32 *)(a0 + 0x3C) = (*(f32 **)(a0 + 0x18))[0x3C / 4];
    *(f32 *)(a0 + 0x38) += 137.14285f;
    a0[0x24] = 10;
    *(u32 *)(a0 + 0x68) = 0;
    *(u32 *)(a0 + 0x6C) = 0;
    func_001757E0(a0, 0x17, 0x2C);
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
s32 func_001E3710(void *a, s32 b);
s32 func_003B5640(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x18);
    if (*(f32 *)(a0 + 0x38) - 34.285713f < *(f32 *)(p + 0x430)) {
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3710(p, 0x30);
        return 1;
    }
    return 0;
}

void func_00333F70(u8 *a0) {
    s16 t = *(s16 *)(a0 + 0x1E);
    u32 a, b;
    *(s16 *)(a0 + 0x1E) = t + 1;
    if (t >= 0x12C) {
        *(s16 *)(a0 + 0x1E) = 0;
        a0[6] = 0;
        a = a0[4];
        a0[4] = a + 1;
        a0[4] = a0[4] % 3u;
        b = a0[7];
        a0[7] = b + 1;
        a0[7] = (u32)a0[7] & 1u;
    }
}

extern u8 D_00583B9A;
extern void (*D_0045E280[])(u8 *);
void func_0032BF60(u8 *a);
void func_0032A9E0(u8 *a0) {
    if (D_00583B9A & (s8)a0[0x4DC]) {
        func_0032BF60(a0);
    } else {
        D_0045E280[a0[4]](a0);
    }
}

extern u8 D_004F20B0[];
void func_00233B70(u8 *a0, u8 *a1) {
    u8 *q = D_004F20B0 + (1 >> a0[2]) * 0x5B8;
    s32 i;
    for (i = 0; i < 3; i++) {
        u32 v = a1[i + 1];
        if ((v & 0x80) && q[5] < 2) {
            a1[i + 1] = v ^ 0x80;
        }
        q += 0xB70;
    }
}

s32 func_00175700();
void func_003266E0(u8 *a);
void func_00323E60(u8 *a0) {
    if (a0[6] == 0) {
        a0[6]++;
        a0[0x20D] = 0;
        func_001757E0(a0, 0x14, 0);
    } else {
        s8 r = func_00175700();
        if (r < 0) {
            func_003266E0(a0);
        }
    }
}

void func_004180F0(f32 a, f32 b, f32 c, f32 d);
void func_00416AA0(f32 a, s32 b, s32 c, s32 d);
void func_00417FB0(void);
extern f32 D_004F7FD0;
extern f32 D_004F7FD4;
void func_0012FC40(void) {
    func_004180F0(0.0f, 0.0f, 640.0f, 480.0f);
    func_00416AA0(0.001f, 0, 0, 0);
    func_00417FB0();
    func_004180F0(D_004F7FD0, D_004F7FD4, 640.0f, 480.0f);
}

extern void (*D_0045DC88[])(u8 *, u8 *);
void func_0018C6E0(u8 *a);
void func_003211B0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x1DC);
    func_0018C6E0(a0);
    a0[0x201] = 3;
    a0[0x2C4] = 0;
    *(s16 *)(s + 0x140) = *(s16 *)(a0 + 0x140);
    *(s16 *)(s + 0x140) = *(s16 *)(s + 0x140) ^ 1;
    s[0x1E6] = *(s8 *)(s + 0x140);
    D_0045DC88[a0[0x20B]](a0, s);
}

void func_001D8C80(u8 *a0) {
    s8 r = func_00175700(a0);
    if (r < 0) {
        u32 t = a0[5];
        a0[5] = t + 1;
        a0[0x13C] = 1;
        if (a0[0x21] == 0) {
            a0[0x168] = 8;
        } else {
            a0[0x168] = 9;
        }
        func_001757E0(a0, 0x17, a0[0x168]);
        *(s16 *)(a0 + 0x1C) = 0x5A;
    }
}

void func_0015B200(u8 *a, u8 *b, s32 c, s32 d);
void func_00175910(u8 *a, s32 b, s32 c, s32 d);
void func_003A4340(u8 *a);
void func_003A4160(u8 *a0) {
    if (*(s8 *)(a0 + 0x1B2)) {
        a0[4] = 2;
        a0[0x13C] = 0;
        func_0015B200(a0, a0 + 0x34, 1, 0x88);
    } else {
        s16 t = *(s16 *)(a0 + 0x1C) - 1;
        *(s16 *)(a0 + 0x1C) = t;
        if (t == 0) {
            a0[5] = 4;
            func_00175910(a0, 0x17, 5, *(s8 *)(a0 + 0x151));
        } else {
            func_003A4340(a0);
        }
    }
}

s32 func_001E7FD0();
s32 func_002A0560(u8 *a0) {
    s32 r = 0;
    if ((*(u16 *)(a0 + 0x20E) & 0xC00) && a0[0x212] == 0 && a0[0x1B7] != 0) {
        r = func_001E7FD0();
        if (r != 0) {
            u8 t = a0[0x20D];
            if (t == 2) {
                a0[0x20B] = 1;
            } else if (t == 0) {
                a0[0x20B] = 0;
            } else {
                r = 0;
            }
        }
    }
    return r;
}

void func_0015D010(u8 *a, f32 *b);
void func_0018C6E0(u8 *a);
void func_002B7AE0(u8 *a0) {
    f32 v[3];
    a0[0x1B4] = 10;
    if ((a0[0x22] << 10) & 0x800) {
        u32 t;
        *(s16 *)(a0 + 0x140) = *(s16 *)(a0 + 0x140) ^ 1;
        t = a0[0x1E6];
        a0[0x1E6] = t ^ 1;
    }
    v[0] = -53.333332f;
    v[1] = 171.42856f;
    func_0015D010(a0, v);
    func_0018C6E0(a0);
    func_001757E0(a0, 0xF, 0);
}

void func_00175670();
void func_00194C30(u8 *a, u8 *b);
void func_001975C0(u8 *a, u8 *b);
void func_00195250(u8 *a0, u8 *a1) {
    u8 *p = a0 + 0x88;
    if (a1[5] != 0 || a1[0x1E4] != 0 || *(s8 *)(a1 + 0x161) == 0) {
        *p = 1;
        func_00194C30(a0, a1);
    } else if (a0[0x21] < 4) {
        func_00175670();
        func_001975C0(a0, a1);
    }
}

void func_00184540(u8 *a);
void func_002AFBD0(u8 *a0) {
    f32 t;
    s8 r;
    *(f32 *)(a0 + 0x34) += *(f32 *)(a0 + 0x5C);
    *(f32 *)(a0 + 0x5C) += *(f32 *)(a0 + 0x68);
    *(f32 *)(a0 + 0x38) += *(f32 *)(a0 + 0x60);
    *(f32 *)(a0 + 0x60) += *(f32 *)(a0 + 0x6C);
    t = *(f32 *)(a0 + 0x430);
    if (t > *(f32 *)(a0 + 0x38)) {
        *(f32 *)(a0 + 0x38) = t;
    }
    r = func_00175700(a0);
    if (r < 0) {
        func_00184540(a0);
    }
}

void func_001266A0(u8 *a, s32 b, s32 c);
void func_002A5E80(u8 *a0) {
    f32 v[3];
    u8 *p;
    func_001266A0(a0, 6, 6);
    a0[0x1B4] = 10;
    v[0] = -120.0f;
    v[1] = 120.0f;
    v[2] = 0.0f;
    func_0015D010(a0, v);
    p = *(u8 **)(a0 + 0x1DC);
    if (*(u32 *)(p + 0x42C) & 0x4000000) {
        *(f32 *)(p + 0x38) = *(f32 *)(a0 + 0x430) + 68.57143f;
    }
    func_001757E0(a0, 0xF, 6);
}

s32 func_00189310(u8 *a, void *b, u8 *c);
void func_0018A990(u8 *a, u8 *b);
s32 func_0025C240(u8 *a);
void func_00186A60(u8 *a, s32 b);
extern u8 D_00453990[];
u8 *func_003DA750(s32 a, s32 b, s32 c);
void func_0036AB90(void);
void func_0036AAF0(u8 *a0, u8 a1, u8 a2) {
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        *(void **)(p + 0x10) = func_0036AB90;
        *(u32 *)(p + 0x18) = *(u32 *)(a0 + 0x18);
        *(u8 **)(p + 0x14) = a0;
        p[0x20] = a1;
        p[0x23] = a2;
        *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x14) + 0x140);
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
        *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    }
}
