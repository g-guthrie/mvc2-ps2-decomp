#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c257850[])(struct LinkedActor *);
extern short table_0c257840[][2];
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c192438(struct LinkedActor *);
void func_0c192546(struct LinkedActor *);
void func_0c19259c(struct LinkedActor *);
struct LinkedActor *func_0c192404(struct LinkedActor *owner,char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c192438;a->p24=owner;a->b32=mode;a->w38=0x901;}return a;}
void func_0c192438(struct LinkedActor *a){table_0c257850[a->b4](a);}
void func_0c19244a(struct LinkedActor *a)
{
 float dx;short *table;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->b36=7;a->f52=a->p24->f52;a->f56=a->p24->f56;
 table=&table_0c257840[0][0];
 dx=table[a->b32*2]*1.66666663f;if(a->p24->sdc.w130)dx=-dx;
 a->f52+=dx;a->f56+=table[a->b32*2+1]*2.1428571f;
 if(a->b32&1)func_0c02a0c4(a,20,1);else func_0c02a0c4(a,20,0);func_0c192546(a);
}
void func_0c192546(struct LinkedActor *a)
{if(func_0c02a026(a)<0){a->b4++;func_0c19259c(a);}}
void func_0c19259c(struct LinkedActor *a)
{a->b4++;a->sdc.b12c=0;func_0c037688(a);}
