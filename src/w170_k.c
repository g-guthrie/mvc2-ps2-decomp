typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_00462520[];
extern f32 D_00462524[];

void func_00351760(u8 *p) {
    u8 *s0 = *(u8 **)(*(u8 **)(p + 0x18) + 0x1DC);
    f32 v;
    *(f32 *)(p + 0x34) = *(f32 *)(s0 + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(s0 + 0x38);
    if (*(s16 *)(p + 0x140) != 0) {
        v = D_00462520[p[0x20] * 2];
    } else {
        v = -D_00462520[p[0x20] * 2];
    }
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x38) += D_00462524[p[0x20] * 2];
    *(f32 *)(p + 0x5C) = (double)(*(f32 *)(s0 + 0x34) - *(f32 *)(p + 0x34)) / 16.0;
    *(f32 *)(p + 0x60) = (double)(*(f32 *)(s0 + 0x38) - *(f32 *)(p + 0x38)) / 16.0;
}
