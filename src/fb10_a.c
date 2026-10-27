typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G94;
extern G94 *D_004C2794;
extern s32 D_004C114C[2];
extern s32 D_004C1150[2];
extern s32 D_004C1154[2];
extern s32 D_004C1164[2];
extern s32 D_004C1168[2];
extern s32 D_004C116C[2];

void func_002E9BC0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        func_001757E0(p, 0xC, 0);
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = D_004C114C;
        } else {
            *(s32 **)(p + 0x408) = D_004C1164;
        }
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        func_001757E0(p, 0xC, 1);
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = D_004C1150;
        } else {
            *(s32 **)(p + 0x408) = D_004C1168;
        }
        p[0x1BB] = 1;
        break;
    case 2:
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = D_004C1154;
        } else {
            *(s32 **)(p + 0x408) = D_004C116C;
        }
        p[0x1BB] = 2;
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0 && 137.14285278f + *(f32 *)(p + 0x430) < *(f32 *)(p + 0x38)) {
            p[0x215] = 0;
            p[0x1EA] = p[0x1EA] & 0xF;
            p[0x210] = 0;
            func_001757E0(p, 0x14, 4);
            p[0x1B5] = 0x15;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            p[6] = 1;
            p[7] = 0;
        } else {
            p[6] = 0;
            p[0x169] = 0xC;
            func_001E3710(p, 0x16);
            if ((*(u16 *)(p + 0x20E) & 0x2000) != 0) {
                func_001757E0(p, 0xC, 6);
                p[0x1B5] = 0x14;
            } else {
                func_001757E0(p, 0xC, 2);
                p[0x1B5] = 0x11;
            }
        }
        break;
    default:
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    {
        s32 q = *(s8 *)(p + 0x1EA);
        if ((q & 0xF0) != 0) p[0x1EA] = q - 0x10;
    }
}
