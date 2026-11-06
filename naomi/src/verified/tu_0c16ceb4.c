#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c16cfa4(struct LinkedActor *,struct LinkedActor *);
void func_0c16ceb4(struct LinkedActor *a,struct LinkedActor *owner)
{
 int distance;unsigned int zero=0;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;a->sdc.b12c=zero;
 distance=(unsigned char)a->b33*64+88;if(A(owner)->b1d2)distance=-distance;
 a->f52=owner->f52-(short)distance*1.66666663f;a->f56=owner->f56;a->b36=8;a->s28=(unsigned char)a->b33*8+1;
 a->pad11[0]=66;a->pad11[1]=66;A(a)->b1a1=a->b1a3+48;A(a)->w1ac=zero;*(unsigned char *)&A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,26);func_0c16cfa4(a,owner);
}
void func_0c16cfa4(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(a->b1!=a->p24->b1)goto cleanup;
 if(!a->b6){if(! --a->s28){a->b6++;a->s28=28;}}
 else{
 a->sdc.b12c=1;
 if(A(a)->b19f)goto cleanup;
 goto animate;animate:if(func_0c02a026(a)<0){cleanup:a->b4++;a->sdc.b12c=0;return;}
 func_0c037d0c(a);
 }
}
