typedef unsigned int u32;
/* func_001E6670 takes selectors from a 4-bit nibble (srl 28, andi 0xF at 0x001E6768-74, 0x001E6800-0C, and 0x001E6880-84). It indexes this bank with selector*8 and loads both words in each selected pair at 0x001E6794-A4 and 0x001E682C-3C; the final pair uses both column bases at 0x001E6890-9C and 0x001E68A0-AC. All 16 pairs are in range. */
u32 data_u32_004B6E10[32] = {
    0x00000020u, 0x00000000u, 0x00000030u, 0x00000000u,
    0x00000040u, 0x00000000u, 0x00000050u, 0x00000000u,
    0x000000A0u, 0x00000010u, 0x000000B0u, 0x00000010u,
    0x000000C0u, 0x00000010u, 0x000000D0u, 0x00000010u,
    0x000000E0u, 0x00000010u, 0x00000000u, 0x00000020u,
    0x000000C0u, 0x00000060u, 0x00000000u, 0x00000000u,
    0x00000020u, 0x00000030u, 0x00000040u, 0x00000050u,
    0x000010A0u, 0x000010B0u, 0x000010C0u, 0x000010D0u,
};
