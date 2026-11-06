/* Complete 0x0c1b2e10..0x0c1b2f84 group. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int *dat_0c2fb42c;
extern void (*dat_0c25aecc[])(struct LinkedActor *);
extern void (*dat_0c25aedc[])(struct LinkedActor *);
void func_0c1b2ed0(struct LinkedActor *);

struct LinkedActor *func_0c1b2e10(struct LinkedActor *p,unsigned char kind)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,3,0))!=0){q->p16=func_0c1b2ed0;q->p24=p;q->b32=kind;q->w38=0x2600;}
 return q;
}
struct LinkedActor *func_0c1b2e44(struct LinkedActor *p)
{
 unsigned char i;
 struct LinkedActor *q;
 for (i = 0; i < 4;) {
  if ((q = func_0c0374da(0,3,0)) != 0) {
   q->p16 = func_0c1b2ed0;
   q->p24 = p;
   q->b32 = 14;
   q->b33 = i;
   i++;
   q->w38 = 0x2600;
  } else break;
 }
 return q;
}
struct LinkedActor *func_0c1b2e9c(struct LinkedActor *p,unsigned char kind)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,4,0))!=0){q->p16=func_0c1b2ed0;q->p24=p;q->b32=kind;q->w38=0x2600;}
 return q;
}
void func_0c1b2ed0(struct LinkedActor *a)
{
 dat_0c2fb42c=a->wcc.arrcc;
 dat_0c25aecc[a->b4](a);
}
void func_0c1b2eec(struct LinkedActor *a)
{
 struct LinkedActor *parent=a->p24;
 a->sdc=parent->sdc;
 a->sdc.b12c=1;
 a->b2=parent->b2;a->b1=parent->b1;
 a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
 a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;
 a->b48=parent->b48;
 a->v80=parent->v80;
 a->b36=parent->b36;
 a->b4++;
 dat_0c25aedc[a->b32](a);
}
