typedef unsigned char u8;
typedef struct { u8 field_0; u8 field_1; } ByteSlotRecord;
/* func_00275950 (src/v0_b.c) reads field_0 with lbu at D_00454C10[(rand & 0xF) << 1], i.e. a
 * 16-entry table of 2-byte records. field_1 is never read; it is zero in every
 * record and is typed from its neighbours. */
ByteSlotRecord data_rec_00454C10[16] = {
    { 5, 0 },
    { 5, 0 },
    { 5, 0 },
    { 6, 0 },
    { 6, 0 },
    { 6, 0 },
    { 7, 0 },
    { 7, 0 },
    { 7, 0 },
    { 8, 0 },
    { 8, 0 },
    { 8, 0 },
    { 9, 0 },
    { 9, 0 },
    { 9, 0 },
    { 10, 0 },
};
