#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0427f2(struct Actor *),func_0c042780(struct Actor *);
extern void func_0c044f1c(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void func_0c03edcc(struct Actor*,struct Actor*);
extern void func_0c03f004(struct Actor*,struct Actor*);
extern void (*table_0c24de70[])(struct Actor *,struct Actor *);
void func_0c12dc44(struct Actor *a)
{
 struct ActorSubControlBytes *sub=(struct ActorSubControlBytes *)&a->sub2a4;
 struct Actor *other=a->p1c8;
 if((a->b141!=8||a->b142==1)&&sub->b13){a->b141=8;a->b142=4;}
 sub->b13=0;
 if(func_0c02a026(a)<0&&sub->b12<0){a->b19d=-128;a->b1ed=0;func_0c044f1c(a);return;}
 if(sub->b12>0){
  if(func_0c0427f2(a))a->b142=1;
  other->s25c--;
  if(func_0c042780(other)){sub->b12=-1;func_0c02a0c4(a,15,3);}
 }
 table_0c24de70[a->b141>>1](a,other);
}

void func_0c12dcf8(struct Actor *a,struct Actor *b){func_0c03edcc(a,b);}

void func_0c12dcfe(struct Actor *a,struct Actor *b){b->s28^=1;func_0c03f004(a,b);}
