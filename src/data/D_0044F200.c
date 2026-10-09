typedef unsigned char u8;
extern u8 data_u8_004B6FB8[4];
extern u8 data_u8_004B6FC0[4];
extern u8 data_u8_004B6FC8[4];
extern u8 data_u8_004B6FD0[4];
extern u8 data_u8_004B6FD8[4];
extern u8 data_u8_004B6FE0[4];
extern u8 data_u8_004B6FE8[4];
extern u8 data_u8_004B6FF0[4];
extern u8 data_u8_004B6FF8[4];
extern u8 data_u8_004B7000[4];
extern u8 data_u8_004B7008[4];
extern u8 data_u8_004B7010[4];
extern u8 data_u8_004B7018[4];
extern u8 data_u8_004B7020[4];
extern u8 data_u8_004B7028[4];
extern u8 data_u8_004B7030[4];
extern u8 data_u8_004B7038[4];
extern u8 data_u8_004B7040[4];
extern u8 data_u8_004B7048[4];
extern u8 data_u8_004B7050[4];
extern u8 data_u8_004B7058[4];
/* func_001E7070 reads selector IDs 1..21 from the 21 fixed D_004ACDD0 rows, loads D_0044F1FC[ID], then reads exactly four suffix bytes. This bank at D_0044F200 contains every selectable pointer. */
const u8 * const D_0044F200[21] = {
    data_u8_004B6FB8,
    data_u8_004B6FC0,
    data_u8_004B6FC8,
    data_u8_004B6FD0,
    data_u8_004B6FD8,
    data_u8_004B6FE0,
    data_u8_004B6FE8,
    data_u8_004B6FF0,
    data_u8_004B6FF8,
    data_u8_004B7000,
    data_u8_004B7008,
    data_u8_004B7010,
    data_u8_004B7018,
    data_u8_004B7020,
    data_u8_004B7028,
    data_u8_004B7030,
    data_u8_004B7038,
    data_u8_004B7040,
    data_u8_004B7048,
    data_u8_004B7050,
    data_u8_004B7058,
};
