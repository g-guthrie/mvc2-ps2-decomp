typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00175700(u8 *);
extern void func_00184540(void *);
extern void func_001855D0(u8 *);
extern void func_0019B110(void *, u8);
extern void func_001E3210(u8 *, s32);
extern void func_001865B0(u8 *);
extern s32 func_001864A0(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2794 __attribute__((section(".sdata")));

void func_0031C940(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_0019B110(p, 4);
        }
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
            break;
        }
        if (*(s8 *)(p + 0x151) == 0)
            break;
        if (*(s8 *)(p + 0x1B2) == 0)
            break;
        if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x200) == 0)
            break;
        if (p[0x210] == 0)
            break;
        *(u16 *)(p + 0x366) = 0;
        func_001855D0(p);
        func_001E3210(p, 0x1F);
        if (*(s8 *)(p + 0x151) == 1) {
            p[0x1B5] = 0x1D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
            func_001757E0(p, 0x0B, 4);
        } else {
            p[0x1B5] = 0x0D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
            func_001757E0(p, 0x0B, 1);
        }
        break;
    }
    if (func_001864A0(p) != 0)
        func_001865B0(p);
}
