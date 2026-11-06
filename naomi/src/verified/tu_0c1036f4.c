#include "objects.h"
extern int func_0c03916c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c0437b8(struct Actor *),func_0c02a684(struct Actor *,int,int,int);
extern void (*table_0c24b274[])(struct Actor *),(*table_0c24b294[])(struct Actor *);
void func_0c1036f4(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 int command;char (*update)(struct Actor *);
 if(a->b1d0==22 && func_0c03916c(a)){func_0c02a39a(a,0);func_0c0437b8(a);return;}
 update=func_0c02a026;
 switch(a->b32){
 case 0:
  if(!sub->b1)goto animate;
  update(a);
  goto event;
event:
  if(a->b141){command=a->b37*48+35;if(a->b141&1)command++;func_0c02a684(a,0,command,1);}
  break;
 case 2:case 1:case 3:case 4:
animate:update(a);break;
 }
}
void func_0c10379e(struct Actor *a){table_0c24b274[a->b1e9](a);}
void func_0c1037b2(struct Actor *a){table_0c24b294[a->b6](a);}
