#include "objects.h"
extern void func_0c1f8f60(struct NaomiClock *);
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c263340[];
extern struct Vec3_tu5_03 dat_0c26335c[];
void func_0c1e2750(struct Obj_tu5_03 *a)
{
    struct NaomiClock t;
    func_0c1f8f60(&t);
    switch (a->b32) {
    case 0:
        a->angles.array[0]=(int)(t.minute*6*65536.0f/360.0f+0.5f)&0xffff;
        break;
    case 1:
        a->angles.array[0]=(int)((t.minute+(t.hour%12)*60)/2*65536.0f/360.0f+0.5f)&0xffff;
        break;
    }
}
void func_0c1e27e4(int n)
{
    struct Obj_tu5_03 *a;
    if ((a=func_0c0374da(0,5,1))!=0) {
        a->b12c=1;
        a->p16=func_0c1e2750;
        a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[9];
        a->lcc=0x807;
        a->pos=dat_0c263340[n];
        a->angles.scalar.l44=(int)(dat_0c26335c[n].x*65536.0f/360.0f+0.5f)&0xffff;
        a->b32=n;
    }
}
void func_0c1e2860(void)
{
    int i;
    for(i=0;i<2;i++)func_0c1e27e4(i);
}
