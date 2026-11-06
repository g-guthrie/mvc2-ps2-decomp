#include "objects.h"
extern int func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c048ce6(struct Actor *),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24b334[])(struct Actor *);
int func_0c105070(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 int result;
 int (*check)(struct Actor *);
 if(((unsigned char *)sub)[9]||((unsigned char *)sub)[12])return 0;
 goto flags;flags:if(!(a->w1fa&0xc00))return 0;
 if(a->b1a3==0)return 0;
 check=func_0c037d54;
 goto choose;choose:if(!a->b1fe){
  if(a->b1f9!=2){if((result=check(a))){a->b1f7=0;return result;}}
  else{if((result=check(a))){a->b1f7=1;goto return_air;return_air:return result;}}
 }else{if((result=check(a))){a->b1f7=2;return result;}}
 return 0;
}
void func_0c1050ee(struct Actor *a){table_0c24b334[a->b1f7&63](a);}
void func_0c105106(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,5,5);
 if(a->w1fa&0x800){a->w130^=1;a->b1d2^=1;}
 func_0c048ce6(a);position.x=-40.0f;position.y=137.142853f;func_0c1d4610(a,&position);
 a->b1a0=10;a->b6=0;a->b7=0;func_0c02a0c4(a,15,0);
}
