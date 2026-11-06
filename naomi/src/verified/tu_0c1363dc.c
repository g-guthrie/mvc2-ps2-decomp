/* Owner effect spawner and its state dispatcher. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c034560(struct Actor *,struct Actor *,int);
extern void func_0c1ce70c(struct Actor *,int,int,float,float);
extern void (*table_0c24e56c[])(struct Actor *);
void func_0c136464(struct Actor *a);

void func_0c1363dc(struct Actor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){
  a->p16=(void (*)(struct LinkedActor *))func_0c136464;a->p24=(struct LinkedActor *)owner;a->p20=(struct LinkedActor *)owner->p1b4;a->w38=0x404;((struct Actor *)a)->b0=1;
  if(owner->p1b4->b1==4){func_0c034560(owner,owner->p1b4,45);func_0c034560(owner,owner->p1b4,48);}
  func_0c1ce70c(owner,0,0,2.0f,2.0f);func_0c1ce70c(owner,16,0,2.0f,2.0f);func_0c1ce70c(owner,240,0,2.0f,2.0f);
 }
}

void func_0c136464(struct Actor *a){table_0c24e56c[a->b4](a);}
