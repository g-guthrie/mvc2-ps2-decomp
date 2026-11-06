#include "objects.h"
#define OWNER(a) ((struct Actor *)((struct LinkedActor *)(a))->p24)
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int);
extern void (*table_0c25162c[])(struct Actor *),(*table_0c251638[])(struct Actor *);
void func_0c162b84(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;func_0c02a0c4(a,23,10);}}
void func_0c162bae(struct Actor *a){table_0c25162c[a->b6](a);}
void func_0c162bc0(struct Actor *a)
{
 func_0c02a026(a);if(a->b141<0 && OWNER(a)->b1d0!=20)a->b34=1;if(!a->b141)a->b6++;
}
void func_0c162bf8(struct Actor *a)
{
 if(!a->b141)func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<OWNER(a)->f41c){a->b6++;a->f56=OWNER(a)->f41c;func_0c0344a0(OWNER(a),32);}
}
void func_0c162c74(struct Actor *a){table_0c251638[a->b6](a);}
