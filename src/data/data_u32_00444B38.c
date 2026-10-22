typedef unsigned int u32;
typedef short s16;
typedef float f32;

typedef struct {
    s16 x;
    s16 y;
} S16Pair;

/* Twelve float weights (0.35 entries), three (x, y) halfword pairs, then three zero words. */
typedef struct {
    f32 weights[12];
    S16Pair pairs[3];
    u32 zeros[3];
} Data444B38Table;

typedef char Data444B38Table_size_check[(sizeof(Data444B38Table) == 72) ? 1 : -1];

Data444B38Table data_u32_00444B38 = {
    { 0.0f, 0.0f, 0.35f, 0.0f, 0.35f, 0.35f, 0.0f, 0.35f, 0.35f, 0.0f, 0.35f, 0.0f },
    { { 0, 30 }, { 20, 30 }, { 0, 50 } },
    { 0u, 0u, 0u },
};
