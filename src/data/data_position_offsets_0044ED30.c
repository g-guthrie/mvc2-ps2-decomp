typedef signed short s16;
typedef struct { s16 x; s16 y; } PositionOffset;

/* Native func_001DE8D0 loads both signed halves at +4-byte selector strides. The next owner at ED70 bounds this physical family; the routine has no local selector cap. */
PositionOffset data_position_offsets_0044ED30[10] = {
    { -33, 119 },
    { -27, 111 },
    { -129, 57 },
    { -131, 79 },
    { -137, 75 },
    { -33, 119 },
    { -120, 50 },
    { -120, 62 },
    { -158, 98 },
    { -158, 98 },
};
