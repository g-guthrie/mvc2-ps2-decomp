typedef short s16;
typedef float f32;
/* Four-word record: a halfword pair (86, 256), then three f32 values -6.0, -1.5, -13.0. */
typedef struct {
    s16 a;
    s16 b;
    f32 f04;
    f32 f08;
    f32 f0C;
} data_u32_00442BBC_t;
typedef char data_u32_00442BBC_size_check[(sizeof(data_u32_00442BBC_t) == 16) ? 1 : -1];

data_u32_00442BBC_t data_u32_00442BBC[1] = {
    { 86, 256, -6.0f, -1.5f, -13.0f },
};
