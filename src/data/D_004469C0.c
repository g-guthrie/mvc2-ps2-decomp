typedef unsigned char u8;
/* Row table for data_u32_00446940 (its unit currently covers 52 of the
 * 64 bytes up to data_u32_00446980). */
extern u8 data_u32_00446940[][8];
extern u8 data_u32_00446980[8][8];
/* func_00171110 indexes this table with global field 0x29 (lb, sll 2, lw)
 * at 0x00171190-0x001711BC and reads 8-byte rows from the selected table. */
u8 (* const D_004469C0[7])[8] = {
    data_u32_00446940,
    data_u32_00446980,
    data_u32_00446980,
    data_u32_00446980,
    data_u32_00446980,
    data_u32_00446980,
    data_u32_00446980,
};
