typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern s8 D_004BFCC8[4];
extern s8 D_004BFCCC[4];
extern s8 D_004BFCD0[4];

void func_001FCAC0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, u8);
    u32 a;
    u8 *q;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = D_004BFCC8;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004BFCCC;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = D_004BFCD0;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
    *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    func_001757E0(p, 7, p[0x168]);
}

extern s8 D_004C0718[4];
extern s8 D_004C071C[4];
extern s8 data_s8_004C0720[4];

void func_0026F650(u8 *p) {
    extern void func_001E3210();
    extern void func_001B7C70();
    extern void func_001757E0(u8 *, s32, u8);
    u8 *q;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3210(p, 0x1F);
        *(s8 **)(p + 0x408) = D_004C0718;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3210(p, 0x20);
        *(s8 **)(p + 0x408) = D_004C071C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        func_001B7C70(p, 2);
        func_001E3210(p, 0x21);
        *(s8 **)(p + 0x408) = data_s8_004C0720;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
    *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    func_001757E0(p, 7, p[0x168]);
}
