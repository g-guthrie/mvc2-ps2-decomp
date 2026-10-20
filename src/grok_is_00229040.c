typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

void func_00229040(u8 *p)
{
    f32 *vx = (f32 *)(p + 0x5C);
    f32 *ax = (f32 *)(p + 0x68);
    f32 z = 0.0f;
    f32 vel;
    f32 acc;
    u32 t;
    vel = *vx;
    *(f32 *)(p + 0x34) += vel;
    acc = *ax;
    vel = *vx;
    acc = vel + acc;
    *vx = acc;
    vel = acc;
    acc = *ax;
    if (!(vel * acc <= z)) {
        t = p[6];
        p[6] = t + 1;
        *vx = z;
        *ax = z;
    }
}
