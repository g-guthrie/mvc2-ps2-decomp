#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1e00a8(struct Obj_tu5_03 *);
extern struct Vec3_tu5_03 dat_0c26255c[],dat_0c262590[];
void func_0c1e023c(int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e00a8;
        a->l84=(*(int (*)[36])dat_0c2d964c->p0)[n+22];
        a->pos=dat_0c26255c[n];
        a->angles.scalar.l44=(int)(dat_0c262590[n].x*65536.0f/360.0f+0.5f)&0xffff;
        a->lcc=0xc0b;
        a->b32=n;
        a->w30=(short)n*270;
    }
}
void func_0c1e02c2(void)
{
    int i;
    for(i=0;i<4;i++)func_0c1e023c(i);
}
