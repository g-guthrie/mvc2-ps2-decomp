/* Exact 0x0c06b6f8..0x0c06b7c8: select limb and strength velocities, then start the next animation. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct ActorMotionFloat2 dat_0c2408e8[],dat_0c2408ec[];
void func_0c06b6f8(struct Actor *a)
{
 int row;float zero;
 if(func_0c02a026(a)<0){
 a->b6++;zero=0.0f;a->f108=a->f104=a->f96=a->f92=zero;a->s28=32;
 row=(unsigned char)a->b1fe*2;
 a->f92=a->b1d2?dat_0c2408e8[row+(unsigned char)a->b1a3].x:-dat_0c2408e8[row+(unsigned char)a->b1a3].x;
 a->f96=dat_0c2408ec[row+(unsigned char)a->b1a3].x;func_0c0344a0(a,6);
 a->b158=(unsigned char)a->b1fe?21:24;
 func_0c02a0c4(a,21,(unsigned char)a->b1a3*2+a->b158);
 }
}
