#include "objects.h"
extern void func_0c029e70(struct LinkedActor *,int,int);
extern char func_0c029fc4(struct LinkedActor *);
extern void (*dat_0c259644[])(struct LinkedActor *);
void func_0c1a968e(struct LinkedActor *);
void func_0c1a9614(struct LinkedActor *a)
{
 a->b4++;
 a->sdc=a->p24->sdc;
 a->sdc.b12c=1;
 a->b2=a->p24->b2;
 a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;
 a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;
 a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;
 a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->b36=7;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&a->p24->f52;
 func_0c1a968e(a);
}
void func_0c1a968e(struct LinkedActor *a)
{
 struct LinkedActor *parent=a->p24;
 a->sdc.b12c=0;
 ((struct Actor *)a)->f264=1.0f;
 if(a->s30!=parent->sdc.w158.short_value){a->b4=2;return;}
 a->sdc.b12c=1;
 switch((unsigned char)a->b5){
 case 0:
  a->b5++;
  func_0c029e70(a,27,0);
  break;
 case 1:
  func_0c029fc4(a);
  if(a->sdc.b141){a->b5++;a->f92=1.0f;a->f104=0.0625f;}
  break;
 case 2:
  a->f92-=a->f104;
  if(a->f92<0.0f){a->b4++;((struct Actor *)a)->f264=1.0f;a->sdc.b12c=0;}
  ((struct Actor *)a)->f264=a->f92;
  break;
 }
}
void func_0c1a973a(struct LinkedActor *a)
{
 dat_0c259644[a->b4](a);
}
