typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }
extern f32 D_00463A40[];

void func_0026A2E0(u8 *a) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *s0, *s1, *s2, *s3;
    func_00175700(a);
    s0 = (f32 *)(a + 0x5C);
    s2 = (f32 *)(a + 0x68);
    s1 = (f32 *)(a + 0x60);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    s3 = (f32 *)(a + 0x6C);
    if (*(f32 *)(a + 0x38) <= *(f32 *)(a + 0x430)) {
        u32 t = a[6];
        a[6] = t + 1;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x20D] = 0;
        func_00183d50(a);
        *(s32 *)s0 = 0;
        *(s32 *)s1 = 0;
        *(s32 *)s2 = 0;
        *(s32 *)s3 = 0;
        func_001757E0(a, 0xF, 2);
    }
}

