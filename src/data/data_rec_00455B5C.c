typedef signed char s8;
typedef unsigned char u8;
/* func_002848D0 (0x002848D0-0x00284918) indexes these 4-byte records with
 * (actor+0x151 & ~1) >> 1 (nonzero) * 4 and reads lb +0 into actor+0x1B5; bytes
 * +1..+3 are never read. Record 0 is the unused zero base slot; nine records up
 * to jtbl_00455B80. */
typedef struct { s8 animation; u8 unread_01[3]; } Data00455B5CRecord;
Data00455B5CRecord data_rec_00455B5C[9] = {
    { 0, { 0, 0, 0 } },
    { 71, { 0, 0, 0 } },
    { 72, { 0, 0, 0 } },
    { 71, { 0, 0, 0 } },
    { 72, { 0, 0, 0 } },
    { 75, { 0, 0, 0 } },
    { 76, { 0, 0, 0 } },
    { 99, { 0, 0, 0 } },
    { 0, { 0, 0, 0 } }
};
