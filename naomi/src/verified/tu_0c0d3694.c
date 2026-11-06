#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c248534[])(struct Actor *),(*table_0c248544[])(struct Actor *);
void func_0c0d3694(struct Actor *a)
{
 if(a->b6==0){
  goto L;L: func_0c044cbc(a);
  a->b6++;
  a->b1f9=1;
  func_0c02a0c4(a,20,5);
  a->b1a1=72;a->w1ac=0;a->b19e=0;a->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c0346da(a,22);
  func_0c048bb0(a,5);
 }
 if(a->b1ff==3) func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if(func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0d375c(struct Actor *a){table_0c248534[a->b6](a);}
void func_0c0d376e(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b6++;
  a->b141=0;
  a->s28=18;
  a->f92=a->b1d2?19.166666031f:-19.166666031f;
  a->f104=a->b1d2?-0.72916663f:0.72916663f;
  a->f96=9.642857f;
  a->f108=-1.0044643f;
 }
}
void func_0c0d3812(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(--a->s28==0){
  a->b6++;
  a->f104=a->b1d2?-0.72916663f:-0.72916663f;
  a->f108=-1.0044643f;
  func_0c02a0c4(a,2,2);
 }
}
void func_0c0d3890(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!a->b141) func_0c02a026(a);
 if(!(a->f56>a->f41c)){
  a->b6++;
  a->f56=a->f41c;
  a->b1f9=0;
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 }
}
void func_0c0d3914(struct Actor *a)
{
 if(func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0d3936(struct Actor *a){table_0c248544[a->b6](a);}
