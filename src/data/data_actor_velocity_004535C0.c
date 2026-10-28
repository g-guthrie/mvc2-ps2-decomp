typedef float f32;
/* func_00259600 (0x00259684-0x0025969C) and func_0025B110 (0x0025B198-0x0025B1B0)
 * index these records with actor+0x1B7 * 16 and read +0/+4/+8/+C. Two records
 * up to D_004535E0. */
typedef struct { f32 velocityX; f32 accelX; f32 velocityY; f32 accelY; } ActorLaunchVelocity;
ActorLaunchVelocity data_actor_velocity_004535C0[2] = {
    { 0.0f, 0.0f, 17.142857f, -1.0714285f },
    { -20.0f, 0.8333333f, 34.285713f, -1.0714285f }
};
