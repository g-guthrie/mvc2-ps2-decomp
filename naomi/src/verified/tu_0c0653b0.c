#include "objects.h"
extern void func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c2403c4[])(struct Actor *);
void func_0c065432(struct Actor *),func_0c065454(struct Actor *),func_0c0654a0(struct Actor *),func_0c0654d8(struct Actor *),func_0c065526(struct Actor *),func_0c065568(struct Actor *),func_0c06571c(struct Actor *);
void func_0c0653b0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0654d8(a);else func_0c0654a0(a);}
 else{if(a->b1f9==1)func_0c065454(a);else func_0c065432(a);}
}
void func_0c065432(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c065454(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b141){a->b141=0;a->b1a1=7;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}
}
void func_0c0654a0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0654d8(struct Actor *a)
{
 switch(a->b1e8){case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);break;}
}
void func_0c065510(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c065526(a);}
void func_0c065526(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1)func_0c06571c(a);else func_0c065568(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c065568(struct Actor *a){if(a->f108==0)a->f108=-0.80357140303f;if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c06559e(struct Actor *a){if(a->f108==0)a->f108=-0.80357140303f;if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c065600(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){a->b6++;if((unsigned char)a->b158==13){a->f92=-5.83333302f;a->f96=-7.5f;if(a->w130)a->f92=-a->f92;}else a->f96=-8.5714283f;}
}
void func_0c065652(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6=5;a->f92=a->f104=a->f96=0;a->f108=-0.80357140303f;func_0c02a0c4(a,1,9);}
}
void func_0c065690(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){a->b6++;a->f92=-10.0f;a->f104=0.625f;if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}}
}
void func_0c0656d6(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;a->f92=a->f104=a->f96=0;a->f108=-0.80357140303f;func_0c02a0c4(a,1,9);}
}
void func_0c065716(struct Actor *a){func_0c02a026(a);}
void func_0c06571c(struct Actor *a){table_0c2403c4[a->b6](a);}
