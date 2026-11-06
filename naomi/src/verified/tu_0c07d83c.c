#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c0438de(struct Actor *),func_0c044f1c(struct Actor *),func_0c0818f8(struct Actor *),func_0c0818cc(struct Actor *),func_0c08183c(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c044df4(struct Actor *),func_0c043352(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c241958[])(struct Actor *),(*table_0c241968[])(struct Actor *),(*table_0c241974[])(struct Actor *),(*table_0c2419a0[])(struct Actor *);
extern float dat_0c24198c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c07d8a2(struct Actor *),func_0c07d850(struct Actor *),func_0c07d9da(struct Actor *);
void func_0c07d83c(struct Actor *a){table_0c241958[a->b1ff](a);}
void func_0c07d850(struct Actor *a){func_0c042018(a);func_0c0421b8(a);if(!a->l320){if(func_0c02a026(a)<0){func_0c0438de(a);return;}if(func_0c044e52(a))func_0c044f1c(a);}else func_0c07d8a2(a);}
void func_0c07d8a2(struct Actor *a){table_0c241968[a->b7](a);}
void func_0c07d8b4(struct Actor *a){func_0c02a026(a);if(a->b141){float velocity;a->b7++;a->b141=0;a->b1fc=0;velocity=-14.166666031f;if(a->b1d2)velocity=14.166666031f;a->f92=velocity;a->f104=0;a->f96=-17.142857f;a->f108=-0.5357143f;}if(func_0c044e52(a))func_0c044f1c(a);}
void func_0c07d91c(struct Actor *a){func_0c02a026(a);if(a->f56<a->f41c){a->b7++;func_0c0818f8(a);func_0c02a0c4(a,1,3);func_0c0818cc(a);}}
void func_0c07d9a0(struct Actor *a){if(func_0c02a026(a)<0)func_0c08183c(a);}
void func_0c07d9c2(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c07d850(a);}
void func_0c07d9da(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);table_0c241974[a->l320](a);}
void func_0c07da30(struct Actor *a){if(func_0c02a026(a)<0)func_0c08183c(a);}
void func_0c07da52(struct Actor *a){if(!a->b6){func_0c02a026(a);if(a->b141){float velocity,acceleration;a->b6++;velocity=26.666666031f;acceleration=-0.8333333135f;if(!a->b1d2){velocity=-26.666666031f;acceleration=0.8333333135f;}a->f92=velocity;a->f104=acceleration;}}else{if(a->b141==2){a->b141=0;a->f92=0;a->f104=0;}if(func_0c02a026(a)<0)func_0c08183c(a);}}
void func_0c07daf8(struct Actor *a){if(func_0c02a026(a)<0)func_0c08183c(a);else if(a->b141){float distance;a->b141=0;distance=53.3333321f;if(!a->b1d2)distance=-53.3333321f;a->f52+=distance;}}
void func_0c07db3c(struct Actor *a){if(func_0c02a026(a)<0)func_0c08183c(a);else if(a->b141){float distance;a->b141=0;distance=53.3333321f;if(!a->b1d2)distance=-53.3333321f;a->f52+=distance;}}
void func_0c07db80(struct Actor *a){if(func_0c02a026(a)<0)func_0c08183c(a);else{float marker=(float)a->b141;if(marker>0){float distance;a->b141=0;distance=dat_0c24198c[(int)marker];if(!a->b1d2)distance=-distance;a->f52+=distance;}else{a->f92=0;a->f104=0;}}}
void func_0c07dbf4(struct Actor *a){if(!a->b6){int zero;func_0c02a026(a);zero=0;if(a->b14b){a->b1a1=a->b14b;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->b14b=zero;}if(*(char*)&a->b140>0){a->b140=zero;dat_0c2d9260.b5=1;dat_0c2d9260.b6=1;func_0c0346da(a,48);}if(--a->s28<=0){a->b6++;func_0c02a0c4(a,7,4);}}else if(func_0c02a026(a)<0)func_0c08183c(a);}
void func_0c07dc8e(struct Actor *a){func_0c043352(a);func_0c07d9da(a);}
void func_0c07dc9e(struct Actor *a){table_0c2419a0[a->b1ff](a);}
