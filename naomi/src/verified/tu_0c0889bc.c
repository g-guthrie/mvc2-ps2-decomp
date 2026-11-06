#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c08a46a(struct Actor *,struct ActorSub2a4 *);
extern void func_0c140a9c(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c0426c2(struct Actor *,int);
extern void func_0c0427be(struct Actor *,int);
extern void func_0c044788(struct Actor *,struct Actor *);
void func_0c0889bc(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);
 if(a->b14b){
 a->b7++;a->b14b=0;a->b27b=1;a->b27a=16;
 func_0c048bb0(a,5);func_0c08a46a(a,sub);func_0c140a9c(a);
 }
}
void func_0c088a10(struct Actor *a,struct ActorSub2a4 *sub)
{
 func_0c02a026(a);
 a->b34=a->b140;
 func_0c08a46a(a,sub);
 if(*(char *)&sub->b7>0){
 a->b7++;a->b1ea=1;a->b1f2=3;
 func_0c02a0c4(a,21,a->b1a3+21);
 }else if(*(char *)&sub->b7<0){
 a->b6++;a->b7=0;
 func_0c02a0c4(a,21,a->b1a3+25);
 }
}
void func_0c088a84(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct Actor *child;
 char zero=0;
 if(*(char *)&sub->b7<0){
 a->b6++;a->b7=zero;a->b1f2=1;
 func_0c02a0c4(a,21,a->b1a3+25);return;
 }
 a->b1ea=1;a->b1f2=3;
 if(func_0c02a026(a)<0){
 a->b7++;
 sub->b7=2;sub->s10=zero;sub->s12=zero;sub->s14=2;sub->s18=5;
 child=a->p1c8;child->b6++;
 func_0c025900(a,5,5);func_0c0426c2(child,16);func_0c0427be(a,10);func_0c02a0c4(a,15,3);func_0c044788(a,a);
 a->b15a=-1;a->b1f7=197;
 }else{
 func_0c08a46a(a,sub);
 a->b34=a->b140;
 }
}
