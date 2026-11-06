/* Two dispatchers and all pools exact; constructors differ in 18 register-scheduling bytes. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c256274[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c25627c[])(struct LinkedActor *);
void func_0c18c81c(struct LinkedActor *);
struct LinkedActor *func_0c18c76c(struct LinkedActor *owner)
{
 int zero=0,index=zero,limit=15,tag=0x300;
 struct LinkedActor *q;
 for(index=0;index<limit;index++){
 if((q=func_0c0374da(0,4,1))){q->p16=func_0c18c81c;q->p24=owner;q->b1=owner->b1;q->b32=zero;q->b33=index;q->w38=tag;}
 }
 return q;
}
struct LinkedActor *func_0c18c7c4(struct LinkedActor *owner)
{
 int index=0,one=1,limit=2,tag=0x300;
 struct LinkedActor *q;
 for(index=0;index<limit;index++){
 if((q=func_0c0374da(0,4,1))){q->p16=func_0c18c81c;q->p24=owner;q->b1=owner->b1;q->b32=one;q->b33=index;q->w38=tag;}
 }
 return q;
}
void func_0c18c81c(register struct LinkedActor *q)
{
 struct LinkedActor *owner=q->p24;
 q->b36=owner->b36;
 table_0c256274[q->b32](q,owner);
}
void func_0c18c83a(struct LinkedActor *q){table_0c25627c[q->b4](q);}
