#include "objects.h"
extern struct Dat_13bb5c dat_0c2f8338;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c13bebc(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 {a->b4++;a->sdc.b12c=0;((struct Actor *)a)->w130=a->b33?0:1;((struct Actor *)a)->b19c=66;((struct Actor *)a)->b19d=66;}
 {struct LinkedActor *p=a->p20;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&p->f52;}
 func_0c02a0c4(a,23,a->s28+16);
}
void func_0c13bf52(struct LinkedActor *a,struct LinkedActor *owner)
{
 register struct LinkedActor *p=a->p20;int zero;
 if((dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))==0){
 zero=0;
 if(!owner->b5&&owner->b1d0==29&&!owner->s30){
  if(p->sdc.b141){
  ((struct Actor *)a)->b1a1=((struct Actor *)a)->b14b;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c037d0c(a);}
 } else {
 a->b4=2;a->sdc.b12c=zero;}
 }
}
void func_0c13bfc2(struct LinkedActor *a){func_0c037688(a);}
