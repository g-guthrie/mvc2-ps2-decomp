typedef short s16;
/* Two signed {x, y} halfword pairs: {-160, -64} and {-256, -160}. */
typedef struct {
    s16 x;
    s16 y;
} data_u32_004C1F48_pt_t;
typedef char data_u32_004C1F48_size_check[(sizeof(data_u32_004C1F48_pt_t) == 4) ? 1 : -1];

data_u32_004C1F48_pt_t data_u32_004C1F48[2] = { { -160, -64 }, { -256, -160 } };
