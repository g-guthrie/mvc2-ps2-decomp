/* Stance and special-state handlers for one character (0x0c1199e0-0x0c11a52c). */
#include "objects.h"
struct Sub2a4_1199e0 { short w0; unsigned char pad2[6]; unsigned char b8; char b9; unsigned char pad10[6]; unsigned char b16; unsigned char pad17; short s18; };
struct Sub2a4Bytes_1199e0 { unsigned char pad0[16]; unsigned char b16; unsigned char pad17; char b18, b19; };
extern void func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c044cbc(struct Actor *);
extern void func_0c11c0ec(struct Actor *,unsigned char),func_0c02a39a(struct Actor *,int),func_0c11b314(struct Actor *,struct Sub2a4_1199e0 *);
extern void func_0c17c9c4(struct Actor *,int),func_0c0344a0(struct Actor *,int),func_0c0438de(struct Actor *);
extern void func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char dat_0c24cc1c[],dat_0c24cc20[],dat_0c24cc24[],dat_0c24cc28[],dat_0c24cc2c[],dat_0c24cc30[];
extern unsigned char dat_0c24cc34[],dat_0c24cc38[],dat_0c24cc3c[],dat_0c24cc40[],dat_0c24cc44[],dat_0c24cc48[];
extern unsigned char dat_0c24cc4c[],dat_0c24cc50[],dat_0c24cc54[],dat_0c24cc58[],dat_0c24cc5c[],dat_0c24cc60[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24cd64[])(struct Actor *),(*table_0c24cd74[])(struct Actor *);
void func_0c119b2a(struct Actor *),func_0c119bbe(struct Actor *),func_0c119c7a(struct Actor *),func_0c119d36(struct Actor *);
void func_0c119e36(struct Actor *),func_0c119e48(struct Actor *),func_0c119f40(struct Actor *);
void func_0c11a060(struct Actor *),func_0c11a11a(struct Actor *),func_0c11a260(struct Actor *),func_0c11a3a0(struct Actor *),func_0c11a3de(struct Actor *);
void func_0c11a478(struct Actor *),func_0c11a4ba(struct Actor *),func_0c11a4dc(struct Actor *);

void func_0c1199e0(struct Actor *p)
{
 register struct Actor *a=p;
 register struct Sub2a4_1199e0 *s=(struct Sub2a4_1199e0 *)((char *)a+0x2a4);
 int zero;
 a->w3e4=2;
 zero=0;
 if(s->b16){
  if(*(short *)&a->b158==s->s18){
   s->b16--;
   if(a->b141){func_0c11c0ec(a,a->b141-1);a->b141=zero;}
  }else s->b16=zero;
 }
 if(a->b201&&!a->b5)goto t;
 if(a->b201&&a->b5==1)return;
 if(!s->b8)return;
 s->b8=zero;func_0c02a39a(a,0);return;
 t:if(!--s->w0){if(a->b1d0==21)s->w0=1;else func_0c11b314(a,s);}
}
void func_0c119aa4(struct Actor *a){table_0c24cd64[a->b1ff](a);}
void func_0c119ab8(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c119d36(a);else func_0c119c7a(a);}else if(a->b1f9==1)func_0c119bbe(a);else func_0c119b2a(a);}
void func_0c119b2a(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c24cc1c;a->b1a7=zero;break;case 1:{int mode=1;a->b158=mode;a->b1a1=mode;a->p3f4=dat_0c24cc20;a->b1a7=mode;break;}case 2:{int mode=2;a->b158=mode;a->b1a1=mode;a->p3f4=dat_0c24cc24;a->b1a7=mode;break;}}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);}
void func_0c119bbe(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c24cc1c;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=7;a->p3f4=dat_0c24cc20;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c24cc24;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);}
void func_0c119c7a(struct Actor *p){register struct Actor *a=p;register int zero;struct Sub2a4Bytes_1199e0 *s=(struct Sub2a4Bytes_1199e0 *)((char *)a+0x2a4);zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c24cc28;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=4;a->p3f4=dat_0c24cc2c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=5;a->p3f4=dat_0c24cc30;func_0c0346da(a,22);a->b1a7=2;s->b19=8;s->b18=a->b158;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);}
void func_0c119d36(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c24cc28;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c24cc2c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c24cc30;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}
void func_0c119e06(struct Actor *a)
{
 if(!a->b201){if(!a->b1fe){if(a->b1d6&15)goto call;}}else goto call;
 goto s;s:if(a->b1fe){if(!(a->b1d6&0xf0))return;call:func_0c119e36(a);}
}
void func_0c119e36(struct Actor *a){if((unsigned char)a->b1fe==1)func_0c119f40(a);else func_0c119e48(a);}
void func_0c119e48(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=12;if(!a->b1fc)a->p3f4=dat_0c24cc34;else a->p3f4=dat_0c24cc4c;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=13;if(!a->b1fc)a->p3f4=dat_0c24cc38;else a->p3f4=dat_0c24cc50;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=14;if(!a->b1fc)a->p3f4=dat_0c24cc3c;else a->p3f4=dat_0c24cc54;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6=a->b1d6-1;
}
void func_0c119f40(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=15;if(!a->b1fc)a->p3f4=dat_0c24cc40;else a->p3f4=dat_0c24cc58;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=16;if(!a->b1fc)a->p3f4=dat_0c24cc44;else a->p3f4=dat_0c24cc5c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=17;if(!a->b1fc)a->p3f4=dat_0c24cc48;else a->p3f4=dat_0c24cc60;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6=a->b1d6-16;
}
void func_0c11a03e(struct Actor *a){table_0c24cd74[a->b1ff](a);}
void func_0c11a052(struct Actor *a){func_0c043352(a);func_0c11a060(a);}
void func_0c11a060(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c11a3de(a);else func_0c11a3a0(a);}
 else if(a->b1f9==1)func_0c11a260(a);else func_0c11a11a(a);
}
void func_0c11a11a(struct Actor *p)
{
 register struct Actor *a=p;
 register struct Sub2a4_1199e0 *s=(struct Sub2a4_1199e0 *)((char *)a+0x2a4);
 int zero=0;
 switch(a->b1e8){
 case 0:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);
  if(a->b141){a->b141=zero;a->b1a1=19;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
  break;
 case 2:
  switch(a->b7){
  case 0:a->b7++;s->b9=zero;
  case 1:if(a->b141){s->b9=a->b141;func_0c17c9c4(a,0);func_0c0344a0(a,38);a->b7++;a->s28=20;}func_0c02a026(a);break;
  case 2:if(!--a->s28){a->b7++;s->b9=zero;func_0c02a0c4(a,7,3);}s->b9=a->b141;func_0c02a026(a);break;
  case 3:if(func_0c02a026(a)<0)func_0c0437b8(a);s->b9=a->b141;if(!s->b9)s->b9=-1;break;
  }
  break;
 }
}
void func_0c11a260(struct Actor *p)
{
 register struct Actor *a=p;
 register struct Sub2a4_1199e0 *s=(struct Sub2a4_1199e0 *)((char *)a+0x2a4);
 int zero=0;
 switch(a->b1e8){
 case 0:if(func_0c02a026(a)<0)func_0c0437b8(a);break;
 case 1:if(func_0c02a026(a)<0)func_0c0437b8(a);
  if(a->b141){a->b141=zero;a->b1a1=20;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;}
  break;
 case 2:
  switch(a->b7){
  case 0:a->b7++;s->b9=zero;
  case 1:if(a->b141){s->b9=a->b141;func_0c17c9c4(a,1);func_0c0344a0(a,38);a->b7++;a->s28=20;}func_0c02a026(a);break;
  case 2:if(!--a->s28){a->b7++;s->b9=zero;func_0c02a0c4(a,9,3);}s->b9=a->b141;func_0c02a026(a);break;
  case 3:if(func_0c02a026(a)<0)func_0c0437b8(a);s->b9=a->b141;if(!s->b9)s->b9=-1;break;
  }
  break;
 }
}
void func_0c11a3a0(struct Actor *a)
{
 register struct Sub2a4_1199e0 *s=(struct Sub2a4_1199e0 *)((char *)a+0x2a4);
 switch(a->b1e8){
 case 0:goto check;
 case 1:goto check;
 case 2:s->b16=8;
 check:if(func_0c02a026(a)<0)func_0c0437b8(a);
 }
}
void func_0c11a3de(struct Actor *a)
{
 switch(a->b1e8){
 case 0:goto check;
 default:break;
 case 1:case 2:if(a->b141){int zero=0;a->b1a1=a->b141;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->b141=zero;}
 check:if(func_0c02a026(a)<0)func_0c0437b8(a);
 }
}
void func_0c11a462(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c11a478(a);}
void func_0c11a478(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1)func_0c11a4dc(a);else func_0c11a4ba(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c11a4ba(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c11a4dc(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
