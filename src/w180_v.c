typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;
extern f32 D_0045999C[];
extern f32 D_004599A0[];
extern f32 D_004599A4[];
extern s8 D_004C0DA0[4];
extern s8 D_004C0DA4[4];
extern s8 D_004C0DA8[4];

void func_002C08A0(u8 *p) {
    extern s32 func_00184110(f32);
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        if (func_00184110(D_0045999C[0]) != 0) {
            p[0x168] = 3;
            p[0x1B5] = 0x36;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 6;
        }
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = D_004C0DA0;
        p[0x1BB] = 0;
        break;
    case 1:
        if (func_00184110(D_004599A0[0]) != 0) {
            p[0x168] = 4;
            p[0x1B5] = 0x37;
        } else {
            p[0x168] = 1;
            p[0x1B5] = 7;
        }
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004C0DA4;
        p[0x1BB] = 1;
        break;
    case 2:
        if (func_00184110(D_004599A4[0]) != 0) {
            p[0x168] = 5;
            p[0x1B5] = 0x38;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 8;
        }
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = D_004C0DA8;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}
