#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25b914[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1bab2c(struct LinkedActor *),func_0c1babf0(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c1bab00(struct LinkedActor *parent)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){a->p16=func_0c1bab2c;a->p24=parent;a->w38=0x3401;}
 return a;
}
void func_0c1bab2c(struct LinkedActor *a){table_0c25b914[a->b4](a,a->p24);}
void func_0c1bab40(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->s28=owner->sdc.w158.short_value;a->b49=-2;
 a->f92=40.0f;a->f96=240.0f;
 if(a->sdc.w130)a->f92=-a->f92;
 func_0c02a0c4(a,23,3);
 func_0c1babf0(a,owner);
}
void func_0c1babf0(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(a->s28!=(unsigned short)owner->sdc.w158.short_value){a->b4++;a->sdc.b12c=0;return;}
 a->b36=owner->b36;
 a->f52=owner->f52+a->f92;
 a->f56=owner->f56+a->f96;
 func_0c02a026(a);
}
void func_0c1bac32(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1bac40(struct LinkedActor *a){func_0c037688(a);}
