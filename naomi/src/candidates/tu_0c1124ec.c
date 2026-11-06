/* Both callbacks and the literal pool match. The main routine differs
 * in movement expression scheduling and event-case instruction ordering. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c02a684(struct Actor *,int,int,int),func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24c06c[])(struct Actor *);
void func_0c1124ec(struct Actor *a)
{
 int zero=0;
 a->b3f8=2;a->b328=5;a->f52+=a->f92;a->f92=a->f92+a->f104;
 if(func_0c02a026(a)<0){float stopped;
  a->b6++;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;func_0c02a39a(a,0);
  stopped=0.0f;a->f92=stopped;a->f104=stopped;func_0c02a0c4(a,22,10);
 }else if(a->b141){
  func_0c02a684(a,0,a->b140,2);
  switch(a->b141){
  case 1:a->b1a1=56;goto count;
  case 2:a->b1a1=57;goto count;
  case 3:a->b1a1=58;
count:a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;break;
  }
  a->b141=zero;
 }
}
void func_0c1125cc(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c1125ee(struct Actor *a){table_0c24c06c[a->b6](a);}
