/* Parent-tracking indicator: constructor, retarget, dispatch and fade callbacks. Resource selection reads parent byte 0x21. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9658;
extern unsigned char dat_0c22ff29[];
extern void func_0c1c4e3c(struct Obj_tu5_03 *,char),func_0c037688(struct Obj_tu5_03 *);
extern void (*table_0c25e90c[])(struct Obj_tu5_03 *);
void func_0c1c77bc(struct Obj_tu5_03 *),func_0c1c77fc(struct Obj_tu5_03 *);
struct Obj_tu5_03 *func_0c1c772c(struct Actor *parent)
{
 struct Obj_tu5_03 *q;float stopped;
 if((q=func_0c0374da(0,5,1))){
 goto s;s:q->b12c=1;q->p16=func_0c1c77bc;q->p24=(struct Obj_tu5_03 *)parent;q->p200=&parent->f136;
 stopped=0.0f;q->b33=parent->b33;
 q->l84=((int *)dat_0c2d9658->p0)[121+dat_0c22ff29[parent->b33*2]];
 q->pos.x=stopped;q->pos.y=stopped;q->pos.z=stopped;
 func_0c1c4e3c(q,(signed char)q->b33);q->lcc=0x805;
 }
 return q;
}
void func_0c1c77a6(struct Actor *parent){struct Obj_tu5_03 *q;if((q=func_0c1c772c(parent)))q->p16=func_0c1c77fc;}
void func_0c1c77bc(struct Obj_tu5_03 *q){table_0c25e90c[q->b4](q);}
void func_0c1c77ce(struct Obj_tu5_03 *q){if(q->p24->pos.z<170.0f||q->p24->b4>=2){q->b12c=0;q->b4++;}}
void func_0c1c77f6(struct Obj_tu5_03 *q){func_0c037688(q);}
void func_0c1c77fc(struct Obj_tu5_03 *q)
{
 q->b12c=q->p24->b12c;
 if(!q->b4){if(!q->b12c)q->b4++;}
 else func_0c037688(q);
}
