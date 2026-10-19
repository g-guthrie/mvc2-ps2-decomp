typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004C0660 __attribute__((section(".sdata")));
extern u8 D_004C0648 __attribute__((section(".sdata")));
extern u8 D_004C0664 __attribute__((section(".sdata")));
extern u8 D_004C064C __attribute__((section(".sdata")));
extern u8 D_004C0668 __attribute__((section(".sdata")));
extern u8 D_004C0650 __attribute__((section(".sdata")));

extern void func_001E3710(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001B53E0(u8 *, int, int);

void func_002632F0(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001757E0(p, 0xB, p[0x168]);
        func_001B53E0(p, 0, 2);
        func_001E3710(p, 0x14);
        if (p[0x210] == 0)
            *(u8 **)(p + 0x408) = &D_004C0648;
        else
            *(u8 **)(p + 0x408) = &D_004C0660;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0)
            *(u8 **)(p + 0x408) = &D_004C064C;
        else
            *(u8 **)(p + 0x408) = &D_004C0664;
        p[0x1BB] = 1;
        func_001757E0(p, 0xB, p[0x168]);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        func_001E3710(p, 0x16);
        if (p[0x210] == 0)
            *(u8 **)(p + 0x408) = &D_004C0650;
        else
            *(u8 **)(p + 0x408) = &D_004C0668;
        p[0x1BB] = 2;
        func_001757E0(p, 0xB, p[0x168]);
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    {
        s8 ea = *(s8 *)(p + 0x1EA);
        if ((ea & 0xF) != 0)
            *(s8 *)(p + 0x1EA) = ea - 1;
    }
}
