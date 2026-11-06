/* func_0c1d5da8 and the 24-byte pool match. func_0c1d5d20 has the right
 * linked size but still differs in register allocation; only the wrapper is
 * exact code credit. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern short dat_0c232350[];
extern void func_0c1d5b08(struct Obj_tu5_03 *);
void func_0c1d5d20(register struct Obj_tu5_03 *parent,register int n)
{
 register int i;
 register short *index=&dat_0c232350[(signed char)n];
 for(i=0;i<3;i++) {
  struct Obj_tu5_03 *a;
  if((a=func_0c0374da(0,7,1))==0)break;
  a->b12c=0;a->p16=func_0c1d5b08;a->lcc=17;
  a->pos=parent->pos;
  a->l84=dat_0c2d9650->p0->entries[*index].value;
  a->p24=parent;a->b35=i;a->w30=i*2;a->b32=n;
 }
}
void func_0c1d5da8(struct Obj_tu5_03 *parent,int n)
{
 func_0c1d5d20(parent,n);
}
