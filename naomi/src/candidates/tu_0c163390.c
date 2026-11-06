/* Candidate: 1740/1748 bytes. func_0c163748 swaps fr5/fr6 between the
 * owner-offset constant (ox) and the target x (8 words at 0x0c1637b0-0x0c163848);
 * everything else, including all pools, matches retail. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define OWNER_STATE(o) (*(int *)&A(o)->pad10c[0x2e4 - 0x2cc])
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c1d330c(struct LinkedActor *,struct LinkedActorVec3 *,int,int);
extern void func_0c0346da(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02849a(void);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2f8338[];
extern float dat_0c251684[];
extern void (*table_0c251664[])(struct LinkedActor *);
extern void (*table_0c251674[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c251698[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c2516a4[])(struct LinkedActor *);
extern void (*table_0c2516b0[])(struct LinkedActor *,struct LinkedActor *);
void func_0c163440(struct LinkedActor *);
void func_0c163660(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c1639bc(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c163a30(struct LinkedActor *a,struct LinkedActor *owner);
#pragma inline(one)
static float one(void){return 1.0f;}
struct LinkedActor *func_0c163390(struct LinkedActor *owner,char kind){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c163440;a->p24=owner;a->b32=kind;a->b33=0;a->w38=0x1f03;}
 return a;
}
struct LinkedActor *func_0c1633ca(struct LinkedActor *owner,char kind,char sub){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c163440;a->p24=owner;a->b32=kind;a->b33=sub;a->w38=0x1f03;}
 return a;
}
void func_0c16340c(struct LinkedActor *a,struct LinkedActor *target){
 struct LinkedActorVec3 v;
 v.x=a->f52;v.y=a->f56;
 func_0c1d330c(target,&v,1,0xf9);
 func_0c0346da(target,7);
}
void func_0c163440(struct LinkedActor *a){table_0c251664[a->b32](a);}
void func_0c163454(struct LinkedActor *a){table_0c251674[a->b4](a,a->p24);}
void func_0c163484(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one;float x,tx,top;struct Actor *p;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b36=A(owner)->p1c8->b36;a->b49=-1;a->f52=owner->f52;a->f56=owner->f56;
 x=dat_0c251684[(unsigned char)a->b33];
 if(A(owner)->w130)x=-x;
 p=A(owner)->p1c8;
 tx=p->f52-x;top=p->f41c+51.42857f;
 a->f92=(tx-a->f52)/32.0f;a->f104=0;
 a->f96=(top-a->f56)/32.0f+12.85714245f;a->f108=-0.80357140303f;
 a->s28=32;func_0c02a0c4(a,23,17);func_0c163660(a,owner);
}
void func_0c1635a8(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(--a->s28<0){
  a->b5++;OWNER_STATE(owner)=(unsigned char)a->b33+1;
  if((unsigned char)a->b33==4)OWNER_STATE(owner)=-1;
 }
}
void func_0c16362a(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c02a026(a);a->b5++;a->sdc.b12c=0;func_0c16340c(a,owner);a->b5=0;func_0c163a30(a,owner);
}
void func_0c16365c(void){}
void func_0c163660(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(A(owner)->b411 && a->b4<2){func_0c16340c(a,owner);func_0c037688(a);return;}
 table_0c251698[(unsigned char)a->b5](a,owner);
}
void func_0c1636ac(struct LinkedActor *a,struct LinkedActor *owner)
{
 int zero=0;
 a->b4++;a->b5=zero;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=zero;a->b49=-8;a->s28=zero;a->s30=func_0c02849a()&3;a->wcc.dword_value=zero;
 func_0c02a0c4(a,23,17);func_0c1639bc(a,owner);
}
void func_0c163748(struct LinkedActor *a,struct LinkedActor *owner)
{
 float lift,dx,target,ox;int n;
 if(!a->s30){
  a->b5++;a->sdc.b12c=1;
  a->f52=owner->f52;lift=51.42857f;a->f56=owner->f56+lift;a->f104=0;
  n=(func_0c02849a()&7)+4;a->f96=(float)(n<<16)*2.1428571f/65536.0f;
  a->f108=-1.60714281f;
  dx=5.0f;ox=-93.33333f;
  if(A(owner)->w130){dx=-5.0f;ox=93.33333f;}
  if(A(owner)->w130)target=owner->f52+dx+266.66666f;else target=owner->f52+dx+-266.66666f;
  a->f52=owner->f52+ox;a->f56=owner->f56+lift;
  a->f92=(target-a->f52)/16.0f;
  A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=64;
  {int zero=0;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;}
  dat_0c2f83f8->arr[a->b2]++;
 }else a->s30--;
}
void func_0c16388a(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(A(a)->b19e){a->wcc.dword_value=1;goto settle;}
 if(A(owner)->f41c+51.42857f>a->f56){
  if(a->s28){
settle:
   a->b5++;a->s28=(func_0c02849a()&7)+16;
   a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  }else{
   float two;
   a->s28++;
   a->f96=(a->f96<0.0f?-a->f96:a->f96);
   two=one();two+=two;
   a->f96/=two;a->f108/=two;
  }
 }
}
void func_0c163974(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(a->wcc.dword_value)goto done;
 func_0c02a026(a);if(--a->s28>=0)return;
done:
 func_0c16340c(a,owner);a->b4++;a->b5=0;func_0c163a30(a,owner);
}
void func_0c1639bc(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct Dat_13bb5c *controls=(struct Dat_13bb5c *)dat_0c2f8338;
 if(!(controls->w3c&(1<<controls->b3b))){
  if(A(owner)->b411 && a->b4<2){func_0c16340c(a,owner);func_0c037688(a);return;}
  a->b36=owner->b36;table_0c2516a4[(unsigned char)a->b5](a);func_0c037d0c(a);
 }
}
void func_0c163a1c(struct LinkedActor *a){table_0c2516b0[a->b4](a,a->p24);}
void func_0c163a30(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c163a3e(struct LinkedActor *a){func_0c037688(a);}
