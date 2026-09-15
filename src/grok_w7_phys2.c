typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);

void func_0025DC40(u8 *p)
{
    f32 *vx;
    f32 *vy;
    f32 *ax;
    f32 *ay;
    f32 t;

    vx = (f32 *)(p + 0x5C);
    ax = (f32 *)(p + 0x68);
    vy = (f32 *)(p + 0x60);
    t = *vx;
    *(f32 *)(p + 0x34) += t;
    t = *ax;
    *vx += t;
    t = *vy;
    *(f32 *)(p + 0x38) += t;
    ay = (f32 *)(p + 0x6C);
    t = *(f32 *)(p + 0x6C);
    *vy += t;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *vx = 0.0f;
        *vy = 0.0f;
        *ax = 0.0f;
        *ay = 0.0f;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    if ((s8)p[0x151] == 0)
        func_00175700(p);
}

void func_0025DED0(u8 *p)
{
    f32 *vx;
    f32 *vy;
    f32 *ax;
    f32 *ay;
    f32 t;

    vx = (f32 *)(p + 0x5C);
    ax = (f32 *)(p + 0x68);
    vy = (f32 *)(p + 0x60);
    t = *vx;
    *(f32 *)(p + 0x34) += t;
    t = *ax;
    *vx += t;
    t = *vy;
    *(f32 *)(p + 0x38) += t;
    ay = (f32 *)(p + 0x6C);
    t = *(f32 *)(p + 0x6C);
    *vy += t;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        *vx = 0.0f;
        *vy = 0.0f;
        *ax = 0.0f;
        *ay = 0.0f;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
    if ((s8)p[0x151] == 0)
        func_00175700(p);
}
