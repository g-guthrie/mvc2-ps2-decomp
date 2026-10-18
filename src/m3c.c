typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD8;
extern f32 D_004F1FDC;

void func_0016C8F0(u8 *p) {
    f32 k = 0.00052083336f;
    s16 v;
    *(f32 *)(p + 0x108) += k;
    *(f32 *)(p + 0x110) += k;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0xF0;
    }
}
