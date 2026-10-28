typedef unsigned char u8;
/* Four timed step lists selected by D_00457950[rand & 3] (func_00292840,
 * 0x002928B4-0x002928CC stores the pointer at state+0x14 of actor+0x2B8).
 * The cursor reader func_00292E20 (0x00292E3C-0x00292E70) loads lbu +0 into
 * state+0xC, lbu +2 (negated and masked with 0x1F when actor+0x1E6 is set),
 * lbu +4 into state+0x1B and advances by 6; the odd bytes are never read. Each
 * list ends with 0x7FFF in its +4 halfword and is zero-filled to its slot. */
typedef struct { u8 cell; u8 unread_01; u8 offset; u8 unread_03; u8 hold; u8 unread_05; } TimedStep6;
typedef struct {
    TimedStep6 list0[10]; /* 0x00457540 */
    u8 unused_tail0[4];
    TimedStep6 list1[8]; /* 0x00457580 */
    TimedStep6 list2[8]; /* 0x004575B0 */
    TimedStep6 list3[8]; /* 0x004575E0 */
} Data00457540;
typedef char data_timed_steps_00457540_size_check[(sizeof(Data00457540) == 0xD0) ? 1 : -1];
Data00457540 data_timed_steps_00457540 = {
    { { 255, 0, 24, 0, 16, 0 }, { 255, 0, 28, 0, 16, 0 }, { 255, 0, 0, 0, 16, 0 }, { 255, 0, 4, 0, 16, 0 }, { 255, 0, 8, 0, 16, 0 }, { 255, 0, 12, 0, 16, 0 }, { 255, 0, 16, 0, 16, 0 }, { 255, 0, 20, 0, 16, 0 }, { 255, 0, 24, 0, 255, 127 }, { 0, 0, 0, 0, 0, 0 } },
    { 0 },
    { { 255, 0, 28, 0, 48, 0 }, { 255, 0, 16, 0, 16, 0 }, { 255, 0, 4, 0, 16, 0 }, { 255, 0, 16, 0, 16, 0 }, { 255, 0, 4, 0, 16, 0 }, { 255, 0, 8, 0, 255, 127 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } },
    { { 255, 0, 0, 0, 48, 0 }, { 255, 0, 16, 0, 16, 0 }, { 255, 0, 24, 0, 16, 0 }, { 255, 0, 16, 0, 16, 0 }, { 255, 0, 0, 0, 16, 0 }, { 255, 0, 24, 0, 255, 127 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } },
    { { 255, 0, 20, 0, 16, 0 }, { 255, 0, 24, 0, 16, 0 }, { 255, 0, 0, 0, 48, 0 }, { 255, 0, 12, 0, 16, 0 }, { 255, 0, 8, 0, 16, 0 }, { 255, 0, 4, 0, 255, 127 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } }
};
