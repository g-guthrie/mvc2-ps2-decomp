#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1bdec0(struct LinkedActor *a,struct LinkedActor *parent)
{
 if(!a->b4){
  struct LinkedActor *target;
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
  target=a->p20;
  a->f52=target->f52;
  a->f56=target->f56;
  a->s28=32;
  func_0c02a0c4(a,18,6);
  a->f92=0.0f;
  a->f104=0.0f;
  a->f96=-2.1428571f;
  a->f108=-0.5357143f;
 }
 func_0c02a026(a);
 if(--a->s28<0){a->b4=2;}else{
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 }
}
