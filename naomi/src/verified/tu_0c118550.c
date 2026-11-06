#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c179a48(struct Actor *,int,int);
extern int func_0c17a03c(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24cb6c[])(struct Actor *),(*table_0c24cb74[])(struct Actor *),(*table_0c24cb7c[])(struct Actor *);
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c1185c2(struct Actor *a,struct ActorSub2a4 *b);
void func_0c118752(struct Actor *a);
void func_0c11870a(struct Actor *a,struct ActorSub2a4 *b);
void func_0c1188c2(struct Actor *a,struct ActorSub2a4 *b);

void func_0c118550(struct Actor *a,struct ActorSub2a4 *b)
{
 int zero;
 a->b7++;
 func_0c048bb0(a,5);
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=50;
 zero=0;
 CLEAR_RECORD;
 func_0c02a0c4(a,21,11);
 func_0c1185c2(a,b);
}

void func_0c1185c2(struct Actor *a,struct ActorSub2a4 *b)
{
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->b141&1){
  a->b141&=0xfe;
  func_0c179a48(a,0,0);
  func_0c179a48(a,0,1);
 }
}

void func_0c11860e(struct Actor *a){table_0c24cb6c[a->b7](a);}

void func_0c118620(struct Actor *a)
{
 if(a->b1f9==2)a->b6=1;
 table_0c24cb74[a->b6](a);
}

void func_0c118642(struct Actor *a,struct ActorSub2a4 *b)
{
 void *zero;
 if(a->b201){func_0c118752(a);return;}
 a->b6++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 if(a->b1f9!=2)func_0c0432ca(a);
 zero=0;
 a->b201=1;
 b->w4=480;
 a->b1f9=2;
 a->b1fc=(int)zero;
 a->b1d4=(int)zero;
 a->pad7f2=(int)zero;
 a->f92=0.0f;a->f104=0.0f;
 a->f96=12.85714245f;
 a->f108=-0.2678571343422f;
 func_0c02a0c4(a,26,(int)zero);
 func_0c11870a(a,b);
}

void func_0c11870a(struct Actor *a,struct ActorSub2a4 *b)
{
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(func_0c02a026(a)<0){
  a->f96=0.0f;a->f108=0.0f;
  func_0c0437b8(a);
 }
}

void func_0c118752(struct Actor *a)
{
 a->b201=0;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f108=-0.80357140303f;
 func_0c0438de(a);
}

void func_0c118776(struct Actor *a){table_0c24cb7c[a->b6](a);}

void func_0c118788(struct Actor *a)
{
 if((unsigned char)a->b159==26){
  func_0c0442fa(a);
  if(a->b201){
   a->f92/=8.0f;a->f104/=8.0f;a->f96/=8.0f;a->f108/=8.0f;
  }else{
   a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
   a->f108=-0.80357140303f;
  }
 }
}

void func_0c118824(register struct Actor *a,struct ActorSub2a4 *b0)
{
 register struct ActorSub2a4 *b=b0; void *zero;
 if(a->b255==6){a->b3f0=0xff;a->b3f1=16;}
 a->b6++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 func_0c0432ca(a);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 zero=0;
 a->b1f9=(int)zero;
 a->f56=a->f41c;
 b->b3=(int)zero;
 b->b6=(int)zero;
 a->b1a1=61;
 a->w1ac=(int)zero;a->b19e=(int)zero;*(void **)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,22,(int)zero);
 func_0c1188c2(a,b);
}

void func_0c1188c2(struct Actor *a,struct ActorSub2a4 *b)
{
 int zero;
 a->b3f8=2;
 a->b328=5;
 a->b3f1=a->b255==6?2:0;
 func_0c02a026(a);
 if(a->b141){
  zero=0;
  a->b141=zero;
  if(!func_0c17a03c(a,zero,zero)){func_0c0437b8(a);return;}
 }
 if(b->b3){
  a->b6++;
  func_0c02a0c4(a,22,1);
 }
}
