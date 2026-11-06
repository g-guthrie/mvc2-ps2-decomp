#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c24e4c8[])(struct LinkedActor *),(*table_0c24e4d8[])(struct LinkedActor *),(*table_0c24e4e4[])(struct LinkedActor *);
extern float dat_0c2d92f0;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct ActorSubByteState dat_0c2d9260;
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037d0c(struct LinkedActor *),func_0c0346da(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
void func_0c135438(struct LinkedActor *),func_0c1355ea(struct LinkedActor *);
struct LinkedActor *func_0c135404(struct LinkedActor *owner,char mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c135438;a->p24=owner;a->b32=mode;a->w38=0x400;}
 return a;
}
void func_0c135438(struct LinkedActor *a){table_0c24e4c8[a->b4](a);}
void func_0c13544a(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->f56=dat_0c2d92f0;((struct Actor *)a)->f92=0.0f;((struct Actor *)a)->f104=0.0f;a->f96=-17.142857f;((struct Actor *)a)->f108=-1.07142854f;a->b36=11;a->pad11[0]=66;a->pad11[1]=66;
 table_0c24e4d8[a->b32](a);func_0c1355ea(a);
}
void func_0c135504(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;int zero=0;
 if(owner->b255==3)a->b1a1=49;else {goto effect;effect:a->b1a1=48;}
 a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;goto animate;animate:func_0c02a0c4((struct LinkedActor *)a,21,18);
}
void func_0c135584(struct LinkedActor *a)
{
 ((struct Actor *)a)->b1a1=80;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,10);
}
void func_0c1355b2(struct LinkedActor *a)
{
 ((struct Actor *)a)->w130^=1;((struct Actor *)a)->b1a1=67;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,22,14);
}
void func_0c1355ea(struct LinkedActor *a){table_0c24e4e4[(unsigned char)a->b5](a);}
void func_0c1355fc(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<((struct Actor *)((struct LinkedActor *)a)->p24)->f41c){a->b5++;a->f56=((struct Actor *)((struct LinkedActor *)a)->p24)->f41c;dat_0c2d9260.b5=3;dat_0c2d9260.b6=1;func_0c02a026((struct LinkedActor *)a);func_0c0346da((struct LinkedActor *)a,a->b32!=2?47:49);return;}
 if(a->b32!=2 && a->b19e){a->b5++;func_0c02a026((struct LinkedActor *)a);return;}
 func_0c037d0c((struct LinkedActor *)a);
}
