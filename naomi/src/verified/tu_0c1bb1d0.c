/* Linked-actor family at 0x0c1bb1d0: spawner, b4/b32/b6 dispatchers, rise/fall states and their animation helpers. */
#include "objects.h"
struct MotionPair { float v, dv; };
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int func_0c02849a(void);
extern int func_0c02850e(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a18c(struct LinkedActor *,int,char,int);
extern void (*table_0c25b988[])(struct LinkedActor *);
extern void (*table_0c25b998[])(struct LinkedActor *);
extern void (*table_0c25b9b8[])(struct LinkedActor *);
extern void (*table_0c25bb08[])(struct LinkedActor *);
extern const float dat_0c25b964[];
extern const short dat_0c25b9d8[];
extern const char dat_0c25b9ea[][8];
extern const float dat_0c25ba34[][4];
extern const float dat_0c25bac4[];
extern const struct MotionPair dat_0c25bae8[];
extern const struct MotionPair dat_0c25bb18[];
extern const struct MotionPair dat_0c25bb58[];
void func_0c1bb224(struct LinkedActor *a);
void func_0c1bb4ae(struct LinkedActor *a);
void func_0c1bb4fc(struct LinkedActor *a);
static void linked_show_by_b141(struct LinkedActor *a);
void func_0c1bb590(struct LinkedActor *a);
void func_0c1bb5ee(struct LinkedActor *a);
void func_0c1bb640(struct LinkedActor *a);
void func_0c1bb676(struct LinkedActor *a);

struct LinkedActor *func_0c1bb1d0(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){
  a->p16=func_0c1bb224;a->p24=owner;a->b1=owner->b1;a->w38=0x3502;
  a->f52=owner->f52;a->f56=owner->f56;
  a->b32=(func_0c02849a()&3)+4;a->b33=0;
 }
 return a;
}
void func_0c1bb224(register struct LinkedActor *a){table_0c25b988[a->b4](a);}
void func_0c1bb236(struct LinkedActor *a)
{
 struct LinkedActor *p;
 a->b4++;p=a->p24;a->sdc=p->sdc;a->sdc.b12c=1;a->b2=p->b2;a->b1=p->b1;
 a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;
 a->v80=p->v80;a->b36=p->b36;
 table_0c25b998[a->b32](a);
 a->b5=a->b6=0;
}
void func_0c1bb2ae(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 a->f52=p->f52;a->f56=((struct Actor *)p)->f41c;a->b36=10;
 func_0c1bb5ee(a);
 a->s28=0;a->sdc.b141=0;a->s30=1;
 func_0c1bb590(a);
}
void func_0c1bb2e6(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 a->f52=p->f52;a->f56=((struct Actor *)p)->f41c;a->b36=12;
 func_0c1bb5ee(a);func_0c1bb640(a);
 a->s28=0;a->sdc.b141=0;a->s30=1;
 func_0c1bb590(a);
}
void func_0c1bb34c(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 a->f52=p->f52;a->f56=((struct Actor *)p)->f41c;a->b36=0;
 func_0c1bb5ee(a);
 a->s28=0;a->sdc.b141=0;a->s30=1;
 func_0c1bb590(a);
}
void func_0c1bb386(struct LinkedActor *a){table_0c25b9b8[a->b32](a);}
void func_0c1bb39a(struct LinkedActor *a)
{
 if(!a->b5){func_0c1bb676(a);func_0c1bb4ae(a);}
 else{if(!func_0c02850e(a))a->b4++;
 func_0c1bb676(a);linked_show_by_b141(a);}
}
void func_0c1bb3d0(struct LinkedActor *a)
{
 if(!a->b5){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  func_0c1bb4fc(a);
 }else{
 if(!func_0c02850e(a))a->b4++;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 linked_show_by_b141(a);}
}
void func_0c1bb46c(struct LinkedActor *a)
{
 if(!a->b5){func_0c1bb676(a);func_0c1bb4fc(a);}
 else{if(!func_0c02850e(a))a->b4++;
 func_0c1bb676(a);linked_show_by_b141(a);}
}
void func_0c1bb4ae(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 float d=((struct Actor *)p)->f41c+dat_0c25b964[a->b32]-a->f56+17.142857f;
 int n;
 if(d<0.0f)d=-d;
 n=(int)(d/2.1428571f);
 if(n<0)n+=7;
 n>>=3;
 if(a->s28>n)linked_show_by_b141(a);
 else{a->s28=n;func_0c1bb590(a);}
}
void func_0c1bb4fc(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 float d=((struct Actor *)p)->f41c+dat_0c25b964[a->b32]-a->f56+17.142857f;
 int n;
 if(d<0.0f)d=-d;
 n=(int)(d/2.1428571f);
 if(n<0)n+=15;
 n>>=4;
 if(a->s28>n)linked_show_by_b141(a);
 else{a->s28=n;func_0c1bb590(a);}
}
static void linked_show_by_b141(struct LinkedActor *a)
{
 func_0c02a026(a);
 a->s30=a->sdc.b142;
 if(a->sdc.b141<0)a->sdc.b12c=0;else a->sdc.b12c=1;
}
void func_0c1bb590(struct LinkedActor *a)
{
 const short *t=dat_0c25b9d8;
 if(a->s28>=t[a->b32]){a->s28=t[a->b32];a->b5++;}
 func_0c02a18c(a,18,dat_0c25b9ea[a->b32][a->s28],a->sdc.b141&127);
 a->sdc.b142=a->s30;
}
void func_0c1bb5ee(struct LinkedActor *a)
{
 float v=dat_0c25ba34[a->b32][func_0c02849a()&3];
 if(a->sdc.w130)v=-v;
 a->f52+=v;
 a->f56-=dat_0c25bac4[a->b32];
}
void func_0c1bb640(struct LinkedActor *a)
{
 unsigned char i;
 a->f92=a->f104=0.0f;
 i=func_0c02849a()&3;a->f96=dat_0c25bae8[i].v;a->f108=dat_0c25bae8[i].dv;
}
void func_0c1bb676(struct LinkedActor *a){table_0c25bb08[a->b6](a);}
void func_0c1bb688(struct LinkedActor *a)
{
 unsigned char i;
 a->b6++;
 i=func_0c02849a()&7;a->f92=dat_0c25bb18[i].v;a->f104=dat_0c25bb18[i].dv;
 i=func_0c02849a()&7;a->f96=dat_0c25bb58[i].v;a->f108=dat_0c25bb58[i].dv;
}
