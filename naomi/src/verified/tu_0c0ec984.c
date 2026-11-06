#include "objects.h"
extern unsigned char dat_0c249c48[],dat_0c249c4c[],dat_0c249c50[],dat_0c249c54[],dat_0c249c58[],dat_0c249c5c[];
extern unsigned char dat_0c249c60[],dat_0c249c64[],dat_0c249c68[],dat_0c249c6c[],dat_0c249c70[],dat_0c249c74[];
extern unsigned char dat_0c249c78[],dat_0c249c7c[],dat_0c249c80[],dat_0c249c84[],dat_0c249c88[],dat_0c249c8c[];
extern void (*table_0c249dac[])(struct Actor *),(*table_0c249dbc[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c0f0406(struct Actor *);
void func_0c0eca90(struct Actor *a),func_0c0ecb32(struct Actor *a),func_0c0ecc1a(struct Actor *a),func_0c0ecd04(struct Actor *a);
void func_0c0ecdec(struct Actor *a),punch_0c0ece2c(struct Actor *a),kick_0c0ecf4c(struct Actor *a);
void func_0c0ec984(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(a->b1a1==57&&a->b1a0&&a->b19e&&a->b5==0&&!a->p1b0->b3){
  struct Actor *o=a->p1b0;
  if(o->b1d0==18||o->b5==3){a->b1a0=0;func_0c02a0c4(a,21,9);return;}
 }
 if(a->b201&&!a->b5&&--sub->s10<0){
  int m=a->b1d0;
  if(m!=21&&m!=29)func_0c0f0406(a);
 }
}
void func_0c0eca0e(struct Actor *a){table_0c249dac[a->b1ff](a);}
void func_0c0eca22(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0ecd04(a);else func_0c0ecc1a(a);}else if(a->b1f9==1)func_0c0ecb32(a);else func_0c0eca90(a);}
void func_0c0eca90(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c249c48;a->b1a7=zero;break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c249c4c;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c249c50;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c0ecb32(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c249c48;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c249c4c;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;func_0c0346da(a,22);a->p3f4=dat_0c249c50;a->b1a7=2;sub->b2=zero;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
void func_0c0ecc1a(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c249c54;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c249c58;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=5;func_0c0346da(a,22);a->p3f4=dat_0c249c5c;a->b1a7=2;sub->b2=zero;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c0ecd04(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c249c54;a->b1a7=zero;break;
 case 1:a->b158=one;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c249c58;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c249c5c;a->b1a7=one;func_0c0344a0(a,3);func_0c0346da(a,41);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
void func_0c0ecdbc(struct Actor *a)
{
 if(a->b201)goto go;
 if((a->b1fe==0&&(a->b1d6&15))||(a->b1fe!=0&&(a->b1d6&0xf0)))go:func_0c0ecdec(a);
}
void func_0c0ecdec(struct Actor *a)
{
 if((unsigned char)a->b1fe==1)kick_0c0ecf4c(a);
 else punch_0c0ece2c(a);
}
void punch_0c0ece2c(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c249c60;else a->p3f4=dat_0c249c78;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c249c64;else a->p3f4=dat_0c249c7c;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=14;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c249c68;else a->p3f4=dat_0c249c80;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&15)a->b1d6--;
}
void kick_0c0ecf4c(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  a->b158=zero;a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c249c6c;else a->p3f4=dat_0c249c84;
  a->b1a7=zero;break;
 case 1:
  a->b158=1;a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c249c70;else a->p3f4=dat_0c249c88;
  a->b1a7=1;break;
 case 2:
  a->b158=2;a->b1a1=17;func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c249c74;else a->p3f4=dat_0c249c8c;
  a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}
void func_0c0ed03a(struct Actor *a){table_0c249dbc[a->b1ff](a);}
