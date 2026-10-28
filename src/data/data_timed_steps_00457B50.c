typedef short s16;
/* func_00294080 (0x002940F4-0x00294144) walks this list with the cursor actor+7: lh +0 is the
 * id passed to func_0038D390 (-1 ends the list) and lh +2 the hold
 * stored in actor+0x1E. 55 steps including the -1 terminator. */
typedef struct { s16 id; s16 hold; } TimedStepS16;
TimedStepS16 data_timed_steps_00457B50[55] = {
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 0, 8 },
    { 1, 8 }, { 2, 8 }, { 0, 8 }, { 1, 8 },
    { 2, 8 }, { 0, 8 }, { 1, 8 }, { 2, 8 },
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 0, 8 },
    { 1, 8 }, { 2, 8 }, { 0, 8 }, { 1, 8 },
    { 2, 8 }, { 0, 8 }, { 1, 8 }, { 2, 8 },
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 0, 8 },
    { 1, 8 }, { 2, 8 }, { 0, 8 }, { 1, 8 },
    { 2, 8 }, { 0, 8 }, { 1, 8 }, { 2, 8 },
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 0, 8 },
    { 1, 8 }, { 2, 8 }, { 0, 8 }, { 1, 8 },
    { 2, 8 }, { 0, 8 }, { 1, 8 }, { 2, 8 },
    { 0, 8 }, { 1, 8 }, { 2, 8 }, { 0, 8 },
    { 1, 8 }, { 2, 8 }, { -1, 0 }
};
