typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct raw_004B7888_rec {
    f32 value0;
    f32 value1;
} raw_004B7888_rec;
typedef char raw_004B7888_rec_size_check[(sizeof(raw_004B7888_rec) == 8) ? 1 : -1];
raw_004B7888_rec data_raw_004B7888[1] = {
    { 10.0f, 15.0f },
};
