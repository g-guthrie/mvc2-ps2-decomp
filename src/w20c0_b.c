typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[8]; s16 h8; } G;
extern G *D_004C2840;
extern s8 D_004C2868, D_004C2860, D_004C2858, D_004C2854;
extern u8 D_004434B0[], D_00443500[], D_00443530[], D_00443580[];

/* Retail behaviour: for selectors other than 0, 2, 5 and 6 the loop inputs
 * (n, lim, dst) are left uninitialised, exactly as in the original object. */
void func_001485C0(u8 *p) {
    u32 t; u8 *dst; s32 n; s32 lim; s32 i;
    if (p[0x20] == D_004C2840->h8) {
        *(u32 *)(p + 0x78) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x80) = 0x3F800000;
    } else {
        *(u32 *)(p + 0x78) = 0x3F333333;
        *(u32 *)(p + 0x7C) = 0x3F333333;
        *(u32 *)(p + 0x80) = 0x3F333333;
    }
    t = p[0x20];
    if (t == 0) {
        lim = D_004C2868; n = 8; dst = D_004434B0;
    } else if (t == 2) {
        lim = D_004C2860; n = 4; dst = D_00443500;
    }
    if (t == 5) {
        lim = D_004C2858; n = 8; dst = D_00443530;
    }
    if (t == 6) {
        lim = D_004C2854; n = 8; dst = D_00443580;
    }
    for (i = 0; i < n; i++) { if (i <= lim) dst[0] = 1; else dst[0] = 0; dst += 8; }
}
