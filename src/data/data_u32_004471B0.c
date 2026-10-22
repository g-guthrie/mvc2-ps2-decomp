typedef short s16;
/* 8 signed {x, y} halfword pairs. */
typedef struct {
    s16 x;
    s16 y;
} data_u32_004471B0_pt_t;
typedef char data_u32_004471B0_size_check[(sizeof(data_u32_004471B0_pt_t) == 4) ? 1 : -1];

data_u32_004471B0_pt_t data_u32_004471B0[8] = {
    { 16, 80 },
    { -64, 48 },
    { 80, -48 },
    { 80, 80 },
    { 384, 384 },
    { 80, -48 },
    { 16, 80 },
    { -16, -32 }
};
