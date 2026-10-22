typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa3_c.c "-O3 -sdatathreshold 8"  (and try30) */
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_c;
extern G_c *D_004C2794;
extern u8 D_004C0B68, D_004C0B6C, D_004C0B70, D_004C0B74, D_004C0B78, D_004C0B7C;
extern u8 D_004C0B80, D_004C0B84, D_004C0B88, D_004C0B8C, D_004C0B90, D_004C0B94;
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_002A1B60(u8 *p) {
    u32 t;
    s32 x;
    s16 y;
    switch (p[0x1FC]) {
    case 0:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 0; else p[0x168] = 3;
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = &D_004C0B74; else *(u8 **)(p + 0x408) = &D_004C0B8C;
        p[0x1BB] = 0;
        break;
    case 1:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 1; else p[0x168] = 4;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = &D_004C0B78; else *(u8 **)(p + 0x408) = &D_004C0B90;
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 2; else p[0x168] = 5;
        p[0x1B5] = 0x11;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = &D_004C0B7C; else *(u8 **)(p + 0x408) = &D_004C0B94;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    t = *(s8 *)(p + 0x1EA);
    if ((t & 0xF0) != 0) *(s8 *)(p + 0x1EA) = t - 0x10;
}

void func_002A19C0(u8 *p) {
    u32 t;
    s32 x;
    s16 y;
    switch (p[0x1FC]) {
    case 0:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 0; else p[0x168] = 3;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = &D_004C0B68; else *(u8 **)(p + 0x408) = &D_004C0B80;
        p[0x1BB] = 0;
        break;
    case 1:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 1; else p[0x168] = 4;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = &D_004C0B6C; else *(u8 **)(p + 0x408) = &D_004C0B84;
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(s8 *)(p + 0x1E7) < 0) p[0x168] = 2; else p[0x168] = 5;
        p[0x1B5] = 0xE;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = &D_004C0B70; else *(u8 **)(p + 0x408) = &D_004C0B88;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xB, p[0x168]);
    t = *(s8 *)(p + 0x1EA);
    if ((t & 0xF) != 0) *(s8 *)(p + 0x1EA) = t - 1;
}
