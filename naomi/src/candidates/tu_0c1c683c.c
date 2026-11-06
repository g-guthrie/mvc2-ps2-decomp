/* Candidate 0x0c1c683c..0x0c1c690c: two-object wrapper and rotation updater exact; initializer differs in resource-fetch register allocation and zero scheduling. All pools exact. */
#include "objects.h"
extern struct Actor *dat_0c2fb1b0;
extern struct ActorGlobalRoot *dat_0c2d9658;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
void func_0c1c6858(int),func_0c1c68c8(struct Obj_tu5_03 *);
void func_0c1c683c(void){int index=0;do{func_0c1c6858(index);index++;}while(index<2);}
void func_0c1c6858(int index)
{
 struct Obj_tu5_03 *q;int zero;float stopped;
 if((q=func_0c0374da(0,5,1))!=0){q->b12c=1;zero=0;q->p200=(float *)((int)dat_0c2fb1b0+0x88);q->p16=func_0c1c68c8;
 q->l84=(int)((void **)dat_0c2d9658->p0)[index+8];stopped=0.0f;
 q->pos.x=stopped;q->pos.y=stopped;q->pos.z=stopped;
 q->angles.array[0]=zero;q->angles.scalar.l44=zero;q->angles.scalar.l48=zero;q->lcc=0x080f;*(int *)&q->pad8[0xd8-0xd4]=zero;}
}
void func_0c1c68c8(struct Obj_tu5_03 *q){q->angles.array[0]+=0x100;q->angles.scalar.l44=q->angles.scalar.l44+0x180;q->angles.scalar.l48=q->angles.scalar.l48+0x80;}
