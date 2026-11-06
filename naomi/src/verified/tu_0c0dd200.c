#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c248c94[];
extern float dat_0c248c8c[];
extern void (*table_0c248e88[])(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int);
extern void func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c0432ca(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);

void func_0c0dd200(struct Actor *a)
{
 float speed;
 a->b6++;a->b1a1=((unsigned char)a->b1a3<<1)+90;
 a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c048bb0(a,4);func_0c0442fa(a);
 a->s28=dat_0c248c94[(unsigned char)a->b1a3];
 speed=dat_0c248c8c[(unsigned char)a->b1a3];
 if(a->b1d2){
  speed=-speed;
  if(a->f92<0.0f)goto reverse;
  goto apply;
 }
 if(a->f92>0.0f){
reverse:
  speed=-speed;
 }
apply:
 a->f92+=speed;a->f104=0;
 func_0c02a0c4(a,21,a->b1a3+25);
}

void func_0c0dd2a6(struct Actor *a)
{
 if(func_0c02a026(a)<0 && --a->s28<=0){a->b6=3;func_0c02a0c4(a,21,34);return;}
 if(a->b14b){
  a->b1a1=a->b14b;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;a->b14b=0;
 }
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
  a->b6=2;a->b1a1=93;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;a->b1f9=0;
  func_0c02a0c4(a,21,34);func_0c043324(a);
 }
}

void func_0c0dd3c8(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b1d2^=1;func_0c0437b8(a);}
}

void func_0c0dd3f2(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c)func_0c0437b8(a);
 else if(func_0c02a026(a)<0)func_0c0438de(a);
}

void func_0c0dd486(struct Actor *a){table_0c248e88[a->b6](a);}

void func_0c0dd498(struct Actor *a)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;a->b1a1=71;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c02a39a(a,0);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->s28=30;a->b1f9=0;
 a->f92=a->b1d2?10.0f:-10.0f;
 func_0c02a0c4(a,22,1);func_0c0432ca(a);
}

void func_0c0dd536(struct Actor *a)
{
 struct LinkedActorVec3 v;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;
 func_0c02a026(a);
 if(a->b141&1){
  a->b141&=254;a->b6++;a->b3f0=0;a->b3f1=0;
  v.x=26.666666031f;v.y=145.71428f;v.z=0;
  func_0c0429a4(a,&v,1);
 }
}
