typedef unsigned int u32;
typedef float f32;
/* Four-word record: id 0x57, two zero words, f32 0.01. */
typedef struct {
    u32 id;
    u32 zero_04;
    u32 zero_08;
    f32 f0C;
} data_u32_00443138_t;
typedef char data_u32_00443138_size_check[(sizeof(data_u32_00443138_t) == 16) ? 1 : -1];

data_u32_00443138_t data_u32_00443138[1] = {
    { 0x00000057u, 0u, 0u, 0.00999999978f },
};
