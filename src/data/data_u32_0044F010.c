/* Six signed (x, y) halfword pairs. */
typedef short s16;
typedef struct { s16 x; s16 y; } data_s16_pair_t;
typedef char data_s16_pair_t_size_check[(sizeof(data_s16_pair_t) == 4) ? 1 : -1];

data_s16_pair_t data_u32_0044F010[6] = {
    { 112, 144 }, { 40, -40 }, { 32, -32 }, { 24, -24 }, { 16, -16 }, { 8, -8 },
};
