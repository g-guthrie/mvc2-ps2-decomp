typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_a;
extern H_a *D_004C2794;
extern s32 D_004C0D4C[2], D_004C0D50[2], D_004C0D54[2], D_004C0D64[2], D_004C0D68[2], D_004C0D6C[2];

void func_002B9210(u8 *p)
{
    extern s32 func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s8 a;

    switch (p[0x1FC]) {
    case 0:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 0; else p[0x168] = 3;
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(s32 **)(p + 0x408) = D_004C0D4C; else *(s32 **)(p + 0x408) = D_004C0D64;
        p[0x1BB] = 0;
        break;
    case 1:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 1; else p[0x168] = 4;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(s32 **)(p + 0x408) = D_004C0D50; else *(s32 **)(p + 0x408) = D_004C0D68;
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 2; else p[0x168] = 5;
        p[0x1B5] = 0x11;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(s32 **)(p + 0x408) = D_004C0D54; else *(s32 **)(p + 0x408) = D_004C0D6C;
        p[0x1BB] = 2;
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, 0xC, p[0x168]);
    a = *(s8 *)(p + 0x1EA);
    if ((a & 0xF0) != 0) *(s8 *)(p + 0x1EA) = a - 0x10;
}
