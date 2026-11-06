/* 0x0c18266c..0x0c18296c: partner-effect state handlers (sibling of tu_0c145f34); one unit, since 0c18266c and 0c182830 reach 0c1828da by bsr and 0c1828d4 by bra. */
#include "objects.h"
struct ShortPair_18266c { short x, y; };
extern struct ShortPair_18266c dat_0c255730;
extern short dat_0c255734[];
extern char func_0c02a026(struct Actor *);
extern int func_0c028642(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,char);
extern void func_0c037d0c(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c0445fe(struct Actor *,struct Actor *);
extern void func_0c0426c2(struct Actor *,int);
extern int func_0c042728(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c04392e(struct Actor *);
extern void func_0c037688(struct Actor *);
extern void func_0c1bc0ac(struct Actor *,int);
void func_0c1828d4(struct Actor *a,struct Actor *o);
void func_0c1828da(struct Actor *a,struct Actor *o);
void func_0c18266c(struct Actor *a,struct Actor *o)
{
 if(o->b5!=0)goto end;
 if(a->b19f!=0)goto end;
 if(a->b19e){
  if(!func_0c0447bc(a))goto end;
  a->b5++;
  a->b36=8;
  func_0c1828da(a,o);
  func_0c02a0c4(a,23,4);
  return;
 }
 goto mv;mv:func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->b33+=64))func_0c1bc0ac(a,0);
 if(!func_0c028642(a))goto done;
 func_0c037d0c(a);
 return;
 end:
 func_0c1bc0ac(a,1);
 done:
 func_0c1828d4(a,o);
}
void func_0c182754(struct Actor *a,struct Actor *o)
{
 struct Actor *t=a->p1b0;
 func_0c02a026(a);
 if(!t->b1a0){
  a->b5++;
  func_0c02a0c4(t,14,0);
  func_0c0445fe(a,t);
  *(struct Actor **)&a->pad5ba[0]=o->p1c8;
  {int v=90;if(o->b411)v=60;a->s28=v;}
  func_0c0426c2(o->p1c8,1);
  t->b1f6=6;
  t->b1f7=o->b1f7=0xc2;
  o->b1ea=1;
  o->b15a=-1;
  if(t->b1f9==2){
   t->f92/=4.0f;
   t->f104/=4.0f;
   if(t->f96>0.0f)t->f96/=4.0f;
   t->f108=-0.80357140303f;
  }
 }
}
void func_0c182830(struct Actor *a,struct Actor *o)
{
 struct Actor *t=*(struct Actor **)&a->pad5ba[0];
 func_0c1828da(a,o);
 if(t->b19f&&t->b5==3)goto end;
 if(a!=*(struct Actor **)&t->pad7e[0])goto end;
 if(func_0c042728(t))a->s28-=3;
 if(--a->s28>=0)return;
 t->b1f6=0;
 t->b1ef=8;
 if((short)t->w420>0){
  if(t->b1f9!=2)func_0c0437b8(t);
  else func_0c04392e(t);
 }
 end:
 func_0c1bc0ac(a,2);
 func_0c1828d4(a,o);
}
void func_0c1828c6(struct Actor *a)
{
 a->b4++;
 a->b12c=0;
}
void func_0c1828d4(struct Actor *a,struct Actor *o)
{
 func_0c037688(a);
}
void func_0c1828da(struct Actor *a,struct Actor *o)
{
 struct Actor *p=a->p1b0;
 short v=dat_0c255730.x;
 if(p->w130)v=-v;
 a->f52=p->f52+v*1.66666663f;
 a->f56=p->f56+(dat_0c255730.y+dat_0c255734[*&a->i204])*2.1428571f;
 a->i204++;a->i204=a->i204&3;
}
