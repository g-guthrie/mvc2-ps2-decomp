/* Candidate (231/248): indexing dat_0c23ff58 directly fixes the pool order; the whole body still runs one register off retail (0xfff/-12/table in r3, row words in r2 where retail uses r2/r1). Labels and else-wrap tried. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern int dat_0c23ff58[][4];
void func_0c060958(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 unsigned short input;
 int strength;
 int *speed;
 if(func_0c02a026(a)>=0)return;
 a->b6++;
 ((struct ActorSubMoveBytes *)sub)->b28=1;
 func_0c0344a0(a,31);
 a->s28=32;
 input=a->w34a;
 if(a->b525)input=sub->s10;
 strength=input&0x3000;
 if(strength<0){goto q;q:strength+=0xfff;}
 strength>>=12;
 a->f92=dat_0c23ff58[(unsigned short)strength][0]*1.66666663f/65536.0f;
 a->f104=dat_0c23ff58[(unsigned short)strength][1]*1.66666663f/65536.0f;
 a->f96=dat_0c23ff58[(unsigned short)strength][2]*2.1428571f/65536.0f;
 a->f108=dat_0c23ff58[(unsigned short)strength][3]*2.1428571f/65536.0f;
 if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,2,strength+5);
}
