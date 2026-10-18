typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_001C6030(u8 *a, u8 *b) {
    extern void func_00175700();
    u8 *c = b + 0x2B8;
    if (b[0x2C3] == 0) {
        a[7] = 5;
        a[0] = 1;
        a[0x13C] = 1;
        if (*(s16 *)(a + 0x140) == 0) {
            *(u32 *)(a + 0x5C) = 0xC0D55555;
        } else {
            *(u32 *)(a + 0x5C) = 0x40D55555;
        }
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x60) = 0x40892492;
        *(u32 *)(a + 0x6C) = 0;
        func_00175700();
        return;
    }
    if (c[0xA] == 0) {
        u32 t = a[7];
        a[7] = t + 1;
        a[0] = 0;
        a[0x13C] = 0;
    } else {
        *(f32 *)(a + 0x34) += (*(f32 *)(b + 0x34) - *(f32 *)(a + 0x34)) / 8.0f;
        *(f32 *)(a + 0x38) += (85.71427917480469f + *(f32 *)(b + 0x38) - *(f32 *)(a + 0x38)) / 8.0f;
        func_00175700();
    }
}

