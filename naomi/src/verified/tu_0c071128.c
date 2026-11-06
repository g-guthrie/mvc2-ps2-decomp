#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c13a394(struct Actor *,int,int,int);
extern void func_0c06f29c(struct Actor *,struct ActorSub2a4 *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c02a39a(struct Actor *,int);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c240f00[])(struct Actor *);
extern void func_0c03edcc(struct Actor *,struct Actor *);
void func_0c071128(struct Actor *a)
{
 struct ActorSub2a4 *sub;
 func_0c02a026(a);
 if(a->b141){
 a->b6++;
 sub=&a->sub2a4;
 sub->b1=64;
 *(unsigned short *)&sub->b2=0;
 *(unsigned char *)&sub->w4=255;
 sub->b0=12;
 func_0c13a394(a,1,2,0);
 a->s28=32;
 sub->b6=0;
 }
}
void func_0c071172(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 *(unsigned char *)&sub->w4=255;
 func_0c06f29c(a,sub);
 func_0c02a026(a);
 if(--a->s28<0){a->b6++;func_0c02a0c4(a,15,9);}
}
void func_0c0711b2(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 struct Actor *child;
 *(unsigned char *)&sub->w4=255;
 if(!a->b7)func_0c06f29c(a,sub);
 if(func_0c02a026(a)>=0){
 if(a->b141!=2){
 a->b141=0;
 *(unsigned char *)&sub->w4=0;
 a->b7++;
 func_0c02a39a(a,0);
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1d2=a->b1d2^1;
 child->b1a1=37;
 }
 }else{
 func_0c02a39a(a,0);
 func_0c0344a0(a,43);
 func_0c0437b8(a);
 }
}
void func_0c071244(struct Actor *a)
{
 table_0c240f00[a->b1f7&63](a);
}
void func_0c07125c(struct Actor *a)
{
 func_0c03edcc(a->p1c8,a);
}
