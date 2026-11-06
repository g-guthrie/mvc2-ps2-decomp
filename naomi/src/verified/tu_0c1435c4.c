#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *),func_0c037688(struct Actor *),func_0c02a0c4(struct Actor *,int,char);
extern void (*table_0c24f910[])(struct Actor *,struct Actor *);
void func_0c14379a(struct Actor *,struct Actor *);
void func_0c1435c4(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;func_0c02a026(a);func_0c037d0c(a);
 if(a->b19e){a->b1a1=58;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 {struct Actor *linked=a->p1b0;if(!linked->b3){a->b5++;goto animation;animation:func_0c02a0c4(a,23,1);a->s28=90;}}}
}
void func_0c143644(struct Actor *a,struct Actor *owner)
{
 short near_distance,other_distance;int zero;struct Tbl_ub3_01 **counts;
 func_0c02a026(a);if(!a->b141)a->b36=10;else a->b36=13;func_0c037d0c(a);zero=0;counts=&dat_0c2f83f8;
 if(!(a->s28&7)){struct Actor *other=owner->p20c;
 near_distance=(short)(owner->f52-a->f52);if(near_distance<0)near_distance=-near_distance;
 other_distance=(short)(owner->f52-other->f52);if(other_distance<0)other_distance=-other_distance;
 if(near_distance<other_distance){a->b1a1=58;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;(*counts)->arr[a->b2]++;a->w1ac|=16;}
 else{a->b1a1=58;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;(*counts)->arr[a->b2]++;}}
 if(!a->s28--){a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;(*counts)->arr[a->b2]++;a->b4++;}
}
void func_0c14375a(struct Actor *a,struct Actor *owner){table_0c24f910[a->b6](a,owner);}
void func_0c14376c(struct Actor *a,struct Actor *owner)
{
 struct ActorSub2a4 *sub=&owner->sub2a4;a->b6++;((unsigned char *)&sub->w4)[0]=1;func_0c02a0c4(a,23,2);func_0c14379a(a,owner);
}
void func_0c14379a(struct Actor *a,struct Actor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;a->b12c=0;}
}
void func_0c1437bc(struct Actor *a){a->b12c=0;func_0c037688(a);}
