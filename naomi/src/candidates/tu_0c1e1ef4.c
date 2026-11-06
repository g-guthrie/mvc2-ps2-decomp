#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct ActorFlags *dat_0c2d6f84;
extern int func_0c1ec190(void);
extern void func_0c1da38c(float *,float *,float *,float);
extern struct Vec3_tu5_03 *dat_0c26304c[];
extern int dat_0c26307c[],dat_0c262a88[],dat_0c263220[];
extern struct Vec3_tu5_03 dat_0c263240[];
void func_0c1e1ef4(register struct Obj_tu5_03 *a)
{
    float vz,vy,vx;
    int count=dat_0c26307c[a->b32];
    register struct Vec3_tu5_03 *points=dat_0c26304c[a->b32];
    struct Vec3_tu5_03 *before,*current,*after;
    int n;
    a->l84=(*(int (*)[36])dat_0c2d964c->p0)[dat_0c262a88[dat_0c2d6f84->b128%18u]+18];
    func_0c1da38c(&vx,&vy,&vz,a->w28/50.0f);
    n=a->w30;
    before=&points[n-1];
    current=&points[n];
    after=&points[n+1];
    a->pos.x=before->x*vx+current->x*vy+after->x*vz;
    a->pos.y=before->y*vx+current->y*vy+after->y*vz;
    a->pos.z=before->z*vx+current->z*vy+after->z*vz;
    if(++a->w28>=50){
        a->w28=0;
        if(++a->w30+1>=count)a->w30=1;
    }
}
void func_0c1e2000(int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e1ef4;
        a->l84=dat_0c2d964c->p0->entries[18].value;
        a->lcc=0x801;
        a->b32=n;
        a->w30=1;
    }
}
void func_0c1e2078(void)
{
    int i;
    for(i=0;i<2;i++)func_0c1e2000(i);
}
void func_0c1e20bc(struct Obj_tu5_03 *);
void func_0c1e2094(void)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e20bc;
        a->lcc=0x801;
    }
}
void func_0c1e20bc(struct Obj_tu5_03 *a)
{
    a->l84=(*(int (*)[36])dat_0c2d964c->p0)[dat_0c263220[a->w28]+21];
    if((unsigned int)++a->w28>=8){
        a->pos=dat_0c263240[func_0c1ec190()&7];
        a->w28=0;
    }
}
