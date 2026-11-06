#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2f833e;
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c2528f4[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2528fc[])(struct LinkedActor *,struct LinkedActor *);
void func_0c171b4c(struct LinkedActor *,struct LinkedActor *),func_0c171d76(struct LinkedActor *,struct LinkedActor *),func_0c171dce(struct LinkedActor *,struct LinkedActor *),func_0c171ddc(struct LinkedActor *,struct LinkedActor *);
void func_0c171a7c(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-1;zero=0;a->b33=zero;A(a)->b1a1=61;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=65;a->pad11[1]=65;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;a->f56+=308.571411133f;
 func_0c02a0c4(a,23,30);func_0c171b4c(a,owner);
}
void func_0c171b4c(struct LinkedActor *a,struct LinkedActor *owner)
{
 unsigned char one=1;
 if(!(dat_0c2f833e&(one<<(a->b2^one)))){
  if((unsigned char)A(owner)->b159!=22 || owner->b5){func_0c171ddc(a,owner);return;}
  goto follow;follow:a->b36=owner->b36;
  if(!a->b33)a->b49=-1;else a->b49=one;
  a->f52=owner->f52;
  if(!A(owner)->b1a0)table_0c2528f4[(unsigned char)a->b5](a,owner);
 }
}
void func_0c171be4(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 if(func_0c02a026(a)<0){
  float zero=0.0f;a->b5++;context->b3=1;
  A(a)->f92=zero;a->f96=zero;A(a)->f104=zero;A(a)->f108=zero;A(a)->f108=-0.5357143f;
 }
}
void func_0c171c2c(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(A(owner)->b141)a->b33=1;
 a->f56+=a->f96;a->f96+=A(a)->f108;func_0c037d0c(a);
 if(!(a->f56>A(owner)->f41c+212.142853f)){a->b5++;func_0c171dce(a,owner);}
}
void func_0c171c92(struct LinkedActor *a,struct LinkedActor *owner){table_0c2528fc[a->b4](a,owner);}
void func_0c171cc0(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-1;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;a->f56+=212.142853f;
 A(a)->f92=0.0f;a->f96=0.0f;A(a)->f104=0.0f;A(a)->f108=0.0f;A(a)->f108=0.016741071f;
 func_0c02a0c4(a,23,31);func_0c171d76(a,owner);
}
void func_0c171d76(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;a->f52=owner->f52;a->f56+=a->f96;a->f96+=A(a)->f108;
 if(func_0c02a026(a)<0){a->b4++;func_0c171dce(a,owner);}
}
void func_0c171dce(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c171ddc(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
