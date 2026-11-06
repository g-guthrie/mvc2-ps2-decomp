#include "objects.h"
extern float dat_0c232494[];
extern struct ActorGlobalRoot *dat_0c2d9650;
extern int func_0c1d8ff8(void *,void *);
extern int func_0c1d901e(void);
extern int func_0c1d912a(float *,float *);
extern int func_0c1d917e(const float *,const float *);
void func_0c1d7e5c(struct LinkedActor *a)
{
 float *offset=dat_0c232494;
 struct ActorGlobalRoot *root;
 float first,second;
 offset+=a->s28*2;
 root=dat_0c2d9650;
 if(a->b5)func_0c1d8ff8(((void **)root->p0)[140],a->p84);
 else func_0c1d8ff8(((void **)root->p0)[78],a->p84);
 while(func_0c1d901e()==0){
  func_0c1d912a(&first,&second);
  first+=offset[0];
  second-=offset[1];
  func_0c1d917e(&first,&second);
 }
}
