/* Eighteen connected actor callbacks, including near-call helpers. */
#include "objects.h"
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c02a684(struct Actor *,int,int,int),func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1bfa20(struct Actor *),func_0c1bac7c(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c0438de(struct Actor *),func_0c03edcc(struct Actor *,struct Actor *);
extern int func_0c02a39a(struct Actor *,int);
extern struct ActorFlags *dat_0c2d6f84;
extern void (*dat_0c24d104[])(struct Actor *),(*dat_0c24d110[])(struct Actor *),(*dat_0c24d120[])(struct Actor *),(*dat_0c24d12c[])(struct Actor *),(*dat_0c24d138[])(struct Actor *);
void func_0c11e6a4(struct Actor *),func_0c11e7a0(struct Actor *);
void func_0c11e4dc(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->f104=0.0f;a->f96=0.0f;a->f108=0.0f;
 if(a->b34&1){a->b1d2=a->w130=(unsigned char)a->b1d2^1;a->p1c8->b1d2=a->p1c8->w130=(unsigned char)a->p1c8->b1d2^1;}
 position.x=-66.666664124f;position.y=257.142853f;
 func_0c1d4610(a,&position);func_0c02a684(a,1,5,1);
 a->p1c8->pad220[10]=3;a->p1c8->pad220[8]=3;
 func_0c1bfa20(a->p1c8);a->b1a0=10;func_0c02a0c4(a,15,4);
}
void func_0c11e57c(struct Actor *a){a->b1ea=1;dat_0c24d104[a->b1f7&63](a);}
void func_0c11e59a(struct Actor *a){dat_0c24d110[a->b6](a);}
void func_0c11e5ac(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){int zero=0;a->b6++;a->b141=zero;func_0c1bac7c(a,zero);}
}
void func_0c11e5dc(struct Actor *a)
{
 func_0c11e6a4(a);
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,15,1);}
}
void func_0c11e640(struct Actor *a)
{
 func_0c11e6a4(a);func_0c02a026(a);
 if(a->b141){struct Actor *other; a->b6++;a->b141=0;
  other=a->p1c8;other->p1b4=a;other->b1d2=a->b1d2^1;
  other->b1a1=32;other->b1f6=1;
  func_0c025900(a,0,0);func_0c02a39a(other,0);
 }
}
void func_0c11e6a4(struct Actor *a)
{
 struct Actor *other=a->p1c8;
 if(dat_0c2d6f84->flags&1)func_0c02a39a(other,1);
 else func_0c02a39a(other,8);
}
void func_0c11e6be(struct Actor *a){dat_0c24d120[a->b6](a);}
void func_0c11e6d0(struct Actor *a)
{
 a->p1c8->pad220[10]=3;a->p1c8->pad220[8]=3;
 func_0c11e7a0(a);func_0c02a026(a);
 if(a->b141==1){struct Actor *other;a->b6++;a->b141=0;
  other=a->p1c8;other->p1b4=a;other->b1d2=a->b1d2^1;
  other->b1a1=33;other->b1f6=10;
  func_0c025900(a,0,0);func_0c02a39a(other,1);func_0c1bac7c(a,2);
 }
}
void func_0c11e750(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,15,3);}
}
void func_0c11e7a0(struct Actor *a)
{
 struct Actor *other=a->p1c8;
 if(dat_0c2d6f84->flags&1)func_0c02a39a(other,5);
 else func_0c02a39a(other,4);
}
void func_0c11e7ba(struct Actor *a){dat_0c24d12c[a->b6](a);}
void func_0c11e7cc(struct Actor *a)
{
 a->p1c8->pad220[10]=3;a->p1c8->pad220[8]=3;
 func_0c11e7a0(a);func_0c02a026(a);
 if(a->b141){struct Actor *other;a->b6++;a->b141=0;
  other=a->p1c8;other->p1b4=a;other->b1d2=a->b1d2^1;
  other->b1a1=34;other->b1f6=10;
  func_0c025900(a,0,0);func_0c02a39a(other,1);func_0c1bac7c(a,3);
 }
}
void func_0c11e84c(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,15,5);}
}
void func_0c11e876(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c11e898(struct Actor *a){dat_0c24d138[a->b1f7&63](a);}
void func_0c11e8b0(struct Actor *a){func_0c03edcc(a->p1c8,a);}
void func_0c11e8be(struct Actor *a)
{
 char *state=(char *)&a->sub2a4;
 state[6]=-1;
 state[4]++;
 state[5]=0;state[2]=0;state[3]=0;
}
