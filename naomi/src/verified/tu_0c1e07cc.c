#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern float func_0c1ec2c0(int),func_0c1ebd40(int);
extern struct Vec3_tu5_03 dat_0c262638[];
extern struct Vec3_tu5_03 dat_0c26262c;
void func_0c1e07cc(struct Obj_tu5_03 *a)
{
    a->angles.array[0]+=512;
}
void func_0c1e07da(struct Obj_tu5_03 *parent,int n)
{
    struct Obj_tu5_03 *a;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e07cc;
        a->l84=dat_0c2d964c->p0->entries[29].value;
        a->pos=dat_0c262638[n];
        a->lcc=0x803;
        a->p20=parent;
        a->p200=&parent->f136;
    }
}
void func_0c1e083e(struct Obj_tu5_03 *a)
{
    float units; float angle; register float half;
    if(a->w28>=300)a->w28=180;
    units=65536.0f;
    angle=360.0f;
    half=0.5f;
    a->angles.scalar.l44=(int)((a->w28+90)*units/angle+half)&0xffff;
    {
        float radius=850.0f;
        a->pos.x=dat_0c26262c.x+func_0c1ec2c0((int)(a->w28*units/angle+half)&0xffff)*radius;
        a->pos.z=dat_0c26262c.z+func_0c1ebd40((int)(a->w28*units/angle+half)&0xffff)*radius;
    }
    a->w28++;
}
void func_0c1e0930(void)
{
    struct Obj_tu5_03 *a;
    int i;
    if((a=func_0c0374da(0,5,1))!=0){
        a->b12c=1;
        a->p16=func_0c1e083e;
        a->l84=dat_0c2d964c->p0->entries[28].value;
        a->pos=dat_0c26262c;
        a->lcc=0x805;
        for(i=0;i<2;i++)func_0c1e07da(a,i);
    }
}
