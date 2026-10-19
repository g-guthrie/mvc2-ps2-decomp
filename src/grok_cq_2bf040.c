typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_00175700(u8 *);

void residual_002BF040(u8 *p)
{
    f32 *vx = (f32 *)(p + 0x5C);
    f32 *ax = (f32 *)(p + 0x68);
    f32 *vy = (f32 *)(p + 0x60);
    f32 *ay;

    if ((s8)p[0x151] == 0)
        func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    ay = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if ((s8)p[0x151] != 0) {
            p[6]++;
            p[0x151] = 0;
            *vx = 0.0f;
            *vy = 0.0f;
            *ax = 0.0f;
            *ay = 0.0f;
        }
    }
}
