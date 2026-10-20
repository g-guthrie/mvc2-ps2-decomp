typedef signed int s32;

typedef struct {
    s32 x_16_16;
    s32 y_16_16;
} Motion16_16Pair;

/* func_003486B0 indexes by p[0x1B7] and reads the selected x/y pair as signed 16.16 values before converting to float. The two physical records end at 0x00461F00, where func_00348F20 independently dispatches through the next ten-entry callback table. Selector provenance/range is unproved; this source makes no universal bound claim. */
Motion16_16Pair data_u32_00461EF0[2] = {
    { 0x00030000, 0x00030000 },
    { 0x00038000, 0x00038000 },
};
