typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {
    f32 a;
    f32 b;
    f32 c;
} Triple;
typedef char Triple_size_check[(sizeof(Triple) == 12) ? 1 : -1];
Triple data_u32_004B1D2C[5] = {
    { 0.0f, 53.0f, -273.0f },
    { 0.0f, 58.7999992f, -249.199997f },
    { 0.0f, 64.5999985f, -225.399994f },
    { 0.0f, 55.9000015f, -202.199997f },
    { 0.0f, 33.4000015f, -178.399994f },
};
