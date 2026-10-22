typedef unsigned int u32;
typedef float f32;

typedef struct {
    u32 word0;
    u32 zeros[5];
    f32 y;
} Data4433A0Entry;

typedef char Data4433A0Entry_size_check[(sizeof(Data4433A0Entry) == 28) ? 1 : -1];

Data4433A0Entry data_u32_004433A0 = { 0xFF000063u, { 0, 0, 0, 0, 0 }, -0.01f };
