typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
/* src/wave8.c passes D_00446800 to func_0016F090, which loads x/y/z
 * (lwc1 +0/+4/+8) into D_004F1CA0. */
Vec3 D_00446800 = { 0.0f, 1.0f, 1.0f };
