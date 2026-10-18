typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_m;
extern G_m *D_004C2794;
extern u8 D_004BFB10[2];
extern u8 D_004BFB14[2];
extern u8 D_004BFB18[2];
extern u8 D_004BFB28[2];
extern u8 D_004BFB2C[2];
extern u8 D_004BFB30[2];

void func_001E9C80(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s8 c;
    p[0x169] = 0xB;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0)
            *(u8 **)(p + 0x408) = D_004BFB10;
        else
            *(u8 **)(p + 0x408) = D_004BFB28;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x169] = 0x14;
        p[0x168] = 2;
        p[0x1B5] = 0x15;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0)
            *(u8 **)(p + 0x408) = D_004BFB14;
        else
            *(u8 **)(p + 0x408) = D_004BFB2C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0)
            *(u8 **)(p + 0x408) = D_004BFB18;
        else
            *(u8 **)(p + 0x408) = D_004BFB30;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
    c = *(s8 *)(p + 0x1EA);
    if ((c & 0xF) != 0)
        p[0x1EA] = c - 1;
}
