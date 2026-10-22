typedef short s16;
typedef unsigned int u32;
typedef float f32;
/* Nine-word record: s16 key (-1), f32 1.0 and 0.1, four zero words, f32 -13.0, zero word. */
typedef struct {
    s16 key;
    s16 key_hi;
    f32 f04;
    f32 f08;
    u32 zero_0C[4];
    f32 f1C;
    u32 zero_20;
} data_u32_00441C48_t;
typedef char data_u32_00441C48_size_check[(sizeof(data_u32_00441C48_t) == 36) ? 1 : -1];

data_u32_00441C48_t data_u32_00441C48[1] = {
    { -1, 0, 1.0f, 0.1f, { 0, 0, 0, 0 }, -13.0f, 0 },
};
