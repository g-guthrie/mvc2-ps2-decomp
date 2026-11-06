#include "objects.h"
extern float _builtin_fabsf(float);
extern char func_0c02a026(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c248284[])(struct Actor *),(*table_0c24828c[])(struct Actor *);
void func_0c0cfbe0(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(--a->s28<0)func_0c0437b8(a);}
void func_0c0cfc40(struct Actor *a){table_0c248284[a->b6](a);}
void func_0c0cfc52(struct Actor *a){a->b6++;a->b12c=1;a->f104=a->f52;if(a->w130){a->f52-=213.33333f;a->f92=5;}else {a->f52+=213.33333f;a->f92=-5;}func_0c02a0c4(a,18,0);}
void func_0c0cfc98(struct Actor *a){a->f52+=a->f92;func_0c02a026(a);if(_builtin_fabsf(a->f52-a->f104)<8.33333302f){a->b5++;a->f52=a->f104;func_0c02a0c4(a,0,0);}}
void func_0c0cfce8(struct Actor *a){if(func_0c03916c(a)){func_0c0437b8(a);return;}else table_0c24828c[a->b32](a);}
