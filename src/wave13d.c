typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
extern u8 *D_004C2840;

void func_0013F810(u8 *p) {
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(f32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -(f32)(*(s16 *)(D_004C2840 + 0xC) + *(s16 *)(D_004C2840 + 0xA) * 8) / 64.0f;
}
