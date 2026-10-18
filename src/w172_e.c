typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h[8]; } G;

extern G *D_004C2794;
extern u8 D_004C152C[1], D_004C1530[1], D_004C1534[1], D_004C1544[1], D_004C1548[1], D_004C154C[1];
extern u8 D_004C0798[1], D_004C079C[1], D_004C07A0[1], D_004C07B0[1], D_004C07B4[1], D_004C07B8[1];

void func_00305B80(u8 *s0) {
    extern void func_001757E0(void *, s32, s32);
    s32 v;
    switch (s0[0x1FC]) {
    case 0:
        s0[0x168] = 0;
        s0[0x1B5] = 0xF;
        if (s0[0x210] == 0) {
            *(u8 **)(s0 + 0x408) = D_004C152C;
        } else {
            *(u8 **)(s0 + 0x408) = D_004C1544;
        }
        s0[0x1BB] = 0;
        break;
    case 1:
        s0[0x168] = 1;
        s0[0x1B5] = 0x10;
        if (s0[0x210] == 0) {
            *(u8 **)(s0 + 0x408) = D_004C1530;
        } else {
            *(u8 **)(s0 + 0x408) = D_004C1548;
        }
        s0[0x1BB] = 1;
        break;
    case 2:
        s0[0x168] = 2;
        s0[0x1B5] = 0x11;
        if (s0[0x210] == 0) {
            *(u8 **)(s0 + 0x408) = D_004C1534;
        } else {
            *(u8 **)(s0 + 0x408) = D_004C154C;
        }
        s0[0x1BB] = 2;
        break;
    default:
        break;
    }
    v = s0[0x1B5];
    s0[0x1B5] = v;
    s0[0x1B2] = *(u16 *)(s0 + 0x1C0) = 0;
    *(u32 *)(s0 + 0x1D8) = 0;
    D_004C2794->h[s0[2]]++;
    func_001757E0(s0, 0xC, s0[0x168]);
    if ((*(s8 *)(s0 + 0x1EA) & 0xF0) != 0) {
        s0[0x1EA] = *(s8 *)(s0 + 0x1EA) - 0x10;
    }
}

void func_002742B0(u8 *s0) {
    extern void func_001757E0(void *, s32, s32);
    s32 v;
    switch (s0[0x1FC]) {
    case 0:
        s0[0x168] = 0;
        s0[0x1B5] = 0xC;
        if (s0[0x210] == 0) {
            *(u8 **)(s0 + 0x408) = D_004C0798;
        } else {
            *(u8 **)(s0 + 0x408) = D_004C07B0;
        }
        s0[0x1BB] = 0;
        break;
    case 1:
        s0[0x168] = 1;
        s0[0x1B5] = 0xD;
        if (s0[0x210] == 0) {
            *(u8 **)(s0 + 0x408) = D_004C079C;
        } else {
            *(u8 **)(s0 + 0x408) = D_004C07B4;
        }
        s0[0x1BB] = 1;
        break;
    case 2:
        s0[0x168] = 2;
        s0[0x1B5] = 0xE;
        if (s0[0x210] == 0) {
            *(u8 **)(s0 + 0x408) = D_004C07A0;
        } else {
            *(u8 **)(s0 + 0x408) = D_004C07B8;
        }
        s0[0x1BB] = 2;
        break;
    default:
        break;
    }
    v = s0[0x1B5];
    s0[0x1B5] = v;
    s0[0x1B2] = *(u16 *)(s0 + 0x1C0) = 0;
    *(u32 *)(s0 + 0x1D8) = 0;
    D_004C2794->h[s0[2]]++;
    func_001757E0(s0, 0xB, s0[0x168]);
    if ((*(s8 *)(s0 + 0x1EA) & 0x0F) != 0) {
        s0[0x1EA] = *(s8 *)(s0 + 0x1EA) - 1;
    }
}
