#include "objects.h"
extern int dat_0c2d9610;
extern struct ActorGlobalRoot *dat_0c2d964c;
extern int func_0c1ec190(void);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct Vec3_tu5_03 dat_0c264728[];
void func_0c1e5730(struct Obj_tu5_03 *a)
{
    int base;
    if (dat_0c2d9610 >= 1) func_0c037688(a);
    switch (a->b4) {
    case 0:
        a->b12c = 1;
        base=78;
        a->l84=(*(int (*)[36])dat_0c2d964c->p0)[a->b32*4+a->w28/2+base];
        if (++a->w28 >= 8) {
            a->w28 = 0;
            a->w30 = func_0c1ec190() % 30 + 30;
            a->b4++;
        }
        break;
    case 1:
        a->b12c = 0;
        if (++a->w28 >= a->w30) {
            a->w28 = 0;
            a->b4 = 0;
        }
        break;
    }
}
void func_0c1e57d0(int n)
{
    struct Obj_tu5_03 *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->p16 = func_0c1e5730;
        a->lcc = 0x901;
        a->pos = dat_0c264728[n];
        a->b32 = n;
    }
}
void func_0c1e5816(void)
{
    int i;
    for (i=0;i<2;i++) func_0c1e57d0(i);
}
