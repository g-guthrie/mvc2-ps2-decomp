typedef unsigned int u32;
typedef float f32;

typedef struct {
    u32 word0;
    f32 x;
    f32 y;
    f32 z;
} Data442C2CEntry;

typedef char Data442C2CEntry_size_check[(sizeof(Data442C2CEntry) == 16) ? 1 : -1];

Data442C2CEntry data_u32_00442C2C = { 0x0000005Eu, -0.5f, -7.5f, -12.98f };
