#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0432ca(struct Actor *),func_0c02a684(struct Actor *,int,int,int),func_0c02a0c4(struct Actor *,int,int),func_0c0438de(struct Actor *);
extern float dat_0c24d37c[];
extern char dat_0c24d394[][2];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c11fa00(struct Actor *a)
{
 int zero;float *row,speed,acceleration,stopped;
 a->b6++;func_0c0442fa(a);func_0c048bb0(a,5);zero=0;
 if(a->b1f9!=2){a->b1f9=zero;func_0c0432ca(a);}
 row=&dat_0c24d37c[(unsigned char)a->b1a3*2];speed=*row++;acceleration=*row;
 if(a->b1d2){speed=-speed;acceleration=-acceleration;}
 a->f92=speed;a->f104=acceleration;stopped=0.0f;a->f96=stopped;a->f108=stopped;
 func_0c02a684(a,1,20,1);
 a->b1a1=dat_0c24d394[(unsigned char)a->b1a3][0];a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3);
}
void func_0c11faae(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141>=0){
  a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
  if(!(0.0f>a->f92*a->f104)){float stopped=0.0f;
   a->f92=stopped;a->f104=stopped;
   if(a->b1f9==2){*(int *)((char *)a+0x2ac)=12;func_0c0438de(a);}
   else{a->b6++;func_0c02a0c4(a,21,a->b1a3+3);}
  }
 }
}
