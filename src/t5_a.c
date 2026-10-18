typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern s32 func_00175700(u8 *);
extern void func_00183d50(u8 *);
extern void func_001863F0(u8 *);
extern void func_001864a0(u8 *);
extern void func_003A2FB0(u8 *);
extern void func_00206A80(u8 *);
extern void func_003CAB20(u8 *, u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001548D0(u8 *, f32 *, s32);
extern void func_001E3210(u8 *, s32);
extern s32 func_00372260(u8 *);
extern s32 D_00463DB0[];
extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_0045AE60[];

void func_00206FB0(u8 *p) {
    f32 g;
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    p[0x209] = 3;
    g = 0.03125f;
    *(f32*)(p+0x118) += g;
    *(f32*)(p+0x50) += g;
    *(f32*)(p+0x54) += g;
    v = *(s16*)(p+0x1C) - 1;
    *(s16*)(p+0x1C) = v;
    if (v == 0) {
        p[6]++;
        *(s16*)(p+0x1C) = 0xB4;
        *(u32*)(p+0x118) = 0x3F800000;
        *(u32*)(p+0x50) = 0x3F800000;
        *(u32*)(p+0x54) = 0x3F800000;
    }
    func_00175700(p);
    func_00206A80(p);
}

void func_0020A7F0(u8 *p, u8 *q) {
    s8 r = func_00175700(p);
    if (r < 0) {
        p[7]++;
        p[0x1E6] ^= 1;
        *(s16*)(p+0x140) = p[0x1E6];
        q[4] = 0;
        *(f32*)(p+0x34) = *(f32*)(q+0x10);
        *(f32*)(p+0x38) = *(f32*)(q+0x14);
        func_001757E0(p, 0x15, 3);
    }
}

void func_0022A830(u8 *p) {
    f32 a, b;
    p[6]++;
    func_00185490(p);
    p[0x20D] = 0;
    a = -20.0f;
    b = 0.20833333f;
    if (p[0x1E6] != 0) { a = -a; b = -b; }
    *(f32*)(p+0x5C) = a;
    *(f32*)(p+0x68) = b;
    *(s32*)(p+0x60) = 0;
    *(s32*)(p+0x6C) = 0;
    func_00183D10(p);
    func_001757E0(p, 0x16, 6);
}

void func_002AF3F0(u8 *p) {
    if (*(f32*)(p+0x38) < *(f32*)(p+0x430)) {
        p[6]++;
        *(u32*)(p+0x5C) = 0;
        *(u32*)(p+0x60) = 0;
        *(u32*)(p+0x68) = 0;
        *(u32*)(p+0x6C) = 0;
        *(f32*)(p+0x38) = *(f32*)(p+0x430);
        func_001757E0(p, 0x15, 5);
        func_00183d50(p);
    }
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    func_00175700(p);
}

void func_002E2680(u8 *p) {
    if (p[0x20D] == 2) {
        func_001863F0(p);
        *(f32*)(p+0x34) += *(f32*)(p+0x5C);
        *(f32*)(p+0x5C) += *(f32*)(p+0x68);
        *(f32*)(p+0x38) += *(f32*)(p+0x60);
        *(f32*)(p+0x60) += *(f32*)(p+0x6C);
        func_001864a0(p);
    }
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        func_003A2FB0(p);
        *(s16*)(p+0x1E) = 0x3C;
        p[6]++;
        p[0x28F] = 0;
        p[0x28E] = 0x10;
    }
}

void func_002FDA00(u8 *p) {
    f32 *a, *b;
    func_00175700(p);
    a = (f32*)(p+0x60);
    b = (f32*)(p+0x6C);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (!(*(f32*)(p+0x430) < *(f32*)(p+0x38))) {
        *(f32*)(p+0x38) = *(f32*)(p+0x430);
        *(u32*)a = 0;
        *(u32*)b = 0;
        func_00183d50(p);
        func_001E3710(p, 0x35);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001757E0(p, 0x12, 1);
        p[6]++;
        *(s16*)(p+0x1C) = 0x3C;
    }
}

s32 func_003777B0(u8 *p) {
    f32 v[3];
    if ((s8)p[0x1B3] != 0) {
        p[4] = 2;
        p[5] = 0;
        *(f32*)(p+0x5C) = -*(f32*)(p+0x5C) / 2.0f;
        func_001757E0(p, 0x17, 0xB);
        v[0] = 26.666666f;
        v[1] = 34.285713f;
        v[2] = 0;
        func_001548D0(p, v, 0);
        func_001E3210(p, 0x25);
        return 1;
    }
    return 0;
}

void func_003CC760(u8 *p, u8 *q) {
    s16 v;
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(f32*)(p+0x38) < *(f32*)(q+0x430)) {
        *(f32*)(p+0x38) = *(f32*)(q+0x430);
        p[0x150] = 0;
        v = *(s16*)(p+0x1C) - 1;
        *(s16*)(p+0x1C) = v;
        if (v <= 0) func_003CAB20(p, q, 10);
    }
    if ((s8)p[0x150] == 0) func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        *(u32*)(p+0x60) = 0x41092492;
        *(u32*)(p+0x6C) = 0xBF4DB6DB;
    }
}

