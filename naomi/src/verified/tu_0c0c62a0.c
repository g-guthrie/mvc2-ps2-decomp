#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
extern void (*table_0c247800[])(struct Actor *);
void func_0c0c62a0(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f41c<a->f56)){a->b6++;a->f56=a->f41c;a->f96=0;a->f108=0;a->b1f9=0;func_0c02a0c4(a,2,2);}}
void func_0c0c6320(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(func_0c02a026(a)<0)func_0c0437b8(a);if(a->b141){a->b141=0;a->f92=0;a->f104=0;}}
void func_0c0c638c(struct Actor *a){table_0c247800[a->b6](a);}
void func_0c0c639e(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;if(!a->b1d2){a->f92=10;a->f104=-0.20833333f;}else {a->f92=-10;a->f104=0.20833333f;}a->f96=4.28571415f;a->f108=-0.2678571343422f;}}
