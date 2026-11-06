#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern int func_0c1d91a8(int),func_0c1d8ff8(int,int),func_0c1d901e(void);
extern int func_0c1d912a(int *,float *),func_0c1d917e(int *,float *);
void func_0c1e151e(struct Obj_tu5_03 *);
void func_0c1e14c4(struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e151e;
  a->l84=dat_0c2d964c->p0->entries[30].value;a->lcc=0x800;
  a->p20=parent;a->p200=&parent->f136;
  func_0c1d91a8(a->l84);
 }
}
void func_0c1e151e(struct Obj_tu5_03 *a)
{
 int first;float value;
 switch(a->b4){
 case 0:
  a->w28++;
  if(a->w28>=100)a->w28=0;
  func_0c1d8ff8((*(int (*)[36])dat_0c2d964c->p0)[31],a->l84);
  while(func_0c1d901e()==0){
   func_0c1d912a(&first,&value);
   value+=a->w28*0.0100000001f;
   func_0c1d917e(&first,&value);
  }
  break;
 }
}
