typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u32 D_004F7FB4;
extern u32 D_004F7FB8;
extern u8 D_004D18A0;
extern f32 D_004F1D0C, D_004F1D10, D_004F1D14;
extern u8 D_004F1D00[];
extern V3 D_004F1F4C, D_004F1F58, D_004F1F94, D_004F1FA0;
extern void (*D_0045BB80[])(void);

extern s8 func_00175700();
extern s32 func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
extern void func_0011D8F8(u8 *, s32, s32);
extern u8 *func_00147870(s8, s8);
extern void func_00169C90(u8 *);
extern void func_0028D810(u8 *, s32);
extern void func_003DD2B0(u8 *);
extern void func_003266E0(u8 *);
extern void func_001E1620(u8 *);
extern void func_003DAA40(u8 *, s32);
extern void func_0039F080(void);
extern void func_0039F190(void);

s32 func_00165C90(u8 *p) {
    if (!*(s8 *)(p + 0x1B4)) {
        if (*(s32 *)(p + 0x460) == 0) {
            p[0x451] -= 1;
            return 1;
        }
        *(s32 *)(p + 0x460) -= 1;
    }
    return 0;
}

void func_0016CDA0(void) {
    func_0011D8F8(D_004F1D00, 0, 0x18);
    D_004F1D14 = 1.0f;
    D_004F1D10 = 1.0f;
    D_004F1D0C = 1.0f;
}

s32 func_003367F0(u8 *p) {
    if (p[4] != 0) return 0;
    if (D_004D18A0 >= 6) {
        p[4] = 3;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        return 1;
    }
    return 0;
}

void func_00135FA0(u8 *p) {
    s16 t;
    *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[5] += 1;
        *(s16 *)(p + 0x1C) = 60;
    }
}



void func_0035EE30(u8 *p, u8 *q) {
    u8 *s = q + 0x2B8;
    if (func_00175700(p) < 0) {
        p[4] = 3;
        p[0x13C] = 0;
        *(s8 *)(s + 2) = -1;
    }
}

s32 func_00168E80(u8 *p) {
    if (!p[0x450]) return 0;
    p[0x450] = 0;
    p[0x451] = 1;
    p[0x452] = 0;
    func_00169C90(p);
    p[0x4B4] = 0;
    p[0x4BC] = 0;
    p[0x4A8] = 0;
    return 0;
}

void func_001BF8A0(u8 *p) {
    s16 t;
    *(f32 *)(p + 0x54) += -*(f32 *)(p + 0x54) / (f32) * (s16 *)(p + 0x1C);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[4] += 1;
        p[0x13C] = 0;
    }
}



void func_003DDA70(u8 *p, f32 a, f32 b, f32 c) {
    func_003DD2B0(p);
    *(f32 *)p = a;
    *(f32 *)(p + 0x14) = b;
    *(f32 *)(p + 0x28) = c;
}

void func_0018F460(u8 *p) {
    if (*(f32 *)(p + 0x60) > 68.571426f) *(f32 *)(p + 0x60) = 68.571426f;
    if (*(f32 *)(p + 0x60) < -68.571426f) *(f32 *)(p + 0x60) = -68.571426f;
}

void func_00324E40(u8 *p) {
    if (func_00175700(p) < 0) {
        func_003266E0(p);
    } else if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        func_001E1620(p);
    }
}

void func_0039F020(u8 *p) {
    s32 v = *(s32 *)(p + 0x18);
    if (p[4] >= 2) {
        func_003DAA40(p, v);
    } else if (p[0x20] == 0) {
        func_0039F080();
    } else {
        func_0039F190();
    }
}
