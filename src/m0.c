typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00185980(void *p);

extern void (*D_0044EE60[])(u8 *, u8 *);
void func_001DF210(u8 *a0, u8 *a1) {
    *(s8 *)(a0 + 0x24) = *(s8 *)(a1 + 0x24);
    if (a1[0x169] != a0[0xD1]) {
        u32 t = a0[4];
        a0[4] = t + 1;
    } else {
        D_0044EE60[a0[5]](a0, a1);
    }
}

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
void func_001F3040(u8 *p) {
    u8 *q = p + 0x2B8;
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        q[2] = 0;
        func_001757E0(p, 0xF, 0x26);
    }
}

extern s32 func_00189660(void *p, void *a, void *b);
extern void func_00186A60(void *p, s32 a);
extern u8 D_00450AB0[];

extern u8 *D_004C2794;
void func_00230670(u8 *p, u8 *context) {
    s8 v = p[0x151];
    u32 low = (u8)v & 0xF;
    if (low) {
        s8 l = low;
        p[0x151] = v & ~0xF;
        p[0x1B5] = l + 0x4F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        { s16 *q = (s16 *)D_004C2794; q[p[2] + 0x3E]++; }
    }
}

static void func_00255620(u8 *a0) {
    if (*(s16 *)(a0 + 0x2B8) > 0) {
        a0[0x40D] = 0;
        a0[0x40C] = 0;
        a0[0x33C] = 5;
    } else {
        a0[0x40D] = 0;
        a0[0x40C] = 0;
        a0[0x33B] = 0;
        a0[0x33C] = 0;
    }
}
extern void func_0036A930(void *p, s32 a, s32 b, s32 c);
extern s32 func_001843A0(void *p);
void func_0025A130(u8 *p) {
    func_00255620(p);
    if (*(s8 *)(p + 0x151) == 4) {
        p[0x151] = 0;
        func_0036A930(p, 5, 0, 1);
    }
    {
        s8 r = func_00175700(p);
        if (r < 0) func_001843A0(p);
    }
}

void func_00392F00(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x140) ^= 1;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 0x17, 4);
    }
}

extern void *func_003996C0(void *p, u8 a);
s32 func_002CB3A0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 0;
        if (!func_003996C0(p, 2)) return func_001843A0(p);
    }
}

extern void func_0019B110(void *p, s32 a);
void func_0031F340(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(u32 *)(p + 0x5C) = 0xC2200000;
        if (p[0x1E6]) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_0019B110(p, 5);
    }
}

void func_001D5CF0(u8 *a0, u8 *a1) {
    u8 *q = a1 + 0x2B8;
    *(s8 *)(a0 + 0x24) = *(s8 *)(a1 + 0x24) + *(s8 *)(a0 + 0x31);
    if (*(s8 *)(a0 + 0x24) > 7) *(s8 *)(a0 + 0x24) = 7;
    if (*(s8 *)(a0 + 0x24) < 0) *(s8 *)(a0 + 0x24) = 0;
    func_00175700(a0);
    if (q[1]) {
        u32 t = a0[4];
        a0[4] = t + 1;
    }
}

extern void func_001CEA00(void *p, s32 a);
void func_002C74F0(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x12, 2);
    }
}

void func_002C7460(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= 51.4285698f + *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001CEA00(p, 0xD);
    }
}

typedef struct { f32 x, y, z; } V3;

extern s32 func_00174170(void *p);
extern s32 func_003D92F0(void *p);
extern void func_002F1DF0(void *p);
extern u8 D_004C1248[8];
void func_002EF220(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        s32 b;
        p[6] = t + 1;
        b = func_00174170(p) & 1;
        func_001757E0(p, 0x13, (u8)(D_004C1248[p[0x20]] + b));
    } else {
        func_00175700(p);
        if (func_003D92F0(p)) func_002F1DF0(p);
    }
}

extern void func_00178F20(void *a, void *b);
extern void func_001E3710(void *a, s32 b);
s32 func_0036F5A0(u8 *a0, u8 *a1, s32 *a2) {
    if (*a2) {
        u8 *s0 = *(u8 **)(a1 + 0x220);
        a1[0x1FE] = 1;
        func_00178F20(a0, s0);
        if (*(s8 *)(*(u8 **)(a0 + 0x18) + 0x151) == 0xF) {
            s0[0x20A] = 1;
            s0[0x1B5] = 0x3D;
            *a2 = 0;
            func_001E3710(s0, 2);
        }
    }
    return *a2;
}

extern u8 D_004F20B4, D_004F20B5, D_004F20B6, D_004F20B7, D_004F2294, D_004F2295, D_004F2298, D_004F2299;
extern u8 D_004F266C, D_004F266D, D_004F266E, D_004F266F, D_004F284C, D_004F284D, D_004F2850, D_004F2851;

void func_002295E0(u8 *p) {
    f32 a, b;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    t = p[6];
    p[6] = t + 1;
    func_001757E0(p, 0x16, 1);
    *(s16 *)(p + 0x1C) = 0x18;
    a = -26.666666f;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    b = 0.416666657f;
    if (p[0x1E6]) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;
}

extern f32 D_004F7FD4;
extern void func_003DAA40();

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0033D0D0();
extern u32 D_004C283C;
extern V3 D_0045EE98;
void func_0033D040(u8 *a0) {
    u8 *r = func_003DA750(0, 6, 1);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_0033D0D0;
        *(s16 *)(r + 0xCC) = 0x20;
        *(u32 *)(r + 0x84) = D_004C283C;
        *(V3 *)(r + 0x34) = D_0045EE98;
        *(u32 *)(r + 0xD0) = 0x801;
        *(u8 **)(r + 0xC8) = a0 + 0x88;
        *(u8 **)(r + 0x14) = a0;
    }
}

extern void func_0039F480();
void func_0039F3F0(u8 *a0) {
    s16 i;
    for (i = 7; i >= 0; i--) {
        u8 *r = func_003DA750(0, 1, 0);
        if (r) {
            *(void **)(r + 0x10) = func_0039F480;
            *(u8 **)(r + 0x18) = a0;
            r[1] = a0[1];
            r[0x21] = i;
            *(s16 *)(r + 0x26) = 0x2A00;
            *(u32 *)(r + 0xD0) = *(u16 *)(a0 + 0x168);
        }
    }
}

extern s32 func_00189310(void *p, void *a, void *b);
extern u8 D_0045BD80[];

extern int func_00174470(const void *);
extern void func_0034FA60(void *p);
extern void func_001E7F60(void *p);
void func_0034EC50(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (!func_00174470(p)) func_0034FA60(p);
    else func_001E7F60(p);
}

extern u8 D_0045BD90[];

extern void (*D_0044F420[])(u8 *, u8 *);
void func_001EBC40(u8 *p) {
    *(f32 *)(p + 0x34) -= 10.0f;
    *(f32 *)(p + 0x38) -= 50.0f;
    D_0044F420[p[6]](p, p + 0x2B8);
    *(f32 *)(p + 0x34) += 10.0f;
    *(f32 *)(p + 0x38) += 50.0f;
}

void func_00260690(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (!p[0x2C6]) {
        if (p[0x20D] != 2) {
            p[6] = 4;
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            *(f32 *)(p + 0x6C) = -0.803571403f;
            func_001757E0(p, 0x16, 0xF);
            return;
        }
    }
    if (!*(s8 *)(p + 0x151)) func_00175700(p);
}

extern void func_001BFCA0(void *p, s32 a);
void func_0027DFF0(u8 *p) {
    func_00175700(p);
    if (!*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001BFCA0(p, 0);
        *(f32 *)(p + 0x5C) = -26.666666f;
        *(u32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = 25.7142849f;
        *(f32 *)(p + 0x6C) = -1.60714281f;
        if (p[0x1E6]) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        p[0x20] = 0;
        p[0x20D] = 2;
    }
}

extern u8 D_0045D6C0[];
extern void func_0018A990();

void func_0020FDC0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0xF, 6);
    }
}

extern V3 D_004B82B0[];
extern void func_00341170();
void func_003410D0(s32 a0) {
    u8 *r = func_003DA750(0, 6, 0);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_00341170;
        *(s16 *)(r + 0xCC) = a0 + 0x17;
        *(u32 *)(r + 0x84) = D_004C283C;
        *(u32 *)(r + 0xD0) = 0x801;
        *(V3 *)(r + 0x34) = D_004B82B0[a0];
        r[0x20] = a0;
    }
}

void func_002C3780(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t;
        p[0x151] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x20D] = 2;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x60) = 10.0f;
        *(f32 *)(p + 0x6C) = -0.3125f;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 1.25f : -1.25f;
    }
}

extern void func_00184540();
void func_0017BBC0(u8 *a0) {
    u8 *a2 = *(u8 **)(a0 + 0x1CC);
    s16 v;
    if (!a2) a2 = *(u8 **)(a0 + 0x220);
    v = *(s16 *)(a0 + 0x1C) - 1;
    *(s16 *)(a0 + 0x1C) = v;
    if (v <= 0) {
        func_00184540();
    } else {
        s16 d = *(s16 *)(a2 + 0x140);
        f32 c = 5.0f;
        if (d) c = -c;
        if (!(*(s8 *)(a2 + 0x211) & (1 << d)))
            *(f32 *)(a2 + 0x34) += c;
    }
}
