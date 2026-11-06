#include "objects.h"
struct Launch2469c4 { int x, y; };
struct Anim2469e4 { char id, pad; };
extern struct Launch2469c4 dat_0c2469c4[];
extern struct Anim2469e4 dat_0c2469e4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int);
extern void func_0c0451f2(struct Actor *),func_0c0432ca(struct Actor *),func_0c1a9cf0(struct Actor *,int),func_0c0346da(struct Actor *,int),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c043014(struct Actor *,struct LinkedActorVec3 *);
extern void (*table_0c2469ec[])(struct Actor *),(*table_0c2469f4[])(struct Actor *),(*table_0c246a10[])(struct Actor *),(*table_0c246a24[])(struct Actor *),(*table_0c246a2c[])(struct Actor *);
void func_0c0c223c(struct Actor *a);
void func_0c0c23f8(struct Actor *a);
void func_0c0c2526(struct Actor *a);
void func_0c0c263e(struct Actor *a);
void func_0c0c20a8(struct Actor *a){table_0c2469ec[a->b6](a);}
void func_0c0c20ba(struct Actor *a){table_0c2469f4[a->b7](a);}
void func_0c0c20cc(register struct Actor *a)
{
 if(a->b1f9==2){
  a->b6++;
  func_0c0c23f8(a);
  return;
 }
 a->b7++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->f56=a->f41c;
 a->b1fc=0;a->b1f9=0;
 func_0c048bb0(a,5);
 if(a->b1d2==0){
  a->f92=dat_0c2469c4[(unsigned char)a->b1a3].x*1.66666663f/65536.0f;
  a->f104=0.72916663f;
 }else{
  a->f92=-(dat_0c2469c4[(unsigned char)a->b1a3].x*1.66666663f/65536.0f);
  a->f104=-0.72916663f;
 }
 a->f96=dat_0c2469c4[(unsigned char)a->b1a3].y*2.1428571f/65536.0f;
 a->f108=-0.9375f;
 a->b1a1=dat_0c2469e4[(unsigned char)a->b1a3].id;
 a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+3);
 func_0c0c223c(a);
}
void func_0c0c223c(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b7++;
  a->b141=0;
  if(!a->b1d2) a->f52+=-13.33333302f; else a->f52+=13.33333302f;
 }
}
void func_0c0c2280(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b7++;
  a->b141=0;
  if(!a->b1d2) a->f52+=-40.0f; else a->f52+=40.0f;
 }
}
void func_0c0c22c4(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b7++;
  func_0c0451f2(a);
  a->b140=0;
  func_0c0432ca(a);
  func_0c1a9cf0(a,8);
  func_0c0346da(a,75);
 }
}
void func_0c0c2308(struct Actor *a)
{
 int prev,cur;
 func_0c02a026(a);
 func_0c0c263e(a);
 prev=(int)a->f92;
 a->f52+=a->f92;
 a->f92+=a->f104;
 cur=(int)a->f92;
 if((prev^cur)<0) a->b7++;
}
void func_0c0c2378(struct Actor *a)
{
 func_0c02a026(a);
 func_0c0c263e(a);
 if(!(a->f41c<a->f56)){
  a->b7++;
  a->b1f9=0;
  a->f56=a->f41c;
  func_0c043324(a);
  func_0c02a0c4(a,21,a->b1a3+6);
 }
}
void func_0c0c23c4(struct Actor *a)
{
 if(func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0c23e6(struct Actor *a){table_0c246a10[a->b7](a);}
void func_0c0c23f8(struct Actor *a)
{
 a->b7++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 func_0c048bb0(a,5);
 if(a->b1d2==0){
  a->f92=(&dat_0c2469c4[2])[(unsigned char)a->b1a3].x*1.66666663f/65536.0f;
  a->f104=0.72916663f;
 }else{
  a->f92=-((&dat_0c2469c4[2])[(unsigned char)a->b1a3].x*1.66666663f/65536.0f);
  a->f104=-0.72916663f;
 }
 a->f96=(&dat_0c2469c4[2])[(unsigned char)a->b1a3].y*2.1428571f/65536.0f;
 a->f108=-0.9375f;
 a->b1a1=(&dat_0c2469e4[2])[(unsigned char)a->b1a3].id;
 a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+16);
 func_0c0c2526(a);
}
void func_0c0c2526(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b7++;
  func_0c1a9cf0(a,8);
  func_0c0346da(a,75);
 }
}
void func_0c0c2558(struct Actor *a)
{
 int prev,cur;
 func_0c02a026(a);
 func_0c0c263e(a);
 prev=(int)a->f92;
 a->f52+=a->f92;
 a->f92+=a->f104;
 cur=(int)a->f92;
 if((prev^cur)<0) a->b7++;
}
void func_0c0c259c(struct Actor *a)
{
 func_0c02a026(a);
 func_0c0c263e(a);
 if(!(a->f41c<a->f56)){
  a->b7++;
  a->b1f9=0;
  a->f56=a->f41c;
  func_0c043324(a);
  func_0c02a0c4(a,21,a->b1a3+6);
 }
}
void func_0c0c261c(struct Actor *a)
{
 if(func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0c263e(struct Actor *a)
{
 int prev,cur;
 prev=(int)a->f96;
 a->f56+=a->f96;
 a->f96+=a->f108;
 cur=(int)a->f96;
 if((prev^cur)<0) a->f108=-1.60714281f;
}
void func_0c0c2674(struct Actor *a){table_0c246a24[a->b6](a);}
void func_0c0c2686(struct Actor *a)
{
 a->b6++;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1f9=0;
 a->f56=a->f41c;
 func_0c02a39a(a,0);
 func_0c0442fa(a);
 func_0c0432ca(a);
 a->b1a1=80;
 a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,15);
}
void func_0c0c26fc(struct Actor *a)
{
 struct LinkedActorVec3 p;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){
  a->b141=0;
  p.x=-58.3333321f;p.y=85.71428f;
  func_0c043014(a,&p);
 }
}
void func_0c0c2746(struct Actor *a){table_0c246a2c[a->b6](a);}
