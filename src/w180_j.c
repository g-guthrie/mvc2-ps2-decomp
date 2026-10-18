typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;
extern s8 data_s8_004C1294[4];
extern s8 D_004C1298[4];
extern s8 D_004C129C[4];

void func_002F2B90(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003AD480(u8 *, s32, u8);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = data_s8_004C1294;
        p[0x1BB] = 0;
        func_001757E0(p, 0xA, p[0x168]);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xA;
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004C1298;
        p[0x1BB] = 1;
        func_001757E0(p, 0xA, p[0x168]);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xB;
        *(s8 **)(p + 0x408) = D_004C129C;
        p[0x1BB] = 2;
        func_001E3710(p, 0x16);
        func_001757E0(p, 0xA, p[0x168]);
        func_003AD480(p, 0, (*(u16 *)(p + 0x20E) & 0xC00) >> 10);
        *(s16 *)(p + 0x1C) = 0x100;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}
