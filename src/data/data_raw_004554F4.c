typedef unsigned char u8;

/* Pointers into the 0x004B75xx data units: 0x004B7520 is a unit start,
   0x004B7530 and 0x004B7540 are interior offsets of data_raw_004B752C. */
extern u8 data_u8_004B7520[];
extern u8 data_raw_004B752C[];
const u8 *const data_raw_004554F4[5] = {
    data_u8_004B7520,
    data_raw_004B752C + 0x04,
    data_raw_004B752C + 0x04,
    data_u8_004B7520,
    data_raw_004B752C + 0x14,
};
