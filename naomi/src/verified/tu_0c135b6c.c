#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *),func_0c037688(struct Actor *);
void func_0c135b6c(struct Actor *a)
{
 struct LinkedActor *owner=((struct LinkedActor *)a)->p24;float height;
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 height=((struct Actor *)((struct LinkedActor *)a)->p24)->f41c+68.57143f;
 if(height>a->f56){a->f56=height;a->s28=1;}
 if(--a->s28==0 || a->b19e){a->b5++;a->s30=21;
  if(a->b19e){struct Actor *other=a->p1b0;if(!other->b3){goto mask;mask:if(!(a->b19e&0x7f)){((struct Actor *)owner)->b19e=-128;owner->p20=(struct LinkedActor *)a->p1b0;}}}}
 else func_0c037d0c(a);
}
void func_0c135c26(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c135c34(struct Actor *a){func_0c037688(a);}
