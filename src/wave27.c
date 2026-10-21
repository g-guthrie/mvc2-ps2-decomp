typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00186A60(u8 *a, s32 b);
void func_00184650(u8 *a);
void func_001845F0(u8 *a) {
    func_00186A60(a, 0xE);
    a[6] = 1;
    if (*(f32 *)(a + 0x60) > 0.0f) {
        a[0x210] = 1;
    } else {
        a[0x210] = 2;
    }
    func_00184650(a);
}

void func_001B3130(u8 *a) {
    s16 t = *(s16 *)(a + 0x1C);
    *(s16 *)(a + 0x1C) = t - 1;
    if (t == 0) {
        u32 u = a[4];
        a[4] = u + 1;
    }
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
}

void func_00389170(u8 *a);
void func_00175700(u8 *a);
void func_001757E0(u8 *a, s32 b, s32 c);
void func_00388D90(u8 *a, u8 *b) {
    u8 *p = b + 0x2B8;
    if (*(s16 *)(b + 0x2D6) == 0) {
        u32 t = a[5];
        a[5] = t + 1;
        a[6] = 0;
        a[0x13C] = 1;
        func_00389170(a);
    } else {
        a[0x13C] = 1;
        if (p[0x19] != 0) {
            a[0x13C] = 0;
        }
        func_00175700(a);
    }
}

void func_001B5350(u32 a, u8 *b);
int func_001754A0(u8 *a, s32 b, int c);
void func_00176160(u8 *a, s32 b, s32 c, s32 d);
void func_001B4D70(u8 *a) {
    u8 *p = a;
    u32 t = p[6];
    u32 q = *(u32 *)(a + 0x18);
    p[6] = t + 1;
    p[0x13C] = 1;
    func_001B5350(q, p);
    func_001754A0(p, 0x1B, p[0x20]);
    p[0x24] = 0;
    func_00176160(p, 2, 2, 2);
}

void func_001E3210(u8 *a, s32 b);
void func_00288140(u8 *a) {
    s16 t = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = t;
    if (t == 0) {
        u32 u = a[6];
        a[6] = u + 1;
        func_001E3210(a, 0x21);
    }
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
}

s32 fptodp(f32 x);
s32 func_00100240(s32 a, s32 b);
void func_00297120(u8 *a);
void func_00297490(u8 *a) {
    f32 v;
    s32 d;
    func_00297120(a);
    v = *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x34) += v;
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    d = fptodp(*(f32 *)(a + 0x5C) * v);
    if (func_00100240(d, 0) != 0) {
        u32 u = a[6];
        a[6] = u + 1;
    }
    func_00175700(a);
}

u8 *func_003DA750(s32 a, s32 b, s32 c);
void func_0019DFD0(void);
void func_0019DE50(u8 *a, u8 b, u8 c) {
    u8 *p = func_003DA750(0, 3, 1);
    if (p != 0) {
        *(void **)(p + 0x10) = func_0019DFD0;
        *(u8 **)(p + 0x18) = a;
        p[0x20] = b;
        p[0x21] = c;
        *(s16 *)(p + 0x26) = 0xB00;
        p[0x13C] = 0;
        *(u16 *)(p + 0x88) = *(u16 *)(a + 0x168);
    }
}

s32 func_00174470(u8 *a, u8 *b);
void func_003785F0(u8 *a, u8 *b);
extern void (*D_00464020[2])(u8 *, u8 *);
void func_00378280(u8 *a, u8 *b) {
    u8 *p = b + 0x2B8;
    if (func_00174470(a, b) == 0) {
        func_003785F0(a, b);
        p[4] = 0;
    } else {
        D_00464020[a[5]](a, b);
    }
}

void func_00185490(u8 *a);
void func_00183D10(u8 *a);
void func_002294C0(u8 *a) {
    if (a[0x269] == 6) {
        a[0x404] = 0xFF;
        a[0x405] = 0x10;
    }
    {
        u32 u = a[6];
        a[6] = u + 1;
    }
    func_00185490(a);
    a[0x20D] = 0;
    func_00183D10(a);
    *(s32 *)(a + 0x2D0) = 0xFF;
    *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
    func_001757E0(a, 0x16, 0);
}
