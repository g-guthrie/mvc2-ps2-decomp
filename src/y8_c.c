typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern f32 D_004643BC[];
extern f32 D_004F1FD0;
extern u8 *D_004C2794;
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

void func_003258B0(u8 *p) {
    extern u8 *func_003CA900();
    extern void func_001757E0();
    extern void func_00325960();
    u8 *o;
    u32 t;
    f32 f;
    t = p[6];
    p[6] = t + 1;
    *(s16 *)(p + 0x1C) = 0x1E;
    *(s16 *)(p + 0x1E) = 0xC;
    if ((o = func_003CA900(p, 0x12)) != 0) {
        f = 53.33333206176758f;
        if (*(s16 *)(p + 0x140) != 0) f = -f;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + f;
        *(f32 *)(o + 0x38) = 68.57142639160156f + D_004F1FD0;
    }
    func_001757E0(p, 0x16, 0x14);
    func_00325960(p);
}

void func_0025BCD0(u8 *p) {
    f32 *a1, *a2, *a3, *t0;
    f32 c;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a1 = (f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x68);
    a2 = (f32 *)(p + 0x60);
    t0 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        *t0 = 0;
        if (p[0x1E6] != 0) {
            c = -12.857142448425293f;
        } else {
            c = 12.857142448425293f;
        }
        *(f32 *)(p + 0x5C) = c;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
}

void func_00251F20(u8 *p) {
    extern void func_00175700();
    extern void func_001AD170();
    extern void func_001757E0();
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001AD170(p, 0x13, 0);
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 3;
        func_001757E0(p, 0x16, 6);
    }
}

static void func_00191F50(u8 *p) {
    u32 t = p[0x12];
    if (t != 0) p[0x12] = t - 1;
    else p[0x13] = 1;
}
void func_001926F0(u8 *p) {
    extern void func_001928E0();
    extern void func_00191EF0();
    extern void func_00175700();
    extern void func_00184540();
    f32 *a1, *a2, *a3, *t0;
    s16 h;
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x18;
        func_001928E0(p, 0x4E2, 0x14);
        func_00191EF0(p, p[0x22]);
    }
    func_00175700(p);
    a1 = (f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x68);
    a2 = (f32 *)(p + 0x60);
    t0 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00191F50(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        *t0 = 0;
        func_00184540(p);
    }
}

s32 func_0016A7C0(u8 *p, u8 *q, s32 a, s32 b) {
    extern f32 func_0016ABA0();
    u8 *s0, *s1;
    f32 f20, d, z;
    s16 h0;
    s32 v;
    s0 = *(u8 **)(p + 0x180);
    s1 = *(u8 **)(q + 0x180);
    s1 += b * 8;
    s0 += a * 8;
    f20 = func_0016ABA0(q, s1, 0);
    d = f20 - func_0016ABA0(p, s0, 0);
    z = 0.0f;
    if (d < z) d = -d;
    v = *(s16 *)(s0 + 2);
    if (v == 0) return 0;
    h0 = v;
    return d < 1.6666666269302368f * (f32)(h0 + *(s16 *)(s1 + 2));
}

void func_003655C0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    u32 t;
    f32 c;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 3;
        if (*(s16 *)(p + 0x140) != 0) {
            c = -1.6666666269302368f;
        } else {
            c = 1.6666666269302368f;
        }
        *(f32 *)(p + 0x5C) = c;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_001757E0(p, 0x17, 4);
    }
}

void func_0020FB40(u8 *p) {
    extern s8 func_00175700();
    extern void func_001266A0();
    extern void func_001757E0();
    u8 *q;
    u32 t;
    f32 c;
    if (func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x21;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            c = -13.333333015441895f;
        } else {
            c = 13.333333015441895f;
        }
        *(f32 *)(p + 0x5C) = c;
        if (p[0x1E6] != 0) {
            c = 0.20833332836627960f;
        } else {
            c = -0.20833332836627960f;
        }
        *(f32 *)(p + 0x68) = c;
        func_001757E0(p, 2, 1);
    }
}
