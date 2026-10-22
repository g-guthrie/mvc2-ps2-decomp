typedef short s16;
typedef float f32;
/* Four-word record: two signed halfword pairs around two f32 values (3.0f each). */
typedef struct {
    s16 a0;
    s16 a2;
    f32 f8;
    f32 fc;
    s16 b10;
    s16 b12;
} data_u32_004416A0_t;
typedef char data_u32_004416A0_size_check[(sizeof(data_u32_004416A0_t) == 16) ? 1 : -1];

data_u32_004416A0_t data_u32_004416A0[1] = {
    { 240, 720, 3.0f, 3.0f, 300, 855 },
};
