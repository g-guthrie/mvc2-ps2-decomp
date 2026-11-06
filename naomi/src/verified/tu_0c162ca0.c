#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037688(struct Actor *);
void func_0c162ca0(struct Actor *a)
{
 if(OWNER(a)->b1d0!=20)a->b34=1;
 if(a->b141){a->b6++;a->f104*=4.0f;a->f108*=4.0f;}
 a->f92+=a->f104;a->f96+=a->f108;a->f52=OWNER(a)->f52+a->f92;a->f56=OWNER(a)->f56+a->f96;func_0c02a026(a);
}
void func_0c162d10(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,23,10);return;}
 a->f92+=a->f104;a->f96+=a->f108;a->f52=OWNER(a)->f52+a->f92;a->f56=OWNER(a)->f56+a->f96;
}
void func_0c162d72(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c162d80(struct Actor *a){func_0c037688(a);}
