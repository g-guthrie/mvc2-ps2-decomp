typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004C2B64;
extern f32 D_004C2B68;
extern f32 D_004C2B5C;
extern f32 D_004C2B60;
extern f32 data_f32_004C2530;
extern void (*D_0043CD0C[])(s32, s32);
extern void func_0041C5B0(s32, s32);

void func_0041C7D0(s32 state, s32 owner) {
    f32 a, b;
    a = D_004C2B64 / 50.0f;
    b = D_004C2B68 / 50.0f;
    if (data_f32_004C2530 <= 1.0f) {
        D_004C2B5C = 0;
        D_0043CD0C[0] = func_0041C5B0;
        data_f32_004C2530 = 1.0f;
        D_004C2B60 = 0;
        D_0043CD0C[0](state, owner);
    } else {
        data_f32_004C2530 = data_f32_004C2530 - 0.03999999910593033f;
        D_004C2B5C -= a;
        D_004C2B60 -= b;
    }
}
