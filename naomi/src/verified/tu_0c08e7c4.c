#include "objects.h"
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void (*table_0c24299c[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c03489c(struct Actor *);
extern void func_0c196c1c(struct Actor *,int,int);
void func_0c08e7c4(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,5,5);
 func_0c02a0c4(a,15,a->b1a3+2);
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 position.x=-238.33333f;
 position.y=169.28571f;
 position.z=0;
 func_0c1d4610(a,&position);
 func_0c048ce6(a);
}
void func_0c08e81c(struct Actor *a)
{
 table_0c24299c[a->b1f7&63](a);
}
void func_0c08e834(struct Actor *a)
{
 struct Actor *child;
 if(func_0c02a026(a)<0){a->w130^=1;func_0c0437b8(a);return;}
 if(a->b141){
 a->b141=0;
 child=a->p1c8;
 child->b1f6=11;
 child->b1f9=2;
 child->b1a1=32;
 a->b1a1=32;
 child->b1d2=a->b1d2;
 a->b1d2^=1;
 func_0c03489c(child);
 }
}
void func_0c08e898(struct Actor *a)
{
 struct Actor *child;
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}
 if(a->b141&1){a->b141&=0xfe;func_0c196c1c(a,4,0);}
 if(a->b141&2){
 a->b141&=0xfd;
 child=a->p1c8;
 child->b1f6=1;
 child->b1f9=2;
 child->b1a1=33;
 a->b1a1=33;
 child->b1d2=a->b1d2;
 }
}
