/* Linked effect attach/fall handlers 0x0c143098-0x0c143358; 0c143098 resumes after a mid-function pool. */
#include "objects.h"
#define L(a) ((struct LinkedActor *)(a))
struct OwnerOffset_143098 { unsigned char pad0[6]; char b6; unsigned char pad7[5]; float f12, f16; };
struct Box4_143098 { unsigned char b0, b1, b2, b3; };
struct BoxAt13c_143098 { unsigned char pad[0x13c]; struct Box4_143098 box; };
struct Speed_143098 { int x, y; };
extern struct Box4_143098 dat_0c24f8b0[];
extern int dat_0c24f8bc[];
extern unsigned char dat_0c24f8d4[];
extern unsigned char dat_0c24f8d7[];
extern char func_0c02a026(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c197cc4(struct Actor *,int,int,int);
extern void func_0c0445fe(struct Actor *,struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,char);
extern void func_0c037d0c(struct Actor *);

void func_0c143098(struct Actor *a,struct Actor *o)
{
 struct OwnerOffset_143098 *sub=(struct OwnerOffset_143098 *)&o->sub2a4;
 struct Actor *t;
 int n;
 unsigned char *p;
 int *q;
 a->b36=o->b36;
 L(a)->b49=8;
 if(o->b5==0&&o->b1d0==21&&o->b1e9==2){
  a->f52=o->f52+sub->f12;
  a->f56=o->f56+sub->f16;
  if(func_0c02a026(a)>=0){
   if(a->b19e){
    if(func_0c0447bc(a)){
     t=a->p1b0;
     func_0c197cc4(o,10,L(a)->b1a3,a->b141);
     sub->b6=1;
     o->b1ed=32;
     o->b19d=0;
     o->b1f7=0xc3;
     o->b15a=-1;
     func_0c0445fe(a,t);
     a->b4=2;
     t->b1f4=2;
     return;
    }
    a->b5=2;
    sub->b6=-1;
    n=dat_0c24f8d7[L(a)->b1a3]+a->b141;
    goto call;
   }
   func_0c037d0c(a);
   return;
  }
 }
 a->b5++;
 sub->b6=-1;
 p=&dat_0c24f8b0[L(a)->b1a3].b0;
 a->b13c=*p++;
 a->b13d=*p++;
 a->b13e=*p++;
 a->b13f=*p;
 q=&dat_0c24f8bc[L(a)->b1a3*2];
 a->f92=(float)*q++*1.66666663f/65536.0f;
 a->f96=(float)*q*1.66666663f/65536.0f;
 a->f104=0.0f;
 a->f108=0.0f;
 if(a->w130)a->f92=-a->f92;
 n=dat_0c24f8d4[L(a)->b1a3]+a->b141;
 call:
 func_0c02a0c4(a,23,n);
}

void func_0c143272(struct Actor *a,struct Actor *o)
{
 struct OwnerOffset_143098 *sub=(struct OwnerOffset_143098 *)&o->sub2a4;
 int n;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 if(!func_0c02850e(a)){a->b4=2;a->b12c=0;return;}
 if(a->b19e){
  a->b5=2;
  sub->b6=-1;
  n=dat_0c24f8d7[L(a)->b1a3]+a->b141;
  func_0c02a0c4(a,23,n);
  return;
 }
 func_0c037d0c(a);
}
