typedef unsigned int u32;
extern u32 data_u32_004447C0[];
/* All consumers load only slot 0, at 0x00153F28, 0x001540E4,
 * 0x001541A0, and 0x00154410; they then index target records directly. */
u32 * const D_00444940[1] = { &data_u32_004447C0[0x40] };
