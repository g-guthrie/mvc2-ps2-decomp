#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c120c24(struct Actor *);
extern void (*table_0c24d324[])(struct Actor *);
void func_0c11f640(struct Actor *);
void func_0c11f614(struct Actor *a)
{
 float speed;
 a->b6++;speed=10.0f;if(!a->b1d2)speed=-10.0f;a->f92=speed;speed=0.0f;a->f104=speed;a->f96=speed;a->f108=speed;a->s28=5;func_0c11f640(a);
}
void func_0c11f640(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){if(--a->s28<=0 || (!a->b525 && !(a->w34a&0x800))){float speed;
  a->b6++;speed=0.8333333135f;if(!a->b1d2)speed=-0.8333333135f;a->f92=speed;a->f104=0.0f;func_0c02a0c4(a,2,2);}}
}
void func_0c11f6de(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(func_0c02a026(a)<0)func_0c120c24(a);
}
void func_0c11f738(struct Actor *a){table_0c24d324[a->b6](a);}
