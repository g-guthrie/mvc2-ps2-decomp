/* Linked actor pair spawner and child chain; matches retail exactly. */
#include "objects.h"
struct EffectMask_13bbc4 {unsigned char pad[59];unsigned char index;unsigned short bits;};
extern struct EffectMask_13bbc4 dat_0c2f8338;
extern short dat_0c2f6830;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c24efbc[])(struct LinkedActor *);
extern void (*table_0c24efc4[])(struct LinkedActor *,struct LinkedActor *),(*table_0c24efd0[])(struct LinkedActor *,struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *),func_0c02a39a(struct LinkedActor *,int);
void func_0c13bc20(struct LinkedActor *),func_0c13be16(struct LinkedActor *,struct LinkedActor *);
int func_0c13bbc4(struct LinkedActor *owner)
{
 int i,mode;struct LinkedActor *a;
 if(dat_0c2f6830<=2)return 0;
 mode=0;
 for(i=0;i<2;i++){a=func_0c0374da(0,1,1);a->w38=0x702;a->b32=mode;a->b33=i;a->p16=func_0c13bc20;a->p24=owner;}
 return 1;
}
void func_0c13bc20(struct LinkedActor *a){table_0c24efbc[a->b32](a);}
void func_0c13bc34(struct LinkedActor *a){table_0c24efc4[a->b4](a,a->p24);}
void func_0c13bc48(struct LinkedActor *a,struct LinkedActor *owner)
{
 int flipped,zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->s28=4;a->pad11[0]=66;a->pad11[1]=66;a->b36=a->b33?12:11;zero=0;((struct Actor *)a)->w130=a->b33?0:1;
 a->f52=owner->f52;a->f56=owner->f56+85.71428f;
 ((struct Actor *)a)->b1a1=68;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c13be16(a,owner);func_0c02a0c4(a,23,a->b32+14);
}
void func_0c13bd54(struct LinkedActor *a,struct LinkedActor *owner)
{
 int zero;
 if(dat_0c2f8338.bits&(1<<dat_0c2f8338.index))return;
 zero=0;
 if(!owner->b5 && owner->b1d0==29){
 a->sdc.b141=zero;
 if(func_0c02a026(a)>=0){if(((struct Actor *)a)->b14b){((struct Actor *)a)->b1a1=((struct Actor *)a)->b14b;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;((struct Actor *)a)->b14b=zero;}goto animate;}
 if(--a->s28)goto animate;}
 a->b4=2;a->sdc.b12c=zero;owner->s30=1;return;
animate:func_0c037d0c(a);
}
void func_0c13bdfc(struct LinkedActor *a,struct LinkedActor *owner){func_0c02a39a(owner,0);func_0c037688(a);}
void func_0c13be16(struct LinkedActor *source,struct LinkedActor *owner)
{
 int i;struct LinkedActor *a;int mode=1;
 for(i=0;i<4;i++){if(a=func_0c0374da((int)source,1,2)){a->w38=0x702;a->b32=mode;a->b33=source->b33;a->s28=i;a->p16=func_0c13bc20;a->p24=owner;a->p20=source;}else break;}
}
void func_0c13be78(struct LinkedActor *a){table_0c24efd0[a->b4](a,a->p24);}
