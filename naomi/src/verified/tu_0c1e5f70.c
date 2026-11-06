#include "objects.h"
extern int func_0c1ec190(void);
extern float func_0c1ec2c0(int);
extern float func_0c1ebd40(int);
extern void func_0c1e5e34(struct Vec3_tu5_03 *);
extern struct Vec3_tu5_03 dat_0c264790[];
extern int dat_0c264740[];
extern float dat_0c264768[];
extern struct ActorGlobalRoot *dat_0c2d964c;
void func_0c1e5f70(register struct Obj_tu5_03 *a)
{
    if (++a->w30 >= 5) {
        a->w30 = 0;
        if ((unsigned int)++a->w28 >= 10) {
            a->pos = dat_0c264790[(unsigned long)func_0c1ec190() % 6];
            a->w28 = 0;
            func_0c1e5e34(&a->pos);
        }
        if (a->w28 == 5) {
            const float amp=50.0f; const float units=65536.0f; register const float angle=360.0f; register const float half=0.5f;
            a->pos.x += func_0c1ec2c0((int)((int)func_0c1ec190() % 360 * units / angle + half) & 0xffff) * amp;
            a->pos.z += func_0c1ebd40((int)((int)func_0c1ec190() % 360 * units / angle + half) & 0xffff) * amp;
        }
        a->l84 = (*(int (*)[36])dat_0c2d964c->p0)[dat_0c264740[a->w28]];
        a->f80 = dat_0c264768[a->w28];
        a->f84 = dat_0c264768[a->w28];
        a->f88 = dat_0c264768[a->w28];
    }
}
