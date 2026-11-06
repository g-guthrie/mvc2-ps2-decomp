#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c047be4(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c02a39a(struct Actor *,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c1b80d8(struct Actor *,int),func_0c173a04(struct Actor *),func_0c10c188(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24b960[])(struct Actor *);
void func_0c10a3b4(struct Actor *);
void func_0c10a270(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);
 zero=0;a->b1a1=54;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 a->b1f9=zero;a->s28=128;a->s30=30;a->f56=a->f41c;func_0c02a0c4(a,21,4);func_0c0344a0(a,20);func_0c10a3b4(a);
}
void func_0c10a2f2(struct Actor *a)
{
 struct LinkedActorVec3 position;int zero;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);a->s28--;
 if(a->b141){zero=0;a->b3f0=zero;a->b3f1=zero;a->b6++;a->b141=zero;func_0c02a39a(a,1);
  *(unsigned int *)&a->sub2a4=zero;position.x=41.666664124f;position.y=186.42856f;func_0c0429a4(a,&position,1);}
}
void func_0c10a3b4(struct Actor *a)
{
 int zero;
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(--a->s28<0){zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;func_0c02a0c4(a,21,5);}
 else{zero=0;
  if(func_0c047be4(a)){if(--a->s30>=0)a->s28++;}
  if(a->b141){a->b141=zero;func_0c0344a0(a,31);func_0c1b80d8(a,1);}
  if(a->b140){a->b140=zero;func_0c173a04(a);}
 }
}
void func_0c10a456(struct Actor *a){if(func_0c02a026(a)<0){func_0c0344a0(a,43);func_0c10c188(a);}}
void func_0c10a47e(struct Actor *a){table_0c24b960[a->b6](a);}
