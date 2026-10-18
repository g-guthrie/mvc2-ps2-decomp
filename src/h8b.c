typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 func_003D90A0(s32);
s32 func_00336690(u8 *p) {
    if (p[4] != 0) return 0;
    if (func_003D90A0(0)) {
        p[4] = 2; p[5] = 0; p[6] = 0; p[7] = 0;
        return 1;
    }
    return 0;
}
