typedef int s32;
/* func_0021AB20 (0x0021ABEC-0x0021AC40) picks record 0 or, when actor+0x20D
 * matches, record 1 (+8) and converts the 16.16 words +0 / +4 to actor+0x5C /
 * +0x60. */
typedef struct { s32 velocityX; s32 velocityY; } FixedVelocityPair;
FixedVelocityPair data_s32_00450EE0[2] = { { -589824, 655360 }, { -196608, 196608 } };
