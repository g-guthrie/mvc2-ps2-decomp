/* Swaying emblem: sine/cosine tilt from the slot phase and a three-channel colour cycle. */
#include "objects.h"
extern float func_0c1ec2c0(int);
extern float func_0c1ebd40(int);
void func_0c1e00a8(struct Obj_tu5_03 *a)
{
    if (a->w28 >= 720) a->w28 = 0;
    if (a->w30 >= 1080) a->w30 = 0;
    a->angles.array[0] = (int)(func_0c1ec2c0((int)((a->w28 / 2.0f + a->b32 * 90) * 65536.0f / 360.0f + 0.5f) & 0xffff) * 1310720.0f / 360.0f + 0.5f) & 0xffff;
    a->angles.scalar.l48 = (int)(func_0c1ebd40((int)((a->w28 / 2.0f + a->b32 * 90) * 65536.0f / 360.0f + 0.5f) & 0xffff) * 3932160.0f / 360.0f + 0.5f) & 0xffff;
    a->f120 = func_0c1ec2c0((int)(a->w30 / 3.0f * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
    a->f124 = func_0c1ec2c0((int)(a->w30 / 2.0f * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
    a->f128 = func_0c1ec2c0((int)(a->w30 / 1.0f * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
    a->w28++;
    a->w30++;
}
