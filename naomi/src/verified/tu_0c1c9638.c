/* Exact 0x0c1c9638..0x0c1c9704: allocate a positioned effect and advance its scale over eight updates. */
#include "objects.h"
extern struct ActorGlobalRoot *dat_0c2d965c;
extern struct LinkedActorVec3 dat_0c2305e4;
extern struct ActorFlags *dat_0c2d6f84;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c037688(struct LinkedActor *);
void func_0c1c96a0(struct LinkedActor *);
void func_0c1c9638(int index,struct LinkedActorVec3 position)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,5,1))!=0){q->sdc.b12c=1;q->b32=index;q->p16=func_0c1c96a0;
 q->p84=((void **)dat_0c2d965c->p0)[index+19];q->v80=dat_0c2305e4;
 *(struct LinkedActorVec3 *)&q->f52=position;q->wcc.dword_value=0x0811;q->s28=0;}
}
void func_0c1c96a0(struct LinkedActor *q)
{
 if(dat_0c2d6f84->b3==2&&q->s28!=8){q->s28++;q->v80.x=1.0f+(float)q->s28*0.375f;q->v80.y=q->v80.x;}
 else func_0c037688(q);
}
