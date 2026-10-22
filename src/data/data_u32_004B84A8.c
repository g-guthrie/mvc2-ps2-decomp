typedef unsigned int u32;
typedef short s16;
typedef float f32;

/* Eight float scales followed by six (x, y) halfword pairs. */
typedef struct {
    s16 x;
    s16 y;
} S16Pair;

typedef struct {
    f32 scales[8];
    S16Pair pairs[6];
} Data4B84A8Table;

typedef char Data4B84A8Table_size_check[(sizeof(Data4B84A8Table) == 56) ? 1 : -1];

Data4B84A8Table data_u32_004B84A8 = {
    { 1.49f, 1.5f, 1.0f, 1.5f, 1.0f, 1.5f, 0.8f, 1.5f },
    { { -80, -160 }, { -240, -320 }, { -400, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
};
