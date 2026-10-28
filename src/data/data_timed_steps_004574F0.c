typedef unsigned char u8;
/* Four timed step lists selected by D_00457860[rand & 3] (func_00291610,
 * 0x00291678-0x00291698 stores the pointer at state+0x14 of actor+0x2B8).
 * The cursor reader func_00292620 (0x00292638-0x00292650) loads lbu +0 into
 * actor+7, lbu +2 into state+0x1B and advances by 4; bytes +1 / +3 are never
 * read. Lists start at records 0, 6, 12 and 16; each ends with 0x7FFF in its
 * +2 halfword, and the second list is followed by three zero records that fill
 * its slot. */
typedef struct { u8 id; u8 unread_01; u8 hold; u8 unread_03; } TimedStep4;
TimedStep4 data_timed_steps_004574F0[20] = {
    { 1, 0, 32, 0 },
    { 2, 0, 32, 0 },
    { 3, 0, 1, 0 },
    { 4, 0, 1, 0 },
    { 5, 0, 1, 0 },
    { 0, 0, 255, 127 },
    { 7, 0, 1, 0 },
    { 5, 0, 1, 0 },
    { 2, 0, 255, 127 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 4, 0, 1, 0 },
    { 4, 0, 1, 0 },
    { 5, 0, 1, 0 },
    { 1, 0, 255, 127 },
    { 2, 0, 32, 0 },
    { 5, 0, 1, 0 },
    { 7, 0, 1, 0 },
    { 1, 0, 255, 127 }
};
