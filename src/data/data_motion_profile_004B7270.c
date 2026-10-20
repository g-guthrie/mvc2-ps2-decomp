typedef signed int s32;

typedef struct MotionProfileRecord {
    s32 vx;
    s32 ax;
    s32 vy;
    s32 ay;
} MotionProfileRecord;

/*
 * Four 16-byte records fill the native 0x40-byte span. The matched consumer
 * reads signed 16.16 velocity/acceleration fields from each record. Its first
 * index is called with 0 or 1; the second (side) index is unchecked, so this
 * physical shape does not claim a global runtime bound for that field.
 */
MotionProfileRecord data_motion_profile_004B7270[2][2] = {
    {
        {-442368, 4096, 458752, -32768},
        {-1064960, 131072, 720896, -32768},
    },
    {
        {-196608, 16384, 393216, -36864},
        {-737280, 98304, 655360, -36864},
    },
};
