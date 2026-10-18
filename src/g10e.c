typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_001B8D90();

void func_001B8D20(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        f32 w;
        w = *(f32 *)(p + 0x118) - 0.012000000104f;
        *(f32 *)(p + 0x118) = w;
        if (w <= 0.0f) {
            func_001B8D90(p);
        }
    }
}
