typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern s16 D_00462D90[];
extern s16 D_00462D92[];

void func_00357940(u8 *p) {
    u32 i = p[0x21];
    f32 a = 1.666666626930237f * (f32)*(s16 *)((u8 *)D_00462D90 + i * 4);
    f32 b;
    f32 *q;
    if (*(s16 *)(p + 0x140) == 0) a = -a;
    b = 2.142857074737549f * (f32)*(s16 *)((u8 *)D_00462D92 + i * 4);
    a = a * (f32)(u32)p[6];
    b = b * (f32)(u32)p[6];
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34) + a;
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38) + b;
}
