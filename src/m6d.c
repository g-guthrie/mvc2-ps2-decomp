typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern double func_00119058(f32);
void func_00138100(u8 *p) {
    *(f32 *)(p + 0x50) += 0.1f;
    *(f32 *)(p + 0x54) += 0.1f;
    if (func_00119058(*(f32 *)(p + 0x50)) >= 1.3) {
        u32 t = p[4];
        p[4] = t + 1;
    }
}
