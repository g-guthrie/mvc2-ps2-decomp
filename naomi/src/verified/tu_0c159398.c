/* Spawner pair: six linked children sharing an owner and a position. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c15903c(struct LinkedActor *);
void func_0c159398(struct LinkedActor *owner,struct LinkedActorVec3 *pos,unsigned char kind,unsigned char index)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,0))) {
        a->p24=owner;
        a->p16=func_0c15903c;
        *(struct LinkedActorVec3 *)((char *)a+52)=*pos;
        a->b32=kind;
        a->b33=index;
    }
}
void func_0c1593e2(struct LinkedActor *owner,struct LinkedActorVec3 *pos,unsigned char kind)
{
    unsigned char i;
    for (i=0;i<6;i++) func_0c159398(owner,pos,kind,i);
}
