typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern s8 D_004C0BF4[4];
extern s8 D_004C0BF8[4];
extern s8 D_004C0BFC[4];
extern s8 D_004C0C0C[4];
extern s8 D_004C0C10[4];
extern s8 D_004C0C14[4];

void func_002A7FD0(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, u8);
    u8 *q;
    switch (p[0x1FC]) {
    case 0:
        if (*(u16 *)(p + 0x20E) & 0x1000) {
            p[0x168] = 0;
            p[0x1B5] = 21;
        } else {
            p[0x168] = 3;
            p[0x1B5] = 15;
        }
        func_001E3710(p, 0x14);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = D_004C0BF4;
        else
            *(s8 **)(p + 0x408) = D_004C0C0C;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 4;
        p[0x1B5] = 16;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = D_004C0BF8;
        else
            *(s8 **)(p + 0x408) = D_004C0C10;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 5;
        p[0x1B5] = 17;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = D_004C0BFC;
        else
            *(s8 **)(p + 0x408) = D_004C0C14;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
    *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    func_001757E0(p, 12, p[0x168]);
    {
        s8 t = p[0x1EA];
        if (t & 0xF0)
            p[0x1EA] = t - 16;
    }
}
