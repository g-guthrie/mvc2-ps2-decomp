typedef unsigned char u8;
typedef short s16;
typedef float f32;
typedef int s32;
typedef struct { f32 f, a, b; } T12;
extern T12 D_004B7874[];
extern f32 D_004B7888[];
void func_00330AA0(u8 *p) {
    extern s32 func_003D90A0(s32);
    switch (p[4]) {
    case 0:
    *(f32 *)(p + 0x60) += -4.0f;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    if (*(f32 *)(p + 0x38) < D_004B7874[p[0x20]].f) {
        *(f32 *)(p + 0x38) = D_004B7874[p[0x20]].f;
        *(s32 *)(p + 0x60) = 0;
        if (*(s16 *)(p + 0x1C) != 0) *(s16 *)(p + 0x1C) = 0;
    }
    if (func_003D90A0(0) != 0) {
        *(f32 *)(p + 0x60) = D_004B7888[p[0x20]];
        *(s16 *)(p + 0x1C) = 1;
    }
    break;
    default:
    break;
    }
}
