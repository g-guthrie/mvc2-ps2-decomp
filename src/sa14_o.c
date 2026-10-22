typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G1;
extern G1 *D_004C2794;
extern u8 D_004C0D58[2], D_004C0D40[2], D_004C0D5C[2], D_004C0D44[2], D_004C0D60[2], D_004C0D48[2];

void func_002B9070(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s8 v;
    switch (p[0x1FC]) {
    case 0:
        if ((s8)p[0x1E7] < 0) p[0x168] = 0; else p[0x168] = 3;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0D40; else *(u8 **)(p + 0x408) = D_004C0D58;
        p[0x1BB] = 0;
        break;
    case 1:
        if ((s8)p[0x1E7] < 0) p[0x168] = 1; else p[0x168] = 4;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0D44; else *(u8 **)(p + 0x408) = D_004C0D5C;
        p[0x1BB] = 1;
        break;
    case 2:
        if ((s8)p[0x1E7] < 0) p[0x168] = 2; else p[0x168] = 5;
        p[0x1B5] = 0xE;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0D48; else *(u8 **)(p + 0x408) = D_004C0D60;
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
    v = p[0x1EA];
    if ((v & 0xF) != 0) p[0x1EA] = v - 1;
}
