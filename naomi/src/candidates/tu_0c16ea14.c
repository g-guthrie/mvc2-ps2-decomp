/* Candidate: constructor and both pools exact. Dispatcher differs
 * in owner/cached-one register allocation; final handler is displaced
 * two bytes. Current whole-section comparison is 416/536. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int func_0c02849a(void);
extern void func_0c037688(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c2525f8[])(struct LinkedActor *);
void func_0c16ea62(struct LinkedActor *);
struct LinkedActor *func_0c16ea14(struct LinkedActor *owner,char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c16ea62;a->b32=mode;a->b33=0;a->p24=owner;a->b1=owner->b1;a->f52=owner->f52;a->f56=owner->f56;a->w38=0x2c01;}
 return a;
}

void func_0c16ea62(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(a->b4>=2){if(!a->b32)((unsigned char *)&A(owner)->sub2a4.s12)[0]=0;func_0c037688(a);return;}
 if(!a->b4){
 short offset;short one;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=66;a->pad11[1]=66;a->f52=owner->f52+13.33333302f;a->f56=owner->f56+171.42856f;
 offset=(func_0c02849a()&31)+32;if(offset&one)offset=-offset;a->f52+=offset*1.66666663f;
 offset=func_0c02849a()&31;if(offset&one)offset=-offset;a->f56+=offset*2.1428571f;
 ((struct MeActor *)a)->blk_dc.b13c=((struct MeActor *)a)->blk_dc.b13d=((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=48;A(a)->b19e=0;
 a->b33=func_0c02849a()&3;a->b49=a->b33?-8:8;func_0c02a0c4(a,21,7);return;
 }
 table_0c2525f8[(unsigned char)a->b5](a);
}
void func_0c16ebca(struct LinkedActor *a){if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,21,(unsigned char)a->b33+8);}}
