#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern float func_0c1ec2c0(int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c263efc[];
extern struct Vec3_tu5_03 dat_0c263f00[];
extern float dat_0c263f20[];
void func_0c1e3864(int);
void func_0c1e38c6(struct Obj_tu5_03 *);
void func_0c1e3848(void)
{
    int i;
    for(i=0;i<3;i++)func_0c1e3864(i);
}
void func_0c1e3864(int n)
{
    struct Obj_tu5_03 *a;
    if ((a=func_0c0374da(0,5,1))!=0) {
        a->b12c=1;
        a->p16=func_0c1e38c6;
        a->l84=((struct ActorGlobalTable *)(&(*(union ActorGlobalEntry (*)[36])dat_0c2d964c->p0)[n]))->entries[15].value;
        a->pos=dat_0c263efc[n];
        a->lcc=0x801;
        a->b32=n;
        a->w28=(short)n*120;
    }
}
void func_0c1e38c6(struct Obj_tu5_03 *a)
{
    a->pos.y = dat_0c263f00[a->b32].x + dat_0c263f20[a->b32] * func_0c1ec2c0((int)(a->w28*65536.0f/360.0f+0.5f)&0xffff);
    a->w28++;
    if(a->w28>=360)a->w28=0;
}
