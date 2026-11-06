/* Exact animation exit, feedback direction flip, launch velocities, and state dispatch. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2487b8[])(struct Actor *);
void func_0c0d6460(struct Actor *a)
{
 if(func_0c02a026(a)>=0)return;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;func_0c0437b8(a);
}
void func_0c0d6492(struct Actor *a){table_0c2487b8[a->b6](a);}
void func_0c0d64a4(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b6++;a->b141=0;if(!(a->b34&1)){a->b1d2^=1;a->w130=a->b1d2;}}
}
void func_0c0d64e4(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
 a->b6++;a->b141=0;a->b1f9=2;
 a->f92=a->b1d2?-10.0f:10.0f;a->f104=0.0f;
 a->f96=8.5714283f;a->f108=-0.5357143f;
 }
}
