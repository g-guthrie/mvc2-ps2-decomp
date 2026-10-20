typedef signed short s16;
typedef struct { s16 a; s16 b; } MotionPair16;

/* func_0038A5A0 reads signed halfwords at pair offsets 0 and 2, using the signed selector at s+0x150 with a four-byte stride. Four complete pair records occupy this 16-byte unit. The next unit at 0x00464CA0 is independently indexed by native loads at 0x0038CE08, 0x0038CE68, and 0x0038D044. Selector provenance/range is unproved; no universal bound is claimed. */
MotionPair16 data_u32_00464C90[4] = {
    { 11, 41 },
    { -20, 72 },
    { 22, 48 },
    { -6, 71 },
};
