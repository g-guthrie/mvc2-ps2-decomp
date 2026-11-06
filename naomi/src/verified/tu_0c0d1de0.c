#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0ce574(struct Actor *);
extern void (*table_0c2483a0[])(struct Actor *);
void func_0c0d1de0(struct Actor *a){a->b6++;a->s28=21;func_0c0344a0(a,43);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1fc=0;a->f56=a->f41c;func_0c0442fa(a);func_0c02a39a(a,0);func_0c048bb0(a,5);a->f92=-8.33333302f;if(a->w130)a->f92=-a->f92;a->b1f5=2;a->b1f9=1;func_0c02a0c4(a,21,11);}
void func_0c0d1e60(struct Actor *a){func_0c02a026(a);if(--a->s28!=0){a->b1f5=2;if(!a->b141){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;return;}}else {a->b6++;a->b1f9=0;func_0c02a0c4(a,21,12);}}
void func_0c0d1ee2(struct Actor *a){if(func_0c02a026(a)<0)func_0c0ce574(a);}
void func_0c0d1f04(struct Actor *a){table_0c2483a0[a->b6](a);}
