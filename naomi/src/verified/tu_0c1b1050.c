#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct ActorSub2a4 *dat_0c2fb424;
extern union LinkedActorWcc *dat_0c2fb420;
extern void (*dat_0c25ad80[])(struct LinkedActor *),(*dat_0c25ad94[])(struct LinkedActor *);
void func_0c1b10e0(struct LinkedActor *);
struct LinkedActor *func_0c1b1050(struct LinkedActor *parent,unsigned char mode,unsigned char phase)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){a->p16=func_0c1b10e0;a->p24=parent;a->b32=mode;a->b33=phase;((struct MeActor *)a)->w26=0x2000;}return a;
}
struct LinkedActor *func_0c1b1092(struct LinkedActor *owner,unsigned char mode,unsigned char phase)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))!=0){a->p16=func_0c1b10e0;a->p24=owner->p24;a->p20=owner;a->b32=mode;a->b33=phase;((struct MeActor *)a)->w26=0x2000;}return a;
}
void func_0c1b10e0(struct LinkedActor *a){dat_0c2fb424=&((struct Actor *)a->p24)->sub2a4;dat_0c2fb420=&a->wcc;dat_0c25ad80[a->b32](a);}
void func_0c1b1108(struct LinkedActor *a){dat_0c25ad94[a->b4](a);}
