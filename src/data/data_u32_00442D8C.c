typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 id;
    f32 value;
    u32 reserved[2];
} Entry16;
typedef char Entry16_size_check[(sizeof(Entry16) == 16) ? 1 : -1];
Entry16 data_u32_00442D8C[1] = {
    { 0x00000060u, 11.6f, { 0x00000000u, 0x00000000u } }
};
