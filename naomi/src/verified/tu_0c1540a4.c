/* Homing projectile: spawn from owner, steer toward a target and expire. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct HomingStep_2505a0 { signed char start; unsigned char pad; short angle, dir; };
struct HomingTarget_2fb354 { short s0; unsigned char b2; signed char b3; struct LinkedActorVec3 v4; };
extern struct HomingStep_2505a0 dat_0c2505a0[];
extern unsigned char dat_0c250640[];
extern float dat_0c250600[];
extern struct HomingTarget_2fb354 *dat_0c2fb354;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern void func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern void func_0c02894c(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02850e(struct LinkedActor *);
extern unsigned char func_0c02887e(float *,struct LinkedActorVec3 *);
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
void func_0c1542e6(struct LinkedActor *a);
void func_0c1544b0(struct LinkedActor *a);
void func_0c1543ee(struct LinkedActor *a);
void func_0c1540a4(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->b4++;
 a->sdc=a->p24->sdc;
 a->sdc.b12c=1;
 a->b2=a->p24->b2;
 a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;
 a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;
 a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;
 a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 A(a)->b19c=66;
 A(a)->b19d=66;
 A(a)->b13c=255;
 A(a)->b13d=255;
 A(a)->b13e=128;
 A(a)->b13f=128;
 a->b36=11;
 func_0c02a0c4(a,23,dat_0c2505a0[A(a)->b33].start+1);
 a->s30=1;
 a->l72=dat_0c2505a0[A(a)->b33].angle;
 a->b34=dat_0c2505a0[A(a)->b33].dir;
 if(!A(a)->w130)a->b34=(32-a->b34)&31;
 dat_0c2fb354->b2=16;
 dat_0c2fb354->s0=500;
 dat_0c2fb354->b3=dat_0c250640[A(a)->b33];
 dat_0c2fb354->v4=*(struct LinkedActorVec3 *)&A(owner)->p20c->f52;
 dat_0c2fb354->v4.y+=68.57143f;
 a->f52=a->p24->f52;
 a->f56=a->p24->f56;
 a->f56+=205.714279175f;
 if(A(a)->w130)a->f52-=func_0c1ebd40(a->l72)*60.0f;
 else a->f52+=func_0c1ebd40(a->l72)*60.0f;
 a->f56+=func_0c1ec2c0(a->l72)*60.0f;
 a->s28=0;
 a->b32=0;
 a->f104=dat_0c250600[A(a)->b33];
 A(a)->b1a1=62;
 A(a)->w1ac=0;
 A(a)->b19e=0;
 A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c1542e6(a);
}
void func_0c1542e6(struct LinkedActor *a)
{
 func_0c02a026(a);
 a->s30--;
 if(a->s30<=0){a->s30=0;func_0c1543ee(a);func_0c02894c(a,dat_0c2fb354->s0);dat_0c2fb354->s0+=50;}
 if(!func_0c02850e(a)){func_0c1544b0(a);return;}
 if(A(a)->b19e)a->b4++;
 func_0c037d0c(a);
}
void func_0c154344(struct LinkedActor *a)
{
 func_0c02a026(a);
 func_0c02894c(a,dat_0c2fb354->s0);
 dat_0c2fb354->s0+=50;
 if(!func_0c02850e(a)){func_0c1544b0(a);return;}
 a->s28++;
 if(++a->b32<5){
 A(a)->b1a1=a->b32+62;
 A(a)->w1ac=0;
 A(a)->b19e=0;
 A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 goto call; call:
 func_0c037d0c(a);
 }
}
void func_0c1543ee(struct LinkedActor *a)
{
 unsigned char d;int step;
 if(!dat_0c2fb354->b2)return;
 if(--dat_0c2fb354->b3)return;
 dat_0c2fb354->b3=dat_0c250640[A(a)->b33];
 dat_0c2fb354->b2--;
 d=func_0c02887e(&a->f52,&dat_0c2fb354->v4)/8;
 if(d==a->b34)dat_0c2fb354->b2=0;
 else{
 if(((d-a->b34)&31)>=15)step=255;else step=1;
 a->b34=(a->b34+step)&31;
 if(A(a)->w130)a->l72=(unsigned short)((a->b34<<11)+0x4000);
 else a->l72=(unsigned short)(0x4000-(a->b34<<11));
 }
}
void func_0c1544b0(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1544be(struct LinkedActor *a){func_0c037688(a);}
