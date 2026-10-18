typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00122FE0();
extern void func_00151A20(u8);
extern void func_001520E0(u8);
extern void func_001C5110();
extern void func_001757E0();
extern s32 func_001748C0();
extern void func_003DAA40();
extern s8 D_004D1900;
extern u8 D_004D1860[];


void func_00153350(u32 a0) {
    func_00122FE0();
    func_00151A20(a0);
    func_001520E0(a0);
}

void func_0036B2B0(u8 *p) {
    p[0x13C] = 1;
    p[0x24] = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x3E3851EC;
    *(u32 *)(p + 0x68) = 0xBCF5C28F;
    *(s16 *)(p + 0x1C) = 6;
    func_001757E0(p, 0x17, 8);
}

s32 func_00197860(u8 *a0, u8 *a1) {
    u8 *q = a1 + 0x2B8;
    u8 *r = a0 + 0x88;
    s8 x;
    if (a1[0x1E4] == 0x1D && (x = *(s8 *)(q + 0xC)) != 0) {
        if (x != *(s8 *)r) return 1;
    }
    return 0;
}

void func_00156750(u8 *p) {
    s16 h;
    h = *(s16 *)(p + 0x1C);
    if (h > 0xA) {
        D_004D1900 = D_004D1900 - 1;
        func_003DAA40();
    } else {
        h++;
        *(s16 *)(p + 0x1C) = h;
    }
}

u32 func_0028BB10(u8 *p) {
    u8 r;
    u8 u;
    s8 t;
    u8 *q;
    q = *(u8 **)(p + 0x220);
    p[0x2C4] = 0xFF;
    r = func_001748C0(p + 0x34, q + 0x34);
    u = r >> 3;
    t = u;
    return (t - 0x10) & 0x1F;
}

u32 func_00189B40(u8 *a0, u8 *a1, u8 *a2) {
    s8 c;
    c = a2[1] - 1;
    a2[1] = c;
    if (c <= 0) {
        return a2[0] = 0;
    }
    return ((*(u16 *)(a0 + 0x362) & *(u16 *)(a1 + 8)) != *(u16 *)(a2 + 6)) ^ 1;
}

void func_001269F0(u8 *p) {
    if (*(float *)(p + 4) < 95.0f) *(float *)(p + 4) = 95.0f;
    if (!(*(float *)(p + 4) < 900.0f)) *(float *)(p + 4) = 900.0f;
}

s16 func_00182E80(u8 *p) {
    s16 r = 0;
    if (!(*(u16 *)(p + 0x356) & 0x3C00) && (*(u16 *)(p + 0x35C) & 0x3C00)) r += 2;
    if (*(u16 *)(p + 0x35C) & 0x3F0) r += 1;
    return r;
}

extern void func_0039BC20();
extern void func_002CE6E0();
extern void func_00175700();



extern void func_00374E40();
extern void (*D_00463F10[])(u8 *);

void func_00374A60(u8 *p) {
    if (p[4] > 2) func_00374E40();
    D_00463F10[p[4]](p);
}

extern void func_0019CE30();
extern void func_0019D050();

void func_0019CDD0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (p[4] >= 2) {
        func_003DAA40(p, q);
    } else if (p[0x20] == 0) {
        func_0019CE30(p, q);
    } else {
        func_0019D050(p, q);
    }
}

extern void func_002029D0();

void func_00202B40(u8 *p) {
    p[6] += 1;
    *(u32 *)(p + 0x5C) = 0x40555555;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41892492;
    *(u32 *)(p + 0x6C) = 0xBE892492;
    if (*(s16 *)(p + 0x140) == 0) {
        *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
    }
    *(s16 *)(p + 0x1C) = 0x5A;
    func_002029D0(p);
}

void func_002BA590(u8 *p) {
    float f;
    p[6] += 1;
    if (p[0x1E6] != 0) {
        f = -2.5f;
    } else {
        f = 2.5f;
    }
    *(float *)(p + 0x5C) = f;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x15, 4);
}

void func_00345AE0(u8 *p) {
    u8 *s;
    s = *(u8 **)(p + 0x18) + 0x2B8;
    p[5] += 1;
    func_001757E0(p, 0x15, 0xD);
    if (p[0x20] == 0) s[2] = 0;
}

extern void func_003B6CB0();


void func_0012F3E0(u16 *p) {
    p[8] = 0;
    if (p[1] == p[0]) {
        p[9] += 1;
        if (p[9] > 0x1E && p[9] > 0x23) {
            p[9] = 0x1E;
            p[8] = p[0];
        }
    } else {
        p[9] = 0;
    }
}

extern float D_004C9F40;
extern float D_004F1FF8;
extern float D_004F1F94;

void func_00126340(s32 a0, s32 a1) {
    D_004F1F94 = D_004C9F40 + (D_004F1FF8 - D_004C9F40) / (float)a1;
    D_004C9F40 = D_004F1F94;
}
