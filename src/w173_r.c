typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G263010;
extern G263010 *D_004C2794;
extern u8 D_004C063C;
extern u8 D_004C0640;
extern u8 D_004C0644;

void func_00263010(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_001B53E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = &D_004C063C;
        p[0x1BB] = 0;
        func_001757E0(p, 8, p[0x168]);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = &D_004C0640;
        p[0x1BB] = 1;
        func_001757E0(p, 8, p[0x168]);
        func_001B53E0(p, 0, 2);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        func_001E3710(p, 0x16);
        *(u8 **)(p + 0x408) = &D_004C0644;
        p[0x1BB] = 2;
        func_001757E0(p, 8, p[0x168]);
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}
