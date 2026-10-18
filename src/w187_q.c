typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
extern s32 D_004C12AC;
extern s32 D_004C12B0;
extern s32 D_004C12B4;
extern s32 D_004C12C4;
extern s32 D_004C12C8;
extern s32 D_004C12CC;
extern void func_001E3710(u8 *, u8);
extern void func_001757E0(u8 *, s32, s32);

void func_002F2EC0(u8 *p) {
    u8 k;
    s32 a;
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xF;
        k = 0x14;
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C12AC;
        else *(s32 *)(p + 0x408) = (s32)&D_004C12C4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0x10;
        k = 0x15;
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C12B0;
        else *(s32 *)(p + 0x408) = (s32)&D_004C12C8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0x11;
        k = 0x16;
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004C12B4;
        else *(s32 *)(p + 0x408) = (s32)&D_004C12CC;
        p[0x1BB] = 2;
        break;
    }
    func_001E3710(p, k);
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    a = (s8)p[0x1EA];
    if ((a & 0xF0) != 0) p[0x1EA] = a - 16;
}
