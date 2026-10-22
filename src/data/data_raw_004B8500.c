typedef unsigned int u32;
typedef short s16;
typedef float f32;

/* 120-byte block. Field layout follows the words; the reader was not located. */
typedef struct {
    f32 f0[4];
    f32 f1[12];
    s16 h[2];
    u32 z[4];
    f32 f2[3];
    f32 f3[4];
    char tag[4];
    u32 tail;
} data_raw_004B8500_block;
typedef char data_raw_004B8500_block_size_check[(sizeof(data_raw_004B8500_block) == 120) ? 1 : -1];
data_raw_004B8500_block data_raw_004B8500 = {
    { 0.0f, 50.0f, 100.0f, 150.0f },
    { 12.0f, 13.0f, 8.0f, 17.0f, 8.0f, 5.0f, 15.0f, 5.0f, 90.0f, 255.0f, 52.0f, 306.0f },
    { 30, 20 },
    { 0, 0, 0, 0 },
    { 50.0f, 100.0f, 150.0f },
    { 1.0f, 0.75f, 1.25f, 1.5f },
    { 'U', 'P', 'L', 'D' },
    0,
};
