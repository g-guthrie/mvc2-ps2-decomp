typedef unsigned int u32;
/* Native caller func_001E6D80 builds E6670's first argument from the TIM2 PSM byte: func_004166B0 maps codes through D_004BED80 (0,16,24,32,4,8) at 0x004166B0-EC; func_001E6B00 stores that value shifted right 3 at 0x001E6B48-54; the caller loads it at 0x001E73BC and calls func_001E6670 at 0x001E73D8. It is therefore 0..4. E6670's fixed three-entry first pass extracts selectors from this value shifted left 20; the first zero nibble selects fallback row10, the second selects row0, and the third selects row0..4 (0x001E673C-40, 0x001E6768-74, 0x001E67B0-7C). Both words of each selected pair are loaded at 0x001E679C/A4. */
u32 data_u32_004B6E10[10] = {
    0x00000020u, 0x00000000u, 0x00000030u, 0x00000000u, 0x00000040u, 0x00000000u, 0x00000050u, 0x00000000u,
    0x000000A0u, 0x00000010u,
};
