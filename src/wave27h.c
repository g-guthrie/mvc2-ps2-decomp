typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00185510(u8 *a) {
    u8 *o = *(u8 **)(a + 0x1DC);
    if (*(f32 *)(a + 0x34) > *(f32 *)(o + 0x34)) {
        a[0x1E6] = *(s16 *)(a + 0x140) = 0;
    } else {
        a[0x1E6] = *(s16 *)(a + 0x140) = 1;
    }
}
