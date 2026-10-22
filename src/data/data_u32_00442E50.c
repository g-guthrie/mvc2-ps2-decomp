typedef unsigned int u32;
typedef float f32;

typedef struct {
    u32 word0;
    f32 x;
    u32 word2;
    f32 y;
} Data442E50Entry;

typedef char Data442E50Entry_size_check[(sizeof(Data442E50Entry) == 16) ? 1 : -1];

Data442E50Entry data_u32_00442E50 = { 0x0003006Fu, 11.0f, 0x00000000u, 0.02f };
