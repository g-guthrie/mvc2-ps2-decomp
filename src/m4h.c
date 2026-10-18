typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern s16 D_004C20D0;
extern s16 D_004C20D2;
extern s16 D_004C20D8[4];
void func_003BFC90(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1C4);
    s32 a = D_004C20D0;
    s32 b;
    if (*(s16 *)(q + 0x140) != 0) a = (s16)-a;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.66666662693f * (f32)a;
    b = D_004C20D2 + D_004C20D8[*(s32 *)(p + 0xD0)];
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.14285707474f * (f32)b;
    *(s32 *)(p + 0xD0) += 1;
    *(s32 *)(p + 0xD0) &= 3;
}
