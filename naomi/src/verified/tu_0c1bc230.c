/* Randomized velocity and lifetime setup; unsigned random arithmetic matches retail wraparound. */
#include "objects.h"
extern unsigned int func_0c02849a(void);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c1bc230(struct LinkedActor *a)
{
 float divisor;
 short velocity=func_0c02849a()&240;
 if(a->f92>0)velocity=-velocity;
 divisor=256.0f;
 a->f92=velocity*1.66666663f/divisor;
 a->f96=((func_0c02849a()&255)-128)*2.1428571f/divisor;
 a->s28=(func_0c02849a()&31)+16;
 func_0c02a0c4(a,23,7);
}
void func_0c1bc2a0(struct LinkedActor *a)
{
 float divisor;
 short velocity=func_0c02849a()&63;int animation;
 if(a->f92>0)velocity=-velocity;
 divisor=256.0f;
 a->f92=velocity*1.66666663f/divisor;
 a->f96=(((func_0c02849a()&63)-32)*16)*2.1428571f/divisor;
 a->s28=(func_0c02849a()&31)+8;
 animation=6;
 if(!(func_0c02849a()&3))animation=7;
 func_0c02a0c4(a,23,animation);
}
