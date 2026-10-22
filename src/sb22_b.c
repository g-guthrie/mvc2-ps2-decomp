typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G262D70;
extern G262D70 *D_004C2794;
extern u8 D_004C0630;
extern u8 D_004C0634;
extern u8 D_004C0638;

void func_00262D70(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_001B53E0(u8 *, s32, s32);
    extern void func_001B3E30(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001757E0(p, 7, p[0x168]);
        func_001B53E0(p, 0, 2);
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = &D_004C0630;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = &D_004C0634;
        p[0x1BB] = 1;
        func_001757E0(p, 7, p[0x168]);
        func_001B53E0(p, 0, 2);
        break;
    case 2:
        if ((*(u16 *)(p + 0x20E) & 0x800) != 0) {
            p[0x168] = 3;
            p[0x1B5] = 0x12;
            func_001757E0(p, 7, p[0x168]);
        } else {
            p[0x168] = 2;
            p[0x1B5] = 2;
            func_001757E0(p, 7, p[0x168]);
            func_001B3E30(p, 4, 0);
            func_001B3E30(p, 5, 0);
        }
        func_001E3710(p, 0x16);
        *(u8 **)(p + 0x408) = &D_004C0638;
        p[0x1BB] = 2;
        func_001B53E0(p, 0, 2);
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}
