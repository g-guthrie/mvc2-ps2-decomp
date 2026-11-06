/* Stance and air-state handlers for one character (0x0c0bce0c-0x0c0bd39c),
 * following tu_0c0bc47c; same shape as tu_0c0c50d0's 0x0c0c5b46 group. */
#include "objects.h"
extern void func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c15ba0c(struct Actor *,int,int);
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char dat_0c245a34[],dat_0c245a38[],dat_0c245a3c[],dat_0c245a40[],dat_0c245a44[],dat_0c245a48[];
extern unsigned char dat_0c245a4c[],dat_0c245a50[],dat_0c245a54[],dat_0c245a58[],dat_0c245a5c[],dat_0c245a60[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c245b68[])(struct Actor *),(*table_0c245b78[])(struct Actor *),(*table_0c245b88[])(struct Actor *);
void func_0c0bce46(struct Actor *),func_0c0bcf54(struct Actor *);
void func_0c0bd180(struct Actor *),func_0c0bd1c6(struct Actor *),func_0c0bd25a(struct Actor *),func_0c0bd2ac(struct Actor *),func_0c0bd2e4(struct Actor *),func_0c0bd32a(struct Actor *);
void func_0c0bd0cc(struct Actor *);
void func_0c0bce34(struct Actor *);

void func_0c0bce0c(struct Actor *a)
{
 if(!a->b1fe){if(a->b1d6&15)goto call;}
 goto s;s:if(a->b1fe){if(!(a->b1d6&0xf0))return;call:func_0c0bce34(a);}
}
void func_0c0bce34(struct Actor *a){if((unsigned char)a->b1fe==1)func_0c0bcf54(a);else func_0c0bce46(a);}
void func_0c0bce46(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=12;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=dat_0c245a34;else a->p3f4=dat_0c245a4c;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=13;func_0c0346da(a,21);if(!a->b1fc)a->p3f4=dat_0c245a38;else a->p3f4=dat_0c245a50;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=14;if(!a->b1fc)a->p3f4=dat_0c245a3c;else a->p3f4=dat_0c245a54;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6=a->b1d6-1;
}
void func_0c0bcf54(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=15;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=dat_0c245a40;else a->p3f4=dat_0c245a58;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=16;func_0c0346da(a,21);if(!a->b1fc)a->p3f4=dat_0c245a44;else a->p3f4=dat_0c245a5c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=26;if(a->w1fa&0x1000){a->b6++;a->b158=6;a->b1a1=19;}else if(a->w1fa&0x800){a->b158=5;a->b1a1=20;}func_0c0346da(a,22);if(!a->b1fc)a->p3f4=dat_0c245a48;else a->p3f4=dat_0c245a60;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6=a->b1d6-16;
}
void func_0c0bd0aa(struct Actor *a){table_0c245b68[a->b1ff](a);}
void func_0c0bd0be(struct Actor *a){func_0c043352(a);func_0c0bd0cc(a);}
void func_0c0bd0cc(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(!a->b1f9)func_0c0bd2ac(a);else func_0c0bd2e4(a);}
 else if(a->b1f9==1)func_0c0bd25a(a);else func_0c0bd180(a);
}
void func_0c0bd180(struct Actor *a)
{
 switch(a->b1e8){
 case 2:if(a->b6){func_0c0bd1c6(a);return;}
 case 0:case 1:goto x; x: if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c0bd1c6(struct Actor *a){table_0c245b78[a->b7](a);}
void func_0c0bd1d8(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b7++;a->s28=0xf0;func_0c15ba0c(a,6,0);}
}
void func_0c0bd208(struct Actor *a)
{
 func_0c02a026(a);
 if(--a->s28<0)a->b7++;
}
void func_0c0bd22a(struct Actor *a){a->b7++;func_0c02a0c4(a,21,24);}
void func_0c0bd238(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0bd25a(struct Actor *a)
{
 switch(a->b1e8){case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);}
}
void func_0c0bd2ac(struct Actor *a)
{
 switch(a->b1e8){case 0:case 1:case 2:if(func_0c02a026(a)<0)func_0c0437b8(a);}
}
void func_0c0bd2e4(struct Actor *a)
{
 switch(a->b1e8){
 case 2:if(a->b6){func_0c0bd32a(a);return;}
 case 0:case 1:goto y; y: if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 }
}
void func_0c0bd32a(struct Actor *a){table_0c245b88[a->b7](a);}
void func_0c0bd33c(struct Actor *a)
{
 a->b7++;a->b1f9=2;
 if(a->b1d2)a->f92=3.3333333f;else a->f92=-3.3333333f;
 a->f104=0.0f;a->f96=25.714285f;a->f108=-1.07142854f;a->s30=0;
}
