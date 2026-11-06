#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c0288a8(struct LinkedActor *,int);
extern int func_0c028642(struct LinkedActor *);
extern int func_0c02849a(void);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
struct Wcc_144c70 { int i0; float f4; unsigned char b8; };
void func_0c144c70(struct LinkedActor *,struct Actor *);
void func_0c144a80(struct LinkedActor *a,struct Actor *b)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&b->sub2a4;struct LinkedActorWccBytes *w=&a->wcc.bytes;
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 func_0c144c70(a,b);
 if(b->b159!=(char)w->b1)goto adv;
 if(!A(a)->b19f)goto cont;
adv:
 a->b4++;return;
cont:
 func_0c037d0c(a);
 if(sub->b9){a->b5++;A(a)->f96=0.0f;A(a)->f108=0.0f;a->s28=30+2*(unsigned char)a->b33;}
}
void func_0c144b26(struct LinkedActor *a,struct Actor *b)
{
 struct LinkedActorWccBytes *w=&a->wcc.bytes;int v;
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 func_0c144c70(a,b);
 if(b->b159!=(char)w->b1)goto adv;
 if(!A(a)->b19f)goto cont;
adv:
 a->b4++;return;
cont:
 func_0c037d0c(a);
 if((a->s28)--==0){
  a->b5++;
  A(a)->b1a1=54;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
  A(a)->f92=0.0f;A(a)->f104=0.0f;
  v=func_0c02849a()&3;
  if(!b->w130)v+=23;else v+=6;
  a->b34=v;a->b34&=31;
 }
}
void func_0c144c16(struct LinkedActor *a,struct LinkedActor *b)
{
 a->b36=b->b36;func_0c0288a8(a,800);
 if(!A(a)->b19f){
  func_0c037d0c(a);
  if(A(a)->b19e)goto adv;
  if(func_0c028642(a))return;
 }
adv:
 a->b4++;
}
void func_0c144c56(struct LinkedActor *a){a->sdc.b12c=0;a->b4++;}
void func_0c144c64(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
void func_0c144c70(struct LinkedActor *a,struct Actor *b)
{
 struct Wcc_144c70 *w=(struct Wcc_144c70 *)&a->wcc;
 if(A(a)->f92*A(a)->f104>0.0f){
  A(a)->f92=w->f4=-w->f4;
  A(a)->f104=-A(a)->f104;
  w->b8^=1;
 }
 if(!w->b8)a->b36=0;else a->b36=7;
}
