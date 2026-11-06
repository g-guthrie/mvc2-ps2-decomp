/* Note: matches only with a dead `if(0)dat_0c2f83f8=zero;` after the jsr, which keeps
 * zero live in r13 as retail does. This is an artificial spelling pending a decision
 * on whether such dead stores are acceptable. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct Glob_0c2f83f8 { unsigned char pad[0x7c]; short w7c[1]; };
extern struct Glob_0c2f83f8 *dat_0c2f83f8;
extern short table_0c252670[];
extern void (*table_0c252784[])(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c16fc14(struct LinkedActor *a,struct LinkedActor *owner,struct LinkedActor *p)
{
 short *o;float dx,dy;void *zero;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;zero=0;
 a->b4++;a->b36=(int)zero;
 if(!(owner->b5==0&&owner->b1d0==21&&A(owner)->b1e9==0&&A(owner)->b19f==0))*(char *)&p->pad1=-1;
 A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=48;A(a)->w1ac=(int)zero;A(a)->b19e=(int)zero;A(a)->p1c4=(int)zero;
 dat_0c2f83f8->w7c[a->b2]++;
 a->s30=a->b32*2;
 o=&table_0c252670[(a->s30<<1)];
 dx=-90.0f;dy=147.857132f;a->s28=1;
 if(a->sdc.w130){dx=90.0f;a->s28=-1;}
 a->f52=owner->f52+dx+*o++*1.66666663f;
 a->f56=owner->f56+dy+*o*2.1428571f;
 func_0c037d0c(a);if(0)dat_0c2f83f8=zero;func_0c02a0c4(a,23,3);
}
void func_0c16fd44(struct LinkedActor *a){table_0c252784[A(a)->b5](a);}
