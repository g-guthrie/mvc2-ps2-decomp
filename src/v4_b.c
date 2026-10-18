typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y; } V2;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;

void func_00162810(u8 *p) {
    extern V2 D_004B3FE0[];
    extern s32 *D_004C2838;
    extern s32 func_00153AA0();
    extern void func_00170DA0(s32 *,s32,s32,s16);
    V2 *v = D_004B3FE0;
    f32 x, y;
    v += *(s16 *)(p + 0x1C);
    if (*(s32 *)(p + 0xDC) != 0) {
        func_00170DA0(D_004C2838, 0x51, func_00153AA0(), *(s16 *)(p + 0xCC));
    } else {
        func_00170DA0(D_004C2838, 0x57, func_00153AA0(), *(s16 *)(p + 0xCC));
    }
    y = v->y; x = v->x; *(f32 *)(p + 0xE0) = x; *(f32 *)(p + 0xE4) = y;
    *(u32 *)(p + 0xD0) |= 0x20000;
}

void func_001E7AE0(u8 *a, u8 *b, s16 c) {
    extern f32 D_004C28CC, D_004C28C8, D_004C28C4, D_004C28C0;
    extern void func_001E7BB0();
    u8 type = 1;
    u8 *t;
    s32 v, w;
    u16 x;
    u32 y;
    f32 lim;
    t = *(u8 **)(b + 0x1D4);
    *(s16 *)(a + 0x1BC) = c;
    *(u8 **)(b + 0x1C8) = a;
    *(u8 **)(a + 0x1C4) = b;
    { u32 g = b[0x1B1]; s8 f = (g & 6) | 0x80; *(s8 *)(a + 0x1B2) |= f; }
    lim = D_004C28CC;
    v = *(s16 *)(t + 4);
    w = v & 0x1FFF;
    if (!(D_004C28C8 <= lim)) {
        v = *(s16 *)(t + 6);
        lim = D_004C28C8;
        type = 2;
        w = v & 0x1FFF;
    }
    if (!(D_004C28C4 <= lim)) {
        v = *(s16 *)(t + 8);
        lim = D_004C28C4;
        type = 3;
        w = v & 0x1FFF;
    }
    if (!(D_004C28C0 <= lim)) {
        y = *(u16 *)(t + 0xA);
        x = y & 0x1FFF;
        w = x & 0x1FFF;
        y = (u8)((u16)(x & 0x6000) >> 13);
        type = y | 4;
    }
    b[0x1B3] = type;
    *(s16 *)(b + 0x1BE) = w;
    func_001E7BB0(a, b);
}

void func_002C8930(u8 *p) {
    extern G *D_004C2794;
    extern void func_00175700();
    extern void func_001757E0();
    f32 z;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    z = 0.0f;
    if (*(f32 *)(p + 0x60) < z) {
        p[6]++;
        p[0x1B5] = 0x39;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 8);
    }
}

void func_002E34A0(u8 *p) {
    extern G *D_004C2794;
    extern void func_00175C00();
    extern void func_00185490();
    extern void func_001757E0();
    extern s8 func_00175700();
    extern void func_001843A0();
    if (p[6] == 0) {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s8 *)(p + 0x1B5) = 0x40;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_00175C00(p, 0);
        func_00185490(p);
        func_001757E0(p, 0x15, 0x17);
    } else {
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}

void func_002FA520(u8 *a, u8 *b) {
    extern G *D_004C2794;
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_00183D10();
    extern void func_001757E0();
    extern void func_002FA5F0();
    a[6]++;
    func_00185490(a);
    func_00175C00(a, 0);
    if (a[0x20D] != 2) func_00183D10(a);
    a[0x1B5] = 0x32;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(u32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_001757E0(a, 0x15, 10);
    b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0; b[0xA] = 0; b[0xB] = 0; b[0xC] = 0;
    func_002FA5F0(a, b);
}
