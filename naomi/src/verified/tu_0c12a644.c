#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c24dcd0[])(struct Actor *),(*table_0c24dcdc[])(struct Actor *),(*table_0c24dce8[])(struct Actor *);
extern unsigned char dat_0c2f8338;
void func_0c12a68c(struct Actor *);
void func_0c12a848(struct Actor *);
void func_0c12a8a8(struct Actor *);
void func_0c12a644(struct Actor *a)
{
 a->b6++;a->b32=a->b200;a->s28=24;
 a->f92=-16.666666031f;a->f104=0;a->f96=0;a->f108=0;
 if(a->b32)a->f92=-26.666666031f;
 if(a->b1d2)a->f92=-a->f92;
 func_0c12a68c(a);
}
void func_0c12a68c(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141)return;
 if(a->b32 && !a->b200){a->b32=0;a->f92=-16.666666031f;if(a->b1d2)a->f92=-a->f92;}
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28<=0)func_0c0437b8(a);
}
void func_0c12a720(struct Actor *a){table_0c24dcd0[a->b6](a);}
void func_0c12a732(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141)return;
 a->b6++;
 if(!a->b200){a->f92=20.0f;a->f104=-0.80357140303f;a->f96=5.0f;a->f108=-0.5357143f;}
 else{a->f92=25.0f;a->f104=-0.80357140303f;a->f96=6.66666651f;a->f108=-0.80357140303f;}
 if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}
}
void func_0c12a7d6(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c12a848(a);}
}
void func_0c12a848(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c12a86a(struct Actor *a){table_0c24dcdc[a->b6](a);}
void func_0c12a87c(struct Actor *a)
{
 if(dat_0c2f8338<2){a->b12c=0;}
 else{a->b6++;a->b12c=1;func_0c12a8a8(a);return;}
}
void func_0c12a8a8(struct Actor *a){table_0c24dce8[a->b7](a);}
