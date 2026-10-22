typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
/* Per-entry 16-byte parameter block; field meanings not yet confirmed from readers. */
typedef struct { u16 a; u16 b; f32 c; u32 d; f32 e; } Param16;
typedef char Param16_size_check[(sizeof(Param16) == 16) ? 1 : -1];
Param16 data_u32_00442DC4[1] = {
    { 0x6Cu, 0u, 7.85f, 0u, 0.02f },
};
