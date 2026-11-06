/* Ambient colour cycle: three sine channels and a periodic random tilt. */
#include "objects.h"
extern float func_0c1ec2c0(int);
extern int func_0c1ec190(void);
extern float dat_0c2625cc;
void func_0c1e06a0(struct Obj_tu5_03 *a)
{
    a->w28 = a->w28 + 1;
    if (a->w28 >= 1080) a->w28 = 0;
    a->f120 = func_0c1ec2c0((int)(a->w28 / 3.0f * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
    a->f124 = func_0c1ec2c0((int)(a->w28 / 2.0f * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
    a->f128 = func_0c1ec2c0((int)(a->w28 / 1.0f * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
    a->w30 = a->w30 + 1;
    if (a->w30 >= 600) {
        float t;
        a->w30 = 0;
        a->b4 = func_0c1ec190() % 3;
        t = dat_0c2625cc;
        if (!a->b4) t += 180.0f;
        a->angles.scalar.l44 = (int)(t * 65536.0f / 360.0f + 0.5f) & 0xffff;
    }
}
