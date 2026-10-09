typedef unsigned int u32;
extern u32 data_u32_00455C00[];
/* func_0028B4D0 masks the random selector to 0..3 at 0x0028B544 and loads
 * this pointer table at 0x0028B55C; its entries address packed records in
 * data_u32_00455C00. */
const void * const D_00456A20[4] = {
    &data_u32_00455C00[0x268],
    &data_u32_00455C00[0x278],
    &data_u32_00455C00[0x284],
    &data_u32_00455C00[0x290],
};
