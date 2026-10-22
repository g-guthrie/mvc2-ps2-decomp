typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD8[];
extern f32 D_004F1FDC[];

typedef struct { u8 pad0[0x34]; f32 f34; u8 pad1[0x140 - 0x38]; s16 h140; } A37;

s32 func_0037AAD0(A37 *p) {
    if (p->h140 == 0) {
        if (D_004F1FD8[0] - 53.333332f <= p->f34) goto z;
        return 1;
    }
    if (53.333332f + D_004F1FDC[0] < p->f34) return 1;
z:
    return 0;
}
