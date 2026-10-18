typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4;
extern u8 *func_003DA750();
extern void func_003A3940();
s32 func_003A38B0(s32 arg) {
    s32 i;
    if (D_004C27A4 < 7) return 0;
    i = 0;
    do {
        u8 *o = func_003DA750(0, 1, 1);
        if (o != 0) {
            *(s16 *)(o + 0x26) = 0x2D00;
            o[0x20] = i;
            *(u32 *)(o + 0x10) = (u32)func_003A3940;
            *(s32 *)(o + 0x18) = arg;
        }
        i++;
    } while (i < 6);
    return i;
}
