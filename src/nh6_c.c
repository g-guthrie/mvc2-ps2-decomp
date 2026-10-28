typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0041C180(void *a, void *b) {
    extern s32 func_0041BBB0(void *);
    if (a == b) return func_0041BBB0(a) == 0 ? 0 : 1;
    return (func_0041BBB0(a) == 0 || func_0041BBB0(b) == 0) ? 0 : 1;
}
