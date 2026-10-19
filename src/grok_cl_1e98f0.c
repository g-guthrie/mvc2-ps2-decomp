typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern u8 D_004BFAF8;
extern u8 D_004BFAFC;
extern u8 D_004BFB00;
extern u8 *D_004C2794;

void func_001E98F0(u8 *p)
{
    p[0x169] = 7;
    switch (p[0x1FC]) {
    case 2:
        p[0x168] = 2;
        func_001E3710(p, 0x16);
        p[0x1B5] = 8;
        *(u8 **)(p + 0x408) = &D_004BFB00;
        p[0x1BB] = 2;
        break;
    case 1:
        p[0x168] = 1;
        func_001E3710(p, 0x15);
        p[0x1B5] = 7;
        *(u8 **)(p + 0x408) = &D_004BFAFC;
        p[0x1BB] = 1;
        break;
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = &D_004BFAF8;
        p[0x1BB] = 0;
        break;
    }
    p[0x1B5] = p[0x1B5];
    *(u16 *)(p + 0x1C0) = 0;
    p[0x1B2] = 0;
    *(s32 *)(p + 0x1D8) = 0;
    *(s16 *)(D_004C2794 + (p[2] << 1) + 0x7C) += 1;
    func_001757E0(p, 9, p[0x168]);
}
