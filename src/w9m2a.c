typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(void *p);
extern s32 func_00174170(void);
extern void func_001E3210(void *p, s32 n);
extern void func_0016B0C0(void *p, void *q, s32 n);
extern void func_00166C80(void *p, void *q, s32 n);
extern void func_00228400(void *p);
extern void func_0022C700(void *p);

void func_001ABAD0(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        *(s16 *)(p + 0x1C) = (func_00174170() & 0x1F) + 0x3C;
        func_001E3210(p, 0x1A);
    }
}

void func_001687A0(u8 *p, u8 *q) {
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    func_00166C80(p, q, (*(s8 *)(*(u8 **)(p + 0x220) + 0x1E7)) == (*(s8 *)(p + 0x4C8)));
}

void func_00228350(u8 *p) {
    func_00228400(p);
    if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0022C700(p);
    }
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001DB6D0(void);
u8 *func_001DB640(u8 *p) {
    u8 *r;
    if ((r = func_003DA750(0, 3, 0))) {
        *(void **)(r + 0x10) = (void *)func_001DB6D0;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x3502;
        *(f32 *)(r + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(r + 0x38) = *(f32 *)(p + 0x38);
        r[0x20] = (func_00174170() & 3) + 4;
        r[0x21] = 0;
    }
    return r;
}

extern void func_001757E0(void *p, s32 a, s32 b);
void func_003067F0(u8 *p) {
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 2, 3);
    }
}

extern void func_001AC3F0(void *p, void *q);
void func_001AAFB0(u8 *p, u8 *q) {
    f32 lim;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    lim = *(f32 *)(q + 0x430);
    if (*(f32 *)(p + 0x38) <= lim) {
        s32 n;
        *(f32 *)(p + 0x38) = lim;
        func_00175700(p);
        n = *(s32 *)(q + 0x2F8);
        if (n != 0) {
            *(s32 *)(q + 0x2F8) = n - 1;
            p[7] = 1;
        } else {
            func_001AC3F0(p, q);
        }
    }
}

typedef struct { f32 a, b; } FP2;
extern FP2 D_00462610[];
void func_00351DB0(u8 *p) {
    f32 d;
    p[0x24] = 0xB;
    if (*(s16 *)(p + 0x140) != 0) d = D_00462610[p[0x21]].a;
    else d = -D_00462610[p[0x21]].a;
    *(f32 *)(p + 0x34) += d;
    *(f32 *)(p + 0x38) += D_00462610[p[0x21]].b;
    func_001757E0(p, 0x15, (p[0x21] + 0x2D) & 0xFF);
}

extern s16 D_004B83BA[];
extern s16 D_004B83B8[];
void func_00375220(u8 *p, u8 *q) {
    s16 f;
    f32 d;
    *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34);
    *(f32 *)(q + 0x38) = *(f32 *)(p + 0x38);
    *(f32 *)(q + 0x38) += (f32)D_004B83BA[p[0x168] * 2];
    d = (f32)D_004B83B8[p[0x168] * 2];
    f = *(s16 *)(p + 0x140);
    *(s16 *)(q + 0x140) = f;
    if (f == 0) d = -d;
    *(f32 *)(q + 0x34) += d;
    *(s8 *)(q + 0x24) = *(s8 *)(p + 0x24);
    *(s8 *)(q + 0x31) = -1;
}

extern void func_0018DB70();
extern void func_0018DA70();
extern void func_0018CDF0();
extern void func_0034C840(void *p);
extern void func_00180DD0(void *p);
extern void func_0011D8F8(void *p, s32 a, s32 b);
void func_0018E500(u8 *p) {
    if (p[0x425] != 0) {
        if (p[0x20D] == 2) {
            func_0018DB70();
        } else {
            func_0018DA70();
        }
    } else {
        p[0x247] = 0x14;
        p[0x248] = 0;
        func_0018CDF0();
        p[0x13C] = 0;
        p[0x159] = 0xFF;
        *(s16 *)(p + 0x1C) = 0x12C;
        func_0034C840(p);
        func_00180DD0(p);
        func_0011D8F8(p + 0x354, 0, 0xC8);
    }
}

extern void func_00313BF0();
extern void func_00313C70(void *p, void *q);
extern void func_00175C00(void *p, s32 a);
void func_00313910(u8 *p, u8 *q) {
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00313BF0(p);
    func_00313C70(p, q);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        q[0xC] = 0;
        q[0xE] = 0;
        p[0x13C] = 1;
        func_00175C00(p, 0);
        func_001757E0(p, 0x16, 0x19);
    }
}

extern s32 func_001864a0(void *p);
extern void func_00183d50(void *p);
void func_00278160(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p)) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00183d50(p);
        func_001757E0(p, 0x14, 1);
        func_001E3210(p, 0xD);
    }
}

extern s16 D_004F4484[];
extern s16 D_004F4490[];
extern s16 D_004F4498[];
extern s16 D_004F44A4[];
extern u16 D_004F4480[];
extern u16 D_004F4494[];
u16 func_0012ABC0(s32 f, s32 sel) {
    u16 r = 0;
    if (sel == 0) {
        if (f & 1) r |= (u16)(D_004F4484[0] | (D_004F4490[0] & 0x3C00));
        if (f & 2) r |= (u16)(D_004F4498[0] | (D_004F44A4[0] & 0x3C00));
    } else {
        if (f & 1) r |= D_004F4480[0];
        if (f & 2) r |= D_004F4494[0];
    }
    return r;
}

typedef struct { f32 a, b, c, d; } F4;
extern F4 D_0044FBB0[];
extern void func_00186A20(void *p);
extern void func_001F97D0(void *p);
void func_001F9720(u8 *p) {
    if (*(s8 *)(p + 0x151) == 0) {
        F4 *t = D_0044FBB0;
        u32 c = p[6];
        p[6] = c + 1;
        t += p[0x1B7];
        *(f32 *)(p + 0x5C) = t->a;
        *(f32 *)(p + 0x68) = t->b;
        *(f32 *)(p + 0x60) = t->c;
        *(f32 *)(p + 0x6C) = t->d;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_00186A20(p);
        func_001F97D0(p);
    }
    func_00175700(p);
}
