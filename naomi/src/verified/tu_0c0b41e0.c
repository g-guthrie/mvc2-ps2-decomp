/* Actor state handlers at 0x0c0b41e0 (exact). */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned int func_0c02849a(void);
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c1d6032(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c244de8[])(struct Actor *),(*table_0c244df4[])(struct Actor *),(*table_0c244e00[])(struct Actor *),(*table_0c244e08[])(struct Actor *),(*table_0c244e10[])(struct Actor *);
void func_0c0b4370(struct Actor *),func_0c0b44ba(struct Actor *),func_0c0b45dc(struct Actor *);
void func_0c0b41e0(struct Actor *a){int zero;
 if(!a->b6){func_0c044cbc(a);a->b6++;zero=0;
 if(a->b1fe==0){a->b1a1=(unsigned char)53;a->b1f9=zero;func_0c02a0c4(a,20,5);}
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c0346da(a,21);func_0c048bb0(a,5);}
 if(a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0b42b4(struct Actor *a){table_0c244de8[a->b6](a);}
void func_0c0b42c6(struct Actor *a){func_0c02a026(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 if(!a->b141){func_0c1d6032(a);a->b6++;a->f92=a->b1d2?18.3333320618f:-18.3333320618f;a->f104=a->b1d2?-0.625f:0.625f;a->s28=12;func_0c0b4370(a);}}
void func_0c0b4370(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(!(a->f92*a->f104<0.0f)){a->f92=0;a->f104=0;}
 if(--a->s28==0){a->b6++;a->b158=2;func_0c02a0c4(a,a->b159,a->b158);}}
void func_0c0b43dc(struct Actor *a){register float zero;
 a->f52+=a->f92;a->f92+=a->f104;zero=0.0f;
 if(!(a->f92*a->f104<0.0f)){a->f92=zero;a->f104=zero;}
 if(func_0c02a026(a)<0){a->f92=zero;a->f104=zero;func_0c0437b8(a);}}
void func_0c0b4440(struct Actor *a){table_0c244df4[a->b6](a);}
void func_0c0b4452(struct Actor *a){func_0c02a026(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b6++;a->f92=a->b1d2?-9.166666031f:9.166666031f;a->s28=8;func_0c0b44ba(a);}
void func_0c0b44ba(struct Actor *a){func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28==0){a->b6++;a->f104=a->b1d2?0.20833333f:-0.20833333f;a->b158=3;func_0c02a0c4(a,a->b159,a->b158);}}
void func_0c0b4540(struct Actor *a){a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0){a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}}
void func_0c0b45ac(struct Actor *a){table_0c244e00[a->b6](a);}
void func_0c0b45be(struct Actor *a){a->b6++;a->b7=func_0c02849a();a->b7&=1;func_0c0b45dc(a);}
void func_0c0b45dc(struct Actor *a){table_0c244e08[a->b7](a);}
void func_0c0b45ee(struct Actor *a){table_0c244e10[a->b32](a);}
