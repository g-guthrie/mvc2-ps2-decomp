typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern s8 D_004BFF98;
extern s8 D_004BFF9C;
extern s8 D_004BFFA0;
extern void func_001E3710(u8 *, s32);
extern void func_00223130(u8 *);
extern void func_00355BE0(u8 *, s32);
extern void func_001757E0(u8 *, s32, u8);

void func_00223310(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x169] = 9;
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = &D_004BFF98;
        p[0x1BB] = 0;
        func_00223130(p);
        break;
    case 1:
        p[0x169] = 9;
        p[0x168] = 1;
        p[0x1B5] = 7;
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = &D_004BFF9C;
        p[0x1BB] = 1;
        func_00223130(p);
        break;
    case 2:
        p[0x169] = 9;
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s8 **)(p + 0x408) = &D_004BFFA0;
        func_001E3710(p, 0x16);
        p[0x1BB] = 2;
        func_00355BE0(p, 3);
        func_00355BE0(p, 4);
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    {
        u8 *q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
        *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    }
    func_001757E0(p, 9, p[0x168]);
}
