typedef unsigned int u32;
typedef float f32;
typedef struct { signed short a; signed short b; f32 c; f32 d; f32 e; } MixedRecord16;
typedef char MixedRecord16_size_check[(sizeof(MixedRecord16) == 16) ? 1 : -1];
MixedRecord16 data_u32_00443218 = { 120, 1, 11.3000002f, 0.0f, 0.00999999978f };
