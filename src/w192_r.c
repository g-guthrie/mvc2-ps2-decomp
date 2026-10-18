typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct G { u8 pad[0x7C]; s16 h7C[1]; } G;
extern G *D_004C2794;
extern void func_001757E0(u8 *, s32, s32);

void func_002789F0(u8 *p)
{
    u8 x;
    s8 a;
    switch (p[0x1FC]) {
    case 0:
    case 6:
        p[0x169] = 0xB; p[0x168] = 0; x = 0xC;
        break;
    case 1:
    case 7:
        p[0x169] = 0xB; p[0x168] = 1; x = 0xD;
        break;
    case 2:
    case 8:
        p[0x169] = 0xB; p[0x168] = 2; x = 0xE;
        break;
    case 3:
    case 9:
        p[0x169] = 0xC; p[0x168] = 0; x = 0xF;
        break;
    case 4:
    case 10:
        p[0x169] = 0xC; p[0x168] = 1; x = 0x10;
        break;
    case 5:
    case 11:
        p[0x169] = 0xC; p[0x168] = 2; x = 0x11;
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
    if (p[0x212] == 0) {
        a = p[0x1EA];
        if ((a & 0xF) != 0)
            p[0x1EA] = a - 1;
    } else {
        a = p[0x1EA];
        if ((a & 0xF0) != 0)
            p[0x1EA] = a - 0x10;
    }
}
