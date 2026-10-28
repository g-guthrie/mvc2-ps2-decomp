typedef unsigned int u32;
/* func_003DC3C0: lw D_00477860[channel] (index << 2), then lw through it (CHCR poll).
 * The values are the ten EE DMA channel register blocks (VIF0, VIF1, GIF, fromIPU, toIPU,
 * SIF0, SIF1, SIF2, fromSPR, toSPR); they are hardware addresses, not image symbols. */
u32 data_u32_00477860[10] = {
    0x10008000u, 0x10009000u, 0x1000A000u, 0x1000B000u, 0x1000B400u,
    0x1000C000u, 0x1000C400u, 0x1000C800u, 0x1000D000u, 0x1000D400u,
};
