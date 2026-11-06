#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0451f2(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Actor *func_0c168828(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c249abc[])(struct Actor *),(*table_0c249ac8[])(struct Actor *),(*table_0c249ad4[])(struct Actor *),(*table_0c249adc[])(struct Actor *),(*table_0c249af0[])(struct Actor *);
void func_0c0e9f06(struct Actor *);
void func_0c0e9c50(struct Actor *a){int zero;
 if(!a->b6){func_0c044cbc(a);func_0c0344a0(a,20);a->b6++;zero=0;a->b1a1=22;a->b1f9=zero;func_0c02a0c4(a,20,16);func_0c0346da(a,21);a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,5);}
 if(a->b1ff==3)func_0c043352(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0e9d24(struct Actor *a){table_0c249abc[a->b6](a);}
void func_0c0e9d36(struct Actor *a){func_0c02a026(a);if(a->b141){a->b6++;a->s28=20;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f92=a->b1d2?15.83333302f:-15.83333302f;a->f104=a->b1d2?-0.3125f:0.3125f;}}
void func_0c0e9dd0(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(--a->s28==0){a->b6++;func_0c02a0c4(a,2,2);}}
void func_0c0e9e38(struct Actor *a){if(func_0c02a026(a)<0){func_0c0437b8(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;}}
void func_0c0e9e66(struct Actor *a){table_0c249ac8[a->b6](a);}
void func_0c0e9e78(struct Actor *a){func_0c02a026(a);if(!a->b141){a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b6++;a->s28=20;a->f92=a->b1d2?-15.83333302f:15.83333302f;a->f104=a->b1d2?0.3125f:-0.3125f;func_0c0e9f06(a);}}
void func_0c0e9f06(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);if(--a->s28==0){a->b6++;func_0c02a0c4(a,2,3);}}
void func_0c0e9f70(struct Actor *a){if(func_0c02a026(a)<0){func_0c0437b8(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;}}
void func_0c0e9f9e(struct Actor *a){table_0c249ad4[a->b6](a);}
void func_0c0e9fb0(struct Actor *a){a->b6++;a->b12c=1;func_0c02a0c4(a,18,0);}
void func_0c0e9fc4(struct Actor *a){if(func_0c02a026(a)<0){a->b5++;return;}if(a->b141){a->b141=0;func_0c168828(a);}}
void func_0c0e9ffc(struct Actor *a){a->f56=a->f41c;if(func_0c03916c(a))func_0c0437b8(a);else table_0c249adc[a->b32](a);}
void func_0c0ea032(struct Actor *a){table_0c249af0[a->b6](a);}
