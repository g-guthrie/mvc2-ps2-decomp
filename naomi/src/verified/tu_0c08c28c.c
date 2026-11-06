#include "objects.h"
extern void (*table_0c242774[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c08c28c(struct Actor *a)
{
 table_0c242774[a->b6](a);
}
void func_0c08c29e(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
 a->b6++;
 a->f96=2.1428571f;a->f108=-0.2678571343422f;
 a->f92=a->b1d2?13.33333302f:-13.33333302f;
 a->f104=a->b1d2?-0.46875f:0.46875f;
 }
}
void func_0c08c2f8(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f41c<a->f56)){
 a->f56=a->f41c;a->f96=0;a->f108=0;
 func_0c02a0c4(a,2,2);
 a->b6++;
 }
}
void func_0c08c36c(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f92*a->f104>0){a->b6++;a->f92=0;a->f104=0;}
}
