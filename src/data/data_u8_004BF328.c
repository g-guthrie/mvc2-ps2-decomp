typedef unsigned char u8;
/* func_00131B50 indexes it as [row * 3 + column] (row = byte 2 of the source record,
   column = byte at +0x425); only the first 2x3 bytes are read. The remaining 26 bytes are
   not consumed by any reader seen, kept as an explicit raw tail. */
typedef struct {
    u8 map[2][3];
    u8 unread_tail[26];
} PlayerSlotMap;
typedef char PlayerSlotMap_size_check[(sizeof(PlayerSlotMap) == 32) ? 1 : -1];
PlayerSlotMap data_u8_004BF328 = {
    { { 0, 2, 4 }, { 1, 3, 5 } },
    { 0x00, 0x00, 0x3E, 0x47, 0x74, 0x76, 0x75, 0x77, 0x00, 0x00, 0x70, 0x71, 0x00, 0x00, 0x72, 0x73, 0x00, 0x00, 0x78, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
};
