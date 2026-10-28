typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00260730(u8 *p) {
    extern void func_00183D50();
    extern void func_001757E0();
    extern void func_00175700();
    u32 t;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        p[0x20D] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_001757E0(p, 0x16, 0x10);
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}

void func_0022BC10(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    extern void func_00126400(void);
    u8 *q;
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x150) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 0x26;
        q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
        func_00126400();
    }
}

void func_00266000(u8 *p) {
    extern void func_001843A0();
    extern void func_00266880();
    u8 *q;
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q = *(u8 **)(p + 0x14);
    if (*(s8 *)(q + 0x13C) == 0) {
        func_001843A0(p);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        func_001843A0(p);
        return;
    }
    if (q[4] == 1 && q[5] == 1 && q[6] != 0) {
        func_00266880(p);
    } else if (q[4] == 1 && q[5] == 2) {
        func_00266880(p);
    }
}

typedef struct { f32 x, y, z; } V3a;
typedef struct { f32 x, y, z, w; } V4a;
extern V3a D_00442890;
extern V4a D_004428A0;

void func_00313400(u8 *p, u8 *q) {
    extern void func_00313BF0();
    extern void func_00313B80();
    extern void func_00313C40();
    extern void func_00313C70();
    extern s8 func_00175700();
    extern s32 func_00118FA8(f32);
    extern void func_001757E0();
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    func_00313BF0(p);
    func_00313B80(p, q);
    if (q[0xF] == 0) {
        func_00313C40(p, q);
    } else {
        func_00313C70(p, q);
    }
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(q + 0x10) = func_00118FA8(*(f32 *)(p + 0x34));
        *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBE892492;
        func_001757E0(p, 0x16, 0x15);
    }
}

extern u8 D_004D18A0[];
extern void (*D_00457870[])();
extern u8 D_004570D0[];

void func_00291720(u8 *p) {
    extern void func_00294BC0();
    extern void func_00294B20();
    extern void func_001757E0();
    extern void func_001E3210();
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    func_00294BC0(p);
    if (D_004D18A0[0] >= 5) {
        *(s16 *)(q + 0x1E) = 0;
    }
    if (*(s16 *)(q + 0x1E) == 0) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        q[0x19] = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00294B20(p, D_004570D0);
        func_001757E0(p, 0x16, 0x22);
        func_001E3210(p, 0x2B);
    } else {
        D_00457870[p[7]](p, q);
    }
}

void func_003BB170(u8 *p) {
    extern void func_00175700();
    extern void func_001E7F60();
    extern void func_003BB260();
    u8 *s;
    f32 v, z, w;
    u32 t;
    s = *(u8 **)(p + 0x18);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(f32 *)(p + 0x5C);
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    z = 0.0f;
    if (v > z) {
        w = *(f32 *)(s + 0x430);
        if (w > *(f32 *)(p + 0x38)) {
            *(f32 *)(p + 0x38) = w;
            *(f32 *)(p + 0x60) = z;
            *(f32 *)(p + 0x6C) = z;
        }
        func_001E7F60(p);
    } else {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_003BB260(p);
    }
}

void func_0017C980(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183D50();
    f32 *v1, *a3, *t0, *t1;
    s16 h = *(s16 *)(p + 0x1C);
    if (h != 0) {
        *(s16 *)(p + 0x1C) = h - 1;
        return;
    }
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t1 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)v1 = 0;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
        *(u32 *)t1 = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001757E0(p, 0, 0);
        (*(void (**)())(*(u8 **)(p + 0x43C) + 0x44))(p);
        func_00183D50(p);
    }
}

