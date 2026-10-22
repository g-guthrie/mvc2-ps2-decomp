typedef unsigned int u32;
typedef float f32;
typedef struct { u32 tag; f32 v[3]; } TaggedVec3;
typedef char TaggedVec3_size_check[(sizeof(TaggedVec3) == 16) ? 1 : -1];
TaggedVec3 data_u32_00442BA0 = { 0x80000056u, { -6.0f, 0.0f, -13.0f } };
