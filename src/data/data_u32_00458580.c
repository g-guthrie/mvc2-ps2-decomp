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
    f32 d;
} Vec4f;
typedef char Vec4f_size_check[(sizeof(Vec4f) == 16) ? 1 : -1];
Vec4f data_u32_00458580[3] = {
    { 1.66666663f, 13.333333f, 1.66666663f, 20.0f },
    { 6.66666651f, -0.572916627f, 12.8571424f, -1.07142854f },
    { 12.5f, -0.572916627f, 21.4285698f, -1.07142854f },
};
