#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c025900(struct Actor *,int,int),func_0c13b9cc(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0437b8(struct Actor *),func_0c025762(void);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*dat_0c24dda8[])(struct Actor *,struct ActorSub2a4 *);
void func_0c12c0d8(struct Actor *a){dat_0c24dda8[a->b7](a,&a->sub2a4);}
void func_0c12c0ee(struct Actor *a,struct ActorSub2a4 *sub)
{
 int zero,anim;
 struct Actor *o;
 float x,stopped;
 void (*f)(struct Actor *,int,int);
 a->b3f8=2;
 a->b328=5;
 a->f52+=a->f92;
 a->f92+=a->f104;
 func_0c02a026(a);
 f=func_0c02a0c4;
 zero=0;
 if(a->b1fd){if((signed char)a->b1fd!=1<<a->b1d2){
  a->b3f9=zero;
 a->b3f8=zero;
 a->b327=zero;
 a->b328=zero;
 a->b6++;
 a->b7=zero;
  goto LB1_27; LB1_27:
  f(a,22,3);
  goto LB0_28; LB0_28:
  return;
 }}
 if(!a->b19e)return;
 o=a->p1b0;
 stopped=0.0f;
 if(!o->b3&&!(a->b19e&1)&&o->b1f9!=3&&o->b5==3){
  a->b7++;
  o->b1f9=zero;
  func_0c025900(a,8,8);
  *(struct Actor **)&sub->w4=o;
  sub->w8=zero;
  *(struct LinkedActorVec3 *)&o->f52=*(struct LinkedActorVec3 *)&a->f52;
  x=-100.0f;
  if(a->b1d2)x=100.0f;
  o->f52+=x;
  a->f92=stopped;
  a->f104=stopped;
  anim=1;
 }else{
  a->b3f9=zero;
 a->b3f8=zero;
 a->b327=zero;
 a->b328=zero;
 a->b6++;
 a->b7=zero;
  a->f92=stopped;
 a->f96=stopped;
 a->f104=stopped;
 a->f108=stopped;
  anim=4;
 }
 f(a,22,anim);
}
void func_0c12c268(struct Actor *a,struct ActorSub2a4 *sub)
{
 float x;
 a->b3f8=2;
 a->b328=5;
 sub->w8++;
 a->b1f5=2;
 if(!a->b19e){func_0c0437b8(a);return;}
 if(func_0c02a026(a)>=0){
  if(a->b141){
   int zero;
   a->b1a1=a->b141;
   zero=0;
   a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
   a->b141=zero;
   if(a->b140){func_0c0344a0(a,(signed char)a->b140+29);a->b140=zero;}
   {struct Actor *o=*(struct Actor **)&sub->w4;if(!o->b202)o->f56+=4.28571415f;}
  }
  return;
 }
 a->b7++;
 func_0c025762();
 func_0c13b9cc(a);
 x=-80.0f;
 if(a->b1d2)x=80.0f;
 a->f52+=x;
 a->f56+=68.57143f;
 func_0c02a0c4(a,22,2);
}
