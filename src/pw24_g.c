typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern void func_001757E0();
extern void func_001E3710();

void func_002D2920(u8 *a) {
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_00175700(a);
    if (*(f32 *)(a + 0x38) <= *(f32 *)(a + 0x430)) {
        u32 n = a[6];
        a[6] = n + 1;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        func_001757E0(a, 2, 2);
        func_001E3710(a, 0x34);
    }
}

void func_00306680(u8 *a) {
    f32 *p5c;
    f32 *p60;
    f32 *p68;
    f32 *p6c;
    func_00175700(a);
    p5c = (f32 *)(a + 0x5C);
    p68 = (f32 *)(a + 0x68);
    p60 = (f32 *)(a + 0x60);
    p6c = (f32 *)(a + 0x6C);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (((*(s16 *)(a + 0x1C))--) == 0) {
        u32 n = a[6];
        a[6] = n + 1;
        *p5c = 0;
        *p60 = 0;
        *p68 = 0;
        *p6c = 0;
        func_001757E0(a, 2, 2);
    }
}
