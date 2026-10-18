typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G7C;
extern G7C *D_004C2794;
extern s32 D_004BFC48;
extern s32 D_004BFC4C;
extern s32 data_s8_004BFC50;
extern f32 D_0044FC40[];

void func_001F7B60(u8 *p) {
    extern s32 func_00184110(f32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 k = p[0x1FC];
    u32 t;
    u32 h;
    switch (k) {
    case 0:
        if (func_00184110(D_0044FC40[0])) {
            p[0x168] = 3;
            p[0x1B5] = 0x42;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 0;
        }
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = &D_004BFC48;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        p[0x168] = 4;
        p[0x1B5] = 0x43;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = &D_004BFC4C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        h = *(u16 *)(p + 0x20E);
        if (h == 0x800) {
            p[0x168] = 6;
            p[0x1B5] = 0x12;
        } else if (h == 0x400) {
            p[0x168] = 5;
            p[0x1B5] = 0x44;
        }
        func_001E3710(p, 0x16);
        *(s32 **)(p + 0x408) = &data_s8_004BFC50;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
