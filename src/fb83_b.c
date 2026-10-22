typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G83b;
extern G83b *D_004C2794;
extern u8 *D_004C2840[1];
extern u8 D_004F4480[];
extern u8 D_004C04B8[4];
extern u8 D_004C04BC[4];
extern u8 D_004C04C0[4];
extern u8 D_004C050C[4];
extern u8 D_004C0510[4];
extern u8 D_004C0514[4];
extern u8 D_004C0518[4];
extern u8 D_004C0520[4];
extern u8 D_004C0524[4];
extern u8 D_004C052C[4];
extern u8 D_004C0530[4];
extern u8 D_004C0534[4];
extern u8 D_004C053C[4];

#define TAIL(n) \
    t = *(volatile u8 *)(p + 0x1B5); p[0x1B5] = t; \
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0; \
    *(s32 *)(p + 0x1D8) = 0; \
    D_004C2794->f7c[p[2]]++; \
    func_001757E0(p, n, p[0x168]);

#define CASEN(c, a168, a1b5, tbl) \
    case c: \
        p[0x168] = a168; p[0x1B5] = a1b5; *(u8 **)(p + 0x408) = tbl; \
        TAIL(0x14) \
        p[0x1BB] = 0; \
        return;

void func_00255FE0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u8 *q;
    *(u16 *)(p + 0x2BC) = 0;
    q = p + 0x2B8;
    if (p[0x1FC] >= 3) *(u16 *)(q + 4) = 1;
    switch (p[0x1FC]) {
    case 0:
        *(u16 *)(q + 2) = 1; p[0x168] = 0; p[0x1B5] = 6; *(u8 **)(p + 0x408) = D_004C04B8; p[0x1BB] = 0;
        break;
    case 1:
        *(u16 *)(q + 2) = 1; p[0x168] = 1; p[0x1B5] = 7; *(u8 **)(p + 0x408) = D_004C04BC; p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2; p[0x1B5] = 8; *(u8 **)(p + 0x408) = D_004C04C0; p[0x1BB] = 2;
        TAIL(9)
        return;
    case 3:
        if (*(u16 *)((p[2] << 1) + (u32)D_004C2840[0] + 0x106) == 1 || D_004F4480 != 0) p[0x168] = 6;
        p[0x1B5] = 0x45; *(u8 **)(p + 0x408) = D_004C050C;
        TAIL(0x14)
        p[0x1BB] = 0;
        return;
    CASEN(4, 7, 0x46, D_004C0510)
    CASEN(5, 8, 0x47, D_004C0514)
    CASEN(6, 9, 0x48, D_004C0518)
    CASEN(7, 0xB, 0x4A, D_004C0520)
    CASEN(8, 0xC, 0x4B, D_004C0524)
    CASEN(9, 0xE, 0x4D, D_004C052C)
    CASEN(10, 0xF, 0x4E, D_004C0530)
    CASEN(11, 0x10, 0x4F, D_004C0534)
    CASEN(12, 0x12, 0x51, D_004C053C)
    default:
        *(u16 *)(q + 2) = 1; p[0x168] = 0; p[0x1B5] = 6; *(u8 **)(p + 0x408) = D_004C04B8; p[0x1BB] = 0;
        return;
    }
    TAIL(9)
}
