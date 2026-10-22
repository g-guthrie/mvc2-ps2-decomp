typedef unsigned int u32;
typedef float f32;

typedef struct {
    u32 word0;
    f32 x;
    f32 y;
    f32 z;
} Data442BF4Entry;

typedef char Data442BF4Entry_size_check[(sizeof(Data442BF4Entry) == 16) ? 1 : -1];

Data442BF4Entry data_u32_00442BF4 = { 0x80000056u, -5.0f, -4.5f, -13.0f };
