typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
/* 16-byte record: two halfwords, an f32 at +4, a zero word, and a small f32 at +12. */
typedef struct { u16 a; u16 b; f32 c; u32 d; f32 e; } Param16;
typedef char Param16_size_check[(sizeof(Param16) == 16) ? 1 : -1];
Param16 data_u32_004431E0[1] = {
    { 0x77u, 0x1u, 11.3000002f, 0u, 0.0199999996f },
};
