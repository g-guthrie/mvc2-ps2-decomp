/* Candidate 0x0c1df94c..0x0c1dfa10: constructor and wrapper exact; animation updater differs in signed-remainder temporary-register allocation. All pools exact. */
#include "objects.h"
extern unsigned int dat_0c2332b0[];
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct LinkedActorVec3 dat_0c2332c0;
extern struct LinkedActor *func_0c0374da(int,int,int);
void func_0c1df94c(struct LinkedActor *q)
{
 int remainder;
 if(++q->s28>=10){q->s28=0;q->b4++;q->b4&=3;q->p84=((void **)dat_0c2d964c->p0)[dat_0c2332b0[q->b4]];}
 remainder=q->s28;if(remainder>=0)remainder&=1;else remainder=-((-remainder)&1);
 if(!remainder)q->sdc.b12c^=1;
}
void func_0c1df9ac(void)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,5,1))!=0){
 q->sdc.b12c=1;q->p16=func_0c1df94c;q->p84=((void **)dat_0c2d964c->p0)[45];q->wcc.dword_value=0x0801;
 *(struct LinkedActorVec3 *)&q->f52=dat_0c2332c0;
 }
}
void func_0c1df9ee(void){func_0c1df9ac();}
