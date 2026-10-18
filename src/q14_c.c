typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0033C8A0(u8 *p) {
    *(s16*)(p+0x1C) = *(s16*)(p+0x1C) + 1;
    if (*(s16*)(p+0x1C) >= 360) *(s16*)(p+0x1C) = 0;
    *(u32*)(p+0x40) = (u16)(0.5 + 65536.0 * *(s16*)(p+0x1C) / 360.0);
}
