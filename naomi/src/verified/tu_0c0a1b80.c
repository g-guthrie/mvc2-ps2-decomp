#include "objects.h"
extern void func_0c09e43a(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c04c010(struct Actor *,struct Actor *,int),func_0c04af58(struct Actor *,int);
extern void func_0c1ceab2(struct Actor *,struct LinkedActorVec3 *,int);
extern unsigned int func_0c02849a(void);
extern int dat_0c2d9634;
void func_0c0a1b80(register struct Actor *a)
{
 struct LinkedActorVec3 position;unsigned char action;
 func_0c09e43a(a);a->b1ea=1;a->b1ed=2;a->b1f5=2;dat_0c2d9634=2;
 if(a->s28--==0){a->b6++;a->s28=80;func_0c02a0c4(a,22,8);}
 if(a->s28%9==1){
  register struct Actor *child=a->p1c8;
  position.x=(float)(func_0c02849a()&63u)*1.66666663f;
  position.y=(float)(func_0c02849a()&95u)*2.1428571f;
  action=(func_0c02849a()&7u)+9;func_0c1ceab2(child,&position,action);
  func_0c0346da(a,func_0c02849a()%3u+4);
  func_0c04c010(child,a,1);func_0c04af58(child,-2);
 }
}
