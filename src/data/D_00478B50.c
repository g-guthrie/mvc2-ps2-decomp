typedef unsigned int u32;
extern u32 data_u32_00478950[0x80];
/* func_003EB810 reads all four entries in its fixed a3=0..3 loop at 0x003EB824-0x003EB8E4. Each target supplies exactly 0x100 bytes through the fixed two-plane and 32-step loops. */
u32 * const D_00478B50[4] = {
    data_u32_00478950,
    data_u32_00478950 + 0x40,
    data_u32_00478950,
    data_u32_00478950 + 0x40,
};
