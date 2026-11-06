#include "objects.h"
extern void func_0c048bb0(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c196c1c(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char dat_0c242868[],dat_0c24286e[],dat_0c2428d6[];
extern unsigned char dat_0c2428d4[];
extern struct ActorMotionFixed4 dat_0c242874[];
void func_0c08d366(struct Actor *,struct ActorSub2a4 *);
void func_0c08d2d0(struct Actor *a,struct ActorSub2a4 *sub)
{
 a->b7++;func_0c048bb0(a,5);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 {int command=dat_0c242868[a->b32+a->b33*2];a->b1a1=command;}a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 a->b159=21;a->b158=dat_0c24286e[a->b32+a->b33*2];func_0c02a0c4(a,a->b159,a->b158);
 func_0c08d366(a,sub);
}
void func_0c08d366(struct Actor *a,struct ActorSub2a4 *sub)
{
 int xs,xa,ys,ya;
 int *row;
 func_0c02a026(a);
 if(!a->b141)return;
 a->b7++;a->s28=dat_0c2428d4[a->b32];
 row=(int *)dat_0c242874+(a->b33*8+a->b32*4);
 xs=row[0];xa=row[1];ys=row[2];ya=row[3];
 a->f92=a->b1d2?-(xs*1.66666663f/65536.0f):xs*1.66666663f/65536.0f;
 a->f104=a->b1d2?-(xa*1.66666663f/65536.0f):xa*1.66666663f/65536.0f;
 a->f96=ys*2.1428571f/65536.0f;a->f108=ya*2.1428571f/65536.0f;
 func_0c0344a0(a,20);func_0c0344a0(a,32);func_0c196c1c(a,5,dat_0c2428d6[a->b33]);
}
void func_0c08d490(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!--a->s28){a->b7++;a->b159=21;a->b158=10;func_0c02a0c4(a,a->b159,a->b158);}
}
void func_0c08d506(struct Actor *a)
{
 if(func_0c02a026(a)>=0){a->b7++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f108=-0.80357140303f;
 a->b1fc=2;a->b159=21;a->b158=12;func_0c02a0c4(a,a->b159,a->b158);}
}
