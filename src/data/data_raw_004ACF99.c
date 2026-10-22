typedef unsigned char u8;
/* One 11-byte body of a 24-byte record row (row+1..row+11 of the 21-row table at D_004ACDD0).
   func_00127FA0 copies row bytes +1..+8 one byte at a time from per-slot state bytes
   (D_004F25F0/D_004F3160/D_004F3CD0/D_004F258D/D_004F30FD/D_004F3C6D, D_004C2840+0x8C, +0x53B)
   and writes +9/+10/+11 as 99/59/99 or a minutes/seconds/frames split of a 0x56C counter. */
typedef struct { u8 state[8]; u8 minutes; u8 seconds; u8 frames; } Rec11;
typedef char Rec11_size_check[(sizeof(Rec11) == 11) ? 1 : -1];
Rec11 data_raw_004ACF99 = {
    { 0x00u, 0x01u, 0x02u, 0x00u, 0x01u, 0x02u, 0x00u, 0x02u },
    0x18u, 0x00u, 0x00u,
};
