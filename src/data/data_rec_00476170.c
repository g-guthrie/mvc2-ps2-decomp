typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
/* func_003C8530 (src/q1_l.c): e = (u16 *)D_00476170 + p[0x21] * 3 + p[0x20] * 15, so the
 * records are 6 bytes, [p[0x20]][p[0x21]] with 5 per row: byte +0 is the motion
 * (func_001757E0), s8 +2 -> p[0x31], s16 +4 -> p[0x1E]. Bytes +1 and +3 are not read. */
typedef struct {
    u8 motion;
    u8 unk_01;
    s8 b31;
    u8 unk_03;
    s16 h1E;
} SlotMotion476170;
typedef char SlotMotion476170_size_check[(sizeof(SlotMotion476170) == 6) ? 1 : -1];
SlotMotion476170 data_rec_00476170[3][5] = {
    { { 4u, 0x00u, -1, 0xFFu, -1 }, { 5u, 0x00u, -1, 0xFFu, -1 }, { 7u, 0x00u, 1, 0x00u, 1 }, { 8u, 0x00u, 1, 0x00u, 1 }, { 22u, 0x00u, 1, 0x00u, 1 } },
    { { 10u, 0x00u, 1, 0x00u, 1 }, { 11u, 0x00u, 1, 0x00u, 1 }, { 13u, 0x00u, 1, 0x00u, 1 }, { 14u, 0x00u, 1, 0x00u, 1 }, { 23u, 0x00u, 1, 0x00u, 1 } },
    { { 16u, 0x00u, 1, 0x00u, 1 }, { 17u, 0x00u, 1, 0x00u, 1 }, { 19u, 0x00u, 1, 0x00u, 1 }, { 20u, 0x00u, 1, 0x00u, 1 }, { 24u, 0x00u, 1, 0x00u, 1 } },
};
