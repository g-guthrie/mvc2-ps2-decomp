typedef struct { float x, y; } F32Pair;
typedef char F32Pair_size_check[(sizeof(F32Pair) == 8) ? 1 : -1];
/* Read at 0x0041A8C8.. through base D_004A6AA8/D_004A6AAC plus (actor byte +0x20) * 8,
 * i.e. &table[-3]: entries are selected by indices 3..14. Ends at the anim script
 * D_004A6B20 (a jtbl_004A6CA0 target). */
F32Pair data_f32pair_004A6AC0[12] = {
    { -37.0f, 132.0f },
    { -21.0f, 132.0f },
    { -37.0f, 125.0f },
    { -21.0f, 125.0f },
    { -37.0f, 118.0f },
    { -21.0f, 118.0f },
    { 11.0f, 132.0f },
    { 27.0f, 132.0f },
    { 11.0f, 125.0f },
    { 27.0f, 125.0f },
    { 11.0f, 118.0f },
    { 27.0f, 118.0f },
};
