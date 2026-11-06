#include "objects.h"
extern unsigned char dat_0c2f8338;
extern char func_0c02a026(struct Actor *);
extern int func_0c1ec190(void),func_0c03916c(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c16b084(struct Actor *,int),func_0c0346da(struct Actor *,int),func_0c0437b8(struct Actor *);
extern void (*table_0c24a4b4[])(struct Actor *),(*table_0c24a4bc[])(struct Actor *),(*table_0c24a4d0[])(struct Actor *);
void func_0c0f5d30(struct Actor *a)
{
 float offset;
 a->b12c=0;
 if(dat_0c2f8338>=2){
  a->b6++;a->s28=30;a->s30=24;a->f96=19.2857132f;a->f108=-0.80357140303f;a->f92=5.0f;
  offset=-245.0f;goto direction;
direction:if(!a->b1d2){a->f92=-a->f92;offset=245.0f;}
  a->f100=a->f52;a->f52+=offset;a->f104=0.0f;func_0c02a0c4(a,18,0);func_0c16b084(a,3);
 }
}
void func_0c0f5db8(struct Actor *a)
{
 int zero=0;a->b12c=zero;
 if(--a->s28<=0){a->b6++;a->b7=zero;a->b12c=1;}
}
void func_0c0f5de0(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!a->b7){if(--a->s30<=0){a->b7++;func_0c02a0c4(a,18,1);}}
 else if(!(a->f56>a->f41c)){float stopped=0.0f;
  a->b6++;a->f56=a->f41c;a->f52=a->f100;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c02a0c4(a,18,3);func_0c0346da(a,52);
 }
}
void func_0c0f5ec0(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b5++;a->b6=a->b7=0;func_0c02a0c4(a,0,0);}
}
void func_0c0f5ef0(struct Actor *a){table_0c24a4b4[a->b6](a);}
void func_0c0f5f02(struct Actor *a){a->b6++;table_0c24a4bc[a->b32](a);}
void func_0c0f5f1e(struct Actor *a){unsigned int r;a->b7++;r=func_0c1ec190();if(r&1)func_0c02a0c4(a,19,0);else func_0c02a0c4(a,19,1);}
void func_0c0f5f48(struct Actor *a){func_0c02a0c4(a,19,3);}
void func_0c0f5f50(struct Actor *a){func_0c02a0c4(a,19,2);}
void func_0c0f5f58(struct Actor *a)
{
 if(func_0c03916c(a))func_0c0437b8(a);
 else table_0c24a4d0[a->b32](a);
}
