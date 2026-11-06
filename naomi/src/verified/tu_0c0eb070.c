#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c025900(struct Actor *,char,char),func_0c02a0c4(struct Actor *,int,int);
void func_0c0eb070(struct Actor *a)
{
 a->b3f8=2;a->b328=5;a->b1ea=1;a->b1ed=2;a->b1f5=2;func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){
  a->f56=a->f41c;a->b1f9=0;a->b6++;func_0c043324(a);
  a->f92=3.3333333f;if(!a->b1d2)a->f92=-a->f92;
  a->f96=34.285714f;a->f108=-1.07142854f;func_0c025900(a,5,5);func_0c02a0c4(a,15,8);
 }
}
void func_0c0eb13a(struct Actor *a)
{
 a->b3f8=2;a->b328=5;a->b1ea=1;a->b1ed=2;func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f96>0.5357143f)return;
 a->b6++;a->s30=16;a->f96=2.1428571f;a->f108=-0.13392857f;
}
