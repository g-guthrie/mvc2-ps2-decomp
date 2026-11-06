#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct Actor *,int,char);
extern void (*table_0c24e374[])(struct Actor *,struct Actor *);
extern int dat_0c24e384[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c133646(struct LinkedActor *);
void func_0c1335f8(struct Actor *owner,unsigned char first,char second)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,1))){a->p16=func_0c133646;a->p24=(struct LinkedActor *)owner;a->b1=owner->b1;a->b32=first;a->b33=second;a->w38=0x300;}
}
void func_0c133646(struct LinkedActor *a)
{
 struct Actor *owner=(struct Actor *)a->p24;
 a->b36=owner->b36;table_0c24e374[a->b4]((struct Actor *)a,owner);
}
void func_0c133662(struct Actor *a,struct Actor *owner)
{
 *(unsigned int *)&a->b13c=0x20202424u;a->pad178[36]=66;a->b19d=66;
 if(owner->b255==3){ /* Retail retains this comparison without taking an action. */ }
 a->b1a1=55;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 a->f52=53.3333321f;goto velocity;velocity:a->f92=dat_0c24e384[(unsigned char)a->b1a3]*1.66666663f/65536.0f;
 if(a->w130)a->f52=a->f52+owner->f52;else{a->f52=-a->f52+owner->f52;a->f92=-a->f92;}
 a->f56=owner->f56+102.85714f;a->f96=0.0f;a->f108=0.0f;a->f104=0.0f;
 a->b159=21;a->b158=11;func_0c02a0c4(a,a->b159,a->b158);
}
