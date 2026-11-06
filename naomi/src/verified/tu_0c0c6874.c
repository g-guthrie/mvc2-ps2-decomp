#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1accc0(struct Actor *,int);
extern void (*table_0c24784c[])(struct Actor *),(*table_0c24785c[])(struct Actor *);
void func_0c0c6874(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f56>a->f41c)){a->b7++;a->f56=a->f41c;func_0c043324(a);func_0c02a0c4(a,18,7);return;}func_0c02a026(a);}
void func_0c0c68ea(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;a->b6=0;a->f52=a->f100;}}
void func_0c0c6912(struct Actor *a){table_0c24784c[a->b7](a);}
void func_0c0c6924(struct Actor *a){a->b7++;a->s28=64;func_0c1accc0(a,13);func_0c02a0c4(a,0,0);}
void func_0c0c694a(struct Actor *a){if(--a->s28==0){a->b7++;func_0c02a0c4(a,8,2);return;}func_0c02a026(a);}
void func_0c0c696a(struct Actor *a){if(func_0c02a026(a)<0){a->b7++;func_0c02a0c4(a,20,2);}func_0c02a026(a);}
void func_0c0c6994(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;a->b6=0;}}
void func_0c0c69b4(struct Actor *a){a->x364[0]=0;table_0c24785c[a->b6](a);}
