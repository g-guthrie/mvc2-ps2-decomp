typedef unsigned char u8;
typedef struct { u8 id; u8 unread_01; u8 hold; u8 unread_03; } TimedStep4;
extern TimedStep4 data_timed_steps_004574F0[20];
/* func_00291610 masks the random selector to 0..3 at 0x00291678 and loads
 * this pointer table at 0x00291690; its entries are the heads of the four
 * timed step lists in data_timed_steps_004574F0 (records 0, 6, 12, 16). */
const TimedStep4 * const D_00457860[4] = {
    &data_timed_steps_004574F0[0],
    &data_timed_steps_004574F0[6],
    &data_timed_steps_004574F0[12],
    &data_timed_steps_004574F0[16],
};
