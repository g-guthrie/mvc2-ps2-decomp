typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

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

extern void func_001843A0(u8 *);

void func_002FE370(u8 *p)
{
    f32 *vx = (f32 *)(p + 92);
    f32 *ax = (f32 *)(p + 104);
    f32 *vz = (f32 *)(p + 96);
    f32 *az = (f32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((*vx * *ax) > 0.0f) {
        *vx = 0.0f;
        *ax = 0.0f;
    }
    if (p[525] == 2) {
        func_00175700(p);
        if (*(f32 *)(p + 1072) < *(f32 *)(p + 56)) goto floor_done;
        *vz = 0.0f;
        *az = 0.0f;
        p[525] = 0;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_001843A0(p);
    floor_done: ;
    } else if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

void func_002FE790(u8 *p)
{
    f32 *vx = (f32 *)(p + 92);
    f32 *ax = (f32 *)(p + 104);
    f32 *vz = (f32 *)(p + 96);
    f32 *az = (f32 *)(p + 108);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if ((*vx * *ax) > 0.0f) {
        *vx = 0.0f;
        *ax = 0.0f;
    }
    if (p[525] == 2) {
        func_00175700(p);
        if (*(f32 *)(p + 1072) < *(f32 *)(p + 56)) goto floor_done;
        *vz = 0.0f;
        *az = 0.0f;
        p[525] = 0;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_001843A0(p);
    floor_done: ;
    } else if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}
