typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004D18C4;
extern u8 *D_004D18B8;

s32 func_00336460(u8 *p) {
    extern f32 func_00117078(f32);
    u8 *q;
    if (p[4] != 0) return 0;
    q = D_004D18C4;
    if (func_00117078(*(f32 *)(D_004D18B8 + 0x34) - *(f32 *)(p + 0x34)) <= 50.0f) {
        p[4] = 1;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        return 1;
    }
    if (func_00117078(*(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) <= 50.0f) {
        p[4] = 1;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        return 1;
    }
    return 0;
}
