#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c044cbc(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24acf0[])(struct Actor *),(*table_0c24ad00[])(struct Actor *);
void func_0c0fd38a(struct Actor *),func_0c0fd406(struct Actor *),func_0c0fd4d6(struct Actor *),func_0c0fd4f8(struct Actor *),func_0c0fd51a(struct Actor *),func_0c0fd552(struct Actor *),func_0c0fd592(struct Actor *),func_0c0fd5e0(struct Actor *);
void func_0c0fd368(struct Actor *a){table_0c24acf0[a->b1ff](a);}
void func_0c0fd37c(struct Actor *a){func_0c043352(a);func_0c0fd38a(a);}
void func_0c0fd38a(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if(a->b1fe==0){if(a->b1f9==0)func_0c0fd406(a);else func_0c0fd4d6(a);}else{if(a->b1f9==0)func_0c0fd4f8(a);else func_0c0fd51a(a);}}
void func_0c0fd406(struct Actor *a){int zero;struct Tbl_ub3_01 **statistics;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 statistics=&dat_0c2f83f8;zero=0;
 switch(a->b1e8){case 0:if(a->b141){a->b141=zero;a->b1a1=25;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;(*statistics)->arr[a->b2]++;func_0c0346da(a,20);}break;
 case 1:break;case 2:if(a->b141!=0){a->b141=zero;a->b1a1=26;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;(*statistics)->arr[a->b2]++;func_0c0346da(a,22);}break;
 default:break;}}
void func_0c0fd4d6(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0fd4f8(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0fd51a(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0fd53c(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c0fd552(a);}
void func_0c0fd552(struct Actor *a){func_0c042018(a);func_0c0421b8(a);if(!a->b1fe)func_0c0fd592(a);else func_0c0fd5e0(a);if(func_0c044e52(a))func_0c044f1c(a);}
void func_0c0fd592(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0fd5e0(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c0fd602(struct Actor *a){int zero;
 if(!a->b6){a->b6++;a->b1f9=1;a->b1a1=18;zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c044cbc(a);func_0c048bb0(a,5);func_0c02a0c4(a,20,5);func_0c0346da(a,22);}
 a->b1ff=3;func_0c043352(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0fd6c6(struct Actor *a){table_0c24ad00[a->b6](a);}
void func_0c0fd6d8(struct Actor *a){func_0c02a026(a);if(!a->b141){a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->s28=34;a->f92=-15.83333302f;a->f104=0;if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}}}
