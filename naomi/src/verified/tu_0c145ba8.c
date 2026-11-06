/* Linked effect spawner and state handlers 0x0c145ba8-0x0c145df4. 0c145c08 falls through into 0c145d70,
 * whose second parameter is a register-only local (it is entered with only the actor argument). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct BytePair_145ba8 { unsigned char b0, b1; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct BytePair_145ba8 dat_0c24fb54[];
extern struct BytePair_145ba8 dat_0c24fb72[];
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern void func_0c1d53e4(struct LinkedActor *);
extern void func_0c0344a0(struct LinkedActor *,int);
extern void (*table_0c24fbc4[])(struct LinkedActor *);
extern void (*table_0c24fbd4[])(struct LinkedActor *);
extern void (*table_0c24fc10[])(struct LinkedActor *);
void func_0c145bf6(struct LinkedActor *);
void func_0c145d70();

struct LinkedActor *func_0c145ba8(struct LinkedActor *p,char x,char y)
{
 struct LinkedActor *q;
 struct ActorSub2a4 *sub;
 if((q=func_0c0374da(0,1,0))!=0){
  q->p16=func_0c145bf6;
  q->p24=p;
  q->b32=x;
  q->b35=y;
  sub=&A(p)->sub2a4;
  sub->b7++;
 }
 return q;
}

void func_0c145bf6(struct LinkedActor *a)
{
 struct LinkedActor *p=a;
 table_0c24fbc4[p->b4](a);
}

void func_0c145c08(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;
 a->b4++;
 a->w38=0x1003;
 a->sdc=p->sdc;
 a->sdc.b12c=1;
 a->b2=p->b2;
 a->b1=p->b1;
 a->v80.x=p->v80.x;
 a->v80.y=p->v80.y;
 a->b1a3=p->b1a3;
 a->b1a4=p->b1a4;
 a->b48=p->b48;
 a->v80=p->v80;
 a->b36=p->b36;
 A(a)->b13c=16;A(a)->b13d=16;A(a)->b13e=24;A(a)->b13f=24;
 a->b36=10;
 a->s28=300;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&p->f52;
 if(!p->sdc.w130){a->f52+=613.333313f;a->f92=-13.33333302f;}
 else{a->f52-=613.333313f;a->f92=13.33333302f;}
 a->f56=A(p)->f41c;
 a->f104=0.0f;
 if(dat_0c24fb72[a->b35].b1)func_0c0344a0(a,26);
 A(a)->b19c=68;A(a)->b19d=68;
 A(a)->b1a1=dat_0c24fb72[a->b35].b0;
 A(a)->w1ac=0;
 A(a)->b19e=0;
 A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,dat_0c24fb54[a->b32].b0);
 a->pad0=1;
 func_0c1d53e4(a);
 func_0c145d70(a);
}

void func_0c145d70(struct LinkedActor *a,struct LinkedActor *p)
{
 p=a->p24;
 if(p->b4>=2||--a->s28<=0){a->b4++;a->sdc.b12c=0;return;}
 table_0c24fbd4[a->b32](a);
}

void func_0c145db2(struct LinkedActor *a)
{
 struct LinkedActor *p=a;
 table_0c24fc10[A(p)->b5](a);
}
