#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern void (*table_0c2577e0[])(struct LinkedActor *);
extern struct LinkedActorVec3 table_0c22f814[];extern float dat_0c2d926c;
void func_0c191d34(struct LinkedActor *);
void func_0c191dfc(struct LinkedActor *);
struct LinkedActor *func_0c191d00(struct LinkedActor *owner,char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c191d34;a->p24=owner;a->b32=mode;a->w38=0x800;}return a;}
void func_0c191d34(struct LinkedActor *a){table_0c2577e0[a->b4](a);}
void func_0c191d46(struct LinkedActor *a)
{
 char old;struct LinkedActorVec3 *row;
 a->b4++;old=a->b1a3;
a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->sdc.b12c=1;a->b1a3=old;a->b36=7;
 row=&table_0c22f814[a->b1a3];A(a)->f92=row->x;A(a)->f96=row->y;
 a->sdc.w130=a->p24->sdc.w130;func_0c02a0c4(a,21,45);func_0c191dfc(a);
}
void func_0c191dfc(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;unsigned char *state;
 if(a->b32 && (owner->b5 || owner->b1d0!=29))goto erase;
 a->f52=dat_0c2d926c+A(a)->f92;a->f56=A(a)->f96;owner->f52=a->f52;owner->f56=a->f56;
 if(func_0c02a026(a)>=0){goto kept;}else{
 erase:a->sdc.b12c=0;a->b4=3;goto done;}
 kept:
 if(a->sdc.b141){state=(unsigned char *)&A(owner)->sub2a4;a->b4++;a->sdc.b141=0;state[13]=1;
 owner->sdc.w130=a->sdc.w130;A(owner)->b1d2=*(unsigned char *)&a->sdc.w130;
 A(owner)->f92=0;A(owner)->f96=0;A(owner)->f104=0;A(owner)->f108=0;}
 done:return;
}
void func_0c191ece(struct LinkedActor *a){if(func_0c02a026(a)<0){a->sdc.b12c=0;a->b4=3;}}
void func_0c191eee(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
