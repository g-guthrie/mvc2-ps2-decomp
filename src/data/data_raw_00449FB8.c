typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

/* Owner motion-start tables (pixel offsets scaled by 5/3 and 15/7 into actor +0x5C/+0x60).
 * - 0x00449FC0: 6-byte steps indexed by actor +0x21; func_00195D10
 *   (src/owner_velocity_start_00195d30.c) loads +0/+2 with lh and +4 with lb.
 * - 0x00449FF0: 16-byte records; func_00196460 (src/owner_mixed_motion_start_001964a0.c)
 *   loads +0/+2 (lh), +4/+8 (lw, 16.16 velocities) and +0xC (lb).
 * - 0x0044A010: 6-byte steps in rows of 9 (stride 54) indexed by actor +0x21 and a step
 *   index; func_00196760 (src/sb1_d.c) loads +0/+2 with lh and +4 with lb.
 * The 6-byte steps' third halfword holds -2/2/0 as a full s16 (high byte is the sign
 * extension), of which the readers load only the low byte. */
typedef struct {
    s16 dx;
    s16 dy;
    s16 dir;
} OwnerMotionStep;
typedef char OwnerMotionStep_size_check[(sizeof(OwnerMotionStep) == 6) ? 1 : -1];

typedef struct {
    s16 dx;
    s16 dy;
    s32 vx; /* 16.16 */
    s32 vy; /* 16.16 */
    s8 dir;
    u8 pad[3];
} OwnerMixedMotion;
typedef char OwnerMixedMotion_size_check[(sizeof(OwnerMixedMotion) == 16) ? 1 : -1];

typedef struct {
    s32 unread_00[2]; /* 0x00449FB8: no reader found */
    OwnerMotionStep velocityStart[8];
    OwnerMixedMotion mixedStart[2];
    OwnerMotionStep fixedRows[24]; /* rows of 9; the third row continues past this unit */
} OwnerMotionStartTables;
typedef char OwnerMotionStartTables_size_check[(sizeof(OwnerMotionStartTables) == 232) ? 1 : -1];

OwnerMotionStartTables data_raw_00449FB8 = {
    { 44418, 1456 },
    {
        { -25, 23, 2 }, { -8, 28, 2 }, { -12, 22, 2 }, { -33, 22, 2 },
        { -22, 19, 2 }, { 2, 21, 2 }, { -32, 33, 2 }, { -2, 45, 2 },
    },
    {
        { -9, 82, -0x2000, 0x1800, -2, { 0 } },
        { 7, 81, 0x1800, 0x2000, 2, { 0 } },
    },
    {
        { 48, -80, -2 }, { 48, -80, -2 }, { 72, -64, -2 }, { -56, -88, 2 }, { 40, -40, -2 },
        { 40, -40, -2 }, { 40, -40, 2 }, { 40, -40, 2 }, { 0, 0, 0 },
        { 16, -96, -2 }, { 32, -96, 2 }, { 32, -104, -2 }, { 56, 0, -2 }, { 16, 0, -2 },
        { 56, 0, -2 }, { 32, 0, -2 }, { 32, 0, -2 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { -16, -80, 2 }, { 56, -8, 2 }, { -8, -8, 2 }, { 56, -8, 2 },
    },
};
