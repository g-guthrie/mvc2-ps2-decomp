/* Mode-selected burst allocation, owner dispatch, and motion initialization. */
#include "objects.h"
extern short dat_0c25bc50[],dat_0c25bc4c[],dat_0c25bc70[];
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25bc94[])(struct LinkedActor *,struct LinkedActor *),(*table_0c25bca4[])(struct LinkedActor *);
void func_0c1bc15e(struct LinkedActor *);
struct LinkedActor *func_0c1bc0ac(struct LinkedActor *parent,unsigned short mode){
 short *offsets=dat_0c25bc50;unsigned char count=8,i;struct LinkedActor *a;
 if(!mode){offsets=dat_0c25bc4c;count=1;}
 if(mode==2){offsets=dat_0c25bc70;count=9;}
 for(i=0;i<count;i++){
 if((a=func_0c0374da(0,3,0))){
 a->p16=func_0c1bc15e;a->p24=parent;a->b1=parent->b1;a->b32=mode;a->w38=0x3602;
 a->wcc.pointer_value=parent->p24;a->f92=parent->f92;
 a->f52=parent->f52+*offsets++*1.66666663f;
 a->f56=parent->f56+*offsets++*2.1428571f;
 }
 }return a;
}
void func_0c1bc15e(struct LinkedActor *a){
 struct LinkedActor *owner=a->wcc.pointer_value;
 ((int *)owner)[0x2b8/4]=4;table_0c25bc94[a->b4](a,owner);
}
void func_0c1bc17c(struct LinkedActor *a,struct LinkedActor *owner){
 float zero;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b36=8;zero=0.0f;a->f104=zero;a->f108=zero;
 table_0c25bca4[a->b32](a);
}
