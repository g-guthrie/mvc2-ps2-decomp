typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 id;
    f32 value;
    u32 reserved[2];
    f32 extra;
} Entry20;
typedef char Entry20_size_check[(sizeof(Entry20) == 20) ? 1 : -1];
Entry20 data_u32_00443400[1] = {
    { 0x0000005Fu, 8.9f, { 0x00000000u, 0x00000000u }, 0.96f }
};
