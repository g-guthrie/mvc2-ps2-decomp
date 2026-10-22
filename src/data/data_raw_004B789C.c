typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
/* A zero word, then two f32 triples; func_003326xx loads the vec3 at D_004B78A0. */
typedef struct Tab_004B789C {
    u32 pad;
    f32 a[3];
    f32 b[3];
} Tab_004B789C;
typedef char Tab_004B789C_size_check[(sizeof(Tab_004B789C) == 28) ? 1 : -1];
Tab_004B789C data_raw_004B789C = { 0x00000000u, { 6.40399981f, 1094.59802f, -789.669006f }, { 6.40399981f, 1094.59802f, -789.669006f } };
