#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1437e0(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void (*table_0c242edc[])(struct Actor *),(*table_0c242eec[])(struct Actor *);
void func_0c094904(struct Actor *,struct ActorSubByteState *);
void func_0c094800(struct Actor *a,struct ActorSubByteState *state)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(a->b141&2){a->b141&=125;func_0c1437e0(a,0,0);func_0c0346da(a,75);}
 if(state->b6){func_0c02a0c4(a,22,6);a->b6++;a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;}
}
void func_0c094872(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c094894(struct Actor *a)
{
 table_0c242edc[a->b6](a);
}
void func_0c0948a6(struct Actor *a,struct ActorSubByteState *state)
{
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1f9=0;a->f56=a->f41c;func_0c02a0c4(a,20,2);func_0c0344a0(a,16);
 a->s28=64;func_0c094904(a,state);
}
void func_0c094904(struct Actor *a,struct ActorSubByteState *state)
{
 func_0c02a026(a);if(a->s28--==0)func_0c0437b8(a);
}
void func_0c09492c(struct Actor *a)
{
 table_0c242eec[a->b6](a);
}
