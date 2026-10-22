typedef short s16;
/* Two signed {x, y} halfword pairs: {0, 5} and {0, 6}. */
typedef struct {
    s16 x;
    s16 y;
} data_u32_004C1998_pt_t;
typedef char data_u32_004C1998_size_check[(sizeof(data_u32_004C1998_pt_t) == 4) ? 1 : -1];

data_u32_004C1998_pt_t data_u32_004C1998[2] = { { 0, 5 }, { 0, 6 } };
