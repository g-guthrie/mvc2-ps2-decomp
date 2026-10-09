typedef unsigned int u32;
extern u32 data_u32_004B20C0[];
/* func_00143D50 calls func_00144260 with selectors 0..6: s0 starts at 0
 * (0x00143D60), is passed at 0x00143D68, and loops while the incremented
 * value is less than 7 (0x00143D6C-0x00143D7C). The factory stores that value
 * in field20 at 0x001442C0; func_001442F0 reads field20 and indexes this table
 * at 0x00144310-0x00144338. Each entry points into the shared point bank. */
const void * const D_00442550[7] = {
    &data_u32_004B20C0[0],
    &data_u32_004B20C0[0x94],
    &data_u32_004B20C0[0x12C],
    &data_u32_004B20C0[0x1C4],
    &data_u32_004B20C0[0x258],
    &data_u32_004B20C0[0x2EC],
    &data_u32_004B20C0[0x380],
};
