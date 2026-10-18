typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#pragma padloop on
void func_003DCD40(u8 *a0, u8 a1, s32 a2) {
    s32 i;
    for (i = 0; i < a2; i++) {
        *a0++ = a1;
    }
}
