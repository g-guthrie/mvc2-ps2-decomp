typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_001757E0(u8 *, int, int);
extern void func_00257F00(u8 *);

void func_00393A20(u8 *p) {
    f32 v;
    p[5] = 6;
    if (*(s16 *)(p + 0x140) != 0) v = 13.333333f; else v = -13.333333f;
    *(f32 *)(p + 0x5C) = v;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 4.2857141f;
    *(f32 *)(p + 0x6C) = -0.03348214f;
    func_001757E0(p, 23, 14);
}

void func_00257EA0(u8 *p) {
    f32 v;
    u32 t = p[7]; p[7] = t + 1;
    if (p[0x1E6] != 0) v = 3.3333333f; else v = -3.3333333f;
    *(f32 *)(p + 0x5C) = v;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 34.285713f;
    *(f32 *)(p + 0x6C) = -1.6071428f;
    p[0x20D] = 2;
    func_00257F00(p);
}

void func_001B7240(u8 *a, u8 *b) {
    if (b[6] == 2) {
        u32 t = a[5]; a[5] = t + 1;
        a[0x13C] = 1;
        *(s16 *)(a + 0x1C) = 0x15;
        *(u32 *)(a + 0x6C) = 0xBF892492;
        *(f32 *)(a + 0x60) = (*(f32 *)(b + 0x38) - *(f32 *)(a + 0x38)) / 21.0f - (21.0f * *(f32 *)(a + 0x6C)) / 2.0f;
    }
}

extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern void func_002837D0(u8 *);

void func_002836D0(u8 *p) {
    f32 d;
    func_00175700(p);
    if (*(s8 *)(p + 0x161) & 1) {
        u32 t = p[6]; p[6] = t + 1;
        func_00186A20(p);
        if (p[0x1E6]) d = 40.0f; else d = -40.0f;
        *(f32 *)(p + 0x34) += d;
        func_002837D0(p);
    }
}

extern int func_001757E0(u8 *, int, int);

void func_00197AE0(u8 *a, u8 *b) {
    if (*(s16 *)(b + 0x140) != 0) *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 93.33333f;
    else *(f32 *)(a + 0x34) = 93.33333f + *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x430);
    *(u32 *)(a + 0x5C) = 0;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x60) = 0x40892492;
    *(u32 *)(a + 0x6C) = 0xBF092492;
    *(u32 *)(a + 0x14C) = 0x60003030;
    func_001757E0(a, 0x14, 6);
}

void func_002BB3C0(u8 *p) {
    f32 v, w;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        t = p[6]; p[6] = t + 1;
        if (p[0x1E6]) v = 10.0f; else v = -10.0f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6]) w = -0.0f; else w = 0.0f;
        *(f32 *)(p + 0x68) = w;
        *(u32 *)(p + 0x60) = 0xC19A4924;
        *(u32 *)(p + 0x6C) = 0;
    }
}

void func_00197A40(u8 *a, u8 *b) {
    a[0x13C] = 1;
    if (a[2] != 0) *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 106.666664f;
    else *(f32 *)(a + 0x34) = 106.666664f + *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = 548.57141f + *(f32 *)(b + 0x38);
    *(u32 *)(a + 0x14C) = 0x20202424;
    *(u32 *)(a + 0x60) = 0xC14DB6DB;
    *(u32 *)(a + 0x6C) = 0x3E092492;
    func_001757E0(a, 0x12, 3);
}
