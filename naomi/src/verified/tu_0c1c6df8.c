/* Fixed-angle orbit markers: spawn, dispatch, and the 0x200-step sweep. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9658;
extern unsigned char dat_0c2d7088[];
extern struct Vec3_tu5_03 table_0c25e69c[];
extern int table_0c25e6b4[][3];
extern void (*table_0c25e6cc[])(struct Obj_tu5_03 *);
extern void func_0c1c7024(struct Obj_tu5_03 *),func_0c1c7368(struct Obj_tu5_03 *),func_0c1c7090(struct Obj_tu5_03 *,int),func_0c034a1c(int);
void func_0c1c6df8(struct Actor *parent)
{
 struct Obj_tu5_03 *q;struct ActorGlobalRoot *root;
 if((q=func_0c0374da(0,5,1))){
 q->b12c=1;q->p16=func_0c1c7024;q->p24=(struct Obj_tu5_03 *)parent;
 q->p20=(struct Obj_tu5_03 *)(dat_0c2d7088+(parent->s30*2+parent->b524)*0x5a4);
 q->b32=parent->b524;q->b33=parent->s30;root=dat_0c2d9658;
 if(q->b32)q->l84=(int)((void **)root->p0)[105];
 else q->l84=(int)((void **)root->p0)[98];
 q->pos=table_0c25e69c[q->b32];
 q->angles.array[0]=table_0c25e6b4[q->b32][0];q->angles.scalar.l44=table_0c25e6b4[q->b32][1];q->angles.scalar.l48=table_0c25e6b4[q->b32][2];
 q->lcc=0x80f;func_0c1c7090(q,1);func_0c1c7368(q);func_0c034a1c((signed char)q->b32+76);
 }
}
void func_0c1c6ef0(struct Obj_tu5_03 *a){table_0c25e6cc[a->b4](a);}
void func_0c1c6f02(struct Obj_tu5_03 *q)
{
 if(q->b32){
  q->angles.scalar.l48-=0x200;
  if(q->angles.scalar.l48<=0)goto next;
 }else{
  q->angles.array[2]+=0x200;if(q->angles.scalar.l48>=0x10000){next:q->b4++;q->angles.scalar.l48=0;}
 }
}
