typedef unsigned int u32;
extern u32 data_u32_00456CF0[];
/* func_00291610 masks the random selector to 0..3 at 0x00291678 and loads
 * this pointer table at 0x00291690; its entries address packed records in
 * data_u32_00456CF0. */
const void * const D_00457860[4] = {
    &data_u32_00456CF0[0x200],
    &data_u32_00456CF0[0x206],
    &data_u32_00456CF0[0x20C],
    &data_u32_00456CF0[0x210],
};
