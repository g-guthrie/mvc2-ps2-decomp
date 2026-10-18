typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C2794;
extern u8 D_004B7130[];
extern f32 D_004B7140[], D_004B7144[], D_004B7148[], D_004B714C[];
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;
extern u32 data_u32_004BFF40, D_004BFF44, D_004BFF48, D_004BFF58, D_004BFF5C, D_004BFF60;
void func_0021DBE0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &data_u32_004BFF40;
        else *(u32 **)(p + 0x408) = &D_004BFF58;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        func_001E3210(p, 3);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004BFF44;
        else *(u32 **)(p + 0x408) = &D_004BFF5C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        func_001E3710(p, 0x16);
        func_001E3210(p, 4);
        func_001E3210(p, 0x20);
        if (p[0x210] == 0) *(u32 **)(p + 0x408) = &D_004BFF48;
        else *(u32 **)(p + 0x408) = &D_004BFF60;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
    func_001757E0(p, 0xB, p[0x168]);
    if (*(s8 *)(p + 0x1EA) & 0xF) p[0x1EA] = *(s8 *)(p + 0x1EA) - 1;
}

extern u8 *D_004C2794;
void func_00234640(u8 *p) {
    extern void func_001861B0(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001E3710(u8 *, u8);
    extern s32 func_001757E0(u8 *, s32, u8);
    extern void func_00183D90(u8 *);
    extern void func_001863F0(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    s32 a, b;
    if (p[6] == 0) {
        s32 c, d;
        p[6]++;
        if (p[0x212] == 0) {
            d = 0x2B; a = 1; b = 0x15; c = 0;
        } else {
            d = 0x2A; a = 2; b = 0x14; c = 1;
        }
        p[0x20D] = c;
        p[0x1B5] = d;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
        func_001861B0(p);
        func_0018C4B0(p, 5);
        func_001E3710(p, b);
        func_001757E0(p, 0x14, a);
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_00175700(p) < 0) func_001843A0(p);
}

extern u8 *D_004C2794;
extern u8 D_00451770[], D_00451740[], D_00451760[], D_00451750[];
extern u32 D_004515F0[];
extern u8 D_004C0058[8];
void func_002269C0(u8 *p) {
    extern void func_001861B0(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    s32 i;
    s32 s;
    func_001861B0(p);
    p[7] = 0;
    p[6] = 0;
    i = p[0x1FC];
    if (p[0x20D] == 1) i = (u8)(i + 6);
    if (p[0x212] != 0) i = (u8)(i + 3);
    s = (u8)i;
    *(u32 *)(p + 0x334) = D_00451770[s];
    *(u32 *)(p + 0x408) = D_004515F0[s % 6];
    p[0x1BB] = D_004C0058[p[0x1FC]];
    p[0x1B5] = D_00451740[s];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
    func_001757E0(p, D_00451760[s], D_00451750[s]);
    if (s == 2 && *(s32 *)(p + 0x2BC) == 0x29 && (*(u16 *)(p + 0x35E) & 0x800)) {
        *(u32 *)(p + 0x334) = 5;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_001757E0(p, 7, 3);
    }
}

extern u8 D_00474BF6[];
void func_003BB730(u8 *p) {
    extern void func_003BD7B0(u8 *);
    extern void func_003BD670(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    extern void func_003BB8F0(u8 *);
    extern void func_003BB910(u8 *);
    extern s32 func_003BD1D0(u8 *);
    extern void func_00175700(u8 *);
    u8 *q = *(u8 **)(p + 0x18);
    u8 *r = *(u8 **)(p + 0xD0);
    u8 *t = q + 0x2B8;
    s32 v;
    func_003BD7B0(p);
    if (p[6] == 0) {
        p[6]++;
        *(s16 *)(p + 0x140) = *(s16 *)(r + 0x140);
        func_003BD670(p);
        func_001757E0(p, 0x19, D_00474BF6[r[1] * 64 + p[0x21] * 8]);
        return;
    }
    func_003BD670(p);
    if (t[3] == 0 || q[0x425] != 0) {
        func_003BB8F0(p);
        return;
    }
    if (r[5] != 3) {
        func_003BB910(p);
        return;
    }
    v = r[0x247];
    if (v != 9 && v != 0x17) {
        func_003BB910(p);
        return;
    }
    v = 2;
    *(s16 *)(r + 0x1F8) = v;
    r[0x24D] = v;
    if (func_003BD1D0(p) != 0) {
        func_003BB910(p);
    } else {
        func_00175700(p);
    }
}

extern void (*jtbl_004C1B94[2])(u8 *, u8 *);
extern void (*jtbl_004C1188[2])(u8 *, u8 *);
