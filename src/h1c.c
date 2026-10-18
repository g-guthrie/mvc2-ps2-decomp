typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_003DAA40(u8 *, u8 *);
extern void (*D_00472B08[])(u8 *, u8 *);
void func_003A1660(u8 *p) {
    u8 *a = *(u8 **)(p + 0x18);
    if (p[4] >= 2) {
        if (p[0x20] == 0) a[0x2C4] = 0;
        func_003DAA40(p, a);
    } else {
        D_00472B08[p[0x20]](p, a);
    }
}
extern void func_00175700(u8 *);
extern void func_00391650(u8 *, s32);
void func_002A5750(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_00391650(p, 4);
        *(s16 *)(p + 0x1C) = 0x68;
        *(s16 *)(p + 0x1E) = 0x1B;
    }
}
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00381FD0();
void func_00381E40(u8 *p, s32 a, s32 b) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_00381FD0;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = a;
        o[0x21] = b;
        *(s16 *)(o + 0x26) = 0x1A00;
        *(u16 *)(o + 0x1E) = *(u16 *)(p + 0x168);
    }
}
typedef struct { f32 a; f32 b; } P2;
extern P2 D_004535A0[];
extern void func_00259320();
void func_002592A0(u8 *p) {
    P2 *e = D_004535A0;
    u32 t = p[6];
    p[6] = t + 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    e += p[0x1B7];
    *(f32 *)(p + 0x5C) = p[0x1E6] ? -e->a : e->a;
    *(f32 *)(p + 0x68) = p[0x1E6] ? -e->b : e->b;
    *(s16 *)(p + 0x1C) = 0;
    func_00259320(p, e);
}
extern void func_00289E30(u8 *);
extern void func_00183d50(u8 *);
extern void func_001757E0(u8 *, s32, s32);
void func_00289D70(u8 *p) {
    func_00175700(p);
    func_00289E30(p);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 6));
    }
}
extern s32 func_00174470(u8 *);
extern s32 func_0034FA60(u8 *);
s32 func_0034F2B0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00174470(p) == 0) {
        return func_0034FA60(p);
    }
}
extern void func_001AC3F0();
extern void (*D_0044B750[])();
void func_001AAC40(u8 *p, u8 *q) {
    if (*(f32 *)(p + 0x38) == *(f32 *)(q + 0x430) && (q[0x1E4] != 0x15 || q[0x1FD] != 3)) {
        func_001AC3F0();
    } else {
        D_0044B750[p[7]]();
    }
}
extern s32 func_00350FD0(u8 *);
s32 func_00350CC0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        return func_00350FD0(p);
    }
}
void func_00202D80(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0xF, 9);
    }
}
extern void func_0015D010(u8 *, void *);
extern void func_0018C6E0(u8 *);
void func_002B7C40(u8 *p) {
    u32 v[3];
    p[0x1B4] = 10;
    if (((p[0x22] << 10) & 0x800) == 0) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    v[0] = 0xC2A00000;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 2);
}
extern void func_0027D740(u8 *);
void func_0027D6B0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (*(s8 *)(p + 0x1B4) == 0) {
        q[1] = 0;
        q[0] = 0;
    }
    if (*(s8 *)(p + 0x1B4) != 0 && p[0x295] != 0) {
        *(u32 *)(p + 0x74) = 0x3F4CCCCD;
        *(u32 *)(p + 0x78) = 0x3F800000;
        if (*(s8 *)(p + 0x1B4) & 1) *(u32 *)(p + 0x78) = 0;
        *(u32 *)(p + 0x7C) = 0;
        *(u32 *)(p + 0x80) = 0;
    }
    if (*(s8 *)(p + 0x1B4) == 0) *(u32 *)(q + 4) = 0x3F800000;
    *(u32 *)(p + 0x118) = 0x3F800000;
    p[0x13C] = 1;
    p[0x209] = 2;
    p[0x208] = 2;
    func_0027D740(p);
}
