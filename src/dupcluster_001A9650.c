/* Count trajectory steps until vertical motion is descending and below the limit. */
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 header[0x38];
    f32 height;
    u8 gap3c[0x24];
    f32 verticalVelocity;
    u8 gap64[8];
    f32 verticalAcceleration;
} Trajectory;
s32 func_001A9650(Trajectory *p, f32 limit)
{
    s32 steps = 0;
    f32 zero = 0.0f;
    f32 height = p->height;
    f32 velocity = p->verticalVelocity;
    do {
        height += velocity;
        velocity += p->verticalAcceleration;
        steps++;
    } while (velocity > zero || height > limit);
    return steps;
}
