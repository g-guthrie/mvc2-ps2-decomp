/* Candidate: the second function loads the 0x418 status word before the 0x414 word (12 bytes in the 0x90001010 test); everything else matches. */
#include "objects.h"
extern void func_0c025762(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c0344a0(struct Actor *,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c03489c(struct Actor *);
extern void func_0c04b02a(struct Actor *);
void func_0c075d14(struct Actor *a,struct Actor *target)
{
 struct LinkedActorVec3 position;
 func_0c025762(a);
 a->b141=16;
 a->f92=13.33333302f;a->f104=0;
 a->f96=8.5714283f;a->f108=-0.5357143f;
 if(a->b1d2)a->f92=-a->f92;
 target->p1b4=a;target->b1f6=2;target->b1d2=a->b1d2^1;target->b1a1=34;
 func_0c0346da(a,2);
 func_0c0344a0(a,4);
 position.x=-106.666664124f;position.y=34.2857132f;
 func_0c1cea66(a,&position,2);
 func_0c03489c(a);
}
void func_0c075dac(struct Actor *a) {}
void func_0c075db0(struct Actor *a,struct Actor *target)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,6,6);
 a->b141=6;
 target->s28=1;
 target->f56=target->f41c;
 func_0c02a0c4(target,13,9);
 {unsigned int *flags=&target->l414;if((flags[0]&0x90001010)|(flags[1]&1)){target->b1d2^=1;target->w130=target->b1d2;}}
 target->p1b4=a;target->b1a1=35;
 func_0c04b02a(a);
 func_0c0346da(a,5);
 func_0c0344a0(a,3);
 position.x=-160.0f;position.y=34.2857132f;
 func_0c1cea66(a,&position,2);
}
