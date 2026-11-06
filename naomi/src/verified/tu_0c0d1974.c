#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *),func_0c0ce574(struct Actor *),func_0c0cfebe(struct Actor *),func_0c0451f2(struct Actor *),func_0c044f1c(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Actor *func_0c1af524(struct Actor *,unsigned char,unsigned char),*func_0c162d9c(struct Actor *,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c248380[])(struct Actor *),(*table_0c248394[])(struct Actor *);
void func_0c0d19ea(struct Actor *);
void func_0c0d1974(struct Actor *a){int action;func_0c02a026(a);if(*(int *)&a->pad10c[40]){a->b6++;if(a->b1e9==12)action=a->b1a3+17;else action=a->b1a3+15;func_0c02a0c4(a,21,action);}}
void func_0c0d19b6(struct Actor *a){if(func_0c02a026(a)<0){if(a->b1f9==2)func_0c0438de(a);else func_0c0ce574(a);}}
void func_0c0d19ea(struct Actor *a){char event;if((event=a->b141)!=0){a->b141=0;func_0c1af524(a,1,event&127);}}
void func_0c0d1a0e(struct Actor *a){int zero=0;
 if(!a->b6){a->b6++;func_0c048bb0(a,5);a->b1a1=48;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,0);func_0c0cfebe(a);return;}
 if(a->b141&128){a->b27b=zero;a->b27a=16;a->b141&=127;func_0c162d9c(a,a->b1a3+0);}
 func_0c0d19ea(a);if(func_0c02a026(a)<0)func_0c0ce574(a);}
void func_0c0d1ade(struct Actor *a){int zero=0;
 if(!a->b6){a->b6++;a->b1f9=zero;func_0c048bb0(a,5);a->b1a1=48;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,1);func_0c0cfebe(a);return;}
 if(a->b141&128){a->b27b=zero;a->b27a=16;a->b141&=127;func_0c162d9c(a,a->b1a3+2);}
 func_0c0d19ea(a);if(func_0c02a026(a)<0)func_0c0ce574(a);}
void func_0c0d1b86(struct Actor *a){table_0c248380[a->b6](a);}
void func_0c0d1bc0(struct Actor *a){int zero;
 a->b6++;func_0c048bb0(a,5);a->b1a1=48;zero=0;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,2);func_0c0cfebe(a);}
void func_0c0d1c0e(struct Actor *a){func_0c02a026(a);if(!a->b141){a->b6++;func_0c0451f2(a);a->f92=0;a->f104=0;a->f96=12.85714245f;a->f108=-0.5357143f;}}
void func_0c0d1c4c(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(a->b141){a->b6++;a->b141=0;}}
void func_0c0d1cd0(struct Actor *a){func_0c02a026(a);if(a->b141&128){a->b6++;a->b141&=127;a->f92=1.66666663f;a->f104=-0.02604166605f;a->f96=7.5f;a->f108=-0.80357140303f;if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}func_0c162d9c(a,a->b1a3+4);}func_0c0d19ea(a);}
void func_0c0d1d3e(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);func_0c0d19ea(a);if(func_0c044e52(a))func_0c044f1c(a);}
void func_0c0d1da2(struct Actor *a){table_0c248394[a->b6](a);}
