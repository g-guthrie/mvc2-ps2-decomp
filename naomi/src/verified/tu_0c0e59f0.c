#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c249620[])(struct Actor *);
struct MotionValues_0c249630 {float vx,ax,vy,ay;};
extern struct MotionValues_0c249630 table_0c249630[];
void func_0c0e59f0(struct Actor *a)
{
 unsigned char direction;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 direction=a->b1d2;
 if((!direction&&a->f92>0.0f)||(direction&&a->f92<0.0f)){
  float stopped=0.0f;a->f92=stopped;a->f104=stopped;
 }
 func_0c02a026(a);
 if(!(a->f56>a->f41c)){
  a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c043324(a);func_0c02a0c4(a,21,18);
 }
}
void func_0c0e5a9c(struct Actor *a)
{
 if(func_0c02a026(a)<0){float stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);}
}
void func_0c0e5ace(struct Actor *a){table_0c249620[a->b6](a);}
void func_0c0e5ae0(struct Actor *a)
{
 int zero;
 a->b6++;a->b1a1=a->b1a3?73:71;zero=0;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c048bb0(a,10);func_0c0442fa(a);
 a->b158=a->b1a3?26:24;func_0c02a0c4(a,21,a->b158);
}
void func_0c0e5b68(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;
  a->f92=a->b1d2?table_0c249630[(unsigned char)a->b1a3].vx:-table_0c249630[(unsigned char)a->b1a3].vx;
  a->f104=a->b1d2?table_0c249630[(unsigned char)a->b1a3].ax:-table_0c249630[(unsigned char)a->b1a3].ax;
  a->f96=table_0c249630[(unsigned char)a->b1a3].vy;a->f108=table_0c249630[(unsigned char)a->b1a3].ay;
 }
}
