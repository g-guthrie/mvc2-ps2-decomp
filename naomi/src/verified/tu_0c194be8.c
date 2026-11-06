/* Owner-driven attachment construction, animation and cleanup. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a18c(struct LinkedActor *,int,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c257d24[])(struct LinkedActor *,char *,struct LinkedActor *);
void func_0c194c14(struct LinkedActor *);
struct LinkedActor *func_0c194be8(struct LinkedActor *owner){
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,1))!=0){a->w38=0x0c01;a->p16=func_0c194c14;a->p24=owner;}
 return a;
}
void func_0c194c14(struct LinkedActor *a){table_0c257d24[a->b4](a,(char *)&a->wcc,a->p24);}
void func_0c194c2c(struct LinkedActor *a,char *state,struct LinkedActor *owner){
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;
 a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=0;*state=0;
}
void func_0c194c8e(struct LinkedActor *a,char *state,struct LinkedActor *owner){
 int frame;
 a->b36=owner->b36;a->b49=-4;a->sdc.w130=owner->sdc.w130;
 if((frame=((signed char *)&((struct Actor *)owner)->w150)[1])!=0){
 a->sdc.b12c=1;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 *state=1;func_0c02a18c(a,23,frame+38,owner->sdc.b141);
 }else if(*state){if(func_0c02a026(a)<0){a->sdc.b12c=0;*state=0;}}
}
void func_0c194d12(struct LinkedActor *a){func_0c037688(a);}
