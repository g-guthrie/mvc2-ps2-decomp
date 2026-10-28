typedef unsigned int u32;
/* Owner word (0xFFFFFFFF when free, set back by func_0011DA38), lock count at 0x0043BB64,
 * then two reserved zero words.  D_0043CB10[0] starts a separate table at 0x0043BB70. */
u32 data_u32_0043BB60[4] = {
    0xFFFFFFFFu, 0x00000000u, 0x00000000u, 0x00000000u,
};
