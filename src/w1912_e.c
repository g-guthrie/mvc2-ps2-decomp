typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004C2B5C, D_004C2B60, data_f32_004C2530;
extern f32 D_004F7FD0[], D_004F7FD4[];
extern s32 D_004A6DA0[], D_004A6DB8[], D_004A6DBC[], D_004A6DC8[], D_004A6DC0[], D_004A6DD4[], D_004A6DD8[], D_004A6DC4[], D_004A6DCC[], D_004A6DD0[], D_004A6DDC[], D_004A6DAC[];
extern f32 D_004A6DA4[], D_004A6DA8[], D_004A6DB0[], D_004A6DB4[];

void func_0041CA40(void) {
    extern void func_00417FE0(s32);
    extern void func_00153AB0(s32 *, s32);
    f32 a = D_004C2B5C;
    f32 b = data_f32_004C2530;
    f32 c = D_004C2B60;
    D_004A6DB8[0] = 0;
    D_004A6DBC[0] = 0;
    D_004A6DA0[0] = 0x918;
    D_004A6DC8[0] = 0;
    D_004A6DAC[0] = 0x3F75C28F;
    D_004A6DC0[0] = 0x3F800000;
    D_004A6DD4[0] = 5;
    D_004A6DD8[0] = -1;
    D_004A6DC4[0] = 0x3F800000;
    D_004A6DCC[0] = 0x3F800000;
    D_004A6DD0[0] = 0;
    D_004A6DDC[0] = 0;
    D_004A6DA4[0] = a + D_004F7FD0[0];
    D_004A6DA8[0] = c + D_004F7FD4[0];
    D_004A6DB0[0] = b;
    D_004A6DB4[0] = b;
    func_00417FE0(0);
    func_00153AB0(D_004A6DA0, 1);
}
