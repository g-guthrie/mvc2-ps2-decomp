#include "objects.h"
extern unsigned char dat_0c243004[],dat_0c243014[];
extern unsigned char dat_0c242f8c[],dat_0c242f90[],dat_0c242f94[],dat_0c242f98[],dat_0c242f9c[],dat_0c242fa0[];
extern unsigned char dat_0c242fa4[],dat_0c242fa8[],dat_0c242fac[],dat_0c242fb0[],dat_0c242fb4[],dat_0c242fb8[];
extern unsigned char dat_0c242fbc[],dat_0c242fc0[],dat_0c242fc4[],dat_0c242fc8[],dat_0c242fcc[],dat_0c242fd0[];
extern void (*table_0c243094[])(struct Actor *),(*table_0c2430a4[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
int func_0c095712(struct Actor *a),func_0c095748(struct Actor *a);
void func_0c095800(struct Actor *a),func_0c0958a8(struct Actor *a),func_0c095970(struct Actor *a),func_0c095a16(struct Actor *a);
void func_0c095b20(struct Actor *a),punch_0c095b4a(struct Actor *a),kick_0c095c62(struct Actor *a);
int func_0c0956ec(struct Actor *a)
{
 if(func_0c095712(a)||func_0c095748(a))return 1;
 return 0;
}
int func_0c095712(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c243014,a->x384))return 0;
 else if(!*a->p40c)return 0;
 a->b258=5;return 1;
}
int func_0c095748(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c243004,a->x37c))return 0;
 else if(!*a->p40c)return 0;
 a->b258=4;return 1;
}
void func_0c09577e(void){}
void func_0c095782(struct Actor *a){table_0c243094[a->b1ff](a);}
void func_0c095796(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c095a16(a);else func_0c095970(a);}else if(a->b1f9==1)func_0c0958a8(a);else func_0c095800(a);}
void func_0c095800(struct Actor *a)
{
 int zero=0,v;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c242f8c;a->b1a7=zero;break;
 case 1:v=1;a->b158=v;a->b1a1=v;func_0c0346da(a,21);a->p3f4=dat_0c242f90;a->b1a7=v;break;
 case 2:v=2;a->b158=v;a->b1a1=v;func_0c0346da(a,22);a->p3f4=dat_0c242f94;a->b1a7=v;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c0958a8(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c242f8c;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=7;a->p3f4=dat_0c242f90;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;func_0c0346da(a,22);a->p3f4=dat_0c242f94;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
void func_0c095970(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c242f98;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;a->p3f4=dat_0c242f9c;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=5;func_0c0346da(a,22);a->p3f4=dat_0c242fa0;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c095a16(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c242f98;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c242f9c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=11;func_0c0346da(a,22);a->p3f4=dat_0c242fa0;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}
void func_0c095ae8(struct Actor *a)
{
 if((a->b1fe==0&&(a->b1d6&15))||(a->b1fe!=0&&(a->b1d6&0xf0)))func_0c095b20(a);
 a->f108=-0.80357140303f;
}
void func_0c095b20(struct Actor *a)
{
 if((unsigned char)a->b1fe==1)kick_0c095c62(a);
 else punch_0c095b4a(a);
 a->f108=-0.80357140303f;
}
void punch_0c095b4a(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c242fa4;else a->p3f4=dat_0c242fbc;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c242fa8;else a->p3f4=dat_0c242fc0;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=14;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c242fac;else a->p3f4=dat_0c242fc4;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6--;
}
void kick_0c095c62(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c242fb0;else a->p3f4=dat_0c242fc8;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c242fb4;else a->p3f4=dat_0c242fcc;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=17;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c242fb8;else a->p3f4=dat_0c242fd0;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}
void func_0c095d82(struct Actor *a){table_0c2430a4[a->b1ff](a);}
