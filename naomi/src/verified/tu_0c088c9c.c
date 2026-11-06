#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c195384(struct Actor *,int);
extern void func_0c04afb4(struct Actor *,short);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2424e4[])(struct Actor *,struct ActorSub2a4 *);
void func_0c088c9c(struct Actor *a,struct ActorSub2a4 *sub)
{
 struct Actor *child;
 int amount;
 char zero=0,one=1;
 a->b1ea=one;a->b1f2=3;
 child=a->p1c8;
 child->b1f4=2;
 if(func_0c02a026(a)<0){
 child->p1b4=a;child->b1f6=one;child->b1d2=a->b1d2;child->b1f9=2;child->b1a1=35;
 child->b6=zero;child->b1fd=zero;
 a->b34=7;
 if(a->b1d2)a->b34=32-(char)a->b34;
 func_0c025900(a,0,0);
 func_0c195384(a,3);
 func_0c04afb4(child,sub->s12);
 a->b6++;a->b7=zero;a->b1f2=one;
 func_0c02a0c4(a,21,24);
 }else{
 amount=sub->s10>>1;
 if(amount<0){sub->s10=zero;amount=zero;}
 if(amount>=a->b142)amount=a->b142-1;
 a->b142=a->b142-amount;
 }
}
void func_0c088d80(struct Actor *a)
{
 a->b1ea=1;
 if(func_0c02a026(a)>=0){
 if(a->b141){a->b141=0;a->w130^=1;a->b1d2^=1;}
 }else func_0c0437b8(a);
}
void func_0c088dc8(struct Actor *a)
{
 table_0c2424e4[a->b6](a,&a->sub2a4);
}
