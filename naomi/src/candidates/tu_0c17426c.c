/* Complete 0x0c17426c..0x0c1745b4 group. Seven functions exact; clone constructor differs only in two owner-pointer register bytes. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c252bc0[])(struct LinkedActor *,struct LinkedActor *);
extern float dat_0c252bd0[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c0287e4(struct LinkedActor *);
extern float func_0c1ebd40(int);
void func_0c1742fa(struct LinkedActor *),func_0c1744f8(struct LinkedActor *,struct LinkedActor *),func_0c174530(struct LinkedActor *,short);
struct LinkedActor *func_0c17426c(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1742fa;a->p24=owner;a->w38=0x2f05;a->b32=0;}
 return a;
}
void func_0c17429e(struct LinkedActor *source,struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1742fa;a->p24=owner;a->w38=0x2f04;a->b32=1;A(a)->b34=A(source)->b34;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&source->f52;goto displacement;displacement:A(a)->f100=a->f52-owner->f52;A(a)->s30=A(source)->s30;}
}
void func_0c1742fa(struct LinkedActor *a){table_0c252bc0[a->b4](a,a->p24);}
void func_0c17430e(struct LinkedActor *a,struct LinkedActor *owner)
{
 int zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;zero=0;
 if(!a->b32){a->sdc.b12c=zero;A(a)->f92=0.0f;A(a)->f104=0.0f;A(a)->f96=15.0f;A(a)->f108=0.0f;A(a)->f100=a->f52=owner->f52;a->f56=owner->f56;A(a)->b34=zero;a->s28=zero;}else{
 a->b49=A(a)->s30;a->v80.x=a->v80.y=dat_0c252bd0[A(a)->b34];a->pad11[0]=66;a->pad11[1]=66;A(a)->b1a1=65;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,6);}
}
void func_0c174422(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(!a->b32){a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;A(a)->f100=owner->f52;A(a)->b34+=3;A(a)->b34&=31;func_0c174530(a,8000);A(a)->s30=1;if((unsigned char)(A(a)->b34+248)<=16)A(a)->s30=-1;func_0c17429e(a,owner);if(!func_0c0287e4(a))goto cleanup;return;}
 goto follow;follow:a->b36=owner->b36;a->f52=owner->f52+A(a)->f100;if(func_0c02a026(a)<0)goto cleanup;goto draw;draw:func_0c037d0c(a);if(A(a)->b140){A(a)->b140=0;a->v80.x*=0.75f;a->v80.y*=0.75f;}return;
 cleanup:func_0c1744f8(a,owner);
}
void func_0c1744f4(struct LinkedActor *a,struct LinkedActor *owner){}
void func_0c1744f8(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
void func_0c174530(struct LinkedActor *a,short scale)
{
 short angle;register float factor=256.0f,value;
 value=scale*factor;angle=(short)(((40-A(a)->b34)&31)<<11);value*=func_0c1ebd40(angle);value*=1000.0f;goto scaled;scaled:value/=100000.0f;goto divided;divided:value/=factor;{float offset=value*1.66666663f;if(A(a)->w130)offset=-offset;a->f52=offset+A(a)->f100;}
}
