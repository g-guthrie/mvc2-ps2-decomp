typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {
    s16 a[10];
    f32 b[5];
} T00444360;
typedef char T00444360_size_check[(sizeof(T00444360) == 40) ? 1 : -1];
T00444360 data_raw_00444360 = {
    { 0, 10, 100, 1000, 10000, 0, 0, 0, 0, 0 },
    { 5.0f, -12.8500004f, 0.0f, -6.9000001f, -12.8500004f },
};
