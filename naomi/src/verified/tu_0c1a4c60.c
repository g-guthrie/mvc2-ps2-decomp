#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c029f0e(struct LinkedActor *,int,int,int),func_0c037688(struct LinkedActor *);
extern void (*table_0c259098[])(struct LinkedActor *);
void func_0c1a4c8c(struct LinkedActor *),func_0c1a4d58(struct LinkedActor *),func_0c1a4d64(struct LinkedActor *);
struct LinkedActor *func_0c1a4c60(struct LinkedActor *parent) {
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){a->p16=func_0c1a4c8c;a->p24=parent;a->w38=0x1605;}
 return a;
}
void func_0c1a4c8c(struct LinkedActor *a){table_0c259098[a->b4](a);}
void func_0c1a4c9e(struct LinkedActor *a){
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=0;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 func_0c029e70(a,27,11);
}
void func_0c1a4d22(struct LinkedActor *a){
 struct Actor *parent=(struct Actor *)a->p24;
 a->f52=parent->f52;a->f56=a->p24->f56;a->b36=0;
 if((int)parent->b14b-1<0){func_0c1a4d58(a);return;}
 func_0c029f0e(a,27,11,(signed char)parent->b14b-1);
}
void func_0c1a4d58(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c1a4d64(a);}
void func_0c1a4d64(struct LinkedActor *a){func_0c037688(a);}
