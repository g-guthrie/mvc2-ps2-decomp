typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
/* Unread: one 12-byte slot past the last D_00444490 index the lists use;
 * typed as Vec3 from the neighbouring table only. */
Vec3 data_f32_004444E4 = { 0.0f, 2.79999995f, -13.0f };
