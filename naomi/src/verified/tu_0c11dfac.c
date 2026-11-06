#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c17ed28(struct Actor *,int,int),func_0c0346da(struct Actor *,int);
extern void func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c11c5e4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24d0dc[])(struct Actor *);
void func_0c11dfac(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;position.x=133.33333f;position.y=85.71428f;func_0c043014(a,&position);}
 if(a->b140){a->b140=0;func_0c17ed28(a,7,1);func_0c0346da(a,22);}
}
void func_0c11e014(struct Actor *a)
{
 int zero=0;
 if(a->b6==0){
  float stopped;
  a->b6++;stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  a->b1f9=zero;a->f56=a->f41c;
  if(a->b255==3)a->b1a1=64;else{goto s;s:a->b1a1=66;}
  a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
  goto c;c:func_0c02a39a(a,0);func_0c0442fa(a);func_0c02a0c4(a,21,27);
  return;
 }
 goto d;d:if(a->b141){a->b141=zero;func_0c17ed28(a,6,0);}
 func_0c11c5e4(a);
}
void func_0c11e0b6(struct Actor *a){table_0c24d0dc[a->b6](a);}
