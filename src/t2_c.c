typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00176160(void *, s32, s32, s32);
extern void func_001CCB70(void *, s32);
extern void func_001757E0(void *, s32, s32);
typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x34 - 8];
    f32 f34;
    u8 pad38[0x5C - 0x38];
    f32 f5c;
    u8 pad60[8];
    f32 f68;
    u8 pad6c[0x140 - 0x6C];
    s16 h140;
} S24A;
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];
extern s32 func_00175700();
extern void func_0024AB20(void *);
void func_0024AA60(S24A *a) {
    s16 h;
    func_00175700(a);
    a->f34 += a->f5c;
    a->f5c += a->f68;
    h = a->h140;
    if ((h == 0 && a->f34 <= D_004F1FCC[0] - 320.0f) || (h != 0 && !(a->f34 < 320.0f + D_004F1FC8[0]))) {
        u32 t = a->b7;
        a->b7 = t + 1;
        func_0024AB20(a);
    }
}

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x21 - 6];
    u8 b21;
    u8 pad22[0x38 - 0x22];
    f32 f38;
    u8 pad3c[0x60 - 0x3C];
    f32 f60;
    u8 pad64[8];
    f32 f6c;
} S3C;
extern void func_001E7F60(void *);
extern void func_003A6D90(void *, void *);
void func_003A6AF0(S3C *a, u8 *b) {
    if (*(s8 *)(b + 0x151) != 0) a->b21 = 1;
    a->f38 += a->f60;
    a->f60 += a->f6c;
    func_001E7F60(a);
    if (!(212.14285f + *(f32 *)(b + 0x430) < a->f38)) {
        u32 t = a->b5;
        a->b5 = t + 1;
        func_003A6D90(a, b);
    }
}

extern s32 func_0018AB10();
extern void func_002CF1D0(void *);
typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x38 - 7];
    f32 f38;
    u8 pad3c[0x60 - 0x3C];
    f32 f60;
    u8 pad64[8];
    f32 f6c;
} S2CF;
void func_002CF4B0(u8 *a) {
    S2CF *s = (S2CF *)a;
    f32 v;
    a[0x40C] = 2;
    a[0x33C] = 5;
    v = s->f60;
    s->f38 += v;
    s->f60 += s->f6c;
    if (v * s->f60 < 0.0f) {
        u32 t = s->b6;
        s->b6 = t + 1;
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
        func_001757E0(a, 0x16, 2);
    } else {
        if (func_0018AB10(a)) a[0x152] = 1;
        func_00175700(a);
        func_002CF1D0(a);
    }
}


extern s32 func_00175700();
extern void func_00185490(void *);
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
void func_002BEEA0(u8 *a) {
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t = a[6];
        u8 *o;
        a[6] = t + 1;
        a[0x151] = 0;
        o = *(u8 **)(a + 0x1DC);
        *(u8 **)(o + 0x1C8) = a;
        o[0x20A] = 3;
        o[0x1B5] = 0x20;
        *(f32 *)(a + 0x5C) = (a[0x1E6] != 0) ? 3.3333332539f : -3.3333332539f;
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x60) = 0x41092492;
        *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
        func_00185490(a);
        D_004F1F45[0] = 2;
        D_004F1F46[0] = 1;
    }
}

extern void func_001757E0(void *, s32, s32);
void func_00395E10(u8 *a, u8 *b) {
    a[0x13C] = 1;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(u32 *)(a + 0x5C) = 0;
    *(u32 *)(a + 0x60) = 0;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x6C) = 0;
    *(f32 *)(a + 0x38) += 201.42855834960938f;
    *(u32 *)(a + 0x5C) = 0x40200000;
    *(u32 *)(a + 0x60) = 0x40CDB6DB;
    *(u32 *)(a + 0x6C) = 0xBE892492;
    if (*(s16 *)(b + 0x140) != 0) {
        *(f32 *)(a + 0x5C) = -*(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x34) += 118.33332824707031f;
    } else {
        *(f32 *)(a + 0x34) += -118.33332824707031f;
    }
    func_001757E0(a, 0x13, 6);
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0039F8A0(void);
void func_0039F7E0(u8 *a, u32 n) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_0039F8A0;
        *(u8 **)(o + 0x18) = a;
        *(u32 *)(o + 0xD8) = *(u32 *)(a + 0x18);
        o[1] = a[1];
        o[0x21] = 1;
        *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38) + 2.1428570747f * (f32)n;
        *(s16 *)(o + 0x26) = 0x2A01;
    }
}

extern void func_001757E0(void *, s32, s32);
void func_0035A010(u8 *a) {
    u8 *b = *(u8 **)(a + 0x18);
    u32 t = a[5];
    s32 kk;
    a[5] = t + 1;
    kk = 0x1800000;
    if (*(s16 *)(a + 0x140) == 0) kk = -0x1800000;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + (1.6666666269f * (f32)kk) / 65536.0f;
    *(f32 *)(a + 0x38) = 342.85711669921875f + *(f32 *)(b + 0x38);
    if (*(s16 *)(b + 0x140) != 0) {
        *(u32 *)(a + 0x5C) = 0xC13AAAAA;
    } else {
        *(u32 *)(a + 0x5C) = 0x413AAAAA;
    }
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x60) = 0;
    *(u32 *)(a + 0x6C) = 0;
    *(s16 *)(a + 0x1C) = 0x20;
    a[0x169] = 0x17;
    a[0x168] = 9;
    func_001757E0(a, a[0x169], a[0x168]);
}

extern u8 D_004D18EC[];
void func_00181690(f32 x, u8 *p, u8 *q, f32 *c) {
    f32 m = 53.33333206176758f;
    if (!(x <= m)) x = m;
    x = x / 2.0f;
    if (c[0] < c[1]) x = -x;
    *(f32 *)(p + 0x34) += x;
    *(f32 *)(q + 0x34) -= x;
    D_004D18EC[0] |= (u8)((1 << p[0x1B8]) | (1 << q[0x1B8]));
}
