typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
/* func_0016B3F0 (src/w182_l.c) passes D_004462A0 to func_0016F090, which
 * loads x/y/z (lwc1 +0/+4/+8) into D_004F1CA0. */
Vec3 D_004462A0 = { 0.0f, 1.0f, 1.0f };
