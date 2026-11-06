/* Linked effect spawners and state handlers 0x0c145f34-0x0c146bfc: one translation unit, since 0c14616a and
 * 0c1462e8 reach func_0c146bc8 by bra/bsr and 0c14644a reaches func_0c145f62. 0c145fb6, 0c146064 and 0c1463d8
 * fall through into the following function; 0c14678e resumes after a mid-function pool. */
#include "objects.h"
#define L(a) ((struct LinkedActor *)(a))
struct ShortPair_145f34 { short x, y; };
struct FloatPair_145f34 { float x, y; };
struct Pair_146670 { float x, y; };
struct EffectParameter_1464f4 {char scale,angle,pad,animation;};
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct ShortPair_145f34 dat_0c24fc64[];
extern struct FloatPair_145f34 dat_0c24fc54[];
extern struct EffectParameter_1464f4 dat_0c24fc18[];
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c24fc28[])(struct Actor *);
extern void (*table_0c24fc38[])(struct Actor *,struct Actor *);
extern void (*table_0c24fc44[])(struct Actor *);
extern void (*table_0c24fc6c[])(struct Actor *);
extern void (*table_0c24fc78[])(struct Actor *);
extern void (*table_0c24fc88[])(struct Actor *);
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
extern void func_0c1d53e4(struct Actor *);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c037688(struct Actor *);
extern void func_0c029e70(struct Actor *,int,char),func_0c02894c(struct Actor *,int);
void func_0c145fa4(struct Actor *);
void func_0c146016(struct Actor *);
void func_0c146168(struct Actor *,struct Actor *);
void func_0c1463a4(struct Actor *,struct Actor *);
void func_0c14644a(struct Actor *,struct Actor *);
void func_0c146bc8(struct Actor *,struct Actor *);
void func_0c14678e(struct Actor *,struct Actor *);
int func_0c146b8a(struct Actor *,float);

struct LinkedActor *func_0c145f34(struct LinkedActor *p,char x)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,1,0))!=0){
  q->p16=(void (*)(struct LinkedActor *))func_0c145fa4;
  q->p24=p;
  q->b32=x;
 }
 return q;
}

struct LinkedActor *func_0c145f62(struct LinkedActor *p,struct LinkedActor *s,char x,char y)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,1,0))!=0){
  q->p16=(void (*)(struct LinkedActor *))func_0c145fa4;
  q->p24=p;
  q->p20=s;
  q->b32=x;
  q->b35=y;
 }
 return q;
}

void func_0c145fa4(struct Actor *a)
{
 struct Actor *p=a;
 table_0c24fc28[p->b4](a);
}

void func_0c145fb6(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 a->b4++;
 a->w38=0x1004;
 a->sdc=p->sdc;
 a->sdc.b12c=1;
 a->b2=p->b2;
 a->b1=p->b1;
 a->v80.x=p->v80.x;
 a->v80.y=p->v80.y;
 a->b1a3=p->b1a3;
 a->b1a4=p->b1a4;
 a->b48=p->b48;
 a->v80=p->v80;
 a->b36=p->b36;
 func_0c146016((struct Actor *)a);
}

void func_0c146016(struct Actor *a)
{
 table_0c24fc38[a->b32](a,(struct Actor *)L(a)->p24);
}

void func_0c14602c(struct Actor *a)
{
 struct Actor *p=a;
 table_0c24fc44[p->b5](a);
}

void func_0c146064(struct Actor *a,struct Actor *o)
{
 short v;
 float fx;
 a->b5++;
 a->b12c=0;
 a->b36=8;
 L(a)->b49=0;
 a->b19c=68;a->b19d=68;
 a->b1a1=63;
 a->w1ac=0;
 a->b19e=0;
 a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 a->w1ac|=0x200;
 a->b13e=a->b13f=32;
 v=dat_0c24fc64[L(a)->b1a3].x;
 if(a->w130)v=-v;
 a->f52=o->f52+1.66666663f*(float)v;
 a->f56=o->f56+2.1428571f*(float)dat_0c24fc64[L(a)->b1a3].y;
 fx=dat_0c24fc54[L(a)->b1a3].x;
 if(a->w130)fx=-fx;
 a->f92=fx;
 a->f96=dat_0c24fc54[L(a)->b1a3].y;
 a->f104=a->f108=0.0f;
 func_0c02a0c4(a,23,81);
 func_0c146168(a,o);
}

void func_0c146168(struct Actor *a,struct Actor *o)
{
 if(o->b5!=0)goto end;
 if(a->b19f!=0)goto end;
 if(a->b19e){
  if(!func_0c0447bc(a))goto end;
  a->b5++;
  a->b6=0;
  func_0c146bc8(a,o);
  return;
 }
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 if(!func_0c028642(a))goto end;
 func_0c037d0c(a);
 return;
 end:
 a->b4++;
 a->b12c=0;
}

void func_0c14623a(struct Actor *a,struct Actor *o)
{
 struct Actor *t=a->p1b0;
 func_0c1463a4(a,o);
 if(!t->b1a0){
  a->b5++;
  func_0c02a0c4(t,14,0);
  func_0c0445fe(a,t);
  *(struct Actor **)&a->pad5ba[0]=o->p1c8;
  a->s28=180;
  func_0c0426c2(o->p1c8,1);
  t->b1f6=6;
  t->b1f7=o->b1f7=0xc3;
  o->b1ea=1;
  o->b15a=-1;
  if(t->b1f9==2){t->f92=t->f104=t->f96=t->f108=0.0f;}
 }
}

void func_0c1462e8(struct Actor *a,struct Actor *o)
{
 struct Actor *t=*(struct Actor **)&a->pad5ba[0];
 if(*(struct Actor **)&(*(struct Actor **)&a->pad7e[0])->pad7e[0]!=a)goto end;
 if(t->b5!=2)goto end;
 if(t->b19f&&t->b5==3)goto end;
 func_0c146bc8(a,o);
 func_0c1463a4(a,o);
 if(func_0c042728(t))a->s28-=3;
 if(--a->s28<0){
  t->b1f6=0;
  t->b1ef=8;
  if(!t->w420)t->b1f6=7;
  else if(t->b1f9!=2)func_0c0437b8(t);
  else func_0c04392e(t);
 }else goto set;
 end:
 a->b4++;
 a->b12c=0;
 if(((struct ActorCountdowns *)o)->l2e4)((struct ActorCountdowns *)o)->l2e4=((struct ActorCountdowns *)o)->l2e4-1;
 return;
 set:((struct ActorCountdowns *)o)->l2e4=1;
}

void func_0c1463a4(struct Actor *a,struct Actor *o)
{
 struct Actor *p=a;
 table_0c24fc6c[p->b6](a);
}

void func_0c1463d8(struct Actor *a,struct Actor *o)
{
 int i;
 struct LinkedActor *q;
 a->b6++;
 a->b12c=1;
 a->s30=10;
 a->f80=0.1000000015f;
 a->f84=0.1000000015f;
 for(i=0;i<4;i++){
  if((q=func_0c0374da((int)a,1,2))!=0){
   q->p16=(void (*)(struct LinkedActor *))func_0c145fa4;
   q->p24=L(o);
   q->p20=L(a);
   q->b32=1;
   q->b35=i;
  }
 }
 func_0c0344a0(o,46);
 func_0c14644a(a,o);
}

void func_0c14644a(struct Actor *a,struct Actor *o)
{
 a->f80+=0.1000000015f;
 a->f84+=0.1000000015f;
 if(!--a->s30){
  a->b6++;
  a->f80=1.0f;
  a->f84=1.0f;
  func_0c145f62(L(o),L(a),2,0);
  func_0c145f62(L(o),L(a),2,1);
 }
}

void func_0c1464a6(void)
{
}

void func_0c1464aa(struct Actor *a)
{
 struct Actor *p=a->p8;
 if(p->b4>=2){a->b4++;a->b12c=0;return;}
 table_0c24fc78[a->b5](a);
}

void func_0c1464f4(struct Actor *a)
{
 struct Actor *source=a->p20;struct EffectParameter_1464f4 *parameter;
 a->b5++;a->s28=10;a->s30=0xc80;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&source->f52;
 a->f80=1.5f;a->f84=1.5f;parameter=&dat_0c24fc18[a->b35];a->b36=8;((struct LinkedActor *)a)->b49=parameter->scale;a->b34=parameter->angle;
 if(a->w130)a->b34=(32-a->b34)&31;
 func_0c029e70(a,27,parameter->animation);
}
void func_0c146568(struct Actor *a)
{
 struct Actor *source=a->p20;
 a->f80-=0.1000000015f;a->f84-=0.1000000015f;a->s30-=200;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&source->f52;func_0c02894c(a,a->s30);
 if(!--a->s28){a->b5++;a->f80=0.5f;a->f84=0.5f;a->s28=6;}
}
void func_0c1465ca(struct Actor *a)
{
 struct Actor *source=a->p20;
 a->s30+=200;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&source->f52;func_0c02894c(a,a->s30);
 if(!--a->s28){a->b5++;a->s28=6;}
}
void func_0c14660c(struct Actor *a)
{
 struct Actor *source=a->p20;
 a->s30-=200;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&source->f52;func_0c02894c(a,a->s30);
 if(!--a->s28){a->b5=2;a->s28=6;}
}

void func_0c146670(struct Actor *a)
{
 struct Actor *p=a;
 table_0c24fc88[p->b5](a);
}

void func_0c146682(struct Actor *a,struct Actor *o)
{
 struct Pair_146670 v;
 struct Actor *p;
 int n;
 a->b5++;
 a->b13c=16;a->b13d=16;a->b13e=24;a->b13f=24;
 a->w130=0;
 a->b36=8;
 ((struct LinkedActor *)a)->b49=-2;
 if(!a->b35)a->f52=dat_0c2d9260.f8c+53.3333321f;else a->f52=dat_0c2d9260.f88+-53.3333321f;
 a->f56=dat_0c2d9260.f90+-137.142853f;
 p=a->p20;
 if(!a->b35)v.x=p->f52-a->f52+26.666666031f;else v.x=p->f52-a->f52+-26.666666031f;
 v.y=p->f56+-34.2857132f;
 a->f96=4.28571415f;
 a->f108=-0.80357140303f;
 n=func_0c146b8a(a,v.y);
 a->f92=v.x/(float)n;
 a->f104=0.0f;
 a->s28=n;
 func_0c02a0c4(a,23,a->b35+71);
 a->b0=1;
 func_0c1d53e4(a);
 if(a->b35==0)func_0c0344a0(a,27);
 func_0c14678e(a,o);
}

void func_0c14678e(struct Actor *a,struct Actor *o)
{
 struct Pair_146670 v;
 struct Actor *p=a->p20;
 if(p->b4>=2){a->b4++;a->b12c=0;a->b0=0;return;}
 if(!a->b35)v.x=p->f52-a->f52+26.666666031f;else v.x=p->f52-a->f52+-26.666666031f;
 v.y=p->f56-a->f56+-34.2857132f;
 a->f92=v.x/(float)a->s28;
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 if(!--a->s28){
  a->b5++;a->s28=0;a->i204=0;
  func_0c0346da(a,35);
  func_0c02a0c4(a,23,a->b35+73);
 }
}

void func_0c1468b4(struct Actor *a)
{
 struct Actor *p=a->p20;
 a->s28++;
 func_0c02a026(a);
 if(!a->b35)a->f52=p->f52+26.666666031f;else a->f52=p->f52+-26.666666031f;
 a->f56=p->f56+-34.2857132f;
 if(p->b4>=2){
  a->b5++;
  a->w130=a->b35;
  if(a->s28>=90)a->i204=1;
  a->f92=a->f104=a->f96=0.0f;
  a->f108=-0.80357140303f;
  func_0c02a0c4(a,23,a->i204+75);
 }
}

void func_0c14696c(struct Actor *a,struct Actor *o)
{
 float lim;
 func_0c02a026(a);
 a->f56+=a->f96;a->f96+=a->f108;
 if(a->i204)lim=o->f41c+25.714285f;else lim=o->f41c;
 if(a->f56>lim)return;
 a->b5++;
 a->f56=lim;
 func_0c02a0c4(a,23,a->i204+77);
}

void func_0c1469e2(struct Actor *a,struct Actor *o)
{
 if(func_0c02a026(a)<0){
  a->b5++;
  a->f56=o->f41c;
  if(a->i204&&!a->b35)func_0c0344a0(a,26);
  if(a->f52>=o->f52){a->w130=0;a->f92=-6.66666651f;}else{a->w130=1;a->f92=6.66666651f;}
  a->f104=0.0f;a->f96=0.0f;a->f108=0.0f;
  func_0c02a0c4(a,23,a->i204+79);
 }
}

void func_0c146a90(struct Actor *a,struct Actor *o)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 if(!func_0c028642(a)){a->b4++;a->b12c=0;a->b0=0;return;}
 if(!a->i204)return;
 if(a->w130==0&&a->f52<=o->f52||a->w130!=0&&a->f52>=o->f52){
  a->b5++;
  func_0c0346da(a,42);
  func_0c02a0c4(a,23,13);
 }
}

void func_0c146b32(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 if(!func_0c028642(a)){a->b4++;a->b12c=0;a->b0=0;}
}

void func_0c146b76(struct Actor *a)
{
 a->b4++;
 a->b12c=0;
}

void func_0c146b84(struct Actor *a)
{
 func_0c037688(a);
}

int func_0c146b8a(struct Actor *p,float lim)
{
 float y=p->f56;
 float vy=p->f96;
 int n=0;
 do{
  y+=vy;
  vy+=p->f108;
  n++;
 }while(vy>0.0f||y>lim);
 return n;
}

void func_0c146bc8(struct Actor *a,struct Actor *o)
{
    struct Actor *p = a->p1b0;
    a->f52 = p->f52;
    a->f56 = p->f56 + 2.14285714f * (float)(p->b13c / 2);
}
