typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 a[1]; } G7C;

void func_0029BCD0(u8 *p) {
    extern G7C *D_004C2794;
    extern u8 D_004C0AF0[4], D_004C0AF4[4], D_004C0AF8[4];
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        *(u8 **)(p + 0x408) = D_004C0AF0;
        p[0x1BB] = 0;
        break;
    case 1:
        *(u8 **)(p + 0x408) = D_004C0AF4;
        p[0x1BB] = 1;
        break;
    case 2:
        *(u8 **)(p + 0x408) = D_004C0AF8;
        p[0x1BB] = 2;
        break;
    }
    func_001E3710(p, p[0x1FC] + 0x14);
    p[0x1B5] = *(s8 *)(p + 0x1FC) + 6;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->a[p[2]]++;
    func_001757E0(p, 9, p[0x1FC]);
}

