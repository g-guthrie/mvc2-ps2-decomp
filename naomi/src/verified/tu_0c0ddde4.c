#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c248ec8[])(struct Actor *);
void func_0c0ddde4(struct Actor *a){a->b3f8=2;a->b328=5;a->s28++;if(!(a->s28&=15))func_0c0432ca(a);func_0c02a026(a);}
void func_0c0dde18(struct Actor *a){int zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;func_0c02a0c4(a,22,10);}
void func_0c0dde38(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0dde5a(struct Actor *a){table_0c248ec8[a->b6](a);}
void func_0c0dde6c(struct Actor *a)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0432ca(a);
 a->b1a1=101;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;a->f96=12.85714245f;func_0c02a0c4(a,22,15);
}
void func_0c0ddef0(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141&1){a->b6++;a->s28=60;a->b3f0=0;a->b3f1=0;position.x=-46.666664124f;position.y=139.28571f;position.z=0;func_0c0429a4(a,&position,1);}
}
void func_0c0ddf96(struct Actor *a)
{
 float offset;
 a->b3f8=2;a->b328=5;func_0c02a026(a);if(a->b141)return;
 a->b1f9=2;if(a->b14b){a->b1a1=a->b14b;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;a->b14b=0;}
 a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28==0){
  if(a->b19e){a->b6++;a->p1b0->f56=a->f56;offset=80;if(!a->w130)offset=-80;a->p1b0->f52=a->f52+offset;func_0c02a0c4(a,22,16);}
  else{a->b6+=2;a->f96=-2.1428571f;a->f108=-0.80357140303f;func_0c02a0c4(a,1,9);}
 }
}
