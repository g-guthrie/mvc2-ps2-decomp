typedef int s32;
/* func_0022F750 (0x0022F924-0x0022F9A0) indexes these records with actor+0x1B7 * 16
 * and converts +0/+4/+8 (+C) to actor+0x5C/+0x68/+0x60 (+0x6C). Four
 * records up to the next referenced object. Each record is four 16.16 fixed-point words
 * (lw, cvt.s.w, scaled by 1/65536).
 */
typedef struct { s32 velocityX; s32 accelX; s32 velocityY; s32 accelY; } FixedLaunchVelocity;
FixedLaunchVelocity data_fixed_velocity_00451CB0[4] = {
    { 0, 0, -327680, -26624 },
    { 0, 0, -524288, -26624 },
    { 0, 0, -262144, -24576 },
    { 0, 0, -262144, -24576 }
};
