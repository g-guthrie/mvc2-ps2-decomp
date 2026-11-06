#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *),func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
void func_0c12a444(struct Actor *a)
{
 float stopped;unsigned char facing;
 func_0c02a026(a);stopped=0.0f;
 if(a->b19e){a->f92=5.83333302f;a->f104=stopped;a->f96=15.0f;a->f108=-1.07142854f;
  if(a->b1d2)a->f92=-a->f92;*(char *)&a->b1d3=-1;facing=a->b1d2;func_0c0438de(a);a->b1d2=facing;a->w130=facing;
 }else if(a->f56<a->f41c){a->b6++;a->f56=a->f41c;a->b1f9=0;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c043324(a);func_0c02a0c4(a,1,3);}
}
void func_0c12a4f0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
