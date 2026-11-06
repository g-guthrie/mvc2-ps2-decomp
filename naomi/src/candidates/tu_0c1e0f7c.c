#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2627dc;
extern int func_0c1d8ff8(void *,void *),func_0c1d901e(void);
extern int func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
void func_0c1e0fd2(struct Obj_tu5_03 *);
void func_0c1e0f7c(struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e0fd2;
  a->l84=(*(int (*)[36])dat_0c2d964c->p0)[32];
  a->pos=dat_0c2627dc;a->lcc=0x801;
  a->p200=&parent->f136;a->p20=parent;
 }
}
void func_0c1e0fd2(struct Obj_tu5_03 *a)
{
 struct Vec3_tu5_03 point;
 switch(a->b4){
 case 0:
  if(a->p20->b5)goto advance;
  break;
 case 1:
  a->w28++;
  if(a->w28>=400){a->w28=0;
advance:
   a->b4++;
  }else{
   func_0c1d8ff8((void *)(*(int (*)[36])dat_0c2d964c->p0)[33],(void *)a->l84);
   while(func_0c1d901e()==0){
    func_0c1d9100(&point);
    point.x-=point.y*(a->w28/400.0f)*0.200000003f;
    func_0c1d914c(&point);
   }
  }
  break;
 case 2:break;
 }
}
