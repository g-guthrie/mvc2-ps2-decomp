typedef int s32;
/* Selected through the gp table D_004BFEE8 (word 1) by func_00218910
 * (0x00218910-0x00218998), indexed by actor+0x1B7 * 16; +0/+4/+8/+C go to
 * actor+0x5C/+0x68/+0x60/+0x6C. Two records up to the next object. Each record is four 16.16 fixed-point words
 * (lw, cvt.s.w, scaled by 1/65536).
 */
typedef struct { s32 velocityX; s32 accelX; s32 velocityY; s32 accelY; } FixedLaunchVelocity;
FixedLaunchVelocity data_fixed_velocity_00450E70[2] = {
    { 0, 32768, 360448, -32768 },
    { 0, 131072, 884736, -65536 }
};
