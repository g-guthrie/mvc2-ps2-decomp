#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c0426c2(struct LinkedActor *,int),func_0c0437b8(struct LinkedActor *),func_0c0344a0(struct LinkedActor *,int);
extern int func_0c042780(struct LinkedActor *);
extern void func_0c19832e(struct LinkedActor *);
extern void (*table_0c2583f8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c258404[])(struct LinkedActor *);
void func_0c1985d8(struct LinkedActor *,struct LinkedActor *);
void func_0c1984a4(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActor *context)
{func_0c02a026(a);if(a->sdc.b141){a->b5++;context->sdc.b12c=0;func_0c02a0c4(context,0,0);func_0c0426c2(context,10);}}
void func_0c1984e6(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActor *context)
{
 int one=1,zero=0;func_0c02a026(a);
 if(A(context)->b19f && (unsigned char)context->b5==3){a->b4=2;a->sdc.b12c=zero;a->s28=zero;
 context->sdc.b12c=one;A(context)->b1ef=8;A(context)->b1eb=10;context->sdc.b12c=one;goto notify;}
 context->sdc.b12c=zero;
 if(func_0c042780(context)){A(a)->b142=one;a->s28-=7;func_0c02a026(a);func_0c0426c2(context,10);}
 if(--a->s28>=0)return;
 A(context)->b1ef=8;A(context)->b1eb=10;context->sdc.b12c=one;func_0c0437b8(context);
 a->b4=2;a->sdc.b12c=zero;a->s28=zero;
 notify:func_0c0344a0(a,35);func_0c1985d8(a,owner);
}
void func_0c1985d8(struct LinkedActor *a,struct LinkedActor *owner)
{
 int i;struct LinkedActor *child;
 if(dat_0c2f6830<=8)return;
 for(i=0;i<8;i++)if((child=func_0c0374da(0,3,1))){child->w38=0xe04;child->b32=2;child->b33=(i>>1)|((i&1)<<7);
 child->b35=a->b35;child->p16=func_0c19832e;child->p24=owner;child->p20=a;}
}
void func_0c198654(struct LinkedActor *a,struct LinkedActor *owner){table_0c2583f8[a->b4](a,owner);}
void func_0c198666(struct LinkedActor *a,struct LinkedActor *owner)
{
 float dx;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->b36=owner->b36;a->b49=-12;dx=-73.33333f;
 if(A(owner)->b1d2)dx=73.33333f;
 a->f52=owner->f52+dx;a->f56=owner->f56+195.0f;func_0c02a0c4(a,23,75);
}
void func_0c1986f6(struct LinkedActor *a){if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;}}
void func_0c198716(struct LinkedActor *a){table_0c258404[a->b4](a);}
