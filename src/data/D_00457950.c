typedef unsigned int u32;
extern u32 data_u32_00456CF0[];
/* func_00292840 masks the random selector to 0..3 at 0x002928B4 and loads
 * this pointer table at 0x002928CC; its entries address packed records in
 * data_u32_00456CF0. */
const void * const D_00457950[4] = {
    &data_u32_00456CF0[0x214],
    &data_u32_00456CF0[0x224],
    &data_u32_00456CF0[0x230],
    &data_u32_00456CF0[0x23C],
};
