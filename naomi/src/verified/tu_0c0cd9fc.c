#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
extern int (*table_0c248084[])(struct Actor *);
void func_0c0cd9fc(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){a->b6++;func_0c02a0c4(a,21,5);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f108=-0.80357140303f;}
}
void func_0c0cda4a(struct Actor *a)
{
 a->b3f8=2;a->b328=5;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){int zero=0;a->b6++;a->f56=a->f41c;a->b1f9=zero;func_0c02a0c4(a,21,7);func_0c043324(a);a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;}
 else func_0c02a026(a);
}
void func_0c0cdad0(struct Actor *a)
{
 if(func_0c02a026(a)<0){int zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;func_0c0437b8(a);}
}
int func_0c0cdb02(struct Actor *a){return table_0c248084[a->b1f9](a);}
