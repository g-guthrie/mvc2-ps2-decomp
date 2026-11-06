#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *);
#define MOVE a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108

void func_0c0deae0(struct Actor *a)
{
 func_0c02a026(a);
 MOVE;
 if(a->f96<0.0f && a->f41c>a->f56){
  a->b6++;
  a->f56=a->f41c;
  if(!a->b1f7){func_0c0442fa(a);func_0c02a0c4(a,15,2);}
  else func_0c02a0c4(a,15,4);
 }
}

void func_0c0deb68(struct Actor *a)
{
 if(a->b1f7==2){MOVE;}
 if(func_0c02a026(a)<0){
  if(a->b1f7){}
  if(a->b1f7==2||a->b1f9==2)func_0c0438de(a);
  else func_0c0437b8(a);
 }
}
