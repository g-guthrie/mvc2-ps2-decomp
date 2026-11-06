#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define SEG(a) ((struct LinkedActorSegment88 *)&(a)->pad9b[0])
extern struct LinkedActor *func_0c0374da(struct LinkedActor *,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct Dat_13bb5c dat_0c2f8338;
extern void (*table_0c251fa4[])(struct LinkedActor *,struct LinkedActor *,struct LinkedActorSegment88 *);
extern void (*table_0c251fb4[])(struct LinkedActor *,struct LinkedActorSegment88 *,struct LinkedActorSegment88 *);
extern void (*table_0c251fc4[])(struct LinkedActor *,struct LinkedActor *,struct LinkedActorSegment88 *);
void func_0c167520(struct LinkedActor *a);
struct LinkedActor *func_0c16741c(struct LinkedActor *owner,float x,float y)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){
  int zero=0;
  a->p16=(void (*)(struct LinkedActor *))func_0c167520;a->b32=zero;a->p24=owner;a->w38=0x2201;
  if(A(owner)->b1d2)x=-x;
  SEG(a)->w12=owner->sdc.w158.short_value;SEG(a)->b10=zero;SEG(a)->f8=x;SEG(a)->fc=y;
 }
 return a;
}
void func_0c16747a(struct LinkedActor *owner,struct LinkedActorSegment88 *s)
{
 char i;unsigned char n;struct LinkedActor *c;
 n=0;for(i=0;i<12;i++){
  if((c=func_0c0374da(owner,1,2))){
   c->p16=(void (*)(struct LinkedActor *))func_0c167520;c->b32=1;c->p24=owner;c->w38=0x2201;
   SEG(c)->b6=n;n++;SEG(c)->b10=s->b10;
  }
 }
}
void func_0c1674e6(struct LinkedActor *a,struct LinkedActorSegment88 *s)
{
 float v;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 v=(float)(s->b6<<5)*1.66666663f;
 if(!A(a)->w130)v=-v;
 a->f52+=v;
}
void func_0c167520(struct LinkedActor *a)
{
 struct LinkedActorSegment88 *s=SEG(a),*ref;
 if(!a->b32)table_0c251fa4[a->b4](a,a->p24,s);
 else{ref=SEG(a->p24);func_0c1674e6(a,s);a->b36=a->p24->b36;table_0c251fb4[a->b4](a,s,ref);}
}
void func_0c1675a0(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActorSegment88 *s)
{
 a->f52=owner->f52;a->f56=owner->f56;a->f52+=s->f8;a->f56+=s->fc;
}
void func_0c1675ca(struct LinkedActor *a,struct LinkedActorSegment88 *s)
{
 if(s->b2<12&&--s->b3<=0){s->b3=2;s->b2++;}
}
void func_0c1675ee(struct LinkedActor *a,struct LinkedActorSegment88 *s)
{
 if(--a->s28<=0){a->s28=2;s->b0++;if(s->b0>=8)s->b0=5;}
}
void func_0c167614(struct LinkedActor *a,struct LinkedActorSegment88 *s)
{
 if(--a->s28<=0){a->s28=2;s->b0--;}
}
void func_0c16762e(struct LinkedActor *a,struct LinkedActorSegment88 *s,struct LinkedActorSegment88 *ref)
{
 if(s->b0!=ref->b0){
  s->b0=ref->b0;
  {int t=s->b0*3,off=0;if(s->b6)off=s->b1;off+=t;func_0c02a0c4(a,25,off);}
 }
}
void func_0c16766c(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActorSegment88 *s)
{
 int zero,two;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 zero=0;a->sdc.b12c=zero;
 func_0c1675a0(a,owner,s);
 a->b49=-16;s->b0=s->b7=zero;two=2;a->s28=two;a->pad11[0]=66;a->pad11[1]=66;s->b2=zero;s->b3=two;
 func_0c16747a(a,s);
}
void func_0c167712(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActorSegment88 *s)
{
 a->b36=owner->b36;func_0c1675a0(a,owner,s);table_0c251fc4[(unsigned char)a->b5](a,owner,s);
}
void func_0c167748(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActorSegment88 *s)
{
 int zero=0,four,two;
 if((unsigned char)A(owner)->b159!=22){a->b4++;a->sdc.b12c=zero;return;}
 four=4;two=2;
 if((unsigned char)A(owner)->b158!=12){a->b5++;s->b0=four;a->s28=two;return;}
 if(!(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))){
  s->b7=zero;
  if(owner->s28<=0){a->b5++;s->b0=four;a->s28=two;}
  func_0c1675ca(a,s);func_0c1675ee(a,s);
 }
}
void func_0c1677ec(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActorSegment88 *s)
{
 int zero=0;
 if((unsigned char)A(owner)->b159!=22){a->b4++;a->sdc.b12c=zero;return;}
 s->b7=zero;func_0c167614(a,s);
 if(s->b0<0)a->b4++;
}
void func_0c16782e(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
void func_0c16783a(struct LinkedActor *a){func_0c037688(a);}
void func_0c167840(struct LinkedActor *a,struct LinkedActorSegment88 *s,struct LinkedActorSegment88 *ref)
{
 int zero;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 zero=0;a->sdc.b12c=zero;a->pad11[0]=66;a->pad11[1]=66;a->b49=-16;
 s->b0=-1;s->b5=zero;s->b1=1;
 A(a)->b1a1=85;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c16762e(a,s,ref);
}
void func_0c167918(struct LinkedActor *a,struct LinkedActorSegment88 *s,struct LinkedActorSegment88 *ref)
{
 int two=2,zero=0,one;
 if(a->p24->b4>=2){a->b4++;a->sdc.b12c=zero;func_0c037688(a);return;}
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 one=1;s->b1=one;a->sdc.b12c=one;
 if(ref->b2<s->b6){a->sdc.b12c=zero;return;}
 if(ref->b2==s->b6){s->b1=two;s->b0=-1;a->sdc.b12c=one;}
 if(A(a)->b19e){
  s->b1=one;s->b0=-1;ref->b7=255;
  if((char)--A(a)->b1a0==0){
   int e=86;
   if(++s->b5>=3){s->b5=zero;e=85;}
   A(a)->b1a1=e;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
  }
 }
 func_0c16762e(a,s,ref);
 if(!ref->b7)func_0c037d0c(a);
}
void func_0c167a06(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
void func_0c167a12(struct LinkedActor *a){func_0c037688(a);}
