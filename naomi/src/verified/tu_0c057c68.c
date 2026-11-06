#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);
void func_0c057c68(struct Actor *a)
{
 a->b1ea=1;a->b1ed=2;a->b1f5=2;a->b1f2=3;
 if(a->b141)a->b141=0;
 if(func_0c02a026(a)<0){
 a->b7++;
 a->f92=4.16666651f;a->f104=0;a->f96=17.142857f;a->f108=-0.66964281f;
 if(a->b1d2)a->f92=-a->f92;
 func_0c02a0c4(a,15,14);
 }
}
void func_0c057ce6(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 struct Actor *child;
 char two=2;
 a->b1ea=1;a->b1ed=two;a->b1f5=two;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){a->b7++;func_0c02a0c4(a,15,33);return;}
 if(a->b141){
 a->b141=0;
 func_0c025900(a,0,0);
 child=a->p1c8;child->b1f6=two;
 child->b1a1=a->b1a3+61;a->b1a1=a->b1a3+61;
 a->b205=(char)sub->b2/2+32;
 }
}
