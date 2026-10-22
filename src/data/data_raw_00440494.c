typedef unsigned int u32;
typedef float f32;

/* Tail of the seven-vector bank in data_f32v3_00440440.c (func_0013BF80), read as
   nine floats followed by ten words; the word fields are not yet decoded. */
typedef struct {
    f32 f[9];
    u32 w[10];
} Data440494Table;

typedef char Data440494Table_size_check[(sizeof(Data440494Table) == 76) ? 1 : -1];

Data440494Table data_raw_00440494 = {
    { 0.0f, 0.0f, -215.0f, 0.0f, 32.0f, -26.0f, -21.0f, 26.0f, -21.0f },
    { 0u, 0u, 0x00000AABu, 0u, 0x00007555u, 0x0000D556u, 0x00007555u, 0x00002AABu, 0u, 0u },
};
