typedef unsigned int u32;
typedef float f32;
/* Three zero words, then eight f32 values (1.0, 0.5, 0.75, 1.0, 0.9, 0.6, 0.8, 0.6). */
typedef struct {
    u32 zero_00[3];
    f32 f_0C[8];
} data_raw_0045EB64_t;
typedef char data_raw_0045EB64_size_check[(sizeof(data_raw_0045EB64_t) == 44) ? 1 : -1];

data_raw_0045EB64_t data_raw_0045EB64 = {
    { 0u, 0u, 0u },
    { 1.0f, 0.5f, 0.75f, 1.0f, 0.899999976f, 0.600000024f, 0.800000012f, 0.600000024f },
};
