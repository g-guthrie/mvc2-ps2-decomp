#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043352(struct Actor *),func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Actor *func_0c16db78(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24adac[])(struct Actor *,struct ActorSub2a4 *),(*table_0c24adb8[])(struct Actor *),(*table_0c24adc4[])(struct Actor *);
void func_0c0fea38(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;if(a->f92>0)func_0c043352(a);
 if(a->b141){a->b141=0;a->f92=0;a->f104=0;}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0fea9a(struct Actor *a){table_0c24adac[a->b6](a,&a->sub2a4);}
void func_0c0feab0(struct Actor *a)
{
 int zero=0;register float fzero=0;struct LinkedActorVec3 position;
 if(!a->b7){
  if(a->b255==6){a->b3f0=255;a->b3f1=16;}
  a->b7++;a->b1f9=zero;a->f56=a->f41c;a->f92=fzero;a->f96=fzero;a->f104=fzero;a->f108=fzero;
  a->b1a1=57;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
  func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,22,9);
 }else{
  a->b3f8=2;a->b328=5;func_0c02a026(a);
  if(a->b141){a->b3f0=zero;a->b3f1=zero;a->b6++;a->b7=zero;a->b141=zero;position.x=fzero;position.y=205.71428f;func_0c0429a4(a,&position,1);}
 }
}
void func_0c0febbe(struct Actor *a,struct ActorSub2a4 *state)
{
 int zero;
 a->b3f8=2;a->b328=5;func_0c02a026(a);zero=0;
 if(!a->b7){if(a->b141){a->b7++;a->b141=zero;func_0c16db78(a,1);}}
 else if(!state->b0){a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;a->b7=zero;func_0c02a0c4(a,22,10);}
}
void func_0c0fec3e(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0fec60(struct Actor *a){table_0c24adb8[a->b6](a);}
void func_0c0fec72(struct Actor *a){table_0c24adc4[a->b7](a);}
