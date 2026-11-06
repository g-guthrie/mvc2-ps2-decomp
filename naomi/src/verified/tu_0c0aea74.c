#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0432ca(struct Actor *),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct LinkedActor *func_0c1a390c(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2448a4[])(struct Actor *);
void func_0c0aea74(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0;a->f104=0;func_0c0437b8(a);}
void func_0c0aea9e(struct Actor *a){table_0c2448a4[a->b6](a);}
void func_0c0aeab0(struct Actor *a)
{
 int zero=0,two=2;unsigned char three=3,five=5;register float fzero=0;struct LinkedActorVec3 p;
 switch(a->b7){
 case 0:
  if(a->b255==6){a->b3f0=255;a->b3f1=16;}
  a->b7++;a->b1f9=zero;a->f56=a->f41c;a->f92=fzero;a->f96=fzero;a->f104=fzero;a->f108=fzero;
  a->b1a1=56;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->w1ac=16;
  func_0c0442fa(a);func_0c02a0c4(a,22,0);func_0c0432ca(a);break;
 case 1:
  a->b3f8=two;a->b328=five;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
  if(a->b141){a->b3f0=zero;a->b3f1=zero;a->b7++;a->b141=zero;p.x=fzero;p.y=102.85714f;p.z=fzero;func_0c0429a4(a,&p,1);}
  break;
 case 2:
  a->b1f5=three;a->b3f8=two;a->b328=five;func_0c02a026(a);
  if(a->b141){a->b7++;a->b141=zero;a->b142=two;func_0c1a390c((struct LinkedActor *)a);}
  break;
 case 3:
  a->b1f5=three;a->b3f8=two;a->b328=five;
  if(func_0c02a026(a)<0){a->b6++;a->b7=zero;a->s28=60;a->s30=40;a->f104=34;a->f108=fzero;*(struct LinkedActorVec3 *)&a->f80=a->v284;func_0c02a0c4(a,22,1);}
  break;
 }
}
