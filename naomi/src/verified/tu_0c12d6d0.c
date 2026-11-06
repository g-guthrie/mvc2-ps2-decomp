#include "objects.h"
extern int func_0c037d54(struct Actor *);
extern void func_0c048ce6(struct Actor *),func_0c0426c2(struct Actor *,int),func_0c0427be(struct Actor *,int),func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24de34[])(struct Actor *,struct Actor *);
int func_0c12d6d0(struct Actor *a)
{
 int result;
 if(a->b200 || a->b1f9==1)return 0;goto inputs;inputs:if(!a->b1a3 || !(a->w1fa&0xc00))return 0;
 if(a->b1fe){if(a->b1f9==2)return 0;if((result=func_0c037d54(a)))a->b1f7=1;}
 else if(a->b1f9==2){if((result=func_0c037d54(a)))a->b1f7=2;}
 else{if((result=func_0c037d54(a)))a->b1f7=0;}
 return result;
}
void func_0c12d760(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;struct Actor *other=a->p1c8;
 func_0c048ce6(a);a->b1ed=3;*(char *)&sub->s12=0;other->w130=a->w130;other->w130^=1;other->b1d2=*(char *)&other->w130;table_0c24de34[a->b1f7](a,other);
}
void func_0c12d7b4(struct Actor *a,struct Actor *other)
{
 func_0c0426c2(other,56);func_0c0427be(a,2);func_0c025900(a,6,6);func_0c02a0c4(a,15,0);
}
