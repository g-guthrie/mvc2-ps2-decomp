#include "objects.h"
extern void func_0c04b02a(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1ce70c(struct Actor *,int,int,float,float);
void func_0c151360(struct Actor *a)
{
 a->f80+=0.0080000004f;a->f84-=0.01200000010431f;
 if(--a->s28<=0){a->b6++;a->s28=5;}
}
void func_0c151396(struct Actor *a)
{
 a->f80+=0.0080000004f;a->f84-=0.01200000010431f;
 if(--a->s28<=0){a->s28=a->s30=3;a->b5++;a->b6=0;a->f80=a->f84=1.0f;}
}
void func_0c1513dc(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;owner->b1ea=1;
 if(a->s28!=a->s30){
 if(a->s28<=0){a->b5++;a->b12c=0;{struct Actor *linked=a->p1b0;linked->b1a1=64;}func_0c04b02a(owner);{int angle=144;func_0c1ce70c(a,0,angle,4.0f,4.0f);func_0c1ce70c(a,16,angle,4.0f,4.0f);func_0c1ce70c(a,240,angle,4.0f,4.0f);}a->b0=0;}
 else{a->s30=a->s28;func_0c02a0c4(a,22,a->b32+a->s28);{struct Actor *linked=a->p1b0;linked->b1a1=64;}func_0c04b02a(owner);return;}}
}
void func_0c151488(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;owner->b1ea=1;
 if(owner->b141){a->b5=4;a->b6=0;}
}
