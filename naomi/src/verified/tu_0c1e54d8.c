#include "objects.h"
extern int func_0c1ec190(void);
extern float func_0c1ec2c0(int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct ActorFlags *dat_0c2d6f84;
extern int dat_0c2d9610;
extern void func_0c1d9314(int,float,float,float,float);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct Vec3_tu5_03 dat_0c26470c[];
void func_0c1e54d8(struct Obj_tu5_03 *a)
{
    switch(a->b4){
    case 0:
        a->w28++;
        if(a->w28>=a->w30){
            a->w30=func_0c1ec190()%27+24;
            a->w28=0;
        }
        a->l84=(*(int (*)[36])dat_0c2d964c->p0)[a->w28/3+12];
        func_0c1d9314(a->l84,1.0f,
            func_0c1ec2c0(dat_0c2d6f84->i32)*0.25f+0.75f,
            func_0c1ec2c0(dat_0c2d6f84->i32*2)*0.25f+0.75f,
            func_0c1ec2c0(dat_0c2d6f84->i32*4)*0.25f+0.75f);
        if(dat_0c2d9610==1)func_0c037688(a);
        break;
    }
}
void func_0c1e55a2(int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e54d8;
        a->l84=(*(int (*)[36])dat_0c2d964c->p0)[n+12];
        a->lcc=0x901;
        a->pos=dat_0c26470c[n];
    }
}
void func_0c1e55fc(void)
{
    int i;
    for(i=0;i<2;i++)func_0c1e55a2(i);
}
