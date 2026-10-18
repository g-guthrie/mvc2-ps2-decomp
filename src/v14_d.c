typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0013B6A0(u8 *p) {
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
    if (*(s16 *)(p + 0x1E) <= 0) {
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0xD4);
        if (p[0x22] != 0) {
            *(f32 *)(p + 0x50) += *(f32 *)(p + 0x5C);
            if (*(f32 *)(p + 0x50) >= 1.03) {
                *(f32 *)(p + 0x50) = 1.03f;
                p[0x22] = 0;
            }
        } else {
            *(f32 *)(p + 0x50) -= *(f32 *)(p + 0x5C);
            if (*(f32 *)(p + 0x50) <= 1.0f) {
                *(f32 *)(p + 0x50) = 1.0f;
                p[0x22] = 1;
            }
        }
    }
}
