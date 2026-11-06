#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,char,char),func_0c03489c(struct Actor *),func_0c1ce916(struct LinkedActorVec3 *,int,int,int);
void func_0c0eb30c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b1ea=1;a->b1ed=2;a->b1f5=2;func_0c02a026(a);
 if(a->b141){
  int zero=0;struct Actor *other;
  goto L;L:if(a->b141>0){
   a->b6++;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b141=zero;
   other=a->p1c8;other->p1b4=a;other->b1f6=1;other->b1f9=zero;func_0c025900(a,0,0);
   other->b1a1=34;a->f104=0;a->f108=0;a->f96=17.142857f;a->f108=-0.401785702f;a->f92=1.25f;
   if(!a->b1d2)a->f92=-a->f92;
  }else{
   a->b141=zero;other=a->p1c8;other->p1b4=a;other->b1a1=39;
   position.x=a->f52+-133.33333f;if(!a->b1d2)position.x=a->f52+133.33333f;
   position.y=a->f56;func_0c1ce916(&position,(short)other->w130,1,16);func_0c03489c(a);
  }
 }
}
