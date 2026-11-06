#include "objects.h"
extern void func_0c044cbc(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern void func_0c139ff0(struct Actor *, int);
extern void func_0c1910d0(struct Actor *, int);
extern void func_0c0443ce(struct Actor *);
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c240d20[])(struct Actor *);
extern unsigned char dat_0c240bc8[], dat_0c240bcc[], dat_0c240bd0[], dat_0c240bd4[], dat_0c240bd8[], dat_0c240bdc[];
extern unsigned char dat_0c240be0[], dat_0c240be4[], dat_0c240be8[], dat_0c240bec[], dat_0c240bf0[], dat_0c240bf4[];
extern unsigned char dat_0c240bf8[], dat_0c240bfc[], dat_0c240c00[], dat_0c240c04[], dat_0c240c08[], dat_0c240c0c[];
void func_0c06dbec(struct Actor *);
void func_0c06dcc0(struct Actor *);
void func_0c06dd66(struct Actor *);
void func_0c06de2e(struct Actor *);
void func_0c06df18(struct Actor *);
void func_0c06df2a(struct Actor *);
void func_0c06e06c(struct Actor *);
void func_0c06e1f2(struct Actor *);
void func_0c06e2a4(struct Actor *);
void func_0c06e2ee(struct Actor *);
void func_0c06e338(struct Actor *);
void func_0c06e3f8(struct Actor *);
void func_0c06e430(struct Actor *);
void func_0c06e472(struct Actor *);
void func_0c06e494(struct Actor *);

void func_0c06dba4(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c06de2e(a);else func_0c06dd66(a);}else if(a->b1f9==1)func_0c06dcc0(a);else func_0c06dbec(a);}
void func_0c06dbec(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c240bc8;a->b1a7=zero;a->pad2a2[0]=one;break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c240bcc;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c240bd0;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c06dcc0(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c240bc8;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c240bcc;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c240bd0;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);
}
void func_0c06dd66(struct Actor *a)
{
 int zero=0;int se;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;se=20;a->p3f4=dat_0c240bd4;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;se=21;a->p3f4=dat_0c240bd8;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=5;se=22;a->p3f4=dat_0c240bdc;a->b1a7=2;break;
 }
 func_0c0346da(a,se);
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c06de2e(struct Actor *a)
{
 int zero=0;int se;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;se=20;a->p3f4=dat_0c240bd4;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=10;se=21;a->p3f4=dat_0c240bd8;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=11;se=22;a->p3f4=dat_0c240bdc;a->b1a7=2;break;
 }
 func_0c0346da(a,se);
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
void func_0c06deca(struct Actor *a)
{
 if(!a->b1fe&&(a->b1d6&0x0f))goto call;else if(a->b1fe&&(a->b1d6&0xf0)){call:func_0c06df18(a);}
}
void func_0c06df18(struct Actor *a){if((unsigned char)a->b1fe==1)func_0c06e06c(a);else func_0c06df2a(a);}
void func_0c06df2a(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=12;func_0c0346da(a,20);if(!a->b1fc)a->p3f4=dat_0c240be0;else a->p3f4=dat_0c240bf8;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=13;if(a->w1fa&0x1000){a->b158=3;a->b1a1=18;}func_0c0346da(a,21);if(!a->b1fc)a->p3f4=dat_0c240be4;else a->p3f4=dat_0c240bfc;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=14;if(a->w1fa&0x1000){a->b158=4;a->b1a1=19;}func_0c0346da(a,22);if(!a->b1fc)a->p3f4=dat_0c240be8;else a->p3f4=dat_0c240c00;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&0x0f)a->b1d6--;
}
void func_0c06e06c(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=15;if(a->w1fa&0x1000){a->b158=3;a->b1a1=20;}func_0c0346da(a,20);if(!a->b1fc)a->p3f4=dat_0c240bec;else a->p3f4=dat_0c240c04;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=16;if(a->w1fa&0x1000){a->b158=4;a->b1a1=21;}func_0c0346da(a,21);if(!a->b1fc)a->p3f4=dat_0c240bf0;else a->p3f4=dat_0c240c08;a->b1a7=1;break;
 case 2:a->b158=2;a->b1a1=17;if(a->w1fa&0x1000){a->b158=5;a->b1a1=22;}func_0c0346da(a,22);if(!a->b1fc)a->p3f4=dat_0c240bf4;else a->p3f4=dat_0c240c0c;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}
void func_0c06e1d0(struct Actor *a){table_0c240d20[a->b1ff](a);}
void func_0c06e1e4(struct Actor *a){func_0c043352(a);func_0c06e1f2(a);}
void func_0c06e1f2(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c06e3f8(a);else func_0c06e338(a);}else if(a->b1f9==1)func_0c06e2ee(a);else func_0c06e2a4(a);
}
void func_0c06e2a4(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b1e8==2&&a->b141){int zero=0;a->b141=zero;func_0c139ff0(a,zero);func_0c1910d0(a,0);}
}
void func_0c06e2ee(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b1e8==2&&a->b141){a->b141=0;func_0c139ff0(a,1);func_0c1910d0(a,1);}
}
void func_0c06e338(struct Actor *a)
{
 switch(a->b1e8){
 case 0:case 1:
  if(func_0c02a026(a)<0)goto finished;
  break;
 case 2:
  if(func_0c02a026(a)<0){
  finished:
   func_0c0437b8(a);
   break;
  }
  if(a->b141&&((a->w34e|a->w352)&0x20)){
   int zero=0;
   func_0c0443ce(a);
   a->w352=zero;a->b1a1=27;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;
   dat_0c2f83f8->arr[a->b2]++;
   func_0c02a0c4(a,8,4);
   func_0c0346da(a,22);
  }
  break;
 }
}
void func_0c06e3f8(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c06e41a(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c06e430(a);}
void func_0c06e430(struct Actor *a)
{
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1)func_0c06e494(a);else func_0c06e472(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c06e472(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c06e494(struct Actor *a){if(func_0c02a026(a)<0)func_0c0438de(a);}
