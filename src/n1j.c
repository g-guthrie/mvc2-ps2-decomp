typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s16 D_004C0A00[4];

void func_0028E530(u8 *p) {
    u8 *q = p + 0x2B8;
    if (*(s8 *)(p + 0x1B4) == 0) {
        s16 v = *(s16 *)(q + 0x1E);
        if (v != 0) *(s16 *)(q + 0x1E) = v - 1;
    }
    if (q[0xD] != 0) {
        if (*(s8 *)(p + 0x1B4) != 0) {
            *(f32 *)(p + 0x34) += 1.6666666f * (f32)D_004C0A00[*(u32 *)(D_004C2840 + 0x1C) & 3];
        } else {
            q[0xD] = 0;
        }
    }
}
