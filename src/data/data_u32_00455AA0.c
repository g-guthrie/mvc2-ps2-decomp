typedef unsigned int u32;
typedef float f32;
typedef struct { f32 f_00; f32 f_04; f32 f_08; f32 f_0C; } Vec4f;
typedef struct { Vec4f rec[2]; u32 tail[6]; } Data00455AA0;
typedef char Data00455AA0_size_check[(sizeof(Data00455AA0) == 56) ? 1 : -1];
Data00455AA0 data_u32_00455AA0 = {
    { { 10.0f, -0.625f, 21.4285698f, -1.07142854f }, { 13.333333f, -0.416666657f, 30.0f, -1.07142854f } },
    { 51u, 52u, 51u, 52u, 55u, 56u }
};
