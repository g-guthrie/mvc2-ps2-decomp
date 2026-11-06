/* func_0c144034..func_0c14423e: owner-copy actor init (b1a1 select via label; pad11 store label fixes scheduling). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c0288a8(struct LinkedActor *,int);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c24f9b6[];
extern char dat_0c24f9b4[];
extern void (*table_0c24f9ec[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1441ae(struct LinkedActor *,struct LinkedActor *);
void func_0c144034(struct LinkedActor *a,struct LinkedActor *owner)
{
 short x;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=0;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 x=dat_0c24f9b6[2*(unsigned char)a->b33]*1.66666663f;
 if(owner->sdc.w130)x=-x;
 a->f52+=x;
 a->f56+=(dat_0c24f9b6+2*(unsigned char)a->b33)[1]*2.1428571f;
 a->b34=dat_0c24f9b4[(unsigned char)a->b33];
 if(a->sdc.w130){a->b34=32-a->b34;a->b34&=31;}
 if(!a->b33)A(a)->b1a1=owner->b1a3+50;else {goto s;s:A(a)->b1a1=owner->b1a3+52;}
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 goto t;t:a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,23);
 func_0c1441ae(a,owner);
}
void func_0c1441ae(struct LinkedActor *a,struct LinkedActor *owner)
{
 short *slot=&a->wcc.short_value;
 if(*(short *)&A(owner)->b158!=*slot)goto adv;
 if(!func_0c028642(a))goto adv;
 if(A(owner)->f41c>a->f56){adv:a->b4++;return;}
 table_0c24f9ec[(unsigned char)a->b5](a,owner);
}
void func_0c144202(struct LinkedActor *a)
{
 func_0c0288a8(a,1600);func_0c037d0c(a);
 if(A(a)->b19e||A(a)->b19f)a->b4++;
}
void func_0c144230(struct LinkedActor *a){a->sdc.b12c=0;a->b4++;}
void func_0c14423e(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
