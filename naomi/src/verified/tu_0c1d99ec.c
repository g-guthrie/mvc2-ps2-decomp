/* Paired child actors copy their parent's visibility and adjust rotation. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c23291c[];
extern void func_0c037688(struct Obj_tu5_03 *);
void func_0c1d9a56(struct Obj_tu5_03 *);
void func_0c1d99ec(struct Obj_tu5_03 *parent,int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->p16=func_0c1d9a56;
  a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n])[7];
  a->pos=dat_0c23291c[n];
  a->lcc=0x809;a->p200=&parent->f136;a->p20=parent;a->b32=n;
 }
}
void func_0c1d9a56(struct Obj_tu5_03 *a)
{
 if(a->p20->b4==1){func_0c037688(a);return;}
 {
  a->b12c=a->p20->b12c;
  switch(a->b32) {
  case 0:a->angles.scalar.l48-=256;break;
  case 1:a->angles.array[2]+=256;break;
  }
 }
}
