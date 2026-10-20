typedef signed short s16;
typedef struct { s16 x; s16 y; } PositionOffset;

/* func_001A7340 reads D_004BF770 and D_004BF772 with a four-byte selector stride. The adjacent BF778 family bounds these two physical records; the routine has no local selector cap. */
PositionOffset data_position_offsets_004BF770[2] = {
    { -77, 143 },
    { -32, 143 },
};
