#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *),func_0c037688(struct Actor *),func_0c02a0c4(struct Actor *,int,char),func_0c0445fe(struct Actor *,struct Actor *),func_0c1982f4(struct Actor *,struct Actor *,int);
extern int func_0c0447bc(struct Actor *);
void func_0c142b28(struct Actor *,struct Actor *);
struct Actor *func_0c142b90(struct Actor *);
void func_0c142a18(struct Actor *a,struct Actor *owner)
{
 struct ActorSub2a4 *sub=&owner->sub2a4;
 if(owner->b5 || owner->b1d0!=29 || owner->b1e9!=3){a->b4=3;a->b12c=0;return;}
 if(!a->b32){
 if(!a->b33 && a->b19e){func_0c142b28(a,owner);return;}
 if(func_0c02a026(a)<0){if(sub->b2 && sub->b3)return;a->b4++;sub->b3=0;func_0c02a0c4(a,23,a->b32+14);}
 func_0c037d0c(a);return;
 }
 goto poll;poll:func_0c02a026(a);
 if(!sub->b3){a->b4++;func_0c02a0c4(a,23,a->b32+14);}
}
void func_0c142ad6(struct Actor *a,struct Actor *owner)
{
 struct ActorSub2a4 *sub=&owner->sub2a4;
 if(func_0c02a026(a)<0){a->b4=3;a->b12c=0;((char *)sub)[2]=-1;}
}
void func_0c142b08(struct Actor *a){func_0c037688(a);}
void func_0c142b28(struct Actor *a,struct Actor *owner)
{
 struct ActorSub2a4 *sub=&owner->sub2a4;struct Actor *other;
 a->b33=1;
 if((other=func_0c142b90(a))){sub->b2=1;other->b1f9=0;func_0c02a0c4(other,13,2);owner->b1f7=196;owner->b15a=-1;func_0c0445fe(a,other);other->b1f6=12;func_0c1982f4(owner,other,0);*(struct Actor **)((unsigned char *)sub+8)=other;}
}
struct Actor *func_0c142b90(struct Actor *a)
{
 struct Actor *other;
 if(!func_0c0447bc(a))return (struct Actor *)0;
 other=a->p1b0;
 if(other->b1a2!=55)return (struct Actor *)0;
 return other;
}
