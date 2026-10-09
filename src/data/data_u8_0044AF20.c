/* func_001A0540 reads field +0x23 as this table index. func_001A00E0 is called at 0x0035C170 with count 12 and assigns selectors 0..11; its func_001A0200 update callback calls func_001A0540, which traverses the linked nodes. Bytes 12..15 remain raw because no higher selector is proven. */
typedef unsigned char u8;
u8 data_u8_0044AF20[12] = { 0x02u, 0x01u, 0x00u, 0x02u, 0x01u, 0x02u, 0x00u, 0x01u, 0x01u, 0x00u, 0x02u, 0x00u };
