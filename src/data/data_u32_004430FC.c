typedef unsigned int u32;
typedef float f32;

typedef struct {
    u32 word0;
    f32 x;
    u32 word2;
    f32 y;
} Data4430FCEntry;

typedef char Data4430FCEntry_size_check[(sizeof(Data4430FCEntry) == 16) ? 1 : -1];

Data4430FCEntry data_u32_004430FC = { 0x00020075u, 13.4f, 0x00000000u, 0.01f };
