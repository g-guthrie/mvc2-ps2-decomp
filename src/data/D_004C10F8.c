typedef int s32;
typedef unsigned int u32;
typedef struct { s32 vx, ax, vy, ay; } MotionLanes;
extern u32 data_u32_0045B0B0[];
/* func_002E6290 (0x002E6318 gp_rel, src/selected_motion_launch_002e6290.c): bank
 * [(s8)work byte +5], then row [actor byte +0x1B7] of 16.16 fixed-point lanes.
 * Both banks lie inside the still-untyped data_u32_0045B0B0 (+0x70 and +0xA0). */
const MotionLanes *D_004C10F8[2] = {
    (const MotionLanes *)&data_u32_0045B0B0[0x70 / 4],
    (const MotionLanes *)&data_u32_0045B0B0[0xA0 / 4],
};
