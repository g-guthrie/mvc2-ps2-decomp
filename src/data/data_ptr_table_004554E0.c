typedef unsigned char u8;

extern u8 data_u8_004C0880[];
extern u8 data_u8_004C0884[];
extern u8 data_u8_004C0888[];
extern u8 data_u8_004C0890[];

/* func_00280F80 selects a command stream consumed by func_00280AE0. */
const u8 *const data_ptr_table_004554E0[4] = {
    data_u8_004C0880,
    data_u8_004C0884,
    data_u8_004C0888,
    data_u8_004C0890
};
