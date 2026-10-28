typedef unsigned char u8;
/* func_001A0540 and its siblings read base[p->b23] with lbu. func_001A00E0
 * (only caller passes count 12) assigns selectors 0..11; entries 12..15 run
 * to the next object D_0044AF30 and are typed like their neighbours. */
u8 data_u8_0044AF20[16] = {
    0x02, 0x01, 0x00, 0x02, 0x01, 0x02, 0x00, 0x01,
    0x01, 0x00, 0x02, 0x00, 0x01, 0x02, 0x01, 0x00,
};
