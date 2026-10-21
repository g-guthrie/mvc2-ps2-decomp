typedef float f32;

typedef struct {
    f32 a;
    f32 b;
} PositionPair;

/* On callback paths with field1C in 1..16 (zero skips the read),
 * func_0015B160 indexes this 8-byte table by field1C - 1. */
PositionPair data_position_pairs_004B3AF0[16] = {
    {0.0f, 0.0f},
    {0.25f, 0.0f},
    {0.5f, 0.0f},
    {0.75f, 0.0f},
    {0.0f, 0.25f},
    {0.25f, 0.25f},
    {0.5f, 0.25f},
    {0.75f, 0.25f},
    {0.0f, 0.5f},
    {0.25f, 0.5f},
    {0.5f, 0.5f},
    {0.75f, 0.5f},
    {0.0f, 0.75f},
    {0.25f, 0.75f},
    {0.5f, 0.75f},
    {0.75f, 0.75f},
};
