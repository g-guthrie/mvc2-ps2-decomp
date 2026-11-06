#include "objects.h"
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c1d53e4(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c1b1ce8(struct LinkedActor *a,struct LinkedActor *owner)
{
 float dx;
 if(!a->b4){
  a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
  a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
  a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
  a->b36=owner->b36;a->b36=12;
  a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
  dx=80.0f;a->f92=11.666666031f;
  if(a->sdc.w130){dx=-80.0f;a->f92=-a->f92;}
  a->f52=owner->f52+dx;
  a->f56=owner->f56+-12.85714245f;
  func_0c02a0c4(a,18,4);
  a->pad0=1;
  func_0c1d53e4(a);
 }else if(!a->b5){
  func_0c02a026(a);
  if(a->sdc.b141){a->sdc.b141=0;a->b5++;a->s28=28;}
 }else{
  a->f52+=a->f92;a->f92+=a->f104;
  if(--a->s28<0)a->b4++;else func_0c02a026(a);
 }
}
void func_0c1b1e0c(void){}
