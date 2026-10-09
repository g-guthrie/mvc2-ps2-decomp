typedef float f32;
extern f32 data_f32_004B20C0[];
extern f32 data_f32_004B2310[];
extern f32 data_f32_004B2570[];
extern f32 data_f32_004B27D0[];
extern f32 data_f32_004B2A20[];
extern f32 data_f32_004B2C70[];
extern f32 data_f32_004B2EC0[];
/* func_00143D50 calls func_00144260 with selectors 0..6: s0 starts at 0
 * (0x00143D60), is passed at 0x00143D68, and loops while the incremented
 * value is less than 7 (0x00143D6C-0x00143D7C). The factory stores that value
 * in field20 at 0x001442C0; func_001442F0 reads field20 and indexes this table
 * at 0x00144310-0x00144338. Each target is also a fixed three-float vector
 * consumed at offsets 0, 4, and 8 in func_00144260. */
const f32 * const D_00442550[7] = {
    data_f32_004B20C0,
    data_f32_004B2310,
    data_f32_004B2570,
    data_f32_004B27D0,
    data_f32_004B2A20,
    data_f32_004B2C70,
    data_f32_004B2EC0,
};
