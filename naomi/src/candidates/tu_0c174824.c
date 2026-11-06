/* Full 0x0c174824..0x0c1749ac constructor, fan-out, vector and dispatch translation. Constructor and dispatcher exact; fan-out and trigonometric helper need further matching. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct SpawnRecord1748 {short a,b,c,d;};
extern struct LinkedActor *func_0c0374da(int,int,int);
extern float func_0c1ebd40(int),func_0c1ec2c0(int);
extern void (*table_0c253558[])(struct LinkedActor *,struct SpawnRecord1748 *);
void func_0c17495a(struct LinkedActor *);
struct LinkedActor *func_0c174824(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c17495a;a->p24=owner;a->p20=owner;a->b32=0;a->w38=0x3001;*(unsigned char *)((char *)a+0xbe)=*(unsigned char *)((char *)A(owner)+0x1e9);}
 return a;
}
void func_0c174860(struct LinkedActor *source,struct SpawnRecord1748 *input,int count)
{
 int i;
 for(i=0;i<count;i++){
 struct LinkedActor *a=func_0c0374da((int)source,1,2);struct SpawnRecord1748 *record=(struct SpawnRecord1748 *)((char *)a+0x88);
 a->p16=func_0c17495a;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&source->f52;a->b32=1;a->p24=source;a->p20=source->p20;a->b34=source->b34;a->w38=0x3001;
 record->a=input->a;record->b=input->b;record->c=input->c;record->d=input->d;
 }
}
void func_0c1748da(unsigned int angle,float *output)
{
 short theta=(short)(((40-((unsigned char)(angle+4)>>3))&31)<<11);
 register float amplitude=409600.0f,factor=256.0f,coefficient=1000.0f;
 float x=amplitude*func_0c1ebd40(theta);x*=coefficient;x/=100000.0f;x/=factor;x*=1.66666663f;output[0]=x;
 amplitude*=func_0c1ec2c0(theta);amplitude*=coefficient;amplitude/=125000.0f;amplitude/=factor;amplitude*=2.1428571f;output[1]=amplitude;
}
void func_0c17495a(struct LinkedActor *a){table_0c253558[a->b4](a,(struct SpawnRecord1748 *)((char *)a+0x88));}
