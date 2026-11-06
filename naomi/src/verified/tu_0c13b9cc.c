#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern short dat_0c2f6830;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,char);
extern void (*table_0c24efb0[])(struct LinkedActor *);
void func_0c13ba1e(struct LinkedActor *);
int func_0c13b9cc(struct LinkedActor *owner)
{
 int i;struct LinkedActor *a;
 if(dat_0c2f6830<=2)return 0;
 for(i=0;i<2;i++){a=func_0c0374da(0,1,1);a->w38=0x701;a->b32=i;a->p16=func_0c13ba1e;a->p24=owner;}
 return 1;
}
void func_0c13ba1e(struct LinkedActor *a){table_0c24efb0[a->b4](a);}
void func_0c13ba30(struct LinkedActor *record)
{
 struct LinkedActor *a=record;struct ActorSub2a4 *sub;struct Actor *other;
 record=a->p24;sub=&((struct Actor *)record)->sub2a4;a->b4++;a->sdc=record->sdc;a->sdc.b12c=1;
 a->b2=record->b2;a->b1=record->b1;a->v80.x=record->v80.x;a->v80.y=record->v80.y;a->b1a3=record->b1a3;a->b1a4=record->b1a4;a->b48=record->b48;
 a->v80=record->v80;a->b36=record->b36;a->pad11[0]=64;a->pad11[1]=64;a->b36=a->b32?12:11;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&record->f52;
 other=((struct ActorChildReference *)sub)->child;a->f56+=(other->b13c/2)*2.1428571f;
 if(!a->b33){((struct Actor *)a)->b1a1=58;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;func_0c037d0c(a);}
 func_0c02a0c4(a,23,a->b32);
}
