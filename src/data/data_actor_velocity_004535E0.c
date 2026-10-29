typedef float f32;
/* func_00259E70 (0x00259EE8-0x00259F1C) reads pair 0; func_00259F90
 * (0x00259FD8-0x00259FF8) reads +0 / +4 at actor+0x1C * 4, and actor+0x1C
 * advances by 2 (0x0025A090-0x0025A09C), so the stride is one pair. Seven pairs;
 * the two zero words before D_00453620 are outside the list. */
typedef struct { f32 velocityX; f32 accelX; } ActorVelocityPair;
ActorVelocityPair data_actor_velocity_004535E0[7] = {
    { -20.0f, 1.5625f },
    { -16.666666f, 1.25f },
    { -16.666666f, 1.25f },
    { -16.666666f, 1.25f },
    { -16.666666f, 1.25f },
    { -16.666666f, 1.25f },
    { -20.0f, 1.0416666f }
};
