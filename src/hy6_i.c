typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_0045AF00[][2];
extern s8 D_0045AF20[][2];
extern u8 D_0045AF40[][2];

void func_002E3A10(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00126400();
    extern void func_002E1520(u8 *, s32);
    extern void func_001D36E0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    p[0x1FE] = 1;
    if (p[0x20B] == 0) {
        if ((s8)func_00175700(p) < 0) {
            func_00126400();
            func_002E1520(p, p[0x20D]);
            return;
        }
        if (*(s8 *)(p + 0x151) == 1) {
            p[0x151] = 0;
            func_001D36E0(p, 3);
        }
        if (*(s8 *)(p + 0x151) == 2) {
            p[0x151] = 0;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            *(u8 **)((*(u8 **)(p + 0x1DC)) + 0x1C8) = p;
            (*(u8 **)(p + 0x1DC))[0x20A] = 5;
            (*(u8 **)(p + 0x1DC))[0x1B5] = D_0045AF00[(*(u16 *)(p + 0x35E) & 0x3C00) >> 10][0];
            func_00126400();
        }
    } else if (p[6] == 0) {
        s16 h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) {
            s16 i;
            u32 t = p[6];
            p[6] = t + 1;
            i = (*(u16 *)(p + 0x35E) & 0x3C00) >> 10;
            p[0x1B7] = D_0045AF20[i][0];
            func_001757E0(p, 0xF, D_0045AF40[i][0]);
        }
        func_00175700(p);
    } else {
        if ((s8)func_00175700(p) < 0) {
            func_00126400();
            func_002E1520(p, p[0x20D]);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            *(u8 **)((*(u8 **)(p + 0x1DC)) + 0x1C8) = p;
            (*(u8 **)(p + 0x1DC))[0x20A] = 1;
            (*(u8 **)(p + 0x1DC))[0x1B5] = p[0x1B7];
        }
    }
}
