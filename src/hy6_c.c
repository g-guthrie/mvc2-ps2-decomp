typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1fd;
extern G1fd *D_004C2794;
extern u8 D_004BFD04[4], D_004BFCEC[4], D_004BFD08[4], D_004BFCF0[4], D_004BFD0C[4], D_004BFCF4[4];

void func_001FD110(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 b;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFCEC; else *(u8 **)(p + 0x408) = D_004BFD04;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFCF0; else *(u8 **)(p + 0x408) = D_004BFD08;
        p[0x1BB] = 1;
        break;
    case 2:
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0) {
            p[6] = 2;
            p[7] = 0;
            p[0x210] = 0;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            p[0x168] = 5;
            p[0x1B5] = 0x12;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 0x11;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFCF4; else *(u8 **)(p + 0x408) = D_004BFD0C;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    b = *(s8 *)(p + 0x1EA);
    if ((b & 0xF0) != 0) p[0x1EA] = b - 0x10;
}
