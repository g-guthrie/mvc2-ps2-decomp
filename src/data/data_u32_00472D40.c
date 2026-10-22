/* Three (x, y) signed halfword pairs followed by a zero pair. */
typedef short s16;
typedef struct { s16 x; s16 y; } data_s16_pair_t;
typedef char data_s16_pair_t_size_check[(sizeof(data_s16_pair_t) == 4) ? 1 : -1];

data_s16_pair_t data_u32_00472D40[4] = {
    { -23, 89 }, { -37, 98 }, { -50, 57 }, { 0, 0 },
};
