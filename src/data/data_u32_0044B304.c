/* Byte table. The 12 leading zero bytes are not read; func_001A5630 reads the 0/1 bytes starting at D_0044B310
   (this unit + 0xC) with lbu, indexed by field 0x1 of an object, stores the result in field 0x23 and adds 0x1D. */
typedef unsigned char u8;
u8 data_u32_0044B304[76] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0,
    0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};
