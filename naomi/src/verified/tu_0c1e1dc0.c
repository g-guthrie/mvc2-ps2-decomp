#include "objects.h"
extern int func_0c038fdc(int);
extern float func_0c1ec2c0(int);
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
void func_0c1e1dc0(struct Obj_tu5_03 *a)
{
    switch (a->b4) {
    case 0:
        if (func_0c038fdc(0)) {
            a->b4++;
            goto reset;
        }
        break;
    case 1:
        a->f120 = func_0c1ec2c0((int)(a->w28 * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
        a->f124 = func_0c1ec2c0((int)(a->w28 * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
        a->f128 = func_0c1ec2c0((int)(a->w28 * 65536.0f / 360.0f + 0.5f) & 0xffff) * 0.5f + 0.5f;
        a->w28 += 2;
        if (a->w28 >= 270) {
            a->b4 = 0;
reset:
            a->w28 = -90;
        }
        break;
    }
}
void func_0c1e1e92(void)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e1dc0;
        a->l84 = dat_0c2d964c->p0->entries[17].value;
        a->lcc = 0xc01;
    }
}
