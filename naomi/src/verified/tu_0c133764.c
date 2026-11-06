#include "objects.h"
extern void func_0c02a0c4(struct Actor *,int,char);
extern int dat_0c24e38c[][2];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24e39c[])(struct Actor *,struct Actor *);
void func_0c133764(struct Actor *a,struct Actor *owner)
{
 *(unsigned int *)&a->b13c=0x20202424u;a->pad178[36]=66;a->b19d=66;a->b1a1=56;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f52=53.3333321f;
 a->f92=dat_0c24e38c[(unsigned char)a->b1a3][0]*1.66666663f/65536.0f;
 a->f96=-(dat_0c24e38c[(unsigned char)a->b1a3][1]*2.1428571f/65536.0f);
 if(a->w130)a->f52=a->f52+owner->f52;else{a->f52=-a->f52+owner->f52;a->f92=-a->f92;}
 a->f56=owner->f56+137.142853f;a->f104=a->f108=0.0f;a->b159=21;a->b158=13;func_0c02a0c4(a,a->b159,a->b158);
}
void func_0c133842(struct LinkedActor *a,struct Actor *owner)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 table_0c24e39c[a->b32]((struct Actor *)a,owner);
}
