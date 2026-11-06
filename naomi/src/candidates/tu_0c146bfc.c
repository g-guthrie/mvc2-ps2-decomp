/* Candidate (2713/2772): every function except func_0c14723a matches. In 0c14723a retail sets r13=1
 * and the memcpy literal earlier, preloads the 0x80/8 bytes before the counter increment, and loads the
 * dat_0c2d926c base inside each w130 arm; the 12-byte frame is reproduced by an unused local Vec3. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define M(a) ((struct MeActor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *),func_0c02850e(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *),func_0c037d0c(struct LinkedActor *);
extern void func_0c1d53e4(struct LinkedActor *),func_0c04992e(struct LinkedActor *),func_0c0344a0(struct LinkedActor *,int);
extern void func_0c19d2ee(struct LinkedActor *,int,int);
extern float _builtin_fabsf(float);
extern unsigned char *dat_0c2fb334;
extern short *dat_0c2fb338;
extern float dat_0c2d926c;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24fca4[])(struct LinkedActor *);
extern void (*table_0c24fcac[])(struct LinkedActor *);
extern void (*table_0c24fcbc[])(struct LinkedActor *);
extern void (*table_0c24fccc[])(struct LinkedActor *);
extern void (*table_0c24fcdc[])(struct LinkedActor *);
extern void (*table_0c24fcec[])(struct LinkedActor *);
extern void (*table_0c24fcf4[])(struct LinkedActor *);
void func_0c146c30(struct LinkedActor *);
void func_0c147092(struct LinkedActor *);
unsigned char func_0c147202(struct LinkedActor *,struct LinkedActor *,unsigned short);
void func_0c1475e6(struct LinkedActor *);
void func_0c14769a(struct LinkedActor *);

struct LinkedActor *func_0c146bfc(struct LinkedActor *p,unsigned char x)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,1,0))!=0){q->p16=func_0c146c30;q->p24=p;q->b32=x;q->w38=0x1100;}
 return q;
}

void func_0c146c30(struct LinkedActor *a)
{
 dat_0c2fb334=(unsigned char *)&A(a->p24)->sub2a4;dat_0c2fb338=&a->wcc.short_value;
 table_0c24fca4[a->b32](a);
}

void func_0c146c58(struct LinkedActor *a){table_0c24fcac[a->b4](a);}

void func_0c146c6a(struct LinkedActor *a)
{
 a->b4++;a->sdc.b12c=1;
 a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;A(a)->w130=A(a->p24)->w130;
 dat_0c2fb334[0]=1;
 a->pad11[0]=68;a->pad11[1]=68;A(a)->b1a1=48;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 M(a)->blk_dc.b13e=64;M(a)->blk_dc.b13f=64;
 a->f52=A(a->p24)->b1d2?(&dat_0c2d926c)[0]+-480.0f:(&dat_0c2d926c)[0]+480.0f;
 a->f56=A(a->p24)->f41c;
 a->s28=16;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 if(A(a)->w130)a->f92=10.0f;else a->f92=-10.0f;
 func_0c1d53e4(a);
 A(a)->b0=1;
 func_0c02a0c4(a,23,0);
}

void func_0c146dd4(struct LinkedActor *a)
{
 if(!a->s28||!--a->s28){if(!func_0c028642(a)){a->b4=3;dat_0c2fb334[0]=0;func_0c14769a(a);return;}}
 if(A(a)->b19f){a->b4++;a->b5=0;func_0c04992e(a);func_0c0344a0(a,44);return;}
 table_0c24fcbc[(unsigned char)a->b5](a);
}

void func_0c146e74(struct LinkedActor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!dat_0c2fb334[3]&&func_0c147202(a,a->p24,96)){a->b5++;dat_0c2fb334[3]=1;}
 func_0c037d0c(a);
}

void func_0c146ee8(struct LinkedActor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!func_0c147202(a,a->p24,96)){a->b5++;a->f96=8.5714283f;a->f108=-0.5357143f;func_0c02a0c4(a,23,1);}
 func_0c037d0c(a);
}

void func_0c146f7c(struct LinkedActor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>A(a->p24)->f41c)){a->b5++;a->f56=A(a->p24)->f41c;a->f96=0.0f;a->f108=0.0f;func_0c02a0c4(a,23,2);}
 func_0c037d0c(a);
}

void func_0c146ffc(struct LinkedActor *a)
{
 func_0c02a026(a);
 if(!a->sdc.b141)a->b5=0;
 func_0c037d0c(a);
}

void func_0c14701c(struct LinkedActor *a){table_0c24fccc[(unsigned char)a->b5](a);}

void func_0c14702e(struct LinkedActor *a)
{
 a->b5++;
 if(A(a)->w130)a->f92=-1.66666663f;else a->f92=1.66666663f;
 a->f104=0.0f;a->f96=12.85714245f;a->f108=-1.60714281f;
 func_0c02a0c4(a,23,3);
 func_0c147092(a);
}

void func_0c147092(struct LinkedActor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>A(a->p24)->f41c)){
  a->b5++;a->s28=3;
  if(A(a)->w130)a->f92=-1.66666663f;else a->f92=1.66666663f;
  a->f104=0.0f;a->f96=4.28571415f;a->f108=-1.07142854f;
  func_0c02a0c4(a,23,4);
 }
}

void func_0c14712e(struct LinkedActor *a)
{
 if(!a->s28||!--a->s28){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(!(a->f56>A(a->p24)->f41c)){a->b5++;a->f56=A(a->p24)->f41c;A(a)->f264=1.0f;}
 }
}

void func_0c1471c8(struct LinkedActor *a)
{
 func_0c02a026(a);
 if(!((A(a)->f264-=0.050000001f)>0.0f)){a->b4++;dat_0c2fb334[0]=0;func_0c14769a(a);}
}

unsigned char func_0c147202(struct LinkedActor *a,struct LinkedActor *p,unsigned short range)
{
 float d=_builtin_fabsf(a->f52-p->f52);
 if(!(d>range*1.66666663f))return 1;
 return 0;
}

void func_0c147228(struct LinkedActor *a){table_0c24fcdc[a->b4](a);}

void func_0c14723a(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;struct LinkedActorVec3 v;
 a->b4++;
 a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 dat_0c2fb334[1]=1;
 a->pad11[0]=68;a->pad11[1]=68;
 if(A(p)->b255==3)A(a)->b1a1=79;else A(a)->b1a1=49;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 M(a)->blk_dc.b13e=64;M(a)->blk_dc.b13f=64;
 M(a)->blk_dc.b13c=128;M(a)->blk_dc.b13d=8;
 a->f52=A(a)->w130?dat_0c2d926c+-426.66666f:dat_0c2d926c+426.66666f;
 a->f56=a->p24->f56+480.0f;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 if(A(a)->w130)a->f92=10.0f;else a->f92=-10.0f;
 a->f96=-17.142857f;a->f108=0.401785702f;
 a->s28=16;
 func_0c1d53e4(a);
 A(a)->b0=1;
 func_0c02a0c4(a,23,5);
}

void func_0c1473be(struct LinkedActor *a)
{
 if(!a->s28||!--a->s28){if(!func_0c02850e(a)){a->b4=3;dat_0c2fb334[1]=0;func_0c14769a(a);return;}}
 if(A(a)->b19f){a->b4++;a->b5=0;func_0c04992e(a);func_0c0344a0(a,44);return;}
 if(!dat_0c2fb334[4]&&func_0c147202(a,a->p24,64))dat_0c2fb334[4]=1;
 table_0c24fcec[(unsigned char)a->b5](a);
}

void func_0c147498(struct LinkedActor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f96<0.0f)){a->b5++;func_0c02a0c4(a,23,6);func_0c19d2ee(a,17,0);func_0c19d2ee(a,17,0);return;}
 func_0c037d0c(a);
}

void func_0c14750e(struct LinkedActor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c037d0c(a);
}

void func_0c14755a(struct LinkedActor *a){table_0c24fcf4[(unsigned char)a->b5](a);}

void func_0c14756c(struct LinkedActor *a)
{
 a->b5++;
 if(A(a)->w130)a->f92=0.625f;else a->f92=-0.625f;
 a->f104=0.0f;a->f96=2.1428571f;a->f108=-0.80357140303f;
 func_0c02a0c4(a,23,7);
 func_0c19d2ee(a,17,1);func_0c19d2ee(a,17,1);
 func_0c1475e6(a);
}

void func_0c1475e6(struct LinkedActor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>A(a->p24)->f41c)){a->b5++;a->f56=A(a->p24)->f41c;A(a)->f264=1.0f;func_0c02a0c4(a,23,8);}
}

void func_0c147660(struct LinkedActor *a)
{
 func_0c02a026(a);
 if(!((A(a)->f264-=0.050000001f)>0.0f)){a->b4++;dat_0c2fb334[1]=0;func_0c14769a(a);}
}

void func_0c14769a(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
