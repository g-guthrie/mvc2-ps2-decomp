typedef short s16;
typedef float f32;

/* Records of 20 bytes: two floats, two s16, two floats. Three full records,
   then a 12-byte tail (two floats and two s16) that ends the 72-byte block. */
typedef struct { f32 f0; f32 f1; s16 h0; s16 h1; f32 f2; f32 f3; } data_u32_0044E274_rec;
typedef struct {
    data_u32_0044E274_rec rec[3];
    f32 tail_f0;
    f32 tail_f1;
    s16 tail_h0;
    s16 tail_h1;
} data_u32_0044E274_block;
typedef char data_u32_0044E274_rec_size_check[(sizeof(data_u32_0044E274_rec) == 20) ? 1 : -1];
typedef char data_u32_0044E274_block_size_check[(sizeof(data_u32_0044E274_block) == 72) ? 1 : -1];
data_u32_0044E274_block data_u32_0044E274 = {
    { { 133.333328f, 175.714279f, 1, 6, 1.0f, 0.600000024f },
      { 133.333328f, 175.714279f, 1, 6, 1.0f, 0.300000012f },
      { 133.333328f, 175.714279f, 1, 6, 1.0f, 1.5f } },
    133.333328f, 175.714279f, 1, 6,
};
