typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
extern s32 D_004BFE8C, D_004BFE90, D_004BFE94;
void func_00211040(u8 *p) {
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    u8 k;
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        k = 0x14;
        *(s32 **)(p + 0x408) = &D_004BFE8C;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xA;
        k = 0x15;
        *(s32 **)(p + 0x408) = &D_004BFE90;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xB;
        k = 0x16;
        *(s32 **)(p + 0x408) = &D_004BFE94;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    func_001E3710(p, k);
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0xA, p[0x168]);
}

void func_00210F40(u8 *p) {
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    u8 k;
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        k = 0x14;
        *(s32 **)(p + 0x408) = &D_004BFE8C;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        k = 0x15;
        *(s32 **)(p + 0x408) = &D_004BFE90;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        k = 0x16;
        *(s32 **)(p + 0x408) = &D_004BFE94;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    func_001E3710(p, k);
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 8, p[0x168]);
}
