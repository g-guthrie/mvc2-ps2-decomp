typedef unsigned int u32;
extern u32 data_u32_00442AAC[37];
/* func_00147750 indexes all four entries with the task field20 at 0x0014775C-0x00147780. func_00147660 creates four tasks with field20=0..3 in its 0x00147674-0x001476D0 loop; its callback reaches func_00147750 through residual_001487D0 at 0x0014886C. */
u32 * const D_00442B40[4] = {
    data_u32_00442AAC + 0x11,
    data_u32_00442AAC + 0x19,
    data_u32_00442AAC + 0x1D,
    data_u32_00442AAC + 0x21,
};
