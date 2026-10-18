typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C27D0;
extern u8 D_004F1F40[16];
extern f32 D_004F1FC0[4];
extern void func_00413F50(void *a, f32 b, s32 c);
extern void func_00417770(f32 a, f32 b);

void func_00122FE0(void) {
    u32 v = D_004C27D0 & 0x1f;
    if (v == 1 || v == 10) {
        func_00413F50(D_004F1F40, 2200000.0f, 1);
    } else {
        func_00413F50(D_004F1F40, 120000.0f, 1);
    }
    func_00417770(0.0f, D_004F1FC0[0]);
}
