typedef float f32;
typedef struct { f32 x; f32 y; f32 z; } Vec3f;
typedef struct { f32 pad_00; Vec3f pos_04; f32 pad_10; f32 pad_14; } Data004B823C;
typedef char Data004B823C_size_check[(sizeof(Data004B823C) == 24) ? 1 : -1];
Data004B823C data_u8_004B823C = { 0.0f, { -149.0f, 647.0f, -898.0f }, 0.0f, 0.0f };
