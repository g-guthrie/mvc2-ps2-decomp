typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern V3 D_004B3F80[];
extern u8 *D_004C2840;

void func_00161690(u8 *p)
{
    V3 *b = D_004B3F80;
    s32 i = *(s8 *)(D_004C2840 + 0x9C) & 0xF;
    if (i != 0) {
        V3 *t = b;
        t += i - 1;
        if (*(s32 *)(p + 0xDC) == 0) {
            f32 x = t->x;
            *(f32 *)(p + 0x50) = (x - *(f32 *)(p + 0x78)) / 20.0f;
            *(f32 *)(p + 0x54) = (t->y - *(f32 *)(p + 0x7C)) / 20.0f;
            *(f32 *)(p + 0x58) = (t->z - *(f32 *)(p + 0x80)) / 20.0f;
            *(s32 *)(p + 0xDC) = 20;
        }
    }
    if (*(s32 *)(p + 0xDC) != 0) {
        *(s32 *)(p + 0xDC) -= 1;
        *(f32 *)(p + 0x78) += *(f32 *)(p + 0x50);
        *(f32 *)(p + 0x7C) += *(f32 *)(p + 0x54);
        *(f32 *)(p + 0x80) += *(f32 *)(p + 0x58);
    }
}
