typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 pad0, pad4, f8, padC; u16 d[16]; } E30; extern E30 D_004F54D0[]; s32 func_00174E90(u16 *src, s32 idx, s32 n) {
 E30 *e;
 u16 *dst;
 s32 i;
 s32 j;
    e = &D_004F54D0[idx];
    for (i = 0; i < n; i++, e++) {
        e->f8 = 1;
        dst = e->d;
        for (j = 0; j < 16; j += 8) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            dst[4] = src[4];
            dst[5] = src[5];
            dst[6] = src[6];
            dst[7] = src[7];
            src += 8;
            dst += 8;
        }
    }
    return 0;
}
