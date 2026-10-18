typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C0D28[1];
extern s32 D_004C0D2C[1];
extern s32 data_s8_004C0D30[1];
typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G1;
extern G1 *D_004C2794;

void func_002B8B90(u8 *a) {
    extern void func_001E3710();
    extern void func_001757E0();
    switch (a[0x1FC]) {
    case 0:
        a[0x168] = 3;
        a[0x1B5] = 0x12;
        func_001E3710(a, 0x14);
        *(s32 **)(a + 0x408) = D_004C0D28;
        a[0x1BB] = 0;
        break;
    case 1:
        a[0x168] = 4;
        a[0x1B5] = 0x13;
        func_001E3710(a, 0x15);
        *(s32 **)(a + 0x408) = D_004C0D2C;
        a[0x1BB] = 1;
        break;
    case 2:
        a[0x168] = 5;
        a[0x1B5] = 0x14;
        func_001E3710(a, 0x15);
        *(s32 **)(a + 0x408) = data_s8_004C0D30;
        a[0x1BB] = 2;
        break;
    }
    a[0x1B5] = *(volatile u8 *)(a + 0x1B5);
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->h7c[a[2]]++;
    func_001757E0(a, 7, a[0x168]);
}
