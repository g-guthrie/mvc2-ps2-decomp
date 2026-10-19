typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_00175700(u8 *);

void func_002BB1E0(u8 *p)
{
    f32 *vx;
    f32 *ax;
    u8 face;

    if ((s8)p[0x151] == 0)
        func_00175700(p);
    vx = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x38) + *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) + *(f32 *)(p + 0x6C);
    face = p[0x1E6];
    ax = (f32 *)(p + 0x68);
    if (face == 0) {
        if (*(f32 *)(p + 0x5C) < 0.0f)
            return;
    }
    if (face != 0) {
        if (*(f32 *)(p + 0x5C) > 0.0f)
            return;
    }
    p[6]++;
    *vx = 0.0f;
    *ax = 0.0f;
}
