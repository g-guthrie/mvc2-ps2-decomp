#include "objects.h"
void func_0c029e70(struct Actor *a,unsigned char sequence,unsigned char step)
{
 unsigned char *bank;
 int *base;
 int *entries;
 a->b159=sequence;a->b158=step;
 bank=a->p168;base=(int *)(bank+a->w132);
 entries=(int *)(bank+base[sequence]);a->p154=(struct AnimationFrame20 *)(bank+entries[step]);
 *(struct AnimationFrame8 *)&a->b140=*(struct AnimationFrame8 *)a->p154;
 *(int *)&a->pad6ca=0;*(int *)&a->b14c=0;*(int *)&a->w150=0;
 if(!a->b142)do{
 a->p154=(struct AnimationFrame20 *)((unsigned char *)a->p154+8);
 if(a->b143&128)a->p154=(struct AnimationFrame20 *)(a->p168+*(int *)a->p154);
 *(struct AnimationFrame8 *)&a->b140=*(struct AnimationFrame8 *)a->p154;
 *(int *)&a->pad6ca=0;*(int *)&a->b14c=0;*(int *)&a->w150=0;
 }while(!a->b142);
}
void func_0c029f0e(struct Actor *a,unsigned char sequence,unsigned char step,int position)
{
 unsigned char *bank;
 int *base;
 int *entries;
 a->b159=sequence;a->b158=step;
 bank=a->p168;base=(int *)(bank+a->w132);
 entries=(int *)(bank+base[sequence]);a->p154=(struct AnimationFrame20 *)(bank+entries[step]);
 a->p154=(struct AnimationFrame20 *)((unsigned char *)a->p154+position*8);
 *(struct AnimationFrame8 *)&a->b140=*(struct AnimationFrame8 *)a->p154;
 *(int *)&a->pad6ca=0;*(int *)&a->b14c=0;*(int *)&a->w150=0;
 if(!a->b142)do{
 a->p154=(struct AnimationFrame20 *)((unsigned char *)a->p154+8);
 if(a->b143&128)a->p154=(struct AnimationFrame20 *)(a->p168+*(int *)a->p154);
 *(struct AnimationFrame8 *)&a->b140=*(struct AnimationFrame8 *)a->p154;
 *(int *)&a->pad6ca=0;*(int *)&a->b14c=0;*(int *)&a->w150=0;
 }while(!a->b142);
}
