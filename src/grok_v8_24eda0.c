typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);

void func_0024EDA0(u8 *p)
{
    f32 *vx;
    f32 *ax;

    if (p[6] == 0) {
        func_00175700(p);
        if ((s8)p[0x151] != 0) {
            p[6]++;
            *(f32 *)(p + 0x5C) = p[0x1E6] ? 14.166666030883789f : -14.166666030883789f;
            *(f32 *)(p + 0x68) = p[0x1E6] ? -0.7291666269302368f : 0.7291666269302368f;
        }
    } else {
        func_00183D90(p);
        if ((s8)p[0x151] != 0)
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        ax = (f32 *)(p + 0x68);
        vx = (f32 *)(p + 0x5C);
        *vx += *ax;
        if ((s8)func_00175700(p) < 0) {
            *vx = 0;
            *(int *)(p + 0x60) = 0;
            *ax = 0;
            *(int *)(p + 0x6C) = 0;
            func_001843A0(p);
        }
    }
}
