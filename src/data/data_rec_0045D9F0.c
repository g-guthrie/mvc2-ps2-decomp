typedef signed int s32;
typedef struct { s32 vx; s32 ax; s32 vy; s32 ay; } FixedMotionRecord;
/* 16.16 fixed-point records (vx, ax, vy, ay): func_0031DE00 (src/x4_a.c) picks this object from D_004C1758[idx] and reads lwc1 +0/+4/+8/+0xC of record p[0x1B7]; two records fit before the next object. */
FixedMotionRecord data_rec_0045D9F0[2] = {
    { 0, 32768, 360448, -32768 },
    { 0, 131072, 884736, -65536 },
};
