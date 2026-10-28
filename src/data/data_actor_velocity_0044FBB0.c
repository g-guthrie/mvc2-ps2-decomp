typedef float f32;
/* func_001F9720 (0x001F974C-0x001F9774), func_001F9A40 (0x001F9A78-0x001F9AA0)
 * and func_001FB1A0 (0x001FB1DC-0x001FB204) index these records with
 * actor+0x1B7 * 16 and copy +0/+4/+8/+C to actor+0x5C/+0x68/+0x60/+0x6C.
 * Two records up to the next referenced object (D_0044FBD0). */
typedef struct { f32 velocityX; f32 accelX; f32 velocityY; f32 accelY; } ActorLaunchVelocity;
ActorLaunchVelocity data_actor_velocity_0044FBB0[2] = {
    { 4.1666665f, 0.0f, 19.285713f, -1.0714285f },
    { 5.0f, 0.0f, 27.857141f, -1.0714285f }
};
