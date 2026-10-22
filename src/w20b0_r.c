typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004C2B64;
extern f32 D_004C2B68;
extern f32 data_f32_004C2530;
extern f32 D_004C2B5C;
extern f32 D_004C2B60;
extern void (*D_0043CD0C[])();

void func_0041C710(void) {
    extern void D_0041C890();
    f32 x, y, a, b;
    x = D_004C2B64;
    y = D_004C2B68;
    a = x / 50.0f;
    b = y / 50.0f;
    if (!(data_f32_004C2530 < 3.0f)) {
        D_0043CD0C[0] = D_0041C890;
        data_f32_004C2530 = 3.0f;
        D_004C2B5C = x;
        D_004C2B60 = y;
        D_0043CD0C[0]();
    } else {
        data_f32_004C2530 += 0.03999999911f;
        D_004C2B5C += a;
        D_004C2B60 += b;
    }
}
