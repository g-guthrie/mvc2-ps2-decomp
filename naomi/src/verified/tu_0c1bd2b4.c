#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c25be18[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1bd362(struct LinkedActor *,struct LinkedActor *);
void func_0c1bd2b4(struct LinkedActor *a,struct LinkedActor *parent)
{
 a->b4++;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2;
 a->b1=parent->b1;
 a->v80.x=parent->v80.x;
 a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;
 a->b1a4=parent->b1a4;
 a->b48=parent->b48;
 a->v80=parent->v80;
 a->b36=parent->b36;
 a->sdc.b12c=1;
 a->b49=-1;
 a->f52=parent->f52;
 a->f56=parent->f56;
 a->f60=parent->f60;
 a->f92=-65.0f;
 a->f96=216.42856f;
 if(a->sdc.w130) a->f92=-a->f92;
 func_0c02a0c4(a,23,29);
 func_0c1bd362(a,parent);
}
void func_0c1bd362(struct LinkedActor *a,struct LinkedActor *parent)
{
 short *word=&a->wcc.short_value;
 a->b36=parent->b36;
 if(parent->sdc.w158.short_value==*word){
  a->f52=parent->f52+a->f92;
  a->f56=parent->f56+a->f96;
  if(func_0c02a026(a)<0){a->sdc.b12c=0;}else{return;}
 }
 a->b4++;
}
void func_0c1bd3b2(struct LinkedActor *a,struct LinkedActor *parent)
{
 table_0c25be18[a->b4](a,parent);
}
