#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c044548(struct Actor *,struct Actor *),func_0c025900(struct Actor *,int,int),func_0c025762(void);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a18c(struct Actor *,int,int,int),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c044f1c(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24ad84[])(struct Actor *),(*table_0c24ad90[])(struct Actor *),(*table_0c24ada0[])(struct Actor *);

void func_0c0fe110(struct Actor *a)
{
 int zero;float gravity;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 zero=0;
 if(a->b19e){
  gravity=-1.07142854f;
  if(func_0c0447bc(a)){
   a->b7++;a->b19d=zero;a->b1f7=194;a->b15a=-1;a->b1ea=1;a->b1f2=3;
   func_0c044548(a,a->p1b0);
   a->f92=-5.0f;a->f104=0.0f;a->f96=12.85714245f;a->f108=gravity;
   if(a->b1d2)a->f92=-a->f92;
   func_0c02a0c4(a,15,5);func_0c025900(a,5,5);
  }else{
   a->b6++;a->b7=1;a->f92=-(a->f92/8.0f);a->f96=17.142857f;
   a->f104=0.0f;a->f108=gravity;func_0c02a0c4(a,21,10);
  }
 }else if(a->f56<a->f41c){
  a->b6++;a->b7=zero;a->f56=a->f41c;a->b1f9=zero;
  a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
  func_0c02a0c4(a,1,3);func_0c043324(a);
 }
}
void func_0c0fe2b6(struct Actor *a)
{
 a->b1f2=3;a->b1ea=1;func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f96<0.0f && a->f56<a->f41c){
  a->b7++;a->f56=a->f41c;a->b1f9=0;
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  func_0c02a0c4(a,15,6);func_0c043324(a);
 }
}
void func_0c0fe358(struct Actor *a)
{
 a->b1f2=3;a->b1ea=1;
 if(func_0c02a026(a)<0){
  struct Actor *child=a->p1c8;
  child->p1b4=a;child->b1f6=1;child->b1a1=52;
  a->b34=25;if(a->b1d2)a->b34=32-a->b34;
  func_0c025762();a->b6++;a->b7=0;func_0c02a0c4(a,21,9);
 }
}
void func_0c0fe3c6(struct Actor *a)
{
 if(!a->b7){if(func_0c02a026(a)<0)func_0c0437b8(a);}
 else{
  func_0c02a026(a);
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(a->f96<0.0f && a->f56<a->f41c){
   a->b1f9=0;a->f56=a->f41c;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
   func_0c044f1c(a);
  }
 }
}
void func_0c0fe488(struct Actor *a){table_0c24ad84[a->b6](a);}
void func_0c0fe49a(struct Actor *a){table_0c24ad90[a->b7](a);}
void func_0c0fe4ac(struct Actor *a)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b7++;zero=(a->b1f9=0);a->f56=a->f41c;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a1=53;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;a->w1ac=16;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,22,zero);
}
void func_0c0fe534(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){
  a->b3f0=0;a->b3f1=0;a->b7++;position.x=0;position.y=205.71428f;
  func_0c0429a4(a,&position,1);
 }
}
void func_0c0fe5ca(struct Actor *a)
{
 a->b3f8=2;a->b328=5;a->b7++;func_0c02a18c(a,22,0,7);
}
void func_0c0fe5e6(struct Actor *a)
{
 int zero=0;
 a->b3f8=2;a->b328=5;a->b6++;a->b7=zero;a->s28=20;a->s30=zero;
 func_0c02a0c4(a,22,1);
}
void func_0c0fe612(struct Actor *a){a->b1f5=2;table_0c24ada0[a->b7](a);}
