typedef unsigned int u32;
/* func_0013B060 reads one word at a time for selectors 0..16; func_0013B140 later subtracts 0x100 from the stored word at task field0x44. The final owner word at 0x004402E4 is outside that fixed loop and remains raw. */
u32 data_u32_004402A0[17] = {
    0x0000FE95u, 0x00000AABu, 0x00001555u, 0x00002000u, 0x00002C17u, 0x0000399Au, 0x00005111u, 0x00005E94u,
    0x00006C17u, 0x0000799Au, 0x00009111u, 0x00009D28u, 0x0000A93Fu, 0x0000B6C1u, 0x0000C2D8u, 0x0000CEEFu,
    0x0000DB06u,
};
