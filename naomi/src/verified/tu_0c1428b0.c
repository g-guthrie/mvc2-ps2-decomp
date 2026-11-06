#include "objects.h"
extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f888[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,char);
void func_0c142908(struct LinkedActor *);
int func_0c1428b0(struct LinkedActor *owner)
{
 int i;struct LinkedActor *a;
 if(dat_0c2f6830<=4)return 0;
 for(i=0;i<4;i++){if((a=func_0c0374da(0,1,1))){a->w38=0xe01;a->b32=i;a->p16=func_0c142908;a->p24=owner;}}
 return i;
}
void func_0c142908(struct LinkedActor *a){table_0c24f888[a->b4](a,a->p24);}
void func_0c14291c(struct LinkedActor *a,struct LinkedActor *owner)
{
 int zero;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->pad11[0]=70;a->pad11[1]=70;a->b36=12;zero=0;a->b33=zero;a->f52=owner->f52;a->f56=owner->f56+171.42856f;
 if(!a->b32){((struct Actor *)a)->b1a1=55;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;}
 func_0c037d0c(a);func_0c02a0c4(a,23,a->b32+10);
}
