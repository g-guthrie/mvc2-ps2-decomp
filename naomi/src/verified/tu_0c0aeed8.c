#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Actor *func_0c1536c0(struct Actor *,unsigned char);
extern void (*table_0c2448c0[])(struct Actor *);
void func_0c0aeed8(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);zero=0;a->f56=a->f41c;a->b1f9=zero;a->b1a1=59;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,3);
}
void func_0c0aef46(struct Actor *a){table_0c2448c0[a->b7](a);}
void func_0c0aef58(struct Actor *a)
{
 struct LinkedActorVec3 position;int zero;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);zero=0;
 if(a->b141){a->b141=zero;a->b3f0=zero;a->b3f1=zero;position.x=-26.666666031f;position.y=171.42856f;position.z=0;func_0c0429a4(a,&position,1);}
 if(a->b140){a->b7++;a->s28=120;if(!(a->p20=func_0c1536c0(a,0))){a->b6++;a->b7=zero;func_0c02a0c4(a,22,4);}}
}
