typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G94;
extern G94 *D_004C2794;
extern signed char data_s8_004C1344[12] __attribute__((section(".sdata")));
extern s32 D_004C1348;
extern s32 D_004C134C;

void func_002F7940(u8 *p)
{
    extern void func_001E3710();
    extern void func_001757E0();
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = data_s8_004C1344;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 10;
        *(s32 **)(p + 0x408) = &D_004C1348;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 11;
        *(s32 **)(p + 0x408) = &D_004C134C;
        p[0x1BB] = 2;
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xA, p[0x168]);
}
