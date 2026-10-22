typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {
    s32 count;
    f32 scale;
    u32 pad0;
    u32 pad1;
} Data00442F14;
typedef char Data00442F14_size_check[(sizeof(Data00442F14) == 16) ? 1 : -1];
Data00442F14 data_u32_00442F14[1] = {
    { 90, 4.0999999f, 0, 0 },
};
