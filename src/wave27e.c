typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s8 func_00175700(u8 *a);
void func_001843A0(u8 *a);
void func_0034E160(u8 *a, s32 b);
void func_0020D4B0(u8 *a) {
    s8 r = func_00175700(a);
    if (r < 0) {
        func_001843A0(a);
    } else if (*(s8 *)(a + 0x151) != 0) {
        a[0x151] = 0;
        if (a[0x1B7] != 0) {
            func_0034E160(a, 6);
        } else {
            func_0034E160(a, 0);
        }
    }
}

s8 func_00175670(u8 *a);
void func_001E1570(u8 *a, u8 *b);
void func_001E1190(u8 *a, u8 *b) {
    s8 r;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    r = func_00175670(a);
    if (r < 0) {
        func_001E1570(a, b);
    }
}
