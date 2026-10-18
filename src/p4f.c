typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_0041B190(u8 *a, u8 *b) {
    if (*(s16 *)(b + 0x140) == 0) {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 183.3333282f;
    } else {
        *(f32 *)(a + 0x34) = 183.3333282f + *(f32 *)(b + 0x34);
    }
    *(f32 *)(a + 0x38) = 246.4285583f + *(f32 *)(b + 0x38);
}
