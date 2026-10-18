typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_00175700();
void func_003868B0(u8 *p, u8 *q) {
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= 8.0f + *(f32 *)(q + 0x430)) {
        t = p[5]; p[5] = t + 1;
        *(f32 *)(p + 0x38) = 8.0f + *(f32 *)(q + 0x430);
    }
    func_00175700(p);
}
