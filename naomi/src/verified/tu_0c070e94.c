#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c13a394(struct Actor *,int,int,int);
void func_0c070e94(struct Actor *a)
{
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 func_0c02a026(a);
 if(a->b141==2){
 a->b6++;
 a->f92=0;
 a->f104=0;
 a->f96=-6.428571224213f;
 a->f108=-0.80357140303f;
 }
}
void func_0c070f06(struct Actor *a)
{
 struct Actor *child;
 struct ActorSub2a4 *sub;
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(a->f56<a->f41c+274.28571f){
 a->b6++;
 a->s28=10;
 a->f108=0.5357143f;
 func_0c02a026(a);
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1d2=a->b1d2;
 child->b1a1=36;
 sub=&a->sub2a4;
 sub->b0=8;
 sub->b1=64;
 *(unsigned short *)&sub->b2=5;
 *(unsigned char *)&sub->w4=255;
 func_0c13a394(a,1,0,0);
 }
}
