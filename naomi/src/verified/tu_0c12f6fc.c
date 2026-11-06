#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1897a8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c13150c(struct Actor *),func_0c04be40(struct Actor *);
extern void (*table_0c24e164[])(struct Actor *);
void func_0c12f6fc(struct Actor *a)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);if(!a->b7){a->b7++;func_0c1897a8(a);}
 if(--a->s28<=0){int zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;a->b6++;a->s28=60;func_0c02a0c4(a,22,3);}
}
void func_0c12f762(struct Actor *a)
{
 func_0c02a026(a);if(--a->s28<=0){a->b6++;func_0c02a0c4(a,22,4);}
}
void func_0c12f792(struct Actor *a){if(func_0c02a026(a)<0)func_0c13150c(a);}
void func_0c12f7b4(struct Actor *a)
{
 if(!a->b6){int zero=0;a->b6++;a->b1f9=zero;func_0c02a0c4(a,20,zero);}
 else if(func_0c02a026(a)<0)func_0c13150c(a);
}
void func_0c12f7f6(struct Actor *a)
{
 a->b1eb=2;a->i204=3;func_0c04be40(a);table_0c24e164[a->b6](a);
}
