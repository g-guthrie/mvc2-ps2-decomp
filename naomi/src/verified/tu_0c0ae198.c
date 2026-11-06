#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c244810[])(struct Actor *),(*table_0c24481c[])(struct Actor *),(*table_0c244824[])(struct Actor *),(*table_0c24482c[])(struct Actor *);
void func_0c0ae2ee(struct Actor *);
void func_0c0ae198(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;if(--a->s28==0){a->b6++;func_0c02a0c4(a,2,2);a->f104=a->b1d2?-0.8333333135f:0.8333333135f;}
}
void func_0c0ae1f6(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;if(func_0c02a026(a)<0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
}
void func_0c0ae246(struct Actor *a){table_0c244810[a->b6](a);}
void func_0c0ae258(struct Actor *a)
{
 func_0c02a026(a);if(!a->b141){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f92=a->b1d2?-8.33333302f:8.33333302f;a->f104=a->b1d2?-0.15625f:0.15625f;a->f96=7.5f;a->f108=-0.80357140303f;}func_0c0ae2ee(a);
}
void func_0c0ae2ee(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f41c>a->f56){a->b6++;func_0c02a0c4(a,2,3);a->f56=a->f41c;a->f92=0;a->f96=0;a->f104=0;a->f108=0;}
}
void func_0c0ae36c(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
void func_0c0ae39e(struct Actor *a){table_0c24481c[a->b6](a);}
void func_0c0ae3b0(struct Actor *a)
{
 struct ActorSub2a4 *state=&a->sub2a4;a->b6++;a->b12c=1;func_0c02a0c4(a,18,0);state->b0=0;
}
void func_0c0ae3dc(struct Actor *a){if(func_0c02a026(a)<0)a->b5++;}
void func_0c0ae3fc(struct Actor *a){table_0c244824[a->b6](a);}
void func_0c0ae40e(struct Actor *a){a->b6++;table_0c24482c[a->b32](a);}
