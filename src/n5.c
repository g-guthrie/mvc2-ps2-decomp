typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#define F32(p, o) (*(f32 *)((p) + (o)))
#define U32(p, o) (*(u32 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S8(p, o) (*(s8 *)((p) + (o)))
extern s32 D_00444BE0[];
extern f32 D_00444C00[];
extern s32 D_004C2838;
extern u16 *D_004C26E8;
extern u8 D_004BFAC8[4];
extern void func_003DAA40(u8 *p);
extern void func_001B93D0(u8 *p);
extern void func_001754A0(u8 *p, s32 a, s32 b);
extern s32 func_00174170();
typedef struct { f32 x, y, z; } V3;
extern s32 func_00175700(u8 *p);
extern s32 func_00189310(u8 *p, void *a, void *b);
extern void func_00186A60(u8 *p, s32 a);
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0039E550();
extern void func_0015D010(u8 *p, u32 *v);
extern void func_001266A0(u8 *p, s32 a, s32 b);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_0022C5D0(u8 *p);
extern u8 *func_001E7FD0(u8 *p);
extern void func_00185640(u8 *p, u8 *a);
extern void func_003859F0(u8 *p);
extern void func_00357650(u8 *p);
extern void func_001E16A0();
extern s32 func_00185A90(u8 *p);
extern void func_0017A450(u8 *p);
extern void func_0018A990(u8 *p, u8 *q);
extern void func_00184540(u8 *p);
extern void func_001A31D0(u8 *p, s32 a, s32 b);
extern void func_003A7BA0(u8 *p, s32 a, s32 b);
extern void func_003A8290(u8 *p, u8 *q);
extern s32 func_001879C0(u8 *p);
extern void func_00185490(u8 *p);
extern void func_0015F8D0(u8 *p);
extern void func_001E3710(u8 *p, s32 a);
extern u8 D_00455C60[];
extern u8 D_00463860[];
extern u8 D_00463864[];
extern int func_00174470(const void *);
extern void func_001741D0(u8 *p, f32 *v);
extern s32 func_00118FA8(f32 f);

u8 *func_0039E470(u8 *p, s32 n) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_0039E550;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = n;
        *(s16 *)(r + 0x26) = 0x2801;
        r[1] = p[1];
        return r;
    }
    return 0;
}

void func_0022B870(u8 *p) {
    u32 v[4];
    v[0] = 0xC2A6AAAA;
    v[1] = 0x431E9249;
    func_0015D010(p, v);
    S16(p, 0x1C) = 0x10;
    func_001266A0(p, 5, 5);
    p[0x1B4] = 0xA;
    func_001757E0(p, 0xF, 9);
}

void func_00227160(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_0022C5D0(p);
    } else if (S8(p, 0x151)) {
        f32 v = 53.33333206f;
        p[0x151] = 0;
        if (p[0x1E6] == 0) {
            v = -v;
        }
        F32(p, 0x34) += v;
    }
}

void func_00259AD0(u8 *p) {
    u8 *r;
    func_00175700(p);
    if (S8(p, 0x153) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 5);
    }
    if (S8(p, 0x151)) {
        if ((r = func_001E7FD0(p)) != 0) {
            p[0x20B] = 0xC3;
            func_00185640(p, r);
        }
    }
}

void func_003854D0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    u8 *r = *(u8 **)(p + 0x18);
    if (S16(q, 0x1C) == 0 || r[0x425] != 0) {
        func_003859F0(p);
    } else if (p[5] == 0) {
        s16 v = S16(p, 0x1C) - 1;
        S16(p, 0x1C) = v;
        if (v == 0) {
            u32 t = p[5];
            p[5] = t + 1;
            p[0x13C] = 1;
        }
    }
}

void func_001E15A0(u8 *p) {
    u32 i = 0;
    do {
        u8 *r = func_003DA750(0, 4, 0);
        if (r) {
            *(void **)(r + 0x10) = func_001E16A0;
            *(u8 **)(r + 0x18) = p;
            r[1] = p[1];
            S16(r, 0x26) = 0x3A03;
            r[0x20] = 0;
            r[0x21] = i;
        }
        i++;
    } while (i < 10);
}

void func_00357530(u8 *p) {
    s16 v = S16(p, 0x1C) - 1;
    S16(p, 0x1C) = v;
    if (v <= 0) {
        func_00357650(p);
        return;
    }
    F32(p, 0x34) += F32(p, 0x5C);
    F32(p, 0x5C) += F32(p, 0x68);
    F32(p, 0x38) += F32(p, 0x60);
    F32(p, 0x60) += F32(p, 0x6C);
}

void func_0017A3C0(u8 *p) {
    p[0x20D] = 0;
    if (!func_00185A90(p)) {
        if (((S8(p, 0x151) != 0) ^ 1) || (func_00175700(p), (*(s8*)(p+0x151) & 0xF) == 0)) {
            u32 t;
            p[0x1ED] = 0;
            p[0x20D] = 2;
            t = p[6];
            p[6] = t + 1;
            func_00186A60(p, 3);
            func_0017A450(p);
        }
    }
}

void func_002CAC50(f32 *q) {
    u8 *p = (u8 *)q;
    q[13] += q[23];
    q[23] += q[26];
    q[14] += q[24];
    q[24] += q[27];
    if (q[14] <= q[268] || (s8)func_00175700(p) < 0) {
        func_00184540(p);
    }
}

void func_001FD510(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x20D] = 2;
        U32(p, 0x5C) = 0x40555555;
        U32(p, 0x68) = 0;
        U32(p, 0x60) = 0x40892492;
        U32(p, 0x6C) = 0xBEAB6DB6;
        if (S16(p, 0x140) == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        func_001757E0(p, 8, 4);
    }
}

void func_0023B230(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (S8(p, 0x151)) {
        p[0x151] = 0;
        U32(p, 0x5C) = 0;
        U32(p, 0x68) = 0;
        U32(p, 0x60) = 0x40CDB6DB;
        U32(p, 0x6C) = 0xBF4DB6DB;
        func_001A31D0(p, 0, 0);
        func_001A31D0(p, 0, 1);
    }
}

void func_003A7E70(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    s16 v = S16(p, 0x1C);
    S16(p, 0x1C) = v - 1;
    if (v == 0) {
        u32 t;
        S16(p, 0x1C) = 2;
        func_003A7BA0(p, 1, p[0x21]);
        t = p[0x21];
        p[0x21] = t + 1;
        t = p[0x21];
        p[0x21] = t & 1;
    }
    if (r[6]) {
        u32 t = p[4];
        p[4] = t + 1;
        func_003A8290(p, q);
    }
}

void func_00313730(u8 *p, u8 *q) {
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        F32(p, 0x34) = (f32)S16(q, 0x10);
        F32(p, 0x38) = F32(p, 0x430);
        func_001757E0(p, 0x16, 0x1A);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

void func_00367EC0(u8 *p) {
    u8 *q;
    f32 t;
    s32 idx, a, b;
    F32(p, 0x34) = F32(*(u8 **)(p + 0x14), 0x34);
    F32(p, 0x38) = F32(*(u8 **)(p + 0x14), 0x38);
    q = *(u8 **)(p + 0x14);
    idx = (s32)p[0x21] + (s32)(q[0x15B] << 1);
    t = *(f32 *)(D_00463860 + idx * 8);
    t = S16(p, 0x140) ? t : -t;
    F32(p, 0x34) += t;
    q = *(u8 **)(p + 0x14);
    idx = (s32)p[0x21] + (s32)(q[0x15B] << 1);
    F32(p, 0x38) += *(f32 *)(D_00463864 + idx * 8);
}

s32 func_00286840(u8 *p) {
    u8 *r = p + 0x2B8;
    if (p[0x2BB] || !func_00189310(p, D_00455C60, p + 0x3A8)) {
        return 0;
    }
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xC;
    func_00186A60(p, 0x15);
    if (S8(p, 0x539) == 0) {
        r[0x1A] = 0;
    } else {
        r[0x1A] = p[0x212];
    }
    return 1;
}

s32 func_003535B0(u8 *p) {
    f32 v[2];
    if (!func_00174470(p)) {
        return 0;
    }
    func_001741D0(p + 0x34, v);
    return !((s16)func_00118FA8(v[1] + 2.14285707f * (f32)(u32)p[0x14D]) <= 0);
}

void func_00187160(u8 *p) {
    if (S8(p, 0x539)) {
        func_00185490(p);
    }
    p[0x20D] = 0;
    p[0x1E7] = 0;
    if (!func_001879C0(p)) {
        func_0015F8D0(p);
        U32(p, 0x5C) = 0;
        U32(p, 0x60) = 0;
        U32(p, 0x68) = 0;
        U32(p, 0x6C) = 0;
        if (U32(p, 0x42C) & 4) {
            (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x64))(p);
        } else {
            func_001757E0(p, 2, 0);
        }
        func_001E3710(p, 0x33);
    }
}

void func_00156A40(u8 *p) {
    s32 i = S16(p, 0x1C);
    f32 v;
    if (i >= 6) {
        func_003DAA40(p);
        return;
    }
    S16(p, 0xCC) = (s16)D_00444BE0[i];
    U32(p, 0x84) = D_004C2838;
    v = D_00444C00[S16(p, 0x1C)];
    F32(p, 0x78) = v;
    F32(p, 0x7C) = v;
    F32(p, 0x80) = F32(p, 0x78);
    S16(p, 0x1C) = S16(p, 0x1C) + 1;
}

void func_001B9130(u8 *p) {
    u8 *q;
    if (*D_004C26E8 != *(u16 *)((q = *(u8 **)(p + 0x18)) + 0x168)) {
        func_001B93D0(p);
        return;
    }
    F32(p, 0x34) = F32(q, 0x34);
    F32(p, 0x38) = F32(*(u8 **)(p + 0x18), 0x38);
    if (S8(*(u8 **)(p + 0x18), 0x150) == 1) {
        u32 t = p[4];
        p[4] = t + 1;
        (*(u8 **)(p + 0x18))[0x150] = 0;
        func_001754A0(p, 0x1B, 0xD);
        p[0x13C] = 1;
    }
}

void func_001DBF10(u8 *p) {
    f32 *q = (f32 *)p;
    q[13] += q[23];
    q[23] += q[26];
    q[14] += q[24];
    q[24] += q[27];
    if (q[24] < 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = D_004BFAC8[func_00174170() & 3];
    }
}
