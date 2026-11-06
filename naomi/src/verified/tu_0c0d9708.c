#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c248a94[])(struct Actor *);
void func_0c0d9708(struct Actor *a){if(!a->b141)func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;}}
void func_0c0d978c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0d97ae(struct Actor *a){if(!a->b6){a->b6++;a->b1f9=0;a->f56=a->f41c;func_0c02a0c4(a,20,2);return;}else if(func_0c02a026(a)<0){func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}}
void func_0c0d9812(struct Actor *a){table_0c248a94[a->b6](a);}
