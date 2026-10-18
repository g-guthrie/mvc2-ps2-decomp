typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001934B0();
void func_001933B0(u8 *p) {
    s32 i = 0;
    do {
        u8 *o = func_003DA750(0, 4, 1);
        if (o != 0) {
            *(void **)(o + 0x10) = func_001934B0;
            *(u8 **)(o + 0x18) = p;
            o[1] = p[1];
            o[0x20] = 0;
            o[0x21] = i;
            *(s16 *)(o + 0x26) = 0x300;
        }
        i++;
    } while (i < 15);
}
