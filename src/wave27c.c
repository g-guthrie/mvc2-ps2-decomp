typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00374320(u8 *a) {
    *(f32 *)(a + 0x50) += 0.016f;
    *(f32 *)(a + 0x54) -= 0.024f;
    {
        s16 t = *(s16 *)(a + 0x1C) - 1;
        *(s16 *)(a + 0x1C) = t;
        if (t <= 0) {
            u32 u = a[6];
            a[6] = u + 1;
            *(f32 *)(a + 0x54) = 1.0f;
            *(f32 *)(a + 0x50) = 1.0f;
        }
    }
}
