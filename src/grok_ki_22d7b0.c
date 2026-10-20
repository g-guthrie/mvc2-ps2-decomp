typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern s8 D_004C00FC;
extern s8 D_004C0100;
extern s8 D_004C0104;
extern s8 D_004C0114;
extern s8 D_004C0118;
extern s8 D_004C011C;
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, u8);

void func_0022D7B0(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = &D_004C00FC;
        else
            *(s8 **)(p + 0x408) = &D_004C0114;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = &D_004C0100;
        else
            *(s8 **)(p + 0x408) = &D_004C0118;
        p[0x1BB] = 1;
        break;
    case 2: {
        u16 h = *(u16 *)(p + 0x20E);
        if (h & 0x1000) {
            p[0x168] = 3;
            p[0x1B5] = 0x1E;
        } else if (h & 0x2000) {
            p[0x168] = 4;
            p[0x1B5] = 0x1F;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 0x11;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0)
            *(s8 **)(p + 0x408) = &D_004C0104;
        else
            *(s8 **)(p + 0x408) = &D_004C011C;
        p[0x1BB] = 2;
        break;
    }
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    {
        u8 *q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
        *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    }
    func_001757E0(p, 0xC, p[0x168]);
    {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF0) != 0)
            p[0x1EA] = t - 0x10;
    }
}
