typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gg;
extern Gg *D_004C2794;
extern s32 D_004C1520[2];
extern s32 D_004C1524[2];
extern s32 D_004C1528[2];
extern s32 D_004C1538[2];
extern s32 D_004C153C[2];
extern s32 D_004C1540[2];

void func_00305A40(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    s32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)D_004C1520;
        else *(s32 *)(p + 0x408) = (s32)D_004C1538;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)D_004C1524;
        else *(s32 *)(p + 0x408) = (s32)D_004C153C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)D_004C1528;
        else *(s32 *)(p + 0x408) = (s32)D_004C1540;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xB, p[0x168]);
    t = *(s8 *)(p + 0x1EA);
    if ((t & 0xF) != 0) p[0x1EA] = t - 1;
}
