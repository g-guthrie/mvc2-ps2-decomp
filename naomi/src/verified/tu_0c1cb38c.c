#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9670;
extern float func_0c1ec2c0(int);
void func_0c1cb3c0(struct LinkedActor *);
void func_0c1cb38c(void)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,11,1))){
 a->sdc.b12c=1;a->p16=func_0c1cb3c0;
 a->p84=dat_0c2d9670->p0->entries[9].pointer;A(a)->i204=0xc00;
 }
}
void func_0c1cb3c0(struct LinkedActor *a)
{
 register float scale=0.75f;
 switch(a->b4){
 case 0:{float value=((struct Obj_tu5_03 *)a)->f120;value+=0.01f;
 if(!(scale>value)){value=scale;a->b4++;}
 ((struct Obj_tu5_03 *)a)->f120=value;((struct Obj_tu5_03 *)a)->f124=value;((struct Obj_tu5_03 *)a)->f128=value;break;}
 case 1:{float value=scale+func_0c1ec2c0((int)(a->s28*65536.0f/360.0f+0.5f)&65535)*0.25f;
 ((struct Obj_tu5_03 *)a)->f120=value;((struct Obj_tu5_03 *)a)->f124=value;((struct Obj_tu5_03 *)a)->f128=value;
 a->s28+=5;if(a->s28>=360)a->s28=0;break;}
 }
}
