/* Exact 0x0c1c004c..0x0c1c00bc: allocate the effect and retire it when the owner leaves its required action state. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
void func_0c1c0078(struct LinkedActor *);
struct LinkedActor *func_0c1c004c(struct LinkedActor *owner)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,10,1))){q->w38=9;q->p16=func_0c1c0078;q->p24=owner;}
 return q;
}
void func_0c1c0078(struct LinkedActor *q)
{
 struct Actor *owner=(struct Actor *)q->p24;
 if(owner->b5||*((unsigned char *)owner+0x1e9)!=1||owner->b1d0!=21||*((unsigned char *)owner+0x159)!=21)func_0c037688(q);
}
