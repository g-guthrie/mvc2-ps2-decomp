typedef signed int s32;
/* D_0043CB10[0]; func_001234D0 loads the count (lw 0x0 at 0x00123520), compares the index
 * D_004F1F49 against it, then selects values[index] (or values[count-1] past the end)
 * at a 4-byte stride from +4. */
typedef struct {
    s32 count;
    s32 values[39];
} CountTable;
CountTable data_count_table_0043BB70 = {
    39,
    { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1000 },
};
