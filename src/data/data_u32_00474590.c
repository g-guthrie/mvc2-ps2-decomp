typedef float f32;
/* func_003BBF20 indexes every table here by actor byte 0x21 (0..7, same index as the
 * f32[8] tables at 0x00474650/0x00474670):
 *   D_00474590/D_00474594: f32 pairs, index << 3, lwc1;
 *   D_004745D0/D_004745D4/D_004745D8/D_004745DC: four f32 per record, index << 4, lwc1.
 * Records 6 and 7 of the second table are all-zero in the image. */
typedef struct F32Pair { f32 a; f32 b; } F32Pair;
typedef struct Quad4F32 { f32 a; f32 b; f32 c; f32 d; } Quad4F32;
typedef struct Tbl474590 { F32Pair pairs[8]; Quad4F32 quads[8]; } Tbl474590;
typedef char Tbl474590_size_check[(sizeof(Tbl474590) == 0xC0) ? 1 : -1];
Tbl474590 data_u32_00474590 = {
  {
    { 80.0f, 180.0f }, { 80.0f, 180.0f },
    { 93.33333f, 188.57143f }, { 93.33333f, 188.57143f },
    { 106.666664f, 197.14285f }, { 106.666664f, 197.14285f },
    { 106.666664f, 100.71428f }, { 106.666664f, 100.71428f },
  },
  {
    { 6.6666665f, 0.0f, -7.5f, -0.26785713f },
    { 7.5f, 0.0f, -6.428571f, -0.26785713f },
    { 6.6666665f, 0.0f, -9.642857f, -0.26785713f },
    { 7.5f, 0.0f, -8.571428f, -0.26785713f },
    { 6.6666665f, 0.0f, -11.785714f, -0.4017857f },
    { 7.5f, 0.0f, -10.714285f, -2.5446427f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f },
  },
};
