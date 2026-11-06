#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c03489c(struct Actor *);
extern void func_0c025762(void);
void func_0c05eda8(struct Actor *a)
{
 struct Actor *child;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b141){
 a->b141=0;
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1f9=0;
 func_0c025900(a,0,0);
 child->b1a1=33;
 child->b1d2=a->b1d2;
 }
}
void func_0c05edfe(struct Actor *a)
{
 struct Actor *child;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b141){
 a->b141=0;
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=11;
 child->b1f9=0;
 func_0c025900(a,0,0);
 child->b1a1=32;
 child->b1d2=a->b1d2;
 func_0c03489c(a);
 }
}
void func_0c05ee60(struct Actor *a)
{
 struct Actor *child;
 if(func_0c02a026(a)<0)func_0c0438de(a);
 if(a->b141){
 a->b141=0;
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=1;
 child->b1f9=2;
 func_0c025762();
 func_0c025900(a,0,0);
 child->b1a1=35;
 child->b1d2=a->b1d2^1;
 }
}
