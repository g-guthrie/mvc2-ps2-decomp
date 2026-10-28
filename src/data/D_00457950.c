typedef unsigned char u8;
typedef struct { u8 cell; u8 unread_01; u8 offset; u8 unread_03; u8 hold; u8 unread_05; } TimedStep6;
typedef struct {
    TimedStep6 list0[10];
    u8 unused_tail0[4];
    TimedStep6 list1[8];
    TimedStep6 list2[8];
    TimedStep6 list3[8];
} Data00457540;
extern Data00457540 data_timed_steps_00457540;
/* func_00292840 masks the random selector to 0..3 at 0x002928B4 and loads
 * this pointer table at 0x002928CC; its entries are the heads of the four
 * timed step lists in data_timed_steps_00457540. */
const TimedStep6 * const D_00457950[4] = {
    data_timed_steps_00457540.list0,
    data_timed_steps_00457540.list1,
    data_timed_steps_00457540.list2,
    data_timed_steps_00457540.list3,
};
