typedef unsigned int u32;
extern u32 data_u32_00455C00[];
/* func_0028A2A0 masks the random selector to 0..3 at 0x0028A308 and loads
 * this pointer table at 0x0028A320; its entries address packed records in
 * data_u32_00455C00. */
const void * const D_00456930[4] = {
    &data_u32_00455C00[0x254],
    &data_u32_00455C00[0x25A],
    &data_u32_00455C00[0x260],
    &data_u32_00455C00[0x264],
};
