#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern int func_0c02849a(void);
extern int func_0c03916c(struct Actor *);
extern void (*table_0c23f31c[])(struct Actor *),(*table_0c23f32c[])(struct Actor *),(*table_0c23f344[])(struct Actor *);
extern void (*table_0c23f37c[])(struct Actor *,struct ActorSub2a4 *);
extern char dat_0c23f33c[],dat_0c23f334[];
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108
void func_0c052e50(struct Actor *a)
{
 register float previous=a->f92;
 MOVE;
 if(previous*a->f92<0.0f){func_0c0437b8(a);return;}
 func_0c02a026(a);
}
void func_0c052ea0(struct Actor *a){table_0c23f31c[a->b6](a);}
void func_0c052efa(struct Actor *);
void func_0c052eb2(struct Actor *a)
{
 float zero=0.0f;
 a->b6++;
 a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;
 a->f92=a->b1d2?-18.3333321f:18.3333321f;
 a->f104=a->b1d2?0.33854166f:-0.33854166f;
 a->s28=20;
 func_0c052efa(a);
}
void func_0c052f12(struct Actor *);
void func_0c052efa(struct Actor *a)
{
 a->b6++;func_0c02a026(a);
 func_0c052f12(a);
}
void func_0c052f12(struct Actor *a)
{
 MOVE;
 func_0c02a026(a);
 if(--a->s28>0)return;
 a->b6++;
 a->f92=a->b1d2?-4.16666651f:4.16666651f;
 a->f104=a->b1d2?0.33854166f:-0.33854166f;
 func_0c02a0c4(a,2,3);
}
void func_0c052fd0(struct Actor *a)
{
 register float previous=a->f92;
 MOVE;
 if(previous*a->f92<0.0f){func_0c0437b8(a);return;}
 func_0c02a026(a);
}
void func_0c053020(struct Actor *a){table_0c23f32c[a->b6](a);}
void func_0c053032(struct Actor *a)
{
 a->b6++;
 a->b12c=1;
 func_0c02a0c4(a,18,0);
}
void func_0c053046(struct Actor *a)
{
 if(func_0c02a026(a)<0)a->b5++;
}
void func_0c0530a4(struct Actor *),func_0c053070(struct Actor *);
void func_0c053066(struct Actor *a)
{
 if(a->b6==0)func_0c053070(a);
 else func_0c0530a4(a);
}
void func_0c053070(struct Actor *a)
{
 char x;int v;
 a->b6++;
 x=a->b32;
 v=dat_0c23f33c[(unsigned char)x];
 if(!(unsigned char)x)v=dat_0c23f334[func_0c02849a()&7];
 func_0c02a0c4(a,19,v);
}
void func_0c0530a4(struct Actor *a)
{
 if(func_0c03916c(a)){func_0c0437b8(a);return;}
 func_0c02a026(a);
}
void func_0c0530c6(struct Actor *a){table_0c23f344[a->b1e9](a);}
void func_0c0530da(struct Actor *a){table_0c23f37c[a->b6](a,&a->sub2a4);}
