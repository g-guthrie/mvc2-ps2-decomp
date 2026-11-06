#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c0451f2(struct Actor *),func_0c18c344(struct Actor *,int),func_0c18c56c(struct Actor *);
extern int func_0c1318e4(struct Actor *,int,float,float);
extern int func_0c047bbe(struct Actor *);
extern void func_0c0429a4(struct Actor *,void *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c23f3e0[])(struct Actor *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c053d00(struct Actor *a)
{
 int zero,n;float x,y;
 a->b3f8=2;a->b328=5;
 func_0c02a026(a);
 if(a->b141){
  a->b141=0;a->b6++;
  if(a->b1f9!=2){zero=0;x=195.0f;y=113.57143f;n=0;}
  else{zero=0;x=173.33333f;y=154.28571f;n=1;}
  func_0c18c344(a,n);
  if(func_0c1318e4(a,zero,x,y)==0);
 }
}
void func_0c053d74(struct Actor *a,struct ActorSubMoveBytes *s)
{
 a->b3f8=2;a->b328=5;
 func_0c02a026(a);
 if(s->b3>=0){if(func_0c047bbe(a)){s->b3--;a->s28++;}}
 if(--a->s28>0)return;
 a->b6++;
 a->b3f8=a->b3f9=0;
 a->b328=a->b327=0;
 if(a->b1f9!=2)func_0c02a0c4(a,22,5);
 else func_0c02a0c4(a,22,7);
}
void func_0c053dfa(struct Actor *a)
{
 if(func_0c02a026(a)<0){
  if(a->b1f9!=2)func_0c0437b8(a);
  else func_0c0438de(a);
 }
}
void func_0c053e64(struct Actor *a){table_0c23f3e0[a->b6](a);}
void func_0c053e76(struct Actor *a)
{
 if(a->b14b){
  int zero=0;unsigned char action=a->b14b;a->b14b=zero;
  a->b1a1=action;CLEAR_RECORD;a->w1ac=16;
 }
}
void func_0c053eb0(struct Actor *a)
{
 if(a->b14b){
  int zero=0;unsigned char action=a->b14b;a->b14b=zero;
  a->b1a1=action;CLEAR_RECORD;
 }
}
void func_0c053ee4(struct Actor *a)
{
 void *zero;float fz;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;func_0c0442fa(a);func_0c0432ca(a);
 zero=0;fz=0.0f;
 a->f56=a->f41c;a->b1f9=(int)zero;a->b1a1=81;
 a->w1ac=(int)zero;a->b19e=(int)zero;*(void **)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->w1ac=16;
 a->f92=fz;a->f104=fz;a->f96=8.5714283f;a->f108=-1.07142854f;
 func_0c02a0c4(a,22,(int)zero);
}
void func_0c053f76(struct Actor *a)
{
 struct {float x,y,z;} v;int zero;
 a->b3f8=2;a->b328=5;
 a->b3f1=a->b255==6?2:0;
 func_0c02a026(a);
 if(a->b140){
  zero=0;a->b6++;a->b140=zero;a->b3f0=zero;a->b3f1=zero;
  v.x=80.0f;v.y=137.142853f;v.z=0.0f;
  func_0c0429a4(a,&v,1);
 }
}
void func_0c05401a(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 func_0c02a026(a);
 if(a->b141){a->b141=0;a->b6++;func_0c0451f2(a);}
}
void func_0c054054(struct Actor *a)
{
 register float previous;
 a->b3f8=2;a->b328=5;
 previous=a->f96;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;
 a->f96+=a->f108;if(previous*(float)a->f96>0.0f){func_0c02a026(a);return;}
 a->b6++;a->s28=8;func_0c18c56c(a);
 func_0c02a0c4(a,22,1);
}
void func_0c0540d4(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){
  if(--a->s28>0)return;
  a->b6++;
  func_0c02a0c4(a,22,8);
  return;
 }
 a->f56+=-0.13392857f;
 func_0c053e76(a);
}
void func_0c054158(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){
  a->b6++;
  func_0c02a0c4(a,22,2);
  a->b3f8=a->b3f9=0;
  a->b328=a->b327=0;
  return;
 }
 a->f56+=-0.13392857f;
 func_0c053eb0(a);
}
void func_0c0541ba(struct Actor *a)
{
 MOVE;
 if(!(a->f56>a->f41c)){
  a->b6++;a->f56=a->f41c;a->b1f9=0;
  func_0c02a0c4(a,22,3);
  return;
 }
 func_0c02a026(a);
}
void func_0c054220(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c054242(struct Actor *a)
{
 if(!a->b6){a->b6++;func_0c02a0c4(a,20,6);}
 else if(func_0c02a026(a)<0)func_0c0437b8(a);
}
