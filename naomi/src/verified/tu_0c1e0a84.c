/* Exact 0x0c1e0a84..0x0c1e0b60: select frame resources and allocate an effect linked to owner parameters. */
#include "objects.h"
extern unsigned int dat_0c2626c8[],dat_0c262668[][3];
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct LinkedActor *func_0c0374da(int,int,int);
void func_0c1e0a84(struct LinkedActor *q)
{
 struct ActorGlobalRoot *root=dat_0c2d964c;
 if(dat_0c262668[dat_0c2626c8[q->s28]][q->b32])q->p84=((void **)root->p0)[q->b32+31];
 else q->p84=((void **)root->p0)[q->b32+34];
 if(++q->s30>=10){int zero=0;q->s30=zero;if((unsigned int)++q->s28>=20)q->s28=zero;}
}
void func_0c1e0b04(struct Actor *owner,int mode)
{
 struct LinkedActor *q;
 if((q=func_0c0374da(0,5,1))!=0){q->sdc.b12c=1;q->p16=func_0c1e0a84;q->wcc.dword_value=0x0800;
 *(float **)&q->pad9b[0xc8-0x88]=&owner->f136;q->b32=mode;}
}
