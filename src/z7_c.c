typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004D17B8;
extern u16 D_004F7F92;
extern u8 D_004F7F91;
extern u8 D_004F7F90;

void func_00131390(void) {
    s32 t;
    D_004F7F92 += (u16)D_004D17B8;
    if (D_004F7F92 > 9999) D_004F7F92 = 9999;
    t = D_004F7F91 + D_004D17B8 / 10;
    while (t >= 100) {
        D_004F7F90++;
        t -= 100;
        if (D_004F7F90 > 99) {
            D_004F7F90 = 99;
            t = 99;
        }
    }
    D_004F7F91 = t;
    D_004D17B8 = 0;
}
