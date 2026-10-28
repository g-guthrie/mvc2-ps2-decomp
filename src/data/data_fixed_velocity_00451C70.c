typedef int s32;
/* func_0022F750 (0x0022F7FC-0x0022F8A0) indexes these records with actor+0x1B7 * 16
 * and converts +0/+4/+8 (+C) to actor+0x5C/+0x68/+0x60 (+0x6C). Four
 * records up to the next referenced object. Each record is four 16.16 fixed-point words
 * (lw, cvt.s.w, scaled by 1/65536).
 */
typedef struct { s32 velocityX; s32 accelX; s32 velocityY; s32 accelY; } FixedLaunchVelocity;
FixedLaunchVelocity data_fixed_velocity_00451C70[4] = {
    { 262144, -32768, 655360, -32768 },
    { 720896, -32768, 1179648, -32768 },
    { 131072, 4096, 655360, 24576 },
    { 131072, 4096, 655360, 24576 }
};
