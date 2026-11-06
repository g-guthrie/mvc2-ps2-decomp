#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c0344a0(struct LinkedActor *,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c257830[])(struct LinkedActor *);
extern float table_0c257810[][2];extern short table_0c257800[];
void func_0c1921b8(struct LinkedActor *);void func_0c192384(struct LinkedActor *);void func_0c1923e6(struct LinkedActor *);
struct LinkedActor *func_0c192148(struct LinkedActor *owner)
{
 signed char i;struct LinkedActor *a;
 for(i=0;i<=8;i++)if((a=func_0c0374da(0,3,0))){a->p16=func_0c1921b8;a->p24=owner;a->w38=0x900;a->b32=i;a->b33=7;a->s28=32;a->s30=118;}
 return a;
}
void func_0c1921b8(struct LinkedActor *a){table_0c257830[a->b4](a);}
void func_0c1921ca(struct LinkedActor *a)
{
 if(--a->s28<=0){if((unsigned char)--a->b33>0)goto initialize;a->b4=2;func_0c1923e6(a);return;}
 goto done;
 initialize:a->b4++;
a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(a->b32&4){float *velocity;func_0c02a0c4(a,23,5);velocity=&table_0c257810[0][0];A(a)->f92=velocity[(a->b32-4)*2];velocity+=(a->b32-4)*2;A(a)->f104=velocity[1];A(a)->f96=12.85714245f;A(a)->f108=-0.2678571343422f;}
 else {func_0c02a0c4(a,23,4);A(a)->f92=0;A(a)->f96=0;A(a)->f104=0;A(a)->f108=0;}
 a->f52+=table_0c257800[a->b32]*1.66666663f;a->f56+=a->s30*2.1428571f;
 if(!a->b32)func_0c0344a0(a,10);func_0c192384(a);return;
 done:;
}
void func_0c192384(struct LinkedActor *a)
{int zero;a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(func_0c02a026(a)<0){zero=0;a->b4=zero;a->sdc.b12c=zero;a->s30-=19;}}
void func_0c1923e6(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
