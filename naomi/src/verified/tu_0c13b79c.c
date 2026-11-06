/* Linked actor pair spawner and setup; matches retail exactly. The b33 test
 * reads the byte through a char view, which selects retail r2. */
#include "objects.h"
extern short dat_0c2f6830;
struct EffectMask_13b79c { unsigned char pad[59]; unsigned char index; unsigned short bits; };
extern struct EffectMask_13b79c dat_0c2f8338;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c24efa4[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c13b7f6(struct LinkedActor *);
int func_0c13b79c(struct LinkedActor *owner,int mode)
{
 int i; struct LinkedActor *a;
 if(dat_0c2f6830<=2)return 0;
 for(i=0;i<2;i++){a=func_0c0374da(0,1,1);a->w38=0x700;a->b32=mode;a->b33=i;a->p16=func_0c13b7f6;a->p24=owner;}
 return 1;
}
void func_0c13b7f6(struct LinkedActor *a){table_0c24efa4[a->b4](a);}
void func_0c13b808(struct LinkedActor *record)
{
 struct LinkedActor *a=record,*owner;int effect,action;
 record=a->p24;owner=record;a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=64;a->pad11[1]=64;a->b36=a->b33?12:11;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 if(((char *)a)[33])goto select_action;
 {effect=a->b1a3*2+a->b32+59;if(((char *)owner)[32]>0)effect=97;if(((struct Actor *)owner)->b1e9==5)effect=a->b32+65;
 ((struct Actor *)a)->b1a1=effect;((struct Actor *)a)->w1ac=0;((struct Actor *)a)->b19e=0;*(void **)&((struct Actor *)a)->p1c4=(void *)0;dat_0c2f83f8->arr[a->b2]++;
 if(((struct Actor *)owner)->b1e9==5)((struct Actor *)a)->w1ac=64;func_0c037d0c(a);}
 select_action:
 action=a->b1a3*4+a->b32*2+(unsigned char)a->b33;func_0c02a0c4(a,23,action+2);
}
void func_0c13b952(struct LinkedActor *a)
{
 if(!(dat_0c2f8338.bits&(1<<dat_0c2f8338.index))){if(func_0c02a026(a)<0){a->b4++;a->sdc.b12c=0;}else if(!a->b32)func_0c037d0c(a);}
}
void func_0c13b9a0(struct LinkedActor *a){func_0c037688(a);}
