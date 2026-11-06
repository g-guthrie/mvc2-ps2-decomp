#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25711c[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c25712c[])(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,unsigned char,unsigned char),func_0c18f21e(struct LinkedActor *);
void func_0c18d652(struct LinkedActor *),func_0c18d6e6(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c18d5f8(struct LinkedActor *parent)
{
 struct LinkedActor *a;
 int i;
 for(i=0;i<8;i++){
  if((a=func_0c0374da(0,4,0))!=0){
   struct LinkedActorStep88 *step=(struct LinkedActorStep88 *)a->pad9b;
   a->p16=func_0c18d652;a->p24=parent;a->b1=parent->b1;a->b33=i;a->w38=0x0302;step->request=4;
  }
 }
 return a;
}
void func_0c18d652(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 a->sdc.b12c=0;a->b36=owner->b36;
 table_0c25711c[a->b4](a,owner);
}
void func_0c18d674(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;
 func_0c029e70(a,27,8);
 func_0c18d6e6(a,owner);
}
void func_0c18d6e6(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActorStep88 *step=(struct LinkedActorStep88 *)a->pad9b;
 int zero=0;
 if(!owner->sdc.b12c){a->sdc.b12c=zero;return;}
 if(step->request!=step->current){a->b7=zero;a->b6=zero;a->b5=zero;step->current=step->request;return;}
 table_0c25712c[step->request&15](a);
}
void func_0c18d728(struct LinkedActor *a){func_0c18f21e(a);}
