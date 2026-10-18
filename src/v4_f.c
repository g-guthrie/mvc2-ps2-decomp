typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00131470(void) {
    extern s32 D_004D17BC;
    extern u16 D_004F7F96;
    extern u8 D_004F7F91, D_004F7F90;
    s32 a, b;
    a = D_004D17BC;
    D_004F7F96 += (u16)a;
    if (D_004F7F96 > 9999) D_004F7F96 = 9999;
    b = D_004F7F91;
    b += a / 4;
    if (b >= 100) do {
        D_004F7F90++;
        b -= 100;
        if (D_004F7F90 > 99) {
            D_004F7F90 = 99;
            b = 99;
        }
    } while (b >= 100);
    D_004F7F91 = b;
    D_004D17BC = 0;
}
