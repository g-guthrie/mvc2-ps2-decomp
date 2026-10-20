typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern s8 D_004C0D34[4];
extern s8 D_004C0D38[4];
extern s8 D_004C0D3C[4];

void func_002B8DA0(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, u8);
    u8 *q;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = D_004C0D34;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 4;
        p[0x1B5] = 22;
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004C0D38;
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(u16 *)(p + 0x20E) & 0x400) {
            p[0x168] = 5;
            p[0x1B5] = 23;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 5;
        }
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = D_004C0D3C;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
    *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    func_001757E0(p, 8, p[0x168]);
}
