#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c037688(struct Obj_tu5_03 *);
extern float func_0c1ce8c4(float *,char *,int);
extern struct Vec3_tu5_03 dat_0c2632f8;
extern float dat_0c263304[];
extern float dat_0c263310[],dat_0c263320[],dat_0c263330[];
void func_0c1e264c(struct Obj_tu5_03 *);
void func_0c1e26a8(struct Obj_tu5_03 *);
void func_0c1e26ec(struct Obj_tu5_03 *);
void func_0c1e25bc(void)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e264c;
        a->l84=dat_0c2d964c->p0->entries[5].value;
        a->lcc=0x805;
        a->pos=dat_0c2632f8;
        a->angles.array[0]=(int)(dat_0c263304[0]*65536.0f/360.0f+0.5f)&0xffff;
        a->angles.scalar.l44=(int)(dat_0c263304[1]*65536.0f/360.0f+0.5f)&0xffff;
        a->angles.scalar.l48=(int)(dat_0c263304[2]*65536.0f/360.0f+0.5f)&0xffff;
        func_0c1e26a8(a);
    }
}
void func_0c1e264c(struct Obj_tu5_03 *a)
{
    if(a->w28>=6000){func_0c037688(a);return;}
    a->pos.x=func_0c1ce8c4(dat_0c263310,(char *)&a->b4,a->w28);
    a->pos.y=func_0c1ce8c4(dat_0c263320,&a->b5,a->w28);
    a->pos.z=func_0c1ce8c4(dat_0c263330,(char *)&a->b6,a->w28);
    a->w28++;
}
void func_0c1e26a8(struct Obj_tu5_03 *parent)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e26ec;
        a->l84=dat_0c2d964c->p0->entries[11].value;
        a->lcc=0x2800;
        a->p200=&parent->f136;
    }
}
void func_0c1e26ec(struct Obj_tu5_03 *a)
{
    if(a->w28>=6000)func_0c037688(a);
    else a->w28++;
}
