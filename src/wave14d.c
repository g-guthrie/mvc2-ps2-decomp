typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 (*D_004C1858[2])(u8 *);

s32 func_00334BA0(u8 *p) {
    if (D_004C1858[p[6]](p) != 0) {
        p[6] = 0;
        return 1;
    }
    return 0;
}
extern s32 (*D_004C1860[2])(u8 *);
s32 func_00334D80(u8 *p) {
    if (D_004C1860[p[6]](p) != 0) {
        p[6] = 0;
        return 1;
    }
    return 0;
}
