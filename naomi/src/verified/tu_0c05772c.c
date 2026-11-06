#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c05772c(struct Actor *a)
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
 child=a->p1c8;child->p1b4=a;child->b1f6=two;
 child->b1a1=a->b1a3+37;a->b1a1=a->b1a3+37;
 a->b205=(char)sub->b2/2+32;
 }
}
void func_0c0577fc(struct Actor *a)
{
 a->b1ea=1;a->b1ed=2;a->b1f5=2;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c044e52(a)){
 func_0c043324(a);
 a->b7++;
 func_0c02a0c4(a,15,34);
 }
}
void func_0c057876(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b205=0;func_0c0437b8(a);}
}
