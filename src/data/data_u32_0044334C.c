typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 id;
    f32 value;
    u32 reserved[2];
} Entry16c;
typedef char Entry16c_size_check[(sizeof(Entry16c) == 16) ? 1 : -1];
Entry16c data_u32_0044334C[1] = {
    { 0x00000060u, 13.7f, { 0x00000000u, 0x00000000u } }
};
