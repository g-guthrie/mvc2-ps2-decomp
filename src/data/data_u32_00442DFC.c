typedef unsigned int u32;
typedef float f32;
typedef struct {
    u32 id;
    f32 value;
    u32 reserved;
    f32 extra;
} Entry16b;
typedef char Entry16b_size_check[(sizeof(Entry16b) == 16) ? 1 : -1];
Entry16b data_u32_00442DFC[1] = {
    { 0x0000006Cu, 4.7f, 0x00000000u, 0.02f }
};
