#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c0f8db0(struct Actor *);
void func_0c0f8d3c(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){float stopped=0.0f;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->b6++;
  a->f96=0.8333333135f;a->f108=-0.15625f;
  a->f92=a->b1d2?-11.666666031f:11.666666031f;
  a->f104=a->b1d2?0.1041666642f:-0.1041666642f;
  func_0c0f8db0(a);
 }
}
void func_0c0f8db0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f41c<a->f56)){float stopped=0.0f;
  a->b6++;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->f56=a->f41c;
  a->f92=a->b1d2?-6.66666651f:6.66666651f;func_0c02a0c4(a,2,3);
 }
}
